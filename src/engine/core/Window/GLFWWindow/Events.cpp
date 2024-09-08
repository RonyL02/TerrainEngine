#include "Events.h"
#include "../../Input.h"
#include "../Window.h"

void TE::GLFWKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        Input::SetKeyState((KeyCode)key, Input::KeyState::KEY_DOWN);
    }
    if (action == GLFW_RELEASE)
    {
        Input::SetKeyState((KeyCode)key, Input::KeyState::KEY_UP);
    }
}

void TE::GLFWMouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        Input::SetKeyState((KeyCode)button, Input::KeyState::KEY_DOWN);
    }
    if (action == GLFW_RELEASE)
    {
        Input::SetKeyState((KeyCode)button, Input::KeyState::KEY_UP);
    }
}

void TE::GLFWFramebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    Window::GetInstance()->SetHeight(height);
    Window::GetInstance()->SetWidth(width);
    glViewport(0, 0, width, height);
}
