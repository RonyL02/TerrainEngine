#include "Application.h"
#include <spdlog/spdlog.h>

namespace TerrainEngine {

Application::Application() {
  this->isRunning = false;
  this->window = Window::Create(WindowProps{
      .title = "yooo",
      .width = 500,
      .height = 200,
  });
}

void Application::Init() {
  spdlog::info("initializing application");
  this->window.get()->Init();
  this->Run();
}

void Application::Run() {
  spdlog::info("running application");
  this->isRunning = true;
  while (this->IsRunning()) {
    this->window.get()->SwapBuffers();
    this->window.get()->PollEvents();
  }

  this->Shutdown();
}

void Application::Shutdown() {
  spdlog::info("shutting down application");
  this->window.get()->Close();
}

bool Application::IsRunning() {
  return this->isRunning && !this->window.get()->ShouldClose();
}

}