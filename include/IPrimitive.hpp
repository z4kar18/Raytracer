/*
** EPITECH PROJECT, 2025
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado [WSL: Ubuntu-20.04]
** File description:
** IPrimitive
*/

#pragma once
#include "Ray.hpp"
#include "Vec3.hpp"

struct HitInfo {
    float t;
    Vec3 point;
    Vec3 normal;
    Vec3 color;
};

class IPrimitive {
public:
    virtual ~IPrimitive() = default;
    virtual bool hit(const Ray& ray, float tMin, float tMax, HitInfo& info) const = 0;
};
