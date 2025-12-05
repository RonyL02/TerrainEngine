#pragma once
#include "core/Window.h"

struct GLFWwindow;
namespace TerrainEngine
{
  class GLFWWindow : public Window
  {
  public:
    GLFWWindow(WindowProps props);
    ~GLFWWindow() override;

    void PollEvents() override;
    void SwapBuffers() override;
    bool ShouldClose() override;
    float GetTime() override;
    void DisableCursor(bool disable) override;

  private:
    static void TerminateGLFW();
    GLFWwindow *handle;
  };
}