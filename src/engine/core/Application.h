#pragma once
#include "GLFWWindow.h"

namespace TE
{
    class Application
    {

    public:
        Application(int width, int height, const char *title);
        ~Application() = default;

        void Run();

    private:
        GLFWWindow m_Window;
    };

}