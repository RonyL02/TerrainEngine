#pragma once
#include <array>
#include "KeyCodes.h"

namespace TerrainEngine
{
    class Input
    {
    public:
        enum KeyState
        {
            KEY_UP,
            KEY_DOWN
        };

        static bool IsKeyDown(KeyCodes keyCode);
        static bool IsKeyUp(KeyCodes keyCode);
        static bool IsKeyPressed(KeyCodes keyCode);
        static bool IsKeyReleased(KeyCodes keyCode);
        static void SetKeyState(KeyCodes keyCode, KeyState state);

        static void SetCurrentMousePosition(double x, double y);
        static std::pair<double, double> GetCurrentMousePosition();

        static void SetMouseOffset(double x, double y);
        static std::pair<double, double> GetMouseOffset();

        static void Update();

    private:
        static std::array<KeyState, (size_t)KeyCodes::KEY_LAST> CurrentKeyStates;
        static std::array<KeyState, (size_t)KeyCodes::KEY_LAST> PreviousKeyStates;
        static std::pair<double, double> MousePosition;
        static std::pair<double, double> MouseOffset;
    };
}