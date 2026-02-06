#pragma once
#include "Camera.h"

namespace TerrainEngine {

  class CameraController {
  public:
    CameraController();
    explicit CameraController(Camera camera);

    void Update(float dt);

    void SetMouseControlEnabled(bool enabled);

    void SetMoveSpeed(float speed) { m_MoveSpeed = speed; }

    void SetMouseSensitivity(float sensitivity) { m_MouseSensitivity = sensitivity; }

    Camera& GetCamera() { return m_Camera; }

    const Camera& GetCamera() const { return m_Camera; }

  private:
    Camera m_Camera;
    float m_MoveSpeed{5.0f};
    float m_MouseSensitivity{0.1f};
    float m_Yaw{-90.0f};
    float m_Pitch{0.0f};
    bool m_MouseControlEnabled{false};
  };

}
