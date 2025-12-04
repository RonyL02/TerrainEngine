#pragma once
#include "graphics/camera/PerspectiveCamera.h"
#include "core/Input.h"
#include "core/Time.h"
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
                position += (speed * glm::vec3(right.x, 0, right.z));
            }
            if (Input::IsKeyDown(KeyCodes::KEY_A))
            {
                position -= (speed * glm::vec3(right.x, 0, right.z));
            }
            if (Input::IsKeyDown(KeyCodes::KEY_W))
            {
                position += (speed * glm::normalize(glm::vec3(forward.x, 0, forward.z)));
            }
            if (Input::IsKeyDown(KeyCodes::KEY_S))
            {
                position -= (speed * glm::normalize(glm::vec3(forward.x, 0, forward.z)));
            }
            if (Input::IsKeyDown(KeyCodes::KEY_SPACE))
            {
                position += (speed * glm::vec3(0, 1, 0));
            }
            if (Input::IsKeyDown(KeyCodes::KEY_LEFT_SHIFT))
            {
                position -= (speed * glm::vec3(0, 1, 0));
            }

            camera.SetPosition(position);
        }

        void UpdateDirection()
        {
            if (Input::GetMouseOffset().first == 0 && Input::GetMouseOffset().second == 0)
            {
                return;
            }

            float yawDelta = Input::GetMouseOffset().first * sensitivity;
            float pitchDelta = Input::GetMouseOffset().second * sensitivity;

            yaw += yawDelta;
            pitch += pitchDelta;
            pitch = glm::clamp(pitch, -89.f, 89.f);

            float pitchRadians = glm::radians(pitch);
            float yawRadians = glm::radians(yaw);

            forward.x = cos(yawRadians) * cos(pitchRadians);
            forward.y = sin(pitchRadians);
            forward.z = sin(yawRadians) * cos(pitchRadians);
            forward = glm::normalize(forward);

            right = glm::normalize(glm::cross(forward, glm::vec3(0, 1, 0)));
            up = glm::normalize(glm::cross(right, forward));
            camera.SetRotation(forward, up);
        }

    private:
        PerspectiveCamera camera;
        glm::vec3 position{0.0f};
        glm::vec3 forward{0.0f, 0.0f, -1.0f};
        glm::vec3 right{1.0f, 0.0f, 0.0f};
        glm::vec3 up{0.0f, 1.0f, 0.0f};
        float yaw = -90.0f;
        float pitch = 0.0f;
        float speed = 1.2f;
        float sensitivity = 0.1f;
    };
}
