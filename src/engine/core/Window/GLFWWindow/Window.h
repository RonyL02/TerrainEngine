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

        void Update() override;

        void SetShouldClose() override;
        bool ShouldClose() override;

        void DisableCursor(bool disable) override;

        void Destroy() override;

        double GetTime() override;

    private:
        void Create() override;
        void RegisterEventCallbacks();

        GLFWwindow *m_Window;
    };
}