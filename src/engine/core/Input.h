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

    private:
        static std::array<KeyState, KeyCode::KEY_LAST + 1> KeyStates;
    };
}