#include "Application.h"
#include <spdlog/spdlog.h>
#include <GL/gl3w.h>
#include "Input.h"
namespace TerrainEngine
{
  std::unique_ptr<Application> Application::instance;

  Application::Application()
  {
    this->isRunning = false;
    this->renderer = Renderer::Create();
    this->window = Window::Create(WindowProps{
        .title = "yooo",
        .width = 1000,
        .height = 800,
    });
  }

  void Application::Init()
  {
    spdlog::info("initializing application");
    this->window->Init();
    this->renderer->Init();
    this->layer->Init();
    this->Run();
  }

  void Application::SetLayer(std::unique_ptr<Layer> layer)
  {
    this->layer = std::move(layer);
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
      glClearColor(0.7f, 0.5f, 0.5f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      this->layer->Update();
      this->layer->Render();

      this->window->PollEvents();
      this->window->SwapBuffers();
      Input::Update();
    }

    this->Shutdown();
  }

  void Application::Shutdown()
  {
    spdlog::info("shutting down application");
    this->layer->Close();
    this->renderer->Shutdown();
    this->window->Close();
  }

  bool Application::IsRunning()
  {
    return this->isRunning && !this->window->ShouldClose();
  }

}