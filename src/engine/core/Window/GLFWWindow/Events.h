#pragma once
#include <GLFW/glfw3.h>

namespace TE
{
    void GLFWKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

    void GLFWMouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
}