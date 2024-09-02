#include "Application.h"
#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>
#include "Window/Window.h"
#include "Input.h"

TE::Application::Application(int width, int height, const char *title)
{
    m_Window = Window::InitializeWindow(width, height, title);
}

void TE::Application::Run()
{
    spdlog::info("APPLICATION::App is running...");
    while (!m_Window->ShouldClose())
    {
        if (Input::IsKeyDown(KeyCode::KEY_ESCAPE))
        {
            m_Window->SetShouldClose();
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        m_Window->Update();
    }

    spdlog::info("APPLICATION::Exiting run loop");
}
