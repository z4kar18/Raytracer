/*
** EPITECH PROJECT, 2025
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado [WSL: Ubuntu-20.04]
** File description:
** Cone
*/

#include "../include/Cone.hpp"
#include <cmath>

Cone::Cone(const Vec3& center, float height, float radius, const Vec3& color)
    : m_center(center), m_height(height), m_radius(radius), m_color(color) {}

bool Cone::hit(const Ray& ray, float tMin, float tMax, HitInfo& info) const {
    Vec3 co = ray.origin() - m_center;

    float k = m_radius / m_height;
    float k2 = k * k;

    float dx = ray.direction().x;
    float dy = ray.direction().y;
    float dz = ray.direction().z;

    float ox = co.x;
    float oy = co.y;
    float oz = co.z;

    float a = dx*dx + dz*dz - k2 * dy*dy;
    float b = 2 * (dx*ox + dz*oz - k2 * dy*oy);
    float c = ox*ox + oz*oz - k2 * oy*oy;

    float discriminant = b*b - 4*a*c;
    if (discriminant < 0)
        return false;

    float sqrt0 = std::sqrt(discriminant);
    float root = (-b - sqrt0) / (2*a);
        if (root < tMin || root > tMax) {
        root = (-b + sqrt0) / (2*a);
        if (root < tMin || root > tMax)
            return false;
    }

    float y = co.y + root * ray.direction().y;
    if (y < 0 || y > m_height)
        return false;

    info.t = root;
    info.point = ray.at(root);
    Vec3 tmp = info.point - m_center;
    tmp.y = -m_radius / m_height;
    info.normal = tmp.normalize();
    info.color = m_color;

    return true;
}