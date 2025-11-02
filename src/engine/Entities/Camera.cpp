#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include "../Core/Input.h"
#include "../Core/Time.h"
#include "../Core/Window/Window.h"
#include <spdlog/spdlog.h>
TE::Camera::Camera(glm::vec3 position, glm::vec3 direction, float fov)
    : m_Position(position), m_Front(direction), m_Fov(fov)
{
}

TE::Camera::Camera(const Camera &camera)
    : m_Position(camera.m_Position), m_Front(camera.m_Front), m_Fov(camera.m_Fov)
{
}

TE::Camera::~Camera()
{
    spdlog::info("destroy camera");
}

void TE::Camera::UpdateVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    front.y = sin(glm::radians(m_Pitch));
    front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_Front = glm::normalize(front);
    m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp)); // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}

void TE::Camera::UpdateDirection()
{
    if (Input::GetMouseOffset().first != 0 || Input::GetMouseOffset().second != 0)
    {
        auto [xoffset, yoffset] = Input::GetMouseOffset();

        m_Yaw += xoffset * m_MouseSpeed * Time::DeltaTime();
        m_Pitch += yoffset * m_MouseSpeed * Time::DeltaTime();

        if (m_Pitch > 89.0f)
            m_Pitch = 89.0f;
        if (m_Pitch < -89.0f)
            m_Pitch = -89.0f;

        UpdateVectors();
    }
}

glm::mat4 TE::Camera::GetViewMatrix()
{
    return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

glm::mat4 TE::Camera::GetProjectionMatrix()
{
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), (float)Window::GetInstance()->GetWidth() / (float)Window::GetInstance()->GetHeight(), 0.1f, 100.0f);

    return projection;
}

void TE::Camera::Move(glm::vec3 direction)
{
    m_Position += direction;
}

glm::vec3 TE::Camera::GetFront()
{
    return m_Front;
}

glm::vec3 TE::Camera::GetRight()
{
    return m_Right;
}

glm::vec3 TE::Camera::GetUp()
{
    return m_Up;
}
