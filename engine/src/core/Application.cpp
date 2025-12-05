#include "Application.h"
#include <GL/gl3w.h>
#include "Input.h"
#include "Time.h"
#include "Log.h"
namespace TerrainEngine
{
  std::unique_ptr<Application> Application::instance;

  Application::Application(const AppProps &props)
      : isRunning(false),
        window(Window::Create(props.windowProps)),
        renderer(Renderer::Create())
  {
    TE_INFO("initializing application");
  }

  Application::~Application()
  {
    TE_INFO("shutting down application");
  }

  void Application::SetLayer(std::unique_ptr<Layer> layer)
  {
    this->layer = std::move(layer);
  }

  void Application::Exit()
  {
    this->isRunning = false;
  }

  Application &Application::Create(const AppProps &props)
  {
    Application::instance = std::make_unique<Application>(props);
    return *Application::instance;
  }

  void Application::Run()
  {
    TE_INFO("running application");

    auto props = this->window->GetWindowProps();
    this->renderer->UpdateViewPort(props.width, props.height);

    this->isRunning = true;
    while (this->IsRunning())
    {
      Time::UpdateDeltaTime(this->GetWindow().GetTime());
      glClearColor(0.7f, 0.5f, 0.5f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      this->layer->Render();
      this->window->SwapBuffers();

      this->window->PollEvents();
      this->layer->Update();
      Input::Update();
      Input::SetMouseOffset(0, 0);
    }

    Application::instance.reset();
  }

  bool Application::IsRunning()
  {
    return this->isRunning && !this->window->ShouldClose();
  }

}