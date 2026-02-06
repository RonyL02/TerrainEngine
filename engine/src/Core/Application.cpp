#include "TerrainEngine/Application.h"
#include <raylib.h>

namespace TerrainEngine {
  Application::Application(const AppConfig &config) : m_Config(config) {}

  void Application::Run() {
    InitWindow(m_Config.width, m_Config.height, m_Config.title);

    SetTargetFPS(m_Config.fps);

    OnInit();

    while (!WindowShouldClose()) {
      Tick();
    }

    if (m_Scene) {
      m_Scene->OnDetach();
      m_Scene.reset();
    }

    OnShutdown();
    CloseWindow();
  }

  void Application::Tick() {
    const float dt = GetFrameTime();

    BeginDrawing();
    ClearBackground(BLACK);

    if (m_Scene) {
      m_Scene->OnUpdate(dt);
      m_Scene->OnRender();
    }

    EndDrawing();
  }

  void Application::SetScene(std::unique_ptr<Scene> scene) {
    if (m_Scene) {
      m_Scene->OnDetach();
    }

    m_Scene = std::move(scene);

    if (m_Scene) {
      m_Scene->OnAttach();
    }
  }
}
