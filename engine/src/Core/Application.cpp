#include "TerrainEngine/Application.h"
#include <chrono>
#include <raylib.h>

TerrainEngine::Application::Application() {}

TerrainEngine::Application::~Application() {}

void TerrainEngine::Application::Run() {
  SetTraceLogLevel(LOG_NONE);
  InitWindow(300, 300, "eeee");
  SetTargetFPS(60);
  OnInit();
  m_Running = true;
  auto lastFrame = std::chrono::steady_clock::now();
  while (IsRunning()) {
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<float> deltaTime = now - lastFrame;

    float deltaTimeSeconds = deltaTime.count();
    lastFrame = now;

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

bool TerrainEngine::Application::IsRunning() {
  return !WindowShouldClose() && m_Running;
}