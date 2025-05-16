/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** TranslatedPrimitive.hpp
*/

#pragma once
#include "IPrimitive.hpp"
#include <memory>

class TranslatedPrimitive : public IPrimitive {
public:
    TranslatedPrimitive(std::shared_ptr<IPrimitive> primitive, const Vec3& offset);

    bool hit(const Ray& ray, float tMin, float tMax, HitInfo& info) const override;

private:
    std::shared_ptr<IPrimitive> m_primitive;
    Vec3 m_offset;
};
