#pragma once
#include <TerrainEngine/Application.h>

namespace Sandbox {
  class SandboxApplication : public TerrainEngine::Application {
  public:
    SandboxApplication(/* args */);
    ~SandboxApplication();

    void OnInit() override;
    void OnUpdate(float deltaTime) override;
    void OnRender() override;
    void OnShutdown() override;
  };

}
