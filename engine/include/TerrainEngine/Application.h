#pragma once
#include "Scene.h"
#include <memory>
#include <string>

namespace TerrainEngine {

  struct AppConfig {
    int width{1280};
    int height{720};
    std::string title{"TerrainEngine"};
    int fps{60};
  };

  class Application {
  public:
    explicit Application(AppConfig config);
    virtual ~Application() = default;

    void Run();

    void SetScene(std::unique_ptr<Scene> scene);

    Scene* GetScene() const { return m_Scene.get(); }

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