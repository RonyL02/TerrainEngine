#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace TE
{
    class GLFWWindow
    {
    public:
        GLFWWindow(int width, int height, const char *title);
        ~GLFWWindow();

        void SwapBuffers();
        void PollEvents();

        bool ShouldClose();

    private:
        void Close();
        void Create();

        GLFWwindow *m_Window;
        int m_Width;
        int m_Height;
        const char *m_Title;
    };
}