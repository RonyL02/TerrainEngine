#pragma once

#include <glm/glm.hpp>

namespace TerrainEngine
{

    class Camera
    {
    public:
        virtual ~Camera() = default;

        virtual const glm::mat4 &GetViewMatrix() const = 0;
        virtual const glm::mat4 &GetProjectionMatrix() const = 0;

        glm::mat4 GetViewProjectionMatrix() const
        {
            return this->GetProjectionMatrix() * this->GetViewMatrix();
        }
    };

}