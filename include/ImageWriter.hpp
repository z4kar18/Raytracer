/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** ImageWriter.hpp
*/

#pragma once
#include <vector>
#include <string>
#include "Vec3.hpp"

class ImageWriter {
public:
    static void saveAsPPM(const std::string& filename, const std::vector<std::vector<Vec3>>& pixels);
};
