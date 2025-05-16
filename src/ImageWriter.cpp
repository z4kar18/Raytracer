/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** ImageWriter.cpp
*/

#include "../include/ImageWriter.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

void ImageWriter::saveAsPPM(const std::string& filename, const std::vector<std::vector<Vec3>>& pixels) {
    int height = pixels.size();
    int width = pixels[0].size();

    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Error al abrir el archivo para escribir: " << filename << "\n";
        return;
    }

    out << "P3\n" << width << " " << height << "\n255\n";

    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            Vec3 color = pixels[y][x];

            int r = std::clamp(static_cast<int>(color.x), 0, 255);
            int g = std::clamp(static_cast<int>(color.y), 0, 255);
            int b = std::clamp(static_cast<int>(color.z), 0, 255);

            out << r << " " << g << " " << b << " ";
        }
        out << "\n";
    }

    out.close();
    std::cout << "Imagen escrita en " << filename << "\n";
}
