#include "TerrainEngine/CameraController.h"
#include <cmath>
#include <raymath.h>

namespace TerrainEngine {

  CameraController::CameraController(Camera camera)
      : m_Camera(camera), m_MoveSpeed(5.0f), m_MouseSensitivity(0.1f) {
    m_Yaw = -90.0f;
    m_Pitch = 0.0f;

    DisableCursor();
  }

  CameraController::CameraController()
      : m_Camera(Camera()), m_MoveSpeed(5.0f), m_MouseSensitivity(0.1f) {
    m_Yaw = -90.0f;
    m_Pitch = 0.0f;

    DisableCursor();
  }

  void CameraController::Update(float dt) {
    Vector2 mouseDelta = GetMouseDelta();
    m_Yaw += mouseDelta.x * m_MouseSensitivity;
    m_Pitch -= mouseDelta.y * m_MouseSensitivity;

    m_Pitch = Clamp(m_Pitch, -89.0f, 89.0f);
    m_Camera.SetYawPitch(m_Yaw, m_Pitch);

    Vector3 forward = m_Camera.GetForward();
    Vector3 right = Vector3CrossProduct(forward, {0, 1, 0});
    Vector3 pos = m_Camera.GetPosition();

    Vector3 flatForward = Vector3Normalize({forward.x, 0.0f, forward.z});
    Vector3 flatRight = Vector3Normalize({right.x, 0.0f, right.z});
    if (IsKeyDown(KEY_W)) {
      pos = Vector3Add(pos, Vector3Scale(flatForward, m_MoveSpeed * dt));
    }
    if (IsKeyDown(KEY_S)) {
      pos = Vector3Add(pos, Vector3Scale(flatForward, -m_MoveSpeed * dt));
    }
    if (IsKeyDown(KEY_A)) {
      pos = Vector3Add(pos, Vector3Scale(flatRight, -m_MoveSpeed * dt));
    }
    if (IsKeyDown(KEY_D)) {
      pos = Vector3Add(pos, Vector3Scale(flatRight, m_MoveSpeed * dt));
    }
    if (IsKeyDown(KEY_SPACE))
      pos.y += m_MoveSpeed * dt;
    if (IsKeyDown(KEY_LEFT_SHIFT))
      pos.y -= m_MoveSpeed * dt;

    m_Camera.SetPosition(pos);
  }

}
