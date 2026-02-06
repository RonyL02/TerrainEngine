#pragma once
#include <TerrainEngine/Application.h>

namespace Sandbox {
  class SandboxApp : public TerrainEngine::Application {
  public:
    SandboxApp();

  protected:
    void OnInit() override;
  };

}
