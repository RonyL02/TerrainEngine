#include "TerrainEngine/CameraController.h"
#include <raymath.h>
#include <algorithm>

namespace TerrainEngine {

  CameraController::CameraController() = default;

  CameraController::CameraController(Camera camera) 
      : m_Camera(std::move(camera)) {}

  void CameraController::SetMouseControlEnabled(bool enabled) {
    m_MouseControlEnabled = enabled;
    if (enabled) {
      DisableCursor();
    } else {
      EnableCursor();
    }
  }

  void CameraController::Update(float dt) {
    if (m_MouseControlEnabled) {
      const Vector2 mouseDelta = GetMouseDelta();
      m_Yaw += mouseDelta.x * m_MouseSensitivity;
      m_Pitch -= mouseDelta.y * m_MouseSensitivity;

      m_Pitch = Clamp(m_Pitch, -89.0f, 89.0f);
      m_Camera.SetYawPitch(m_Yaw, m_Pitch);
    }

    const Vector3 forward = m_Camera.GetForward();
    const Vector3 right = Vector3CrossProduct(forward, Vector3{0.0f, 1.0f, 0.0f});
    Vector3 pos = m_Camera.GetPosition();

    const Vector3 flatForward = Vector3Normalize(Vector3{forward.x, 0.0f, forward.z});
    const Vector3 flatRight = Vector3Normalize(Vector3{right.x, 0.0f, right.z});

    const float moveAmount = m_MoveSpeed * dt;

    if (IsKeyDown(KEY_W)) {
      pos = Vector3Add(pos, Vector3Scale(flatForward, moveAmount));
    }
    if (IsKeyDown(KEY_S)) {
      pos = Vector3Add(pos, Vector3Scale(flatForward, -moveAmount));
    }
    if (IsKeyDown(KEY_A)) {
      pos = Vector3Add(pos, Vector3Scale(flatRight, -moveAmount));
    }
    if (IsKeyDown(KEY_D)) {
      pos = Vector3Add(pos, Vector3Scale(flatRight, moveAmount));
    }
    if (IsKeyDown(KEY_SPACE)) {
      pos.y += moveAmount;
    }
    if (IsKeyDown(KEY_LEFT_SHIFT)) {
      pos.y -= moveAmount;
    }

    m_Camera.SetPosition(pos);
  }

}
