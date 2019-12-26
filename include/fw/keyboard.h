/**
 * @file eventsystem.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the keyboard class, which is only used to decipher the event keycodes right now
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_KEYBOARD_H
#define BE_KEYBOARD_H

namespace be
{

class Keyboard
{
public:
    enum Key
    {
        Unknown = -1,
        A = 0, 
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        Num0,
        Num1,
        Num2,
        Num3,
        Num4,
        Num5,
        Num6,
        Num7,
        Num8,
        Num9,
        Escape,
        LeftControl,
        LeftShift,
        LeftAlt,
        LeftSystem,
        RightControl,
        RightShift,
        RightAlt,
        RightSystem,
        Menu,
        LeftBracket,
        RightBracket,
        SemiColon,
        Comma,
        Period,
        Quote,
        Slash,
        BackSlash,
        Tilde,
        Equal,
        Dash,
        Space,
        Return,
        BackSpace,
        Tab,
        PageUp,
        PageDown,
        End,
        Home,
        Insert,
        Delete,
        NumpadPlus,
        NumpadMinus,
        NumpadAsterisk,
        NumpadForwardSlash,
        LeftArrow,
        RightArrow,
        UpArrow,
        DownArrow,
        Numpad0,
        Numpad1,
        Numpad2,
        Numpad3,
        Numpad4,
        Numpad5,
        Numpad6,
        Numpad7,
        Numpad8,
        Numpad9,
        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        F13,
        F14,
        F15,
        Pause,

        END
    };
};

}

#endif // BE_KEYBOARD_H