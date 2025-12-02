#pragma once
#include "Window.h"
#include "Layer.h"
#include "graphics/Renderer.h"
#include <memory>
namespace TerrainEngine
{

  struct AppProps
  {
    WindowProps windowProps;
  };

  class Application
  {
  public:
    ~Application() = default;
    Application(const AppProps& props);

    void Init();
    void SetLayer(std::unique_ptr<Layer> layer);
    void Exit();
    static Application &Create(const AppProps& props);
    static Application &Get();
    inline Window &GetWindow() { return *this->window; }
    inline Renderer &GetRenderer() { return *this->renderer; }

  private:
    static std::unique_ptr<Application> instance;

  private:
    void Run();
    void Shutdown();
    bool IsRunning();
    bool isRunning;
    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Layer> layer;
  };

}