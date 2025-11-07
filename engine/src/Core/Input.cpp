#include "Input.h"

std::array<TE::Input::KeyState, TE::KeyCode::KEY_LAST + 1> TE::Input::KeyStates;
std::pair<double, double> TE::Input::MousePosition;
std::pair<double, double> TE::Input::MouseOffset;

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

void TE::Input::SetCurrentMousePosition(double x, double y)
{
    MousePosition.first = x;
    MousePosition.second = y;
}

std::pair<double, double> TE::Input::GetCurrentMousePosition()
{
    return MousePosition;
}

void TE::Input::SetMouseOffset(double x, double y)
{
    MouseOffset.first = x;
    MouseOffset.second = y;
}

std::pair<double, double> TE::Input::GetMouseOffset()
{
    return MouseOffset;
}
