#pragma once
#include <memory>
#include "../../Utils.h"
namespace TE
{
    class Window
    {
    public:
        Window(int width, int height, const char *title)
            : m_Width(width), m_Height(height), m_Title(title)
        {
        }

        virtual ~Window() = default;

        virtual void Update() = 0;

        virtual void SetShouldClose() = 0;
        virtual bool ShouldClose() = 0;

        static Ref<Window> InitializeWindow(int width, int height, const char *title);

        static Ref<Window> GetInstance();

        int GetWidth();
        int GetHeight();
        void SetWidth(int width);
        void SetHeight(int height);

        virtual void Destroy() = 0;
    protected:
        static Ref<Window> m_WindowInstance;

        virtual void Create() = 0;

        int m_Width;
        int m_Height;
        const char *m_Title;
    };
}