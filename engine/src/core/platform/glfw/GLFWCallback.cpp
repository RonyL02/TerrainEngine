#include "GLFWCallback.h"
#include "../../Application.h"
#include "../../Input.h"
#include <GLFW/glfw3.h>
namespace TerrainEngine
{
    void GLFWCallback::Key(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        if (action == GLFW_PRESS)
        {
            Input::SetKeyState((KeyCodes)key, Input::KeyState::KEY_DOWN);
        }
        if (action == GLFW_RELEASE)
        {
            Input::SetKeyState((KeyCodes)key, Input::KeyState::KEY_UP);
        }
    }
    void GLFWCallback::MouseButton(GLFWwindow *window, int button, int action, int mods)
    {
        if (action == GLFW_PRESS)
        {
            Input::SetKeyState((KeyCodes)button, Input::KeyState::KEY_DOWN);
        }
        if (action == GLFW_RELEASE)
        {
            Input::SetKeyState((KeyCodes)button, Input::KeyState::KEY_UP);
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
}
