#pragma once
#include "PerspectiveCamera.h"
#include "../../core/Input.h"
#include "../../core/Time.h"
namespace TerrainEngine
{
    class CameraController
    {
    public:
        CameraController(float aspectRatio)
            : camera(45.0f, aspectRatio, 0.1f, 100.0f) {}
        CameraController() = delete;

        PerspectiveCamera &GetCamera() { return camera; }

        void Move()
        {
            float speed = this->speed * Time::DeltaTime();
            if (Input::IsKeyDown(KeyCodes::KEY_D))
            {
                position += (speed * glm::vec3(1, 0, 0));
            }
            if (Input::IsKeyDown(KeyCodes::KEY_A))
            {
                position += (-speed * glm::vec3(1, 0, 0));
            }
            if (Input::IsKeyDown(KeyCodes::KEY_W))
            {
                position += (-speed * glm::vec3(0, 0, 1));
            }
            if (Input::IsKeyDown(KeyCodes::KEY_S))
            {
                position += (speed * glm::vec3(0, 0, 1));
            }
            if (Input::IsKeyDown(KeyCodes::KEY_SPACE))
            {
                position += (speed * glm::vec3(0, 1, 0));
            }
            if (Input::IsKeyDown(KeyCodes::KEY_LEFT_SHIFT))
            {
                position += (-speed * glm::vec3(0, 1, 0));
            }

            camera.SetPosition(position);
        }

    private:
        PerspectiveCamera camera;
        glm::vec3 position{0.0f};
        glm::vec3 forward{0.0f, 0.0f, -1.0f};
        float speed = 1.2f;
    };
}
