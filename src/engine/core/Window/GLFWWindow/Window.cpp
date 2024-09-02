#include "Window.h"
#include <spdlog/spdlog.h>
#include "../../Input.h"
#include "Events.h"

void TE::GLFWWindow::Create()
{
    spdlog::info("GLFWWINDOW::Initializing GLFW window...");

    if (!glfwInit())
    {
        spdlog::error("GLFWWINDOW::Failed to initialize GLFW");
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

    if (m_Window == NULL)
    {
        spdlog::error("GLFWWINDOW::Failed to create GLFW window");
        Destroy();
        return;
    }

    glfwMakeContextCurrent(m_Window);

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        spdlog::error("GLFWWINDOW::Failed to initialize glew: {}", reinterpret_cast<const char *>(glewGetErrorString(err)));
        Destroy();
        return;
    }

    spdlog::info("GLFWWINDOW::GLFW window initialized successfully");

    RegisterEventCallbacks();
}

void TE::GLFWWindow::RegisterEventCallbacks()
{
    glfwSetKeyCallback(m_Window, GLFWKeyCallback);
    glfwSetMouseButtonCallback(m_Window, GLFWMouseButtonCallback);
}

void TE::GLFWWindow::Destroy()
{
    if (m_Window != nullptr)
    {
        spdlog::info("GLFWWINDOW::Terminating GLFW window...");
        glfwDestroyWindow(m_Window);
        m_Window = nullptr;
    }
    spdlog::info("GLFWWINDOW::Terminating GLFW...");
    glfwTerminate();
}

void TE::GLFWWindow::Update()
{
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

void TE::GLFWWindow::SetShouldClose()
{
    glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
}

bool TE::GLFWWindow::ShouldClose()
{
    if (!m_Window)
    {
        spdlog::warn("GLFWWINDOW::GLFW window not found. Closing...");
        return true;
    }

    bool shouldClose = glfwWindowShouldClose(m_Window);
    if (shouldClose)
    {
        spdlog::info("GLFWWINDOW::GLFW received closing event");
    }
    return shouldClose;
}