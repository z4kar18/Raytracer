/*
** EPITECH PROJECT, 2025
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado [WSL: Ubuntu-20.04]
** File description:
** Cone
*/

#pragma once
#include "IPrimitive.hpp"

class Cone : public IPrimitive {
public:
    Cone(const Vec3& center,  float height, float radius, const Vec3& color);
    bool hit(const Ray& ray, float tMin, float tMax, HitInfo& info) const override;

private:
    Vec3 m_center;
    float m_height;
    float m_radius;
    Vec3 m_color;
};
