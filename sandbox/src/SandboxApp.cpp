#include "SandboxApp.h"
#include "WorldScene.h"
#include <TerrainEngine/TerrainEngine.h>

namespace Sandbox {
  SandboxApp::SandboxApp()
      : TerrainEngine::Application({
            .width = 1280,
            .height = 720,
            .title = "TerrainEngine - Voxel Sandbox",
            .fps = 60
        }) {}

  void SandboxApp::OnInit() { SetScene(std::make_unique<WorldScene>()); }
}

void TerrainEngine::StartApplication() {
  Sandbox::SandboxApp app;
  app.Run();
}