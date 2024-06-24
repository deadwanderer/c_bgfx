/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2024 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/**
 * # CategoryKeycode
 *
 * Defines constants which identify keyboard keys and modifiers.
 */

#ifndef SDL_keycode_h_
#define SDL_keycode_h_

#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_scancode.h>

/**
 * The SDL virtual key representation.
 *
 * Values of this type are used to represent keyboard keys using the current
 * layout of the keyboard. These values include Unicode values representing
 * the unmodified character that would be generated by pressing the key, or an
 * `SDLK_*` constant for those keys that do not generate characters.
 *
 * A special exception is the number keys at the top of the keyboard which map
 * to SDLK_0...SDLK_9 on AZERTY layouts.
 *
 * \since This datatype is available since SDL 3.0.0.
 *
 * \sa SDL_KeyCode
 */
typedef Uint32 SDL_Keycode;

#define SDLK_SCANCODE_MASK (1u<<30)
#define SDL_SCANCODE_TO_KEYCODE(X)  (X | SDLK_SCANCODE_MASK)
#define SDLK_UNKNOWN    0
#define SDLK_RETURN '\r'
#define SDLK_ESCAPE '\x1B'
#define SDLK_BACKSPACE  '\b'
#define SDLK_TAB    '\t'
#define SDLK_SPACE  ' '
#define SDLK_EXCLAIM    '!'
#define SDLK_DBLAPOSTROPHE   '"'
#define SDLK_HASH   '#'
#define SDLK_PERCENT    '%'
#define SDLK_DOLLAR '$'
#define SDLK_AMPERSAND  '&'
#define SDLK_APOSTROPHE  '\''
#define SDLK_LEFTPAREN  '('
#define SDLK_RIGHTPAREN ')'
#define SDLK_ASTERISK   '*'
#define SDLK_PLUS   '+'
#define SDLK_COMMA  ','
#define SDLK_MINUS  '-'
#define SDLK_PERIOD '.'
#define SDLK_SLASH  '/'
#define SDLK_0  '0'
#define SDLK_1  '1'
#define SDLK_2  '2'
#define SDLK_3  '3'
#define SDLK_4  '4'
#define SDLK_5  '5'
#define SDLK_6  '6'
#define SDLK_7  '7'
#define SDLK_8  '8'
#define SDLK_9  '9'
#define SDLK_COLON  ':'
#define SDLK_SEMICOLON  ';'
#define SDLK_LESS   '<'
#define SDLK_EQUALS '='
#define SDLK_GREATER    '>'
#define SDLK_QUESTION   '?'
#define SDLK_AT '@'
#define SDLK_LEFTBRACKET    '['
#define SDLK_BACKSLASH  '\\'
#define SDLK_RIGHTBRACKET   ']'
#define SDLK_CARET  '^'
#define SDLK_UNDERSCORE '_'
#define SDLK_GRAVE  '`'
#define SDLK_a  'a'
#define SDLK_b  'b'
#define SDLK_c  'c'
#define SDLK_d  'd'
#define SDLK_e  'e'
#define SDLK_f  'f'
#define SDLK_g  'g'
#define SDLK_h  'h'
#define SDLK_i  'i'
#define SDLK_j  'j'
#define SDLK_k  'k'
#define SDLK_l  'l'
#define SDLK_m  'm'
#define SDLK_n  'n'
#define SDLK_o  'o'
#define SDLK_p  'p'
#define SDLK_q  'q'
#define SDLK_r  'r'
#define SDLK_s  's'
#define SDLK_t  't'
#define SDLK_u  'u'
#define SDLK_v  'v'
#define SDLK_w  'w'
#define SDLK_x  'x'
#define SDLK_y  'y'
#define SDLK_z  'z'
#define SDLK_CAPSLOCK   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CAPSLOCK)
#define SDLK_F1 SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F1)
#define SDLK_F2 SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F2)
#define SDLK_F3 SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F3)
#define SDLK_F4 SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F4)
#define SDLK_F5 SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F5)
#define SDLK_F6 SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F6)
#define SDLK_F7 SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F7)
#define SDLK_F8 SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F8)
#define SDLK_F9 SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F9)
#define SDLK_F10    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F10)
#define SDLK_F11    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F11)
#define SDLK_F12    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F12)
#define SDLK_PRINTSCREEN    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRINTSCREEN)
#define SDLK_SCROLLLOCK SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SCROLLLOCK)
#define SDLK_PAUSE  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAUSE)
#define SDLK_INSERT SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_INSERT)
#define SDLK_HOME   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HOME)
#define SDLK_PAGEUP SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEUP)
#define SDLK_DELETE '\x7F'
#define SDLK_END    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_END)
#define SDLK_PAGEDOWN   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEDOWN)
#define SDLK_RIGHT  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RIGHT)
#define SDLK_LEFT   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LEFT)
#define SDLK_DOWN   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DOWN)
#define SDLK_UP SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UP)
#define SDLK_NUMLOCKCLEAR   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_NUMLOCKCLEAR)
#define SDLK_KP_DIVIDE  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DIVIDE)
#define SDLK_KP_MULTIPLY    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MULTIPLY)
#define SDLK_KP_MINUS   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MINUS)
#define SDLK_KP_PLUS    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUS)
#define SDLK_KP_ENTER   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_ENTER)
#define SDLK_KP_1   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_1)
#define SDLK_KP_2   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_2)
#define SDLK_KP_3   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_3)
#define SDLK_KP_4   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_4)
#define SDLK_KP_5   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_5)
#define SDLK_KP_6   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_6)
#define SDLK_KP_7   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_7)
#define SDLK_KP_8   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_8)
#define SDLK_KP_9   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_9)
#define SDLK_KP_0   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_0)
#define SDLK_KP_PERIOD  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERIOD)
#define SDLK_APPLICATION    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APPLICATION)
#define SDLK_POWER  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_POWER)
#define SDLK_KP_EQUALS  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALS)
#define SDLK_F13    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F13)
#define SDLK_F14    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F14)
#define SDLK_F15    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F15)
#define SDLK_F16    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F16)
#define SDLK_F17    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F17)
#define SDLK_F18    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F18)
#define SDLK_F19    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F19)
#define SDLK_F20    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F20)
#define SDLK_F21    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F21)
#define SDLK_F22    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F22)
#define SDLK_F23    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F23)
#define SDLK_F24    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F24)
#define SDLK_EXECUTE    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXECUTE)
#define SDLK_HELP   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HELP)
#define SDLK_MENU   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MENU)
#define SDLK_SELECT SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SELECT)
#define SDLK_STOP   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_STOP)
#define SDLK_AGAIN  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AGAIN)
#define SDLK_UNDO   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UNDO)
#define SDLK_CUT    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CUT)
#define SDLK_COPY   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COPY)
#define SDLK_PASTE  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PASTE)
#define SDLK_FIND   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_FIND)
#define SDLK_MUTE   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MUTE)
#define SDLK_VOLUMEUP   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEUP)
#define SDLK_VOLUMEDOWN SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEDOWN)
#define SDLK_KP_COMMA   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COMMA)
#define SDLK_KP_EQUALSAS400 SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALSAS400)
#define SDLK_ALTERASE   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ALTERASE)
#define SDLK_SYSREQ SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SYSREQ)
#define SDLK_CANCEL SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CANCEL)
#define SDLK_CLEAR  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEAR)
#define SDLK_PRIOR  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRIOR)
#define SDLK_RETURN2    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RETURN2)
#define SDLK_SEPARATOR  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SEPARATOR)
#define SDLK_OUT    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OUT)
#define SDLK_OPER   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OPER)
#define SDLK_CLEARAGAIN SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEARAGAIN)
#define SDLK_CRSEL  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CRSEL)
#define SDLK_EXSEL  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXSEL)
#define SDLK_KP_00  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_00)
#define SDLK_KP_000 SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_000)
#define SDLK_THOUSANDSSEPARATOR SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_THOUSANDSSEPARATOR)
#define SDLK_DECIMALSEPARATOR   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DECIMALSEPARATOR)
#define SDLK_CURRENCYUNIT   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYUNIT)
#define SDLK_CURRENCYSUBUNIT    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYSUBUNIT)
#define SDLK_KP_LEFTPAREN   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTPAREN)
#define SDLK_KP_RIGHTPAREN  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTPAREN)
#define SDLK_KP_LEFTBRACE   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTBRACE)
#define SDLK_KP_RIGHTBRACE  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTBRACE)
#define SDLK_KP_TAB SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_TAB)
#define SDLK_KP_BACKSPACE   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BACKSPACE)
#define SDLK_KP_A   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_A)
#define SDLK_KP_B   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_B)
#define SDLK_KP_C   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_C)
#define SDLK_KP_D   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_D)
#define SDLK_KP_E   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_E)
#define SDLK_KP_F   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_F)
#define SDLK_KP_XOR SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_XOR)
#define SDLK_KP_POWER   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_POWER)
#define SDLK_KP_PERCENT SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERCENT)
#define SDLK_KP_LESS    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LESS)
#define SDLK_KP_GREATER SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_GREATER)
#define SDLK_KP_AMPERSAND   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AMPERSAND)
#define SDLK_KP_DBLAMPERSAND    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLAMPERSAND)
#define SDLK_KP_VERTICALBAR SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_VERTICALBAR)
#define SDLK_KP_DBLVERTICALBAR  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLVERTICALBAR)
#define SDLK_KP_COLON   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COLON)
#define SDLK_KP_HASH    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HASH)
#define SDLK_KP_SPACE   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_SPACE)
#define SDLK_KP_AT  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AT)
#define SDLK_KP_EXCLAM  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EXCLAM)
#define SDLK_KP_MEMSTORE    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSTORE)
#define SDLK_KP_MEMRECALL   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMRECALL)
#define SDLK_KP_MEMCLEAR    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMCLEAR)
#define SDLK_KP_MEMADD  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMADD)
#define SDLK_KP_MEMSUBTRACT SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSUBTRACT)
#define SDLK_KP_MEMMULTIPLY SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMMULTIPLY)
#define SDLK_KP_MEMDIVIDE   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMDIVIDE)
#define SDLK_KP_PLUSMINUS   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUSMINUS)
#define SDLK_KP_CLEAR   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEAR)
#define SDLK_KP_CLEARENTRY  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEARENTRY)
#define SDLK_KP_BINARY  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BINARY)
#define SDLK_KP_OCTAL   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_OCTAL)
#define SDLK_KP_DECIMAL SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DECIMAL)
#define SDLK_KP_HEXADECIMAL SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HEXADECIMAL)
#define SDLK_LCTRL  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LCTRL)
#define SDLK_LSHIFT SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LSHIFT)
#define SDLK_LALT   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LALT)
#define SDLK_LGUI   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LGUI)
#define SDLK_RCTRL  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RCTRL)
#define SDLK_RSHIFT SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RSHIFT)
#define SDLK_RALT   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RALT)
#define SDLK_RGUI   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RGUI)
#define SDLK_MODE   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MODE)
#define SDLK_AUDIONEXT  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIONEXT)
#define SDLK_AUDIOPREV  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPREV)
#define SDLK_AUDIOSTOP  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOSTOP)
#define SDLK_AUDIOPLAY  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPLAY)
#define SDLK_AUDIOMUTE  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOMUTE)
#define SDLK_MEDIASELECT    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIASELECT)
#define SDLK_WWW    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_WWW)
#define SDLK_MAIL   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MAIL)
#define SDLK_CALCULATOR SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALCULATOR)
#define SDLK_COMPUTER   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COMPUTER)
#define SDLK_AC_SEARCH  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SEARCH)
#define SDLK_AC_HOME    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_HOME)
#define SDLK_AC_BACK    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BACK)
#define SDLK_AC_FORWARD SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_FORWARD)
#define SDLK_AC_STOP    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_STOP)
#define SDLK_AC_REFRESH SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_REFRESH)
#define SDLK_AC_BOOKMARKS   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BOOKMARKS)
#define SDLK_BRIGHTNESSDOWN SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSDOWN)
#define SDLK_BRIGHTNESSUP   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSUP)
#define SDLK_DISPLAYSWITCH  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DISPLAYSWITCH)
#define SDLK_KBDILLUMTOGGLE SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMTOGGLE)
#define SDLK_KBDILLUMDOWN   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMDOWN)
#define SDLK_KBDILLUMUP SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMUP)
#define SDLK_EJECT  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EJECT)
#define SDLK_SLEEP  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SLEEP)
#define SDLK_APP1   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APP1)
#define SDLK_APP2   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APP2)
#define SDLK_AUDIOREWIND    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOREWIND)
#define SDLK_AUDIOFASTFORWARD   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOFASTFORWARD)
#define SDLK_SOFTLEFT   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTLEFT)
#define SDLK_SOFTRIGHT  SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTRIGHT)
#define SDLK_CALL   SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALL)
#define SDLK_ENDCALL    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ENDCALL)

/**
 * Valid key modifiers (possibly OR'd together).
 *
 * \since This datatype is available since SDL 3.0.0.
 */
typedef Uint16 SDL_Keymod;

#define SDL_KMOD_NONE   0x0000u /**< no modifier is applicable. */
#define SDL_KMOD_LSHIFT 0x0001u /**< the left Shift key is down. */
#define SDL_KMOD_RSHIFT 0x0002u /**< the right Shift key is down. */
#define SDL_KMOD_LCTRL  0x0040u /**< the left Ctrl (Control) key is down. */
#define SDL_KMOD_RCTRL  0x0080u /**< the right Ctrl (Control) key is down. */
#define SDL_KMOD_LALT   0x0100u /**< the left Alt key is down. */
#define SDL_KMOD_RALT   0x0200u /**< the right Alt key is down. */
#define SDL_KMOD_LGUI   0x0400u /**< the left GUI key (often the Windows key) is down. */
#define SDL_KMOD_RGUI   0x0800u /**< the right GUI key (often the Windows key) is down. */
#define SDL_KMOD_NUM    0x1000u /**< the Num Lock key (may be located on an extended keypad) is down. */
#define SDL_KMOD_CAPS   0x2000u /**< the Caps Lock key is down. */
#define SDL_KMOD_MODE   0x4000u /**< the !AltGr key is down. */
#define SDL_KMOD_SCROLL 0x8000u /**< the Scroll Lock key is down. */
#define SDL_KMOD_CTRL   (SDL_KMOD_LCTRL | SDL_KMOD_RCTRL)   /**< Any Ctrl key is down. */
#define SDL_KMOD_SHIFT  (SDL_KMOD_LSHIFT | SDL_KMOD_RSHIFT) /**< Any Shift key is down. */
#define SDL_KMOD_ALT    (SDL_KMOD_LALT | SDL_KMOD_RALT)     /**< Any Alt key is down. */
#define SDL_KMOD_GUI    (SDL_KMOD_LGUI | SDL_KMOD_RGUI)     /**< Any GUI key is down. */

#endif /* SDL_keycode_h_ */
