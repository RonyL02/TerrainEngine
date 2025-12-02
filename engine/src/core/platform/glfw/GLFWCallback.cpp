#include "GLFWCallback.h"
#include "core/Application.h"
#include "core/Input.h"
#include <GLFW/glfw3.h>
#include "core/Log.h"
#include "GLFWKeyCodeMapper.h"

namespace TerrainEngine
{
    void GLFWCallback::Key(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        if (action == GLFW_PRESS)
        {
            Input::SetKeyState(GLFWToKeyCode(key), Input::KeyState::KEY_DOWN);
        }
        if (action == GLFW_RELEASE)
        {
            Input::SetKeyState(GLFWToKeyCode(key), Input::KeyState::KEY_UP);
        }
    }
    void GLFWCallback::MouseButton(GLFWwindow *window, int button, int action, int mods)
    {
        if (action == GLFW_PRESS)
        {
            Input::SetKeyState(GLFWToKeyCode(button), Input::KeyState::KEY_DOWN);
        }
        if (action == GLFW_RELEASE)
        {
            Input::SetKeyState(GLFWToKeyCode(button), Input::KeyState::KEY_UP);
        }
    }
    void GLFWCallback::FramebufferSize(GLFWwindow *window, int width, int height)
    {
        Application::Get().GetWindow().SetWidth(width);
        Application::Get().GetWindow().SetHeight(height);
        Application::Get().GetRenderer().UpdateViewPort(width, height);
    }
    void GLFWCallback::MousePosition(GLFWwindow *window, double xpos, double ypos)
    {
        double xoffset = xpos - Input::GetCurrentMousePosition().first;
        double yoffset = Input::GetCurrentMousePosition().second - ypos;

        Input::SetCurrentMousePosition(xpos, ypos);
        Input::SetMouseOffset(xoffset, yoffset);
    }

    void GLFWCallback::ErrorCallback(int error, const char *description)
    {
        TE_ERROR("glfw error ({}): {}", error, description);
    }
}
