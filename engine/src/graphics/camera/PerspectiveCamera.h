#pragma once
#include "Camera.h"

namespace TerrainEngine
{
    class PerspectiveCamera : public Camera
    {
    public:
        PerspectiveCamera(float fovDegrees, float aspect, float nearClip, float farClip);
        void SetPosition(const glm::vec3 &position);
        void SetRotation(const glm::vec3 &forward, const glm::vec3 &up);
        inline const glm::mat4 &GetViewMatrix() const override { return this->viewMatrix; }
        inline const glm::mat4 &GetProjectionMatrix() const override { return this->projectionMatrix; }

    private:
        void RecalculateProjection();
        void RecalculateView();

    private:
        glm::mat4 viewMatrix{1.0f};
        glm::mat4 projectionMatrix{1.0f};
        glm::vec3 position{0.0f};
        glm::vec3 forward{0, 0, -1};
        glm::vec3 up{0, 1, 0};

        float fov, aspect, neaar, faar;
    };
}