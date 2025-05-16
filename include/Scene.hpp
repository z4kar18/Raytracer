#pragma once

#include <vector>
#include <string>
#include <memory>
#include <libconfig.h++>
#include "Camera.hpp"
#include "IPrimitive.hpp"
#include "Light.hpp"

class Scene {
public:
    Scene();
    bool loadFromFile(const std::string& filename);

    std::shared_ptr<Camera> getCamera() const;
    const std::vector<std::shared_ptr<IPrimitive>>& getPrimitives() const;
    const std::vector<Light>& getLights() const;
    float getAmbientLight() const;
    float getDiffuseLight() const;

private:
    std::shared_ptr<Camera> _camera;
    std::vector<std::shared_ptr<IPrimitive>> _primitives;
    std::vector<Light> _lights;
    float _ambientLight;
    float _diffuseLight;
};
