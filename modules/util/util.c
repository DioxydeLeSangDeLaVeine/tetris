#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "util.h"


/**
 * Minimum of a and b.
 *
 * @param {int32_t} a
 * @param {int32_t} b
 *
 * @returns {int32_t}
 */
int32_t __min(int32_t a, int32_t b)
{
    return a<=b?a:b;
}


/**
 * Maximum of a and b.
 *
 * @param {int32_t} a
 * @param {int32_t} b
 *
 * @returns {int32_t}
 */
int32_t __max(int32_t a, int32_t b)
{
    return a>=b?a:b;
}


/**
 * Returns char[] from a MLV_Keyboard_button.
 *
 * @param {MLV_Keyboard_button} sym
 * @param {char} response[]
 *
 * @returns {void}
 */
void getKeyFromMLV(MLV_Keyboard_button sym, char response[])
{
    switch(sym)
    {
        case MLV_KEYBOARD_a: strcpy(response, "A"); break;
        case MLV_KEYBOARD_b: strcpy(response, "B"); break;
        case MLV_KEYBOARD_c: strcpy(response, "C"); break;
        case MLV_KEYBOARD_d: strcpy(response, "D"); break;
        case MLV_KEYBOARD_e: strcpy(response, "E"); break;
        case MLV_KEYBOARD_f: strcpy(response, "F"); break;
        case MLV_KEYBOARD_g: strcpy(response, "G"); break;
        case MLV_KEYBOARD_h: strcpy(response, "H"); break;
        case MLV_KEYBOARD_i: strcpy(response, "I"); break;
        case MLV_KEYBOARD_j: strcpy(response, "J"); break;
        case MLV_KEYBOARD_k: strcpy(response, "K"); break;
        case MLV_KEYBOARD_l: strcpy(response, "L"); break;
        case MLV_KEYBOARD_m: strcpy(response, "M"); break;
        case MLV_KEYBOARD_n: strcpy(response, "N"); break;
        case MLV_KEYBOARD_o: strcpy(response, "O"); break;
        case MLV_KEYBOARD_p: strcpy(response, "P"); break;
        case MLV_KEYBOARD_q: strcpy(response, "Q"); break;
        case MLV_KEYBOARD_r: strcpy(response, "R"); break;
        case MLV_KEYBOARD_s: strcpy(response, "S"); break;
        case MLV_KEYBOARD_t: strcpy(response, "T"); break;
        case MLV_KEYBOARD_u: strcpy(response, "U"); break;
        case MLV_KEYBOARD_v: strcpy(response, "V"); break;
        case MLV_KEYBOARD_w: strcpy(response, "W"); break;
        case MLV_KEYBOARD_x: strcpy(response, "X"); break;
        case MLV_KEYBOARD_y: strcpy(response, "Y"); break;
        case MLV_KEYBOARD_z: strcpy(response, "Z"); break;
        case MLV_KEYBOARD_0: strcpy(response, "0"); break;
        case MLV_KEYBOARD_1: strcpy(response, "1"); break;
        case MLV_KEYBOARD_2: strcpy(response, "2"); break;
        case MLV_KEYBOARD_3: strcpy(response, "3"); break;
        case MLV_KEYBOARD_4: strcpy(response, "4"); break;
        case MLV_KEYBOARD_5: strcpy(response, "5"); break;
        case MLV_KEYBOARD_6: strcpy(response, "6"); break;
        case MLV_KEYBOARD_7: strcpy(response, "7"); break;
        case MLV_KEYBOARD_8: strcpy(response, "8"); break;
        case MLV_KEYBOARD_9: strcpy(response, "9"); break;
        case MLV_KEYBOARD_LALT: strcpy(response, "LEFT_ALT"); break;
        case MLV_KEYBOARD_RALT: strcpy(response, "RIGHT_ALT"); break;
        case MLV_KEYBOARD_LSHIFT: strcpy(response, "LEFT_SHIFT"); break;
        case MLV_KEYBOARD_RSHIFT: strcpy(response, "RIGHT_SHIFT"); break;
        case MLV_KEYBOARD_LCTRL: strcpy(response, "LEFT_CTRL"); break;
        case MLV_KEYBOARD_RCTRL: strcpy(response, "RIGHT_CTRL"); break;
        case MLV_KEYBOARD_SPACE: strcpy(response, "SPACE"); break;
        case MLV_KEYBOARD_RETURN: strcpy(response, "ENTER"); break;
        case MLV_KEYBOARD_BACKSPACE: strcpy(response, "BACKSPACE"); break;
        case MLV_KEYBOARD_TAB: strcpy(response, "TAB"); break;
        case MLV_KEYBOARD_CAPSLOCK: strcpy(response, "CAPS_LOCK"); break;
        case MLV_KEYBOARD_ESCAPE: strcpy(response, "ESCAPE"); break;
        case MLV_KEYBOARD_UP: strcpy(response, "UP_ARROW"); break;
        case MLV_KEYBOARD_DOWN: strcpy(response, "DOWN_ARROW"); break;
        case MLV_KEYBOARD_LEFT: strcpy(response, "LEFT_ARROW"); break;
        case MLV_KEYBOARD_RIGHT: strcpy(response, "RIGHT_ARROW"); break;
        case MLV_KEYBOARD_EXCLAIM: strcpy(response, "!"); break;
        case MLV_KEYBOARD_COMMA: strcpy(response, "?"); break;
        case MLV_KEYBOARD_SEMICOLON: strcpy(response, ";"); break;
        case MLV_KEYBOARD_COLON: strcpy(response, ":"); break;
        case MLV_KEYBOARD_EQUALS: strcpy(response, "="); break;
        case MLV_KEYBOARD_ASTERISK: strcpy(response, "*"); break;
        case MLV_KEYBOARD_DOLLAR: strcpy(response, "$"); break;
        case MLV_KEYBOARD_KP0: strcpy(response, "NUMPAD_0"); break;
        case MLV_KEYBOARD_KP1: strcpy(response, "NUMPAD_1"); break;
        case MLV_KEYBOARD_KP2: strcpy(response, "NUMPAD_2"); break;
        case MLV_KEYBOARD_KP3: strcpy(response, "NUMPAD_3"); break;
        case MLV_KEYBOARD_KP4: strcpy(response, "NUMPAD_4"); break;
        case MLV_KEYBOARD_KP5: strcpy(response, "NUMPAD_5"); break;
        case MLV_KEYBOARD_KP6: strcpy(response, "NUMPAD_6"); break;
        case MLV_KEYBOARD_KP7: strcpy(response, "NUMPAD_7"); break;
        case MLV_KEYBOARD_KP8: strcpy(response, "NUMPAD_8"); break;
        case MLV_KEYBOARD_KP9: strcpy(response, "NUMPAD_9"); break;
        case MLV_KEYBOARD_KP_DIVIDE: strcpy(response, "NUMPAD_DIVIDE"); break;
        case MLV_KEYBOARD_KP_MULTIPLY: strcpy(response, "NUMPAD_MULTIPLY"); break;
        case MLV_KEYBOARD_KP_MINUS: strcpy(response, "NUMPAD_MINUS"); break;
        case MLV_KEYBOARD_KP_PLUS: strcpy(response, "NUMPAD_PLUS"); break;
        case MLV_KEYBOARD_KP_ENTER: strcpy(response, "NUMPAD_ENTER"); break;
        case MLV_KEYBOARD_KP_PERIOD: strcpy(response, "NUMPAD_PERIOD"); break;
        case MLV_KEYBOARD_F1: strcpy(response, "F1"); break;
        case MLV_KEYBOARD_F2: strcpy(response, "F2"); break;
        case MLV_KEYBOARD_F3: strcpy(response, "F3"); break;
        case MLV_KEYBOARD_F4: strcpy(response, "F4"); break;
        case MLV_KEYBOARD_F5: strcpy(response, "F5"); break;
        case MLV_KEYBOARD_F6: strcpy(response, "F6"); break;
        case MLV_KEYBOARD_F7: strcpy(response, "F7"); break;
        case MLV_KEYBOARD_F8: strcpy(response, "F8"); break;
        case MLV_KEYBOARD_F9: strcpy(response, "F9"); break;
        case MLV_KEYBOARD_F10: strcpy(response, "F10"); break;
        case MLV_KEYBOARD_F11: strcpy(response, "F11"); break;
        case MLV_KEYBOARD_F12: strcpy(response, "F12"); break;
        default: strcpy(response, ""); break;
    }
}


/**
 * Returns MLV_Keyboard_button from a char[].
 *
 * @param {char} key[]
 *
 * @returns {MLV_Keyboard_button}
 */
MLV_Keyboard_button getMLVFromKey(char key[])
{
    if (strcmp(key, "A") == 0) return MLV_KEYBOARD_a;
    else if (strcmp(key, "B") == 0) return MLV_KEYBOARD_b;
    else if (strcmp(key, "C") == 0) return MLV_KEYBOARD_c;
    else if (strcmp(key, "D") == 0) return MLV_KEYBOARD_d;
    else if (strcmp(key, "E") == 0) return MLV_KEYBOARD_e;
    else if (strcmp(key, "F") == 0) return MLV_KEYBOARD_f;
    else if (strcmp(key, "G") == 0) return MLV_KEYBOARD_g;
    else if (strcmp(key, "H") == 0) return MLV_KEYBOARD_h;
    else if (strcmp(key, "I") == 0) return MLV_KEYBOARD_i;
    else if (strcmp(key, "J") == 0) return MLV_KEYBOARD_j;
    else if (strcmp(key, "K") == 0) return MLV_KEYBOARD_k;
    else if (strcmp(key, "L") == 0) return MLV_KEYBOARD_l;
    else if (strcmp(key, "M") == 0) return MLV_KEYBOARD_m;
    else if (strcmp(key, "N") == 0) return MLV_KEYBOARD_n;
    else if (strcmp(key, "O") == 0) return MLV_KEYBOARD_o;
    else if (strcmp(key, "P") == 0) return MLV_KEYBOARD_p;
    else if (strcmp(key, "Q") == 0) return MLV_KEYBOARD_q;
    else if (strcmp(key, "R") == 0) return MLV_KEYBOARD_r;
    else if (strcmp(key, "S") == 0) return MLV_KEYBOARD_s;
    else if (strcmp(key, "T") == 0) return MLV_KEYBOARD_t;
    else if (strcmp(key, "U") == 0) return MLV_KEYBOARD_u;
    else if (strcmp(key, "V") == 0) return MLV_KEYBOARD_v;
    else if (strcmp(key, "W") == 0) return MLV_KEYBOARD_w;
    else if (strcmp(key, "X") == 0) return MLV_KEYBOARD_x;
    else if (strcmp(key, "Y") == 0) return MLV_KEYBOARD_y;
    else if (strcmp(key, "Z") == 0) return MLV_KEYBOARD_z;
    else if (strcmp(key, "0") == 0) return MLV_KEYBOARD_0;
    else if (strcmp(key, "1") == 0) return MLV_KEYBOARD_1;
    else if (strcmp(key, "2") == 0) return MLV_KEYBOARD_2;
    else if (strcmp(key, "3") == 0) return MLV_KEYBOARD_3;
    else if (strcmp(key, "4") == 0) return MLV_KEYBOARD_4;
    else if (strcmp(key, "5") == 0) return MLV_KEYBOARD_5;
    else if (strcmp(key, "6") == 0) return MLV_KEYBOARD_6;
    else if (strcmp(key, "7") == 0) return MLV_KEYBOARD_7;
    else if (strcmp(key, "8") == 0) return MLV_KEYBOARD_8;
    else if (strcmp(key, "9") == 0) return MLV_KEYBOARD_9;
    else if (strcmp(key, "LEFT_ALT") == 0) return MLV_KEYBOARD_LALT;
    else if (strcmp(key, "RIGHT_ALT") == 0) return MLV_KEYBOARD_RALT;
    else if (strcmp(key, "LEFT_SHIFT") == 0) return MLV_KEYBOARD_LSHIFT;
    else if (strcmp(key, "RIGHT_SHIFT") == 0) return MLV_KEYBOARD_RSHIFT;
    else if (strcmp(key, "LEFT_CTRL") == 0) return MLV_KEYBOARD_LCTRL;
    else if (strcmp(key, "RIGHT_CTRL") == 0) return MLV_KEYBOARD_RCTRL;
    else if (strcmp(key, "SPACE") == 0) return MLV_KEYBOARD_SPACE;
    else if (strcmp(key, "ENTER") == 0) return MLV_KEYBOARD_RETURN;
    else if (strcmp(key, "BACKSPACE") == 0) return MLV_KEYBOARD_BACKSPACE;
    else if (strcmp(key, "TAB") == 0) return MLV_KEYBOARD_TAB;
    else if (strcmp(key, "CAPS_LOCK") == 0) return MLV_KEYBOARD_CAPSLOCK;
    else if (strcmp(key, "ESCAPE") == 0) return MLV_KEYBOARD_ESCAPE;
    else if (strcmp(key, "UP_ARROW") == 0) return MLV_KEYBOARD_UP;
    else if (strcmp(key, "DOWN_ARROW") == 0) return MLV_KEYBOARD_DOWN;
    else if (strcmp(key, "LEFT_ARROW") == 0) return MLV_KEYBOARD_LEFT;
    else if (strcmp(key, "RIGHT_ARROW") == 0) return MLV_KEYBOARD_RIGHT;
    else if (strcmp(key, "!") == 0) return MLV_KEYBOARD_EXCLAIM;
    else if (strcmp(key, "?") == 0) return MLV_KEYBOARD_COMMA;
    else if (strcmp(key, ";") == 0) return MLV_KEYBOARD_SEMICOLON;
    else if (strcmp(key, ":") == 0) return MLV_KEYBOARD_COLON;
    else if (strcmp(key, "=") == 0) return MLV_KEYBOARD_EQUALS;
    else if (strcmp(key, "*") == 0) return MLV_KEYBOARD_ASTERISK;
    else if (strcmp(key, "$") == 0) return MLV_KEYBOARD_DOLLAR;
    else if (strcmp(key, "NUMPAD_0") == 0) return MLV_KEYBOARD_KP0;
    else if (strcmp(key, "NUMPAD_1") == 0) return MLV_KEYBOARD_KP1;
    else if (strcmp(key, "NUMPAD_2") == 0) return MLV_KEYBOARD_KP2;
    else if (strcmp(key, "NUMPAD_3") == 0) return MLV_KEYBOARD_KP3;
    else if (strcmp(key, "NUMPAD_4") == 0) return MLV_KEYBOARD_KP4;
    else if (strcmp(key, "NUMPAD_5") == 0) return MLV_KEYBOARD_KP5;
    else if (strcmp(key, "NUMPAD_6") == 0) return MLV_KEYBOARD_KP6;
    else if (strcmp(key, "NUMPAD_7") == 0) return MLV_KEYBOARD_KP7;
    else if (strcmp(key, "NUMPAD_8") == 0) return MLV_KEYBOARD_KP8;
    else if (strcmp(key, "NUMPAD_9") == 0) return MLV_KEYBOARD_KP9;
    else if (strcmp(key, "NUMPAD_DIVIDE") == 0) return MLV_KEYBOARD_KP_DIVIDE;
    else if (strcmp(key, "NUMPAD_MULTIPLY") == 0) return MLV_KEYBOARD_KP_MULTIPLY;
    else if (strcmp(key, "NUMPAD_MINUS") == 0) return MLV_KEYBOARD_KP_MINUS;
    else if (strcmp(key, "NUMPAD_PLUS") == 0) return MLV_KEYBOARD_KP_PLUS;
    else if (strcmp(key, "NUMPAD_ENTER") == 0) return MLV_KEYBOARD_KP_ENTER;
    else if (strcmp(key, "NUMPAD_PERIOD") == 0) return MLV_KEYBOARD_KP_PERIOD;
    else if (strcmp(key, "F1") == 0) return MLV_KEYBOARD_F1;
    else if (strcmp(key, "F2") == 0) return MLV_KEYBOARD_F2;
    else if (strcmp(key, "F3") == 0) return MLV_KEYBOARD_F3;
    else if (strcmp(key, "F4") == 0) return MLV_KEYBOARD_F4;
    else if (strcmp(key, "F5") == 0) return MLV_KEYBOARD_F5;
    else if (strcmp(key, "F6") == 0) return MLV_KEYBOARD_F6;
    else if (strcmp(key, "F7") == 0) return MLV_KEYBOARD_F7;
    else if (strcmp(key, "F8") == 0) return MLV_KEYBOARD_F8;
    else if (strcmp(key, "F9") == 0) return MLV_KEYBOARD_F9;
    else if (strcmp(key, "F10") == 0) return MLV_KEYBOARD_F10;
    else if (strcmp(key, "F11") == 0) return MLV_KEYBOARD_F11;
    else if (strcmp(key, "F12") == 0) return MLV_KEYBOARD_F12;
    else return MLV_KEYBOARD_UNKNOWN;
}