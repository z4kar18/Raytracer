/*
** EPITECH PROJECT, 2025
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado [WSL: Ubuntu-20.04]
** File description:
** Sphere
*/

#include "../include/Sphere.hpp"
#include <cmath>

Sphere::Sphere(const Vec3& center, float radius, const Vec3& color)
    : m_center(center), m_radius(radius), m_color(color) {}

bool Sphere::hit(const Ray& ray, float tMin, float tMax, HitInfo& info) const {
    Vec3 oc = ray.origin() - m_center;
    float a = ray.direction().dot(ray.direction());
    float b = 2.0f * oc.dot(ray.direction());
    float c = oc.dot(oc) - m_radius * m_radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return false;

    float sqrtD = std::sqrt(discriminant);
    float root = (-b - sqrtD) / (2 * a);
    if (root < tMin || root > tMax) {
        root = (-b + sqrtD) / (2 * a);
        if (root < tMin || root > tMax)
            return false;
    }

    info.t = root;
    info.point = ray.at(root);
    info.normal = (info.point - m_center).normalize();
    info.color = m_color;
    return true;
}
