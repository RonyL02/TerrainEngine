#include "Window.h"
#include "platform/glfw/GLFWWindow.h"
namespace TerrainEngine
{

  std::unique_ptr<Window> Window::Create(WindowProps windowProps)
  {
    return std::make_unique<GLFWWindow>(windowProps);
  }

}
