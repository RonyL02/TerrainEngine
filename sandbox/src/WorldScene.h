#pragma once
#include <TerrainEngine/Scene.h>

using namespace TerrainEngine;

namespace Sandbox {
  class WorldScene : public Scene {
  public:
    void OnAttach() override {}

    void OnUpdate(float dt) override {}

    void OnRender() override {}
  };
}