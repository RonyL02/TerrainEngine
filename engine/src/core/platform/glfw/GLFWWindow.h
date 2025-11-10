#pragma once
#include "../../Window.h"

struct GLFWwindow;
namespace TerrainEngine
{
  class GLFWWindow : public Window
  {
  public:
    GLFWWindow(WindowProps props) : Window(props), handle(nullptr) {}
    ~GLFWWindow() = default;

    void Init() override;
    void Close() override;
    void PollEvents() override;
    void SwapBuffers() override;
    bool ShouldClose() override;
    float GetTime() override;
    void DisableCursor(bool disable) override;

  private:
    static void ErrorCallback(int error, const char *description);
    static void FramebufferSizeCallback(GLFWwindow *window, int width, int height);
    static void TerminateGLFW();
    GLFWwindow *handle;
  };
}