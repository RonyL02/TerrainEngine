#pragma once
#include <array>
#include "KeyCodes.h"

namespace TE
{
    class Input
    {
    public:
        enum KeyState
        {
            KEY_UP,
            KEY_DOWN
        };

        static bool IsKeyDown(KeyCode keyCode);
        static bool IsKeyUp(KeyCode keyCode);
        static void SetKeyState(KeyCode keyCode, KeyState state);

        static void SetCurrentMousePosition(double x, double y);
        static std::pair<double, double> GetCurrentMousePosition();

        static void SetMouseOffset(double x, double y);
        static std::pair<double, double> GetMouseOffset();

    private:
        static std::array<KeyState, KeyCode::KEY_LAST + 1> KeyStates;
        static std::pair<double, double> MousePosition;
        static std::pair<double, double> MouseOffset;
    };
}