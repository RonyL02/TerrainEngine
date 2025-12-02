#include "Application.h"
#include <GL/gl3w.h>
#include "Input.h"
#include "Time.h"
#include "Log.h"
namespace TerrainEngine
{
  std::unique_ptr<Application> Application::instance;

  Application::Application(const AppProps &props)
  {
    this->isRunning = false;
    this->renderer = Renderer::Create();
    this->window = Window::Create(props.windowProps);
  }

  void Application::Init()
  {
    TE_INFO("initializing application");
    this->window->Init();
    this->renderer->Init();
    this->layer->Init();
    this->Run();
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

  Application &Application::Get()
  {
    return *Application::instance;
  }

  void Application::Run()
  {
    TE_INFO("running application");
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

    this->Shutdown();
  }

  void Application::Shutdown()
  {
    TE_INFO("shutting down application");
    this->layer->Close();
    this->renderer->Shutdown();
    this->window->Close();
  }

  bool Application::IsRunning()
  {
    return this->isRunning && !this->window->ShouldClose();
  }

}