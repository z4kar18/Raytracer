/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** RayTracerUtils.cpp
*/

#include "../include/RayTracerUtils.hpp"
#include <algorithm>
#include <cmath>

Vec3 rayToColor(const Ray& ray,
                const std::vector<std::shared_ptr<IPrimitive>>& objects,
                const std::vector<Light>& lights,
                float ambientIntensity,
                float diffuseIntensity) {
    HitInfo closestHit;
    bool hasHit = false;
    float closestT = 1e30f;

    for (const auto& obj : objects) {
        HitInfo hit;
        if (obj->hit(ray, 0.001f, closestT, hit)) {
            hasHit = true;
            closestT = hit.t;
            closestHit = hit;
        }
    }

    if (hasHit) {
        Vec3 color = closestHit.color * ambientIntensity;

        for (const auto& light : lights) {
            Vec3 lightDir;
            float intensity = light.getIntensity();

            if (light.getType() == Light::Type::DIRECTIONAL) {
                lightDir = -light.getVector().normalize();
            } else if (light.getType() == Light::Type::POINT) {
                lightDir = (light.getVector() - closestHit.point).normalize();
            }

            Ray shadowRay(closestHit.point + closestHit.normal * 0.001f, lightDir);
            bool inShadow = false;

            for (const auto& obj : objects) {
                HitInfo shadowHit;
                if (obj->hit(shadowRay, 0.001f, 1000.0f, shadowHit)) {
                    inShadow = true;
                    break;
                }
            }

            if (!inShadow) {
                float dot = std::max(0.0f, closestHit.normal.dot(lightDir));
                color = color + (closestHit.color * diffuseIntensity * dot * intensity);
            }
        }

        return color;
    }

    return Vec3(0, 0, 0);  // Fondo negro
}

