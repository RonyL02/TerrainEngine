#include "TerrainEngine/Application.h"
#include <chrono>
#include <raylib.h>

TerrainEngine::Application::Application() {}

TerrainEngine::Application::~Application() { OnShutdown(); }

void TerrainEngine::Application::Run() {
  OnInit();
  m_Running = true;
  auto lastFrame = std::chrono::steady_clock::now();
  InitWindow(300, 300, "eeee");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<float> deltaTime = now - lastFrame;

    float deltaTimeSeconds = deltaTime.count();

    if (IsKeyPressed(KEY_C)) {
      m_Running = false;
    }

    OnUpdate(deltaTimeSeconds);
    Render();
  }
  OnShutdown();
  CloseWindow();
}
void TerrainEngine::Application::Render() {
  BeginDrawing();
  OnRender();
  EndDrawing();
}