/*
** EPITECH PROJECT, 2025
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado [WSL: Ubuntu-20.04]
** File description:
** Plane
*/

#pragma once
#include "IPrimitive.hpp"

class Plane : public IPrimitive {
public:
    Plane(const Vec3& point, const Vec3& normal, const Vec3& color);

    bool hit(const Ray& ray, float tMin, float tMax, HitInfo& info) const override;

private:
    Vec3 m_point;
    Vec3 m_normal;
    Vec3 m_color;
};
