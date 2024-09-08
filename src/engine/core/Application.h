#pragma once
#include "Window/Window.h"
#include "../Utils.h"

namespace TE
{
    class Application
    {
    public:
        Application(int width, int height, const char *title);
        ~Application() = default;

        void Run();

    private:
        Ref<Window> m_Window;
    };

}