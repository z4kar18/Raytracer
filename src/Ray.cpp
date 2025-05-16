/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** Ray.cpp
*/

#include "../include/Ray.hpp"

Ray::Ray(const Vec3& origin, const Vec3& direction)
    : m_origin(origin), m_direction(direction.normalize()) {}

Vec3 Ray::origin() const { return m_origin; }
Vec3 Ray::direction() const { return m_direction; }

Vec3 Ray::at(float t) const {
    return m_origin + m_direction * t;
}
