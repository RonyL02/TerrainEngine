#pragma once

struct GLFWwindow;
namespace TerrainEngine
{

    class GLFWCallback
    {
    public:
        static void Key(GLFWwindow *window, int key, int scancode, int action, int mods);

        static void MouseButton(GLFWwindow *window, int button, int action, int mods);

        static void FramebufferSize(GLFWwindow *window, int width, int height);

        static void MousePosition(GLFWwindow *window, double xpos, double ypos);

        static void ErrorCallback(int error, const char *description);
    };

}