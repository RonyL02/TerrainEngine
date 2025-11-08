#include "Application.h"
#include <spdlog/spdlog.h>

namespace TerrainEngine
{
  std::unique_ptr<Application> Application::instance;

  Application::Application()
  {
    this->isRunning = false;
    this->renderer = Renderer::Create();
    this->window = Window::Create(WindowProps{
        .title = "yooo",
        .width = 500,
        .height = 200,
    });
  }

  void Application::Init()
  {
    spdlog::info("initializing application");
    this->window->Init();
    this->renderer->Init();
    this->Run();
  }

  Application &Application::Get()
  {
    if (!Application::instance)
    {
      Application::instance = std::make_unique<Application>();
    }

    return *Application::instance;
  }

  void Application::Run()
  {
    spdlog::info("running application");
    this->isRunning = true;
    while (this->IsRunning())
    {
      this->window->SwapBuffers();
      this->window->PollEvents();
    }

    this->Shutdown();
  }

  void Application::Shutdown()
  {
    spdlog::info("shutting down application");
    this->window->Close();
  }

  bool Application::IsRunning()
  {
    return this->isRunning && !this->window->ShouldClose();
  }

}