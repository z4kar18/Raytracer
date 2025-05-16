#include "../include/Scene.hpp"
#include "../include/Sphere.hpp"
#include "../include/Plane.hpp"
#include "../include/Vec3.hpp"
#include <iostream>

Scene::Scene() : _ambientLight(0.0f), _diffuseLight(1.0f) {}

bool Scene::loadFromFile(const std::string& filename) {
    libconfig::Config cfg;
    try {
        cfg.readFile(filename.c_str());

        const libconfig::Setting& cam = cfg.lookup("camera");
        libconfig::Setting& pos = cam["position"];
        libconfig::Setting& lookAt = cam["lookAt"];
        libconfig::Setting& up = cam["up"];
        libconfig::Setting& res = cam["resolution"];
        float fov = cam["fieldOfView"];
        Vec3 camPos(pos["x"], pos["y"], pos["z"]);
        Vec3 camLookAt(lookAt["x"], lookAt["y"], lookAt["z"]);
        Vec3 camUp(up["x"], up["y"], up["z"]);
        int width = res["width"];
        int height = res["height"];
        _camera = std::make_shared<Camera>(width, height, fov, camPos, camLookAt, camUp);

        const libconfig::Setting& primitives = cfg.lookup("primitives");

        if (primitives.exists("spheres")) {
            const libconfig::Setting& spheres = primitives["spheres"];
            for (int i = 0; i < spheres.getLength(); ++i) {
                const auto& s = spheres[i];
                Vec3 center(s["x"], s["y"], s["z"]);
                float radius = s["r"];
                libconfig::Setting& color = s["color"];
                Vec3 col(color["r"], color["g"], color["b"]);
                _primitives.push_back(std::make_shared<Sphere>(center, radius, col));
            }
        }

        if (primitives.exists("planes")) {
            const libconfig::Setting& planes = primitives["planes"];
            for (int i = 0; i < planes.getLength(); ++i) {
                const auto& p = planes[i];
                std::string axis = p["axis"];
                float position = p["position"];
                libconfig::Setting& color = p["color"];
                Vec3 col(color["r"], color["g"], color["b"]);
                
                Vec3 point;
                Vec3 normal;
                
                if (axis == "x") {
                    point = Vec3(position, 0, 0);
                    normal = Vec3(1, 0, 0);
                } else if (axis == "y") {
                    point = Vec3(0, position, 0);
                    normal = Vec3(0, 1, 0);
                } else if (axis == "z") {
                    point = Vec3(0, 0, position);
                    normal = Vec3(0, 0, 1);
                }
                
                _primitives.push_back(std::make_shared<Plane>(point, normal, col));
            }
        }

        const libconfig::Setting& lights = cfg.lookup("lights");

        if (lights.exists("ambient")) _ambientLight = lights["ambient"];
        if (lights.exists("diffuse")) _diffuseLight = lights["diffuse"];

        if (lights.exists("point")) {
            const libconfig::Setting& pointLights = lights["point"];
            for (int i = 0; i < pointLights.getLength(); ++i) {
                const auto& p = pointLights[i];
                Vec3 pos(p["x"], p["y"], p["z"]);
                float intensity = 1.0f;
                if (p.exists("intensity")) intensity = p["intensity"];
                _lights.emplace_back(Light::Type::POINT, pos, intensity);
            }
        }

        if (lights.exists("directional")) {
            const libconfig::Setting& dirLights = lights["directional"];
            for (int i = 0; i < dirLights.getLength(); ++i) {
                const auto& d = dirLights[i];
                Vec3 dir(d["x"], d["y"], d["z"]);
                float intensity = 1.0f;
                if (d.exists("intensity")) intensity = d["intensity"];
                _lights.emplace_back(Light::Type::DIRECTIONAL, dir, intensity);
            }
        }

        return true;
    } catch (const libconfig::FileIOException &e) {
        std::cerr << "Error: Cannot read file: " << filename << std::endl;
    } catch (const libconfig::ParseException &e) {
        std::cerr << "Error: Parse error at " << e.getFile() << ":" << e.getLine() << " - " << e.getError() << std::endl;
    } catch (const libconfig::SettingNotFoundException &e) {
        std::cerr << "Error: Missing setting: " << e.getPath() << std::endl;
    } catch (const libconfig::SettingTypeException &e) {
    std::cerr << "Error: Wrong type in setting: " << e.getPath() << std::endl;
    return false;
    }

    return false;
}

std::shared_ptr<Camera> Scene::getCamera() const {
    return _camera;
}

const std::vector<std::shared_ptr<IPrimitive>>& Scene::getPrimitives() const {
    return _primitives;
}

const std::vector<Light>& Scene::getLights() const {
    return _lights;
}

float Scene::getAmbientLight() const {
    return _ambientLight;
}

float Scene::getDiffuseLight() const {
    return _diffuseLight;
}