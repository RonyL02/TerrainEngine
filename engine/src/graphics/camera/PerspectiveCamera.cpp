#include "PerspectiveCamera.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

namespace TerrainEngine
{
    PerspectiveCamera::PerspectiveCamera(float fovDegrees, float aspect, float nearClip, float farClip)
    {
        this->fov = glm::radians(fovDegrees);
        this->aspect = aspect;
        this->neaar = nearClip;
        this->faar = farClip;
        this->RecalculateProjection();
        this->RecalculateView();
    }

    void PerspectiveCamera::SetPosition(const glm::vec3 &position)
    {
        this->position = position;
        this->RecalculateView();
    }

    void PerspectiveCamera::SetRotation(const glm::vec3 &forward, const glm::vec3 &up)
    {
        this->forward = forward;
        this->up = up;
        this->RecalculateView();
    }
    void PerspectiveCamera::RecalculateProjection()
    {
        this->projectionMatrix = glm::perspective(this->fov, this->aspect, this->neaar, this->faar);
    }
    void PerspectiveCamera::RecalculateView()
    {
        this->viewMatrix = glm::lookAt(this->position, this->position + this->forward, this->up);
    }
}
