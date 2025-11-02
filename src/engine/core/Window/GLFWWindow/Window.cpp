#include "Window.h"
#include <spdlog/spdlog.h>
#include "../../Input.h"
#include "../../../Graphics/OpenGL/Defines.h"
#include "Events.h"

void TE::GLFWWindow::Create()
{
    spdlog::info("GLFWWINDOW::Initializing GLFW window...");

    if (!glfwInit())
    {
        spdlog::error("GLFWWINDOW::Failed to initialize GLFW");
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, TE_OPENGL_VERSION_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, TE_OPENGL_VERSION_MINOR);
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
    glfwSwapInterval(1);

    spdlog::info("GLFWWINDOW::GLFW window initialized successfully");

    spdlog::info("GLFWWINDOW::Using opengl {}", reinterpret_cast<const char *>(glGetString(GL_VERSION)));

    glViewport(0, 0, m_Width, m_Height);

    RegisterEventCallbacks();
}

void TE::GLFWWindow::RegisterEventCallbacks()
{
    glfwSetKeyCallback(m_Window, GLFWKeyCallback);
    glfwSetMouseButtonCallback(m_Window, GLFWMouseButtonCallback);
    glfwSetFramebufferSizeCallback(m_Window, GLFWFramebufferSizeCallback);
    glfwSetCursorPosCallback(m_Window, GLFWMouseCallback);
}

void TE::GLFWWindow::Destroy()
{
    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {
        spdlog::error("OpenGL Error: {}", error);
    }

    if (m_Window != nullptr)
    {
        spdlog::info("GLFWWINDOW::Terminating GLFW window...");
        glfwDestroyWindow(m_Window);
        m_Window = nullptr;
    }
    spdlog::info("GLFWWINDOW::Terminating GLFW...");
    glfwTerminate();
}

double TE::GLFWWindow::GetTime()
{
    return glfwGetTime();
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

void TE::GLFWWindow::DisableCursor(bool disable)
{
    glfwSetInputMode(m_Window, GLFW_CURSOR, disable ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}
