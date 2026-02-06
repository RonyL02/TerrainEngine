#include "TerrainEngine/Camera.h"
#include <raymath.h>

namespace TerrainEngine {
  Camera::Camera() = default;

  void Camera::SetYawPitch(float yaw, float pitch) {
    m_Yaw = yaw;
    m_Pitch = pitch;
    UpdateOrientation();
  }

  void Camera::UpdateOrientation() {
    const float yawRad = m_Yaw * DEG2RAD;
    const float pitchRad = m_Pitch * DEG2RAD;

    m_Forward.x = cos(yawRad) * cos(pitchRad);
    m_Forward.y = sin(pitchRad);
    m_Forward.z = sin(yawRad) * cos(pitchRad);

    m_Forward = Vector3Normalize(m_Forward);
  }

}
