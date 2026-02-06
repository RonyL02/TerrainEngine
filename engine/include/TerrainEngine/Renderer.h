#pragma once
#include "Camera.h"
#include "CommonTypes.h"

struct Camera3D;

namespace TerrainEngine {
  class Renderer {
  public:
    static void BeginFrame();
    static void SetClearColor(const ColorRGBA &color);
    static void EndFrame();
    static void DrawCubeShape(const Vec3 &position, float size,
                              const ColorRGBA &color);
    static void SetCamera(Camera camera);

  private:
    static Camera3D s_Camera;
  };
}