#include "SandboxApp.h"
#include "WorldScene.h"
#include <TerrainEngine/TerrainEngine.h>
namespace Sandbox {
  SandboxApp::SandboxApp()
      : Application({
            .width = 1200,
            .height = 700,
            .title = "TerrainEngine",
        }) {}

  void SandboxApp::OnInit() { SetScene(std::make_unique<WorldScene>()); }
}

void TerrainEngine::StartApplication() {
  Sandbox::SandboxApp app;
  app.Run();
}