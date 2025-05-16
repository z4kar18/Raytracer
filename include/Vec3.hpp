/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** Vec3.hpp
*/

#pragma once

class Vec3 {
public:
    float x;
    float y;
    float z;

    Vec3();
    Vec3(float x, float y, float z);

    Vec3 operator+(const Vec3& v) const;
    Vec3 operator-(const Vec3& v) const;
    Vec3 operator-() const;  // unario negativo
    Vec3 operator*(float scalar) const;
    Vec3 operator/(float scalar) const;

    float dot(const Vec3& v) const;
    Vec3 cross(const Vec3& v) const;
    float length() const;
    Vec3 normalize() const;
};
