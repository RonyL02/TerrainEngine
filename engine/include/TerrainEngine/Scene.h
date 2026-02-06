#pragma once

namespace TerrainEngine {

  class Scene {
  public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void OnAttach() {}
    virtual void OnDetach() {}

    virtual void OnUpdate(float dt) = 0;
    virtual void OnRender() = 0;
  };

}
