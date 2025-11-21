#include "Input.h"

namespace TerrainEngine
{
    std::array<Input::KeyState, (size_t)KeyCodes::KEY_LAST> Input::CurrentKeyStates;
    std::array<Input::KeyState, (size_t)KeyCodes::KEY_LAST> Input::PreviousKeyStates;

    std::pair<double, double> Input::MousePosition;
    std::pair<double, double> Input::MouseOffset;

    bool Input::IsKeyDown(KeyCodes keyCode)
    {
        return Input::CurrentKeyStates[(size_t)keyCode] == KeyState::KEY_DOWN;
    }

    bool Input::IsKeyUp(KeyCodes keyCode)
    {
        return Input::CurrentKeyStates[(size_t)keyCode] == KeyState::KEY_UP;
    }

    bool Input::IsKeyPressed(KeyCodes keyCode)
    {
        return Input::CurrentKeyStates[(size_t)keyCode] == KeyState::KEY_DOWN && Input::PreviousKeyStates[(size_t)keyCode] == KeyState::KEY_UP;
    }

    bool Input::IsKeyReleased(KeyCodes keyCode)
    {
        return Input::CurrentKeyStates[(size_t)keyCode] == KeyState::KEY_UP && Input::PreviousKeyStates[(size_t)keyCode] == KeyState::KEY_DOWN;
    }

    void Input::SetKeyState(KeyCodes keyCode, KeyState state)
    {
        Input::CurrentKeyStates[(size_t)keyCode] = state;
    }

    void Input::SetCurrentMousePosition(double x, double y)
    {
        MousePosition.first = x;
        MousePosition.second = y;
    }

    std::pair<double, double> Input::GetCurrentMousePosition()
    {
        return MousePosition;
    }

    void Input::SetMouseOffset(double x, double y)
    {
        MouseOffset.first = x;
        MouseOffset.second = y;
    }

    std::pair<double, double> Input::GetMouseOffset()
    {
        return MouseOffset;
    }

    void Input::Update()
    {
        Input::PreviousKeyStates = Input::CurrentKeyStates;
    }
}