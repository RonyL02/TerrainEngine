#pragma once
#include "Scene.h"
#include <memory>

namespace TerrainEngine {
  struct AppConfig {
    int width;
    int height;
    const char *title;
    int fps = 60;
  };

  class Application {
  public:
    Application(const AppConfig &config);
    ~Application() = default;

    void Run();
    void SetScene(std::unique_ptr<Scene> scene);

  protected:
    virtual void OnInit() {}
    virtual void OnShutdown() {}

  private:
    void Tick();

  private:
    std::unique_ptr<Scene> m_Scene;
    AppConfig m_Config;
  };
}