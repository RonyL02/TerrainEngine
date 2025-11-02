#pragma once
#include <glm/glm.hpp>

namespace TE
{
    class Camera
    {
    public:
        Camera(glm::vec3 position, glm::vec3 direction, float fov = 45.f);
        Camera(const Camera& camera);
        ~Camera();

        void UpdateVectors();
        void UpdateDirection();
        glm::mat4 GetViewMatrix();
        glm::mat4 GetProjectionMatrix();

        void Move(glm::vec3 direction);
        glm::vec3 GetFront();
        glm::vec3 GetRight();
        glm::vec3 GetUp();

    private:
        float m_MouseSpeed = 4.f;

        glm::vec3 m_Position = {0, 0, 0};
        float m_Pitch = 0;
        float m_Yaw = -90;

        glm::vec3 m_Front = {0, 0, -1};
        glm::vec3 m_Right = {1, 0, 0};
        glm::vec3 m_Up = {0, 1, 0};

        const glm::vec3 m_WorldUp = {0, 1, 0};

        float m_Fov;
    };

}