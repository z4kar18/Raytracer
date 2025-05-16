/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** RayTracerUtils.hpp
*/

#pragma once
#include <vector>
#include <memory>
#include "Vec3.hpp"
#include "Ray.hpp"
#include "IPrimitive.hpp"
#include "Light.hpp"

Vec3 rayToColor(const Ray& ray,
                const std::vector<std::shared_ptr<IPrimitive>>& objects,
                const std::vector<Light>& lights,
                float ambientIntensity,
                float diffuseIntensity);
