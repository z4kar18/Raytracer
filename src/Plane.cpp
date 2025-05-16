/*
** EPITECH PROJECT, 2025
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado [WSL: Ubuntu-20.04]
** File description:
** Plane
*/

#include "../include/Plane.hpp"
#include <cmath>

Plane::Plane(const Vec3& point, const Vec3& normal, const Vec3& color)
    : m_point(point), m_normal(normal.normalize()), m_color(color) {}

bool Plane::hit(const Ray& ray, float tMin, float tMax, HitInfo& info) const {
    float denom = m_normal.dot(ray.direction());

    if (fabs(denom) < 1e-6f)
        return false;

    float t = (m_point - ray.origin()).dot(m_normal) / denom;
    if (t < tMin || t > tMax)
        return false;

    info.t = t;
    info.point = ray.at(t);
    info.normal = m_normal;
    info.color = m_color;
    return true;
}
