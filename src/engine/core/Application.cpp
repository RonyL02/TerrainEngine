#include "Application.h"
#include <spdlog/spdlog.h>
TE::Application::Application(int width, int height, const char *title)
    : m_Window(GLFWWindow(width, height, title))
{
}

void TE::Application::Run()
{
    spdlog::info("APPLICATION::App is running...");
    while (!m_Window.ShouldClose())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        m_Window.SwapBuffers();
        m_Window.PollEvents();
    }
    spdlog::info("APPLICATION::Exiting run loop");
}
