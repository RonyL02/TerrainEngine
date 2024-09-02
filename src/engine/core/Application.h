#pragma once
#include "Window/Window.h"
#include "../utils.h"

namespace TE
{
    class Application
    {
    public:
        Application(int width, int height, const char *title);
        ~Application() = default;

        void Run();

    private:
        Box<Window> m_Window;
    };

}