#pragma once
#include "Camera.h"

namespace TerrainEngine {

  class CameraController {
  public:
    CameraController(Camera camera);
    CameraController();

    void Update(float dt);

    void SetMoveSpeed(float speed) { m_MoveSpeed = speed; }
    void SetMouseSensitivity(float sensitivity) {
      m_MouseSensitivity = sensitivity;
    }

    Camera &GetCamera() { return m_Camera; }

  private:
    Camera m_Camera;
    float m_MoveSpeed;
    float m_MouseSensitivity;
    float m_Yaw;
    float m_Pitch;
  };

}
