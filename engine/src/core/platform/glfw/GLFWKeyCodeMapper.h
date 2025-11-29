#pragma once
#include <GLFW/glfw3.h>
#include "core/KeyCodes.h"

namespace TerrainEngine
{
    KeyCodes GLFWToKeyCode(int key)
    {
        switch (key)
        {
        case GLFW_MOUSE_BUTTON_LEFT:
            return KeyCodes::MOUSE_BUTTON_LEFT;
        case GLFW_MOUSE_BUTTON_RIGHT:
            return KeyCodes::MOUSE_BUTTON_RIGHT;
        case GLFW_MOUSE_BUTTON_MIDDLE:
            return KeyCodes::MOUSE_BUTTON_MIDDLE;

        case GLFW_KEY_SPACE:
            return KeyCodes::KEY_SPACE;

        case GLFW_KEY_0:
            return KeyCodes::KEY_0;
        case GLFW_KEY_1:
            return KeyCodes::KEY_1;
        case GLFW_KEY_2:
            return KeyCodes::KEY_2;
        case GLFW_KEY_3:
            return KeyCodes::KEY_3;
        case GLFW_KEY_4:
            return KeyCodes::KEY_4;
        case GLFW_KEY_5:
            return KeyCodes::KEY_5;
        case GLFW_KEY_6:
            return KeyCodes::KEY_6;
        case GLFW_KEY_7:
            return KeyCodes::KEY_7;
        case GLFW_KEY_8:
            return KeyCodes::KEY_8;
        case GLFW_KEY_9:
            return KeyCodes::KEY_9;

        case GLFW_KEY_A:
            return KeyCodes::KEY_A;
        case GLFW_KEY_B:
            return KeyCodes::KEY_B;
        case GLFW_KEY_C:
            return KeyCodes::KEY_C;
        case GLFW_KEY_D:
            return KeyCodes::KEY_D;
        case GLFW_KEY_E:
            return KeyCodes::KEY_E;
        case GLFW_KEY_F:
            return KeyCodes::KEY_F;
        case GLFW_KEY_G:
            return KeyCodes::KEY_G;
        case GLFW_KEY_H:
            return KeyCodes::KEY_H;
        case GLFW_KEY_I:
            return KeyCodes::KEY_I;
        case GLFW_KEY_J:
            return KeyCodes::KEY_J;
        case GLFW_KEY_K:
            return KeyCodes::KEY_K;
        case GLFW_KEY_L:
            return KeyCodes::KEY_L;
        case GLFW_KEY_M:
            return KeyCodes::KEY_M;
        case GLFW_KEY_N:
            return KeyCodes::KEY_N;
        case GLFW_KEY_O:
            return KeyCodes::KEY_O;
        case GLFW_KEY_P:
            return KeyCodes::KEY_P;
        case GLFW_KEY_Q:
            return KeyCodes::KEY_Q;
        case GLFW_KEY_R:
            return KeyCodes::KEY_R;
        case GLFW_KEY_S:
            return KeyCodes::KEY_S;
        case GLFW_KEY_T:
            return KeyCodes::KEY_T;
        case GLFW_KEY_U:
            return KeyCodes::KEY_U;
        case GLFW_KEY_V:
            return KeyCodes::KEY_V;
        case GLFW_KEY_W:
            return KeyCodes::KEY_W;
        case GLFW_KEY_X:
            return KeyCodes::KEY_X;
        case GLFW_KEY_Y:
            return KeyCodes::KEY_Y;
        case GLFW_KEY_Z:
            return KeyCodes::KEY_Z;

        case GLFW_KEY_ESCAPE:
            return KeyCodes::KEY_ESCAPE;
        case GLFW_KEY_ENTER:
            return KeyCodes::KEY_ENTER;
        case GLFW_KEY_TAB:
            return KeyCodes::KEY_TAB;
        case GLFW_KEY_BACKSPACE:
            return KeyCodes::KEY_BACKSPACE;

        case GLFW_KEY_RIGHT:
            return KeyCodes::KEY_RIGHT;
        case GLFW_KEY_LEFT:
            return KeyCodes::KEY_LEFT;
        case GLFW_KEY_DOWN:
            return KeyCodes::KEY_DOWN;
        case GLFW_KEY_UP:
            return KeyCodes::KEY_UP;

        case GLFW_KEY_CAPS_LOCK:
            return KeyCodes::KEY_CAPS_LOCK;

        case GLFW_KEY_F1:
            return KeyCodes::KEY_F1;
        case GLFW_KEY_F2:
            return KeyCodes::KEY_F2;
        case GLFW_KEY_F3:
            return KeyCodes::KEY_F3;
        case GLFW_KEY_F4:
            return KeyCodes::KEY_F4;
        case GLFW_KEY_F5:
            return KeyCodes::KEY_F5;
        case GLFW_KEY_F6:
            return KeyCodes::KEY_F6;
        case GLFW_KEY_F7:
            return KeyCodes::KEY_F7;
        case GLFW_KEY_F8:
            return KeyCodes::KEY_F8;
        case GLFW_KEY_F9:
            return KeyCodes::KEY_F9;
        case GLFW_KEY_F10:
            return KeyCodes::KEY_F10;
        case GLFW_KEY_F11:
            return KeyCodes::KEY_F11;
        case GLFW_KEY_F12:
            return KeyCodes::KEY_F12;

        case GLFW_KEY_LEFT_SHIFT:
            return KeyCodes::KEY_LEFT_SHIFT;
        case GLFW_KEY_LEFT_CONTROL:
            return KeyCodes::KEY_LEFT_CONTROL;
        case GLFW_KEY_LEFT_ALT:
            return KeyCodes::KEY_LEFT_ALT;

        case GLFW_KEY_RIGHT_SHIFT:
            return KeyCodes::KEY_RIGHT_SHIFT;

        default:
            return KeyCodes::KEY_LAST;
        }
    }
}
