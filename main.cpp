/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-pol.carranza-lavado
** File description:
** main.cpp
*/

#include <iostream>
#include "include/Vec3.hpp"
#include "include/Ray.hpp"
#include "include/Camera.hpp"
#include "include/ImageWriter.hpp"
#include "include/Sphere.hpp"
#include <memory>
#include "include/IPrimitive.hpp"
#include "include/Sphere.hpp"
#include "include/Plane.hpp"
#include "include/TranslatedPrimitive.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <string>
#include "include/RayTracerUtils.hpp"
#include "include/Cone.hpp"
#include "include/Scene.hpp"
#include "include/Light.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "USAGE: ./raytracer <SCENE_FILE>\n";
        return 84;
    }

    Scene scene;
    if (!scene.loadFromFile(argv[1])) {
        std::cerr << "Failed to load scene file.\n";
        return 84;
    }

    std::shared_ptr<Camera> cam = scene.getCamera();
    const auto& primitives = scene.getPrimitives();
    const auto& lights = scene.getLights();
    float ambient = scene.getAmbientLight();
    float diffuse = scene.getDiffuseLight();

    int width = cam->getWidth();
    int height = cam->getHeight();
    std::vector<std::vector<Vec3>> pixels(height, std::vector<Vec3>(width));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Ray ray = cam->getRay(x, y);
            pixels[y][x] = rayToColor(ray, primitives, lights, ambient, diffuse);
        }
    }

    ImageWriter::saveAsPPM("output.ppm", pixels);
    std::cout << "✅ Render complete -> output.ppm\n";
    return 0;
}
