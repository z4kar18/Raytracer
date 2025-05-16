/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** Ray.hpp
*/

#pragma once
#include "Vec3.hpp"

class Ray {
public:
    Ray(const Vec3& origin, const Vec3& direction);

    Vec3 origin() const;
    Vec3 direction() const;

    Vec3 at(float t) const;

private:
    Vec3 m_origin;
    Vec3 m_direction;
};
