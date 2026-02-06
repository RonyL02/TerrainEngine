#include "TerrainEngine/Application.h"
#include "TerrainEngine/Renderer.h"
#include <chrono>
#include <raylib.h>

namespace TerrainEngine {
  Application::Application() {}

  Application::~Application() {}

  void Application::Run() {
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

  void Application::Render() {
    Renderer::BeginFrame();
    OnRender();
    Renderer::EndFrame();
  }

  bool Application::IsRunning() { return !WindowShouldClose() && m_Running; }
}