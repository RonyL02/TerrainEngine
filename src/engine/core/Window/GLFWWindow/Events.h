#pragma once
#include <GLFW/glfw3.h>

namespace TE
{
    void GLFWKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

    void GLFWMouseButtonCallback(GLFWwindow *window, int button, int action, int mods);

    void GLFWFramebufferSizeCallback(GLFWwindow* window, int width, int height);  

    void GLFWMouseCallback(GLFWwindow* window, double xpos, double ypos);
}