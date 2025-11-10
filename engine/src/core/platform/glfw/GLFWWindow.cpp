#include "GLFWWindow.h"
#include "GLFWCallback.h"
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <spdlog/spdlog.h>
namespace TerrainEngine
{

  void GLFWWindow::Init()
  {
    if (!glfwInit())
    {
      spdlog::error("failed to init glfw");
      return;
    }

    std::atexit(GLFWWindow::TerminateGLFW);
    auto [title, width, height] = this->windowProps;
    this->handle =
        glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (!this->handle)
    {
      spdlog::error("failed to init glfw window");
      return;
    }

    glfwSetErrorCallback(GLFWWindow::ErrorCallback);
    glfwSetKeyCallback(this->handle, GLFWCallback::Key);
    glfwSetMouseButtonCallback(this->handle, GLFWCallback::MouseButton);
    glfwSetCursorPosCallback(this->handle, GLFWCallback::MousePosition);
    glfwSetFramebufferSizeCallback(this->handle, GLFWCallback::FramebufferSize);
    glfwMakeContextCurrent(this->handle);
    glfwSwapInterval(1);
    spdlog::info("successfully created glfw window");
  }

  void GLFWWindow::Close()
  {
    glfwDestroyWindow(this->handle);
    this->handle = nullptr;
  }

  void GLFWWindow::PollEvents() { glfwPollEvents(); }

  void GLFWWindow::SwapBuffers() { glfwSwapBuffers(this->handle); }

  bool GLFWWindow::ShouldClose() { return glfwWindowShouldClose(this->handle); }

  float GLFWWindow::GetTime()
  {
    return glfwGetTime();
  }

  void GLFWWindow::DisableCursor(bool disable)
  {
    glfwSetInputMode(this->handle, GLFW_CURSOR, disable ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
  }

  void GLFWWindow::ErrorCallback(int error, const char *description)
  {
    spdlog::error("glfw error ({}): {}", error, description);
  }

  void GLFWWindow::TerminateGLFW()
  {
    spdlog::info("terminating glfw");
    glfwTerminate();
  }

}