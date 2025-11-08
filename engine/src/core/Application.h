#pragma once
#include "../graphics/Renderer.h"
#include "Window.h"
#include "Layer.h"

#include <memory>
namespace TerrainEngine
{

  class Application
  {
  public:
    ~Application() = default;
    Application();

    void Init();
    void SetLayer(std::unique_ptr<Layer> layer);
    static Application &Get();
    inline Window &GetWindow() { return *this->window; }
    inline Renderer &GetRenderer() { return *this->renderer; }

  private:
    void Run();
    void Shutdown();
    bool IsRunning();
    bool isRunning;
    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
    static std::unique_ptr<Application> instance;
    std::unique_ptr<Layer> layer;
  };

}