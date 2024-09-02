#include "Input.h"

std::array<TE::Input::KeyState, TE::KeyCode::KEY_LAST + 1> TE::Input::KeyStates;

bool TE::Input::IsKeyDown(KeyCode keyCode)
{
    return KeyStates[keyCode] == KeyState::KEY_DOWN;
}

bool TE::Input::IsKeyUp(KeyCode keyCode)
{
    return KeyStates[keyCode] == KeyState::KEY_UP;
}

void TE::Input::SetKeyState(KeyCode keyCode, KeyState state)
{
    KeyStates[keyCode] = state;
}
