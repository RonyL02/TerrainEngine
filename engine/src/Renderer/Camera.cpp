#include "TerrainEngine/Camera.h"

#include "TerrainEngine/Camera.h"
#include <cmath>

namespace TerrainEngine {
  Camera::Camera()
      : m_Position{0, 0, 0}, m_Forward{0, 0, -1}, m_Yaw(-90), m_Pitch(0) {}

  void Camera::SetYawPitch(float yaw, float pitch) {
    m_Yaw = yaw;
    m_Pitch = pitch;
    UpdateOrientation();
  }

  void Camera::UpdateOrientation() {
    float yawRad = m_Yaw * DEG2RAD;
    float pitchRad = m_Pitch * DEG2RAD;

    m_Forward.x = cosf(yawRad) * cosf(pitchRad);
    m_Forward.y = sinf(pitchRad);
    m_Forward.z = sinf(yawRad) * cosf(pitchRad);

    float length = sqrtf(m_Forward.x * m_Forward.x + m_Forward.y * m_Forward.y +
                         m_Forward.z * m_Forward.z);
    m_Forward.x /= length;
    m_Forward.y /= length;
    m_Forward.z /= length;
  }

}
