/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** Light.hpp
*/

#pragma once
#include "Vec3.hpp"

class Light {
public:
    enum class Type {
        POINT,
        DIRECTIONAL
    };

    Light(Type type, const Vec3& vector, float intensity = 1.0f);
    
    Type getType() const;
    const Vec3& getVector() const;
    float getIntensity() const;

private:
    Type _type;
    Vec3 _vector;      // Position for POINT, direction for DIRECTIONAL
    float _intensity;
};