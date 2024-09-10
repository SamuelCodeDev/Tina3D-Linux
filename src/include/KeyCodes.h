#ifndef KEYCODES_H
#define KEYCODES_H

/*

Virtual KeyCodes

This file shows a complete list of all the virtual keys VK_ aliases and their hex value.
You can use either the alias, the hex value or the decimal value for ReShade key bindings.

.------------------------.
| :: Reference layout :: |
'------------------------'

Keys should be set to a Windows Virtual Keycode in either decimal, hexadecimal or its VK_ alias.
Below is US ANSI keyboard reference for the keycodes in decimal:

US ANSI keyboard (104 keys) keycodes (note that your countrys keyboard layout maybe slightly different):
.---.  .---.---.---.---. .---.---.---.---. .---.---.---.---.  .---.---.---.
| 27|  |112|113|114|115| |116|117|118|119| |120|121|122|123|  | 44|145| 19|
`---'  `---'---'---'---' `---'---'---'---' `---'---'---'---'  `---'---'---'

.---.---.---.---.---.---.---.---.---.---.---.---.---.------.  .---.---.---.  .---.---.---.---.
|192| 49| 50| 51| 52| 53| 54| 55| 56| 57| 48|189|187|   8  |  | 45| 36| 33|  |144|111|106|109|
:---'---'---'---'---'---'---'---'---'---'---'---'---'------:  :---:---:---:  :---:---:---:---:
|  9 | 81| 87| 69| 82| 84| 89| 85| 73| 79| 80|219|221| 220 |  | 46| 35| 34|  |103|104|105|   |
:----'---'---'---'---'---'---'---'---'---'---'---'---'-----|  `---'---'---'  :---:---:---|107|
|  20 | 65| 83| 68| 70| 71| 72| 74| 75| 76|186|222|   13   |                 |100|101|102|   |
:-----'---'---'---'---'---'---'---'---'---'---'---'--------'      .---.      :---:---:---:---:
|   16  | 90| 88| 67| 86| 66| 78| 77|188|190|191|    16    |      | 38|      | 97| 98| 99|   |
:-------'---'---'---'---'---'---'---'---'---'---'----------'  .---:---|---.  :---'---:---| 13|
| 17 | 91 | 18 |           32          | 18 | 92 | 93 | 17 |  | 37| 40| 39|  |   96  |110|   |
`----'----'----'-----------------------'----'----'----'----'  `---'---'---'  `-------'---'---'

*/

#include <X11/keysym.h>

enum VirtualKeys
{
    VK_LBUTTON = 0x01,        // Left mouse button
    VK_MBUTTON = 0x02,        // Middle mouse button
    VK_RBUTTON = 0x03,        // Right mouse button
    
    VK_BACK = XK_BackSpace,
    VK_TAB = XK_Tab,
    VK_CLEAR = XK_Clear,
    VK_RETURN = XK_Return,

    VK_SHIFT = XK_Shift_L,
    VK_CONTROL = XK_Control_L,
    
    VK_MENU = XK_Menu,
    VK_PAUSE = XK_Pause,
    VK_CAPITAL = XK_Caps_Lock,
    VK_ESCAPE = XK_Escape,
    VK_MODECHANGE = XK_Mode_switch,
    VK_SPACE = XK_space,
    VK_PRIOR = XK_Prior,
    VK_NEXT = XK_Next,
    VK_END = XK_End,
    VK_HOME = XK_Home,
    
    VK_LEFT = XK_Left,
    VK_UP = XK_Up,
    VK_RIGHT = XK_Right,
    VK_DOWN = XK_Down,
    
    VK_SELECT = XK_Select,
    VK_EXECUTE = XK_Execute,
    VK_SNAPSHOT = XK_Print,
    VK_INSERT = XK_Insert,
    VK_DELETE = XK_Delete,
    VK_HELP = XK_Help,

    VK_A = XK_A,
    VK_B = XK_B,
    VK_C = XK_C,
    VK_D = XK_D,
    VK_E = XK_E,
    VK_F = XK_F,
    VK_G = XK_G,
    VK_H = XK_H,
    VK_I = XK_I,
    VK_J = XK_J,
    VK_K = XK_K,
    VK_L = XK_L,
    VK_M = XK_M,
    VK_N = XK_N,
    VK_O = XK_O,
    VK_P = XK_P,
    VK_Q = XK_Q,
    VK_R = XK_R,
    VK_S = XK_S,
    VK_T = XK_T,
    VK_U = XK_U,
    VK_V = XK_V,
    VK_W = XK_W,
    VK_X = XK_X,
    VK_Y = XK_Y,
    VK_Z = XK_Z,
    
    VK_LWIN = XK_Super_L,
    VK_RWIN = XK_Super_R,
    VK_APPS = XK_Menu,
    
    VK_NUMPAD0 = XK_KP_0,
    VK_NUMPAD1 = XK_KP_1,
    VK_NUMPAD2 = XK_KP_2,
    VK_NUMPAD3 = XK_KP_3,
    VK_NUMPAD4 = XK_KP_4,
    VK_NUMPAD5 = XK_KP_5,
    VK_NUMPAD6 = XK_KP_6,
    VK_NUMPAD7 = XK_KP_7,
    VK_NUMPAD8 = XK_KP_8,
    VK_NUMPAD9 = XK_KP_9,
    VK_MULTIPLY = XK_KP_Multiply,
    VK_ADD = XK_KP_Add,
    VK_SEPARATOR = XK_KP_Separator,
    VK_SUBTRACT = XK_KP_Subtract,
    VK_DECIMAL = XK_KP_Decimal,
    VK_DIVIDE = XK_KP_Divide,
    
    VK_F1 = XK_F1,
    VK_F2 = XK_F2,
    VK_F3 = XK_F3,
    VK_F4 = XK_F4,
    VK_F5 = XK_F5,
    VK_F6 = XK_F6,
    VK_F7 = XK_F7,
    VK_F8 = XK_F8,
    VK_F9 = XK_F9,
    VK_F10 = XK_F10,
    VK_F11 = XK_F11,
    VK_F12 = XK_F12,
    VK_F13 = XK_F13,
    VK_F14 = XK_F14,
    VK_F15 = XK_F15,
    VK_F16 = XK_F16,
    VK_F17 = XK_F17,
    VK_F18 = XK_F18,
    VK_F19 = XK_F19,
    VK_F20 = XK_F20,
    VK_F21 = XK_F21,
    VK_F22 = XK_F22,
    VK_F23 = XK_F23,
    VK_F24 = XK_F24,

    VK_NUMLOCK = XK_Num_Lock,
    VK_SCROLL = XK_Scroll_Lock,

    VK_LSHIFT = XK_Shift_L,
    VK_RSHIFT = XK_Shift_R,
    VK_LCONTROL = XK_Control_L,
    VK_RCONTROL = XK_Control_R,
    VK_LMENU = XK_Alt_L,
    VK_RMENU = XK_Alt_R
};

#endif