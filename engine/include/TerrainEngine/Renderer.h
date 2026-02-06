#pragma once
#include "Camera.h"

namespace TerrainEngine {
  class Renderer {
  public:
    static void Begin3D(const Camera &camera);

    static void End3D();
  };

}
