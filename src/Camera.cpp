/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** Camera.cpp
*/

#include "../include/Camera.hpp"
#include <cmath>

Camera::Camera(int imageWidth, int imageHeight, float fov,
                const Vec3& origin, const Vec3& lookAt, const Vec3& up)
    : m_width(imageWidth), m_height(imageHeight), m_fov(fov), m_origin(origin)
{
    float aspectRatio = float(imageWidth) / float(imageHeight);
    float theta = fov * (M_PI / 180.0f);
    float halfHeight = std::tan(theta / 2.0f);
    float halfWidth = aspectRatio * halfHeight;

    Vec3 w = (origin - lookAt).normalize();
    Vec3 u = up.cross(w).normalize();
    Vec3 v = w.cross(u);

    m_horizontal = u * (2 * halfWidth);
    m_vertical = v * (2 * halfHeight);
    m_lowerLeftCorner = m_origin - m_horizontal / 2 - m_vertical / 2 - w;
}

Ray Camera::getRay(int x, int y) const {
    float u = float(x) / float(m_width);
    float v = float(y) / float(m_height);
    Vec3 direction = m_lowerLeftCorner + m_horizontal * u + m_vertical * v - m_origin;
    return Ray(m_origin, direction);
}

int Camera::getWidth() const { return m_width; }
int Camera::getHeight() const { return m_height; }
