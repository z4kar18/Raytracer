/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** Camera.hpp
*/

#pragma once
#include "Vec3.hpp"
#include "Ray.hpp"

class Camera {
public:
    Camera(int imageWidth, int imageHeight, float fov,
        const Vec3& origin, const Vec3& lookAt, const Vec3& up);

    Ray getRay(int x, int y) const;

    int getWidth() const;
    int getHeight() const;

private:
    int m_width;
    int m_height;
    float m_fov;
    Vec3 m_origin;
    Vec3 m_horizontal;
    Vec3 m_vertical;
    Vec3 m_lowerLeftCorner;
};
