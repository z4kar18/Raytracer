/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** TranslatedPrimitive.cpp
*/

#include "../include/TranslatedPrimitive.hpp"

TranslatedPrimitive::TranslatedPrimitive(std::shared_ptr<IPrimitive> primitive, const Vec3& offset)
    : m_primitive(primitive), m_offset(offset) {}

bool TranslatedPrimitive::hit(const Ray& ray, float tMin, float tMax, HitInfo& info) const {
    Ray movedRay(ray.origin() - m_offset, ray.direction());

    if (!m_primitive->hit(movedRay, tMin, tMax, info))
        return false;

    info.point = info.point + m_offset;
    return true;
}
