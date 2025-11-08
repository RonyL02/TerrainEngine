#include <TerrainEngine.h>
#include "SandboxLayer.h"
int main()
{
  TerrainEngine::Application &application = TerrainEngine::Application::Get();
  application.SetLayer(std::make_unique<SandboxLayer>());
  application.Init();
}