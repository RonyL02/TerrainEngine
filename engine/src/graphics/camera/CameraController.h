#pragma once
#include "PerspectiveCamera.h"
namespace TerrainEngine
{
    class CameraController
    {
    public:
        CameraController(float aspectRatio)
            : camera(45.0f, aspectRatio, 0.1f, 100.0f) {}
        CameraController() = delete;

        PerspectiveCamera &GetCamera() { return camera; }

    private:
        PerspectiveCamera camera;
        glm::vec3 position{0.0f};
        glm::vec3 forward{0.0f, 0.0f, -1.0f};
        float speed = 5.0f;
    };
}
