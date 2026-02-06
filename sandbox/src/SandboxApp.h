#pragma once
#include <TerrainEngine/Application.h>

using namespace TerrainEngine;

namespace Sandbox {
  class SandboxApp : public Application {
  public:
    SandboxApp();

  protected:
    void OnInit() override;
  };

}
