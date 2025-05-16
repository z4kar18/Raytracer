/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** Light.cpp
*/

#include "../include/Light.hpp"

Light::Light(Type type, const Vec3& vector, float intensity)
    : _type(type), _vector(vector), _intensity(intensity) 
{
}

Light::Type Light::getType() const 
{
    return _type;
}

const Vec3& Light::getVector() const 
{
    return _vector;
}

float Light::getIntensity() const 
{
    return _intensity;
}