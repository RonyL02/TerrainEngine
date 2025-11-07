#include "Window.h"
#include "GLFWWindow/Window.h"
#include <spdlog/spdlog.h>

Ref<TE::Window> TE::Window::m_WindowInstance;

Ref<TE::Window> TE::Window::InitializeWindow(int width, int height, const char *title)
{
    m_WindowInstance = MakeRef<GLFWWindow>(width, height, title);
    return GetInstance();
}

Ref<TE::Window> TE::Window::GetInstance()
{
    if (m_WindowInstance != nullptr)
    {
        return m_WindowInstance;
    }
    else
    {
        spdlog::error("WINDOW::GetInstance was called before initialization");
        return nullptr;
    }
}

int TE::Window::GetWidth()
{
    return m_Width;
}

int TE::Window::GetHeight()
{
    return m_Height;
}

void TE::Window::SetWidth(int width)
{
    m_Width = width;
}

void TE::Window::SetHeight(int height)
{
    m_Height = height;
}
