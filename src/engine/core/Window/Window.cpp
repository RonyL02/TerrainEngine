#include "Window.h"
#include "GLFWWindow/Window.h"

Box<TE::Window> TE::Window::InitializeWindow(int width, int height, const char *title)
{
    return MakeBox<GLFWWindow>(width, height, title);
}