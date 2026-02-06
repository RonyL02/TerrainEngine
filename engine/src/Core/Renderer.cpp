#include "TerrainEngine/Renderer.h"
#include <raylib.h>

namespace TerrainEngine {
  Camera3D Renderer::s_Camera;

  void Renderer::BeginFrame() {
    UpdateCamera(&s_Camera, CAMERA_FREE);
    BeginDrawing();
    BeginMode3D(s_Camera);
  }
  void Renderer::SetClearColor(const ColorRGBA &color) {
    ClearBackground({.r = color.r, .g = color.g, .b = color.b, .a = color.a});
  }
  void Renderer::EndFrame() {
    EndMode3D();
    EndDrawing();
  }
  void Renderer::DrawCubeShape(const Vec3 &position, float size,
                               const ColorRGBA &color) {
    DrawCube({.x = position.x, .y = position.y, .z = position.z}, size, size,
             size, {.r = color.r, .g = color.g, .b = color.b, .a = color.a});
  }
  void Renderer::SetCamera(Camera camera) {
    s_Camera = {
        .position = {camera.position.x, camera.position.y, camera.position.z},
        .target = {camera.target.x, camera.target.y, camera.target.z},
        .up = {camera.up.x, camera.up.y, camera.up.z},
        .fovy = camera.fov,
        .projection = CAMERA_PERSPECTIVE,
    };
  }
}
