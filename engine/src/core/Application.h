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
    ~Application();
    Application(const AppProps &props);

    void Run();
    void SetLayer(std::unique_ptr<Layer> layer);
    void Exit();
    static Application &Create(const AppProps &props);
    static Application &Get() { return *instance; }
    inline Window &GetWindow() const { return *this->window; }
    inline Renderer &GetRenderer() const { return *this->renderer; }

  private:
    static std::unique_ptr<Application> instance;

  private:
    bool IsRunning() const;
    bool isRunning;
    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Layer> layer;
  };

}