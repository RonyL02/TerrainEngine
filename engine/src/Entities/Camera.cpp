#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

TE::Camera::Camera(glm::vec3 position, glm::vec3 direction)
    : m_Position(position), m_Front(direction)
{
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

void TE::Camera::UpdateDirection(double xoffset, double yoffset)
{
    m_Yaw += xoffset;
    m_Pitch += yoffset;

    if (m_Pitch > 89.0f)
        m_Pitch = 89.0f;
    if (m_Pitch < -89.0f)
        m_Pitch = -89.0f;

    UpdateVectors();
}

glm::mat4 TE::Camera::GetViewMatrix()
{
    return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
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
