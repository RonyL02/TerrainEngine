#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Window.h"

namespace TE
{
    class GLFWWindow : public Window
    {
    public:
        GLFWWindow(int width, int height, const char *title)
            : Window(width, height, title)
        {
            Create();
        }

        ~GLFWWindow()
        {
            Destroy();
        };

        void Update() override;

        void SetShouldClose() override;
        bool ShouldClose() override;

    private:
        void Create() override;
        void Destroy() override;
        void RegisterEventCallbacks();

        GLFWwindow *m_Window;
    };
}