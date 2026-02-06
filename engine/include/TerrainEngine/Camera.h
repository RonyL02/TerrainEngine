#pragma once
#include <raylib.h>

namespace TerrainEngine {
  class Camera {
  public:
    Camera();

    void SetPosition(const Vector3 &pos) { m_Position = pos; }
    void SetYawPitch(float yaw, float pitch);

    Vector3 GetPosition() const { return m_Position; }
    Vector3 GetForward() const { return m_Forward; }
    Vector3 GetTarget() const {
      return {
          m_Position.x + m_Forward.x,
          m_Position.y + m_Forward.y,
          m_Position.z + m_Forward.z,
      };
    }

  private:
    void UpdateOrientation();

  private:
    Vector3 m_Position;
    Vector3 m_Forward;
    float m_Yaw;
    float m_Pitch;
  };
}
