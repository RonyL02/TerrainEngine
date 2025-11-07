#pragma once
#include "Window.h"
#include <memory>
namespace TerrainEngine {

class Application {
public:
  Application();
  ~Application() = default;
  void Init();

private:
  void Run();
  void Shutdown();
  bool IsRunning();
  bool isRunning;
  std::unique_ptr<Window> window;
};

}