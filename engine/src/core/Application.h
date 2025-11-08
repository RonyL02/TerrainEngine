#pragma once
#include "../graphics/Renderer.h"
#include "Window.h"
#include <memory>
namespace TerrainEngine
{

  class Application
  {
  public:
    ~Application() = default;
    Application();

    void Init();
    static Application &Get();

  private:
    void Run();
    void Shutdown();
    bool IsRunning();
    bool isRunning;
    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
    static std::unique_ptr<Application> instance;
  };

}