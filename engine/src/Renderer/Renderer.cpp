#include "TerrainEngine/Renderer.h"
#include <raylib.h>

namespace TerrainEngine {

  static ::Camera3D s_RaylibCamera;

  void Renderer::Begin3D(const Camera &camera) {
    s_RaylibCamera = {
        .position = camera.GetPosition(),
        .target = camera.GetTarget(),
        .up = {0, 1, 0},
        .fovy = 60,
        .projection = CAMERA_PERSPECTIVE,
    };

    BeginMode3D(s_RaylibCamera);
  }

  void Renderer::End3D() { EndMode3D(); }
}
