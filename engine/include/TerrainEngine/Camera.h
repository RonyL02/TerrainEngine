#pragma once
#include "CommonTypes.h"

namespace TerrainEngine {
  struct Camera {
    Vec3 position = {0, 0, 0};
    Vec3 target = {0, 0, 0};
    Vec3 up = {0, 1, 0};
    float fov = 45.0f;
  };
};
