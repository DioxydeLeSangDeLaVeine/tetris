#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <X11/Xlib.h>
#include <X11/cursorfont.h>
#include <time.h>

#include "./modules/ui/ui.h"
#include "./src/style/stylesheet.h"

/**
 * Every functions in this project need to contain
 * at the first line, a comment like this one,
 * containing the @param, and @returns.
 *
 * Example :
 * @param {YOUR_SUPER_DUPER_COOL_TYPE} VARIABLE_NAME
 * ...
 * @returns {YOUR_SUPER_DUPER_COOL_TYPE}
 */

/**
 * Rules :
 * 0. ( Yeah 0 because we are developer ) ONLY ENGLISH.
 * 1. snake_case for variables names.
 * 2. camelCase for functions names.
 * 3. No spacing inside parentheses.
 * 4. Spacing after parentheses, after commas,
 * between operands.
 * 5. Braces on a new line.
 * 6. Every colors used, need to be described in RGBA.
 * 7. If you have a switch case without a break and it's
 * not an error, put "fall-through" in a comment at the
 * end of the case.
 */

component lastHovered(int32_t top, int32_t left, int32_t height, int32_t width, component components[], int components_size, int x, int y)
{
    int i;
    component cmp;
    cmp.id = 0;
    for(i = 0; i<components_size; i++)
    {
        if(idboxComponent(styleReal(top, left, height, width, components, components_size, components[i]), x, y) == TRUE)
        {
            if(!components[i].ignore_hover) cmp = components[i];
        }
    }
    return cmp;
}

boolean hover(int32_t top, int32_t left, int32_t height, int32_t width, component components[], int components_size, int x, int y, int fps)
{
    int i;
    component cmp;
    boolean change = FALSE;

    cmp = lastHovered(top, left, height, width, components, components_size, x, y);

    for(i = 0; i<components_size; i++) {
        if(components[i].id != cmp.id) {
            if(components[i].is_hoverable == TRUE) {
                if(components[i].is_hovered != FALSE) {
                    change = TRUE;
                    components[i].is_hovered = FALSE;
                }
                if(components[i].__transition != 0) {
                    change = TRUE;
                    if(components[i].transition_duration==0) components[i].__transition = 0;
                    else {
                        if(components[i].__transition-(float)fps/components[i].transition_duration < 0) components[i].__transition = 0;
                        else components[i].__transition-=(float)fps/components[i].transition_duration;
                    }
                }
            }
        } else {
            if(components[i].is_hoverable == TRUE) {
                if(components[i].is_hovered != TRUE) {
                    change = TRUE;
                    components[i].is_hovered = TRUE;
                }
                if(components[i].__transition != 1) {
                    change = TRUE;
                    if(components[i].transition_duration==0) components[i].__transition = 1;
                    else {
                        if(components[i].__transition+(float)fps/components[i].transition_duration > 1) components[i].__transition = 1;
                        else components[i].__transition+=(float)fps/components[i].transition_duration;
                    }
                }
            }
        }
    }
    return change;
}

void takeAction(button_action_type action_type, boolean *quit, page_components *page, boolean *actualise, boolean *recreate) {
    switch(action_type)
        {
            case BUTTON_ACTION_QUIT:
                *quit = TRUE;
                break;
            case BUTTON_ACTION_CREATE_MENU_COMPONENTS:
                if(*page != MENU_COMPONENTS) {
                    *page = MENU_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                }
                break;
            case BUTTON_ACTION_CREATE_SETTINGS_KEYBOARD_COMPONENTS:
                if(*page != SETTINGS_KEYBOARD_COMPONENTS) {
                    *page = SETTINGS_KEYBOARD_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                }
                break;
            case BUTTON_ACTION_CREATE_SETTINGS_VIDEO_COMPONENTS:
                if(*page != SETTINGS_VIDEO_COMPONENTS) {
                    *page = SETTINGS_VIDEO_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                }
                break;
            case BUTTON_ACTION_CREATE_SETTINGS_GRAPHICS_COMPONENTS:
                if(*page != SETTINGS_GRAPHICS_COMPONENTS) {
                    *page = SETTINGS_GRAPHICS_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                }
                break;
            case BUTTON_ACTION_CREATE_SETTINGS_AUDIO_COMPONENTS:
                if(*page != SETTINGS_AUDIO_COMPONENTS) {
                    *page = SETTINGS_AUDIO_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                }
                break;
            default:
                break;
        }
}

void getKeyFromMLV(MLV_Keyboard_button sym, MLV_Keyboard_modifier mod, char response[]) {
    (void)mod;
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

int main()
{
    MLV_Event event = 0;
    MLV_Keyboard_button sym = 0;
    MLV_Keyboard_modifier mod = 0;
    MLV_Mouse_button mouse = 0;
    MLV_Button_state state = 0;

    Display *display = XOpenDisplay(NULL);
    Window window;
    Cursor current_cursor = 0, cursor_default, cursor_pointer;

    boolean recreate = FALSE, actualise = FALSE, quit = FALSE, listen = FALSE;
    int32_t x = 0, y = 0,
    width = MLV_get_desktop_width(),
    height = MLV_get_desktop_height();
    uint32_t fps = 1000/60, i = 0, components_size = 0, buttons_size = 0, texts_size = 0, keys_size = 0;
    page_components page = MENU_COMPONENTS;

    struct timespec start, end;

    component components[COMPONENTS_MAX_SIZE];
    button_component buttons[COMPONENTS_MAX_SIZE];
    text_component texts[COMPONENTS_MAX_SIZE];
    key_component keys[COMPONENTS_MAX_SIZE];

    component cmp;
    button_component button;
    key_component key;

    style stylesheet;

    MLV_create_full_screen_window("Tetris", "tetris", width, height);

    if(display != NULL) {
        window = DefaultRootWindow(display);
        cursor_default = XCreateFontCursor(display, XC_arrow);
        cursor_pointer = XCreateFontCursor(display, XC_hand2);
        XDefineCursor(display, window, cursor_default);
        current_cursor = cursor_default;
        XFlush(display);
    }
    createComponents(page, 0, 0, height, width, components, &components_size, buttons, &buttons_size, texts, &texts_size, keys, &keys_size);
    drawComponents(0, 0, height, width, components, components_size, texts, texts_size, keys, keys_size);
    MLV_actualise_window();

    while(quit != TRUE)
    {
        actualise = 0;
        clock_gettime(CLOCK_REALTIME, &start);
        do
        {
            event = MLV_get_event( 
                &sym, &mod, NULL,
                NULL, NULL, &x,
                &y, &mouse, &state
            );
            switch(event)
            {
                case MLV_NONE:
                    break;
                case MLV_KEY:
                    if(state == MLV_PRESSED)
                    {
                        if(listen == TRUE) {
                            getKeyFromMLV(sym, mod, key.content);
                            if(strcmp(key.content, "") != 0) {
                                for(i = 0; i<keys_size; i++) {
                                    if(keys[i].take_type == key.take_type) {
                                        strcpy(keys[i].content, key.content);
                                    }
                                }
                                components_size-=2;
                                texts_size-=1;
                                listen = FALSE;
                                actualise = TRUE;
                            }
                        }
                    }
                    break;
                case MLV_MOUSE_BUTTON:
                    if(state == MLV_PRESSED && mouse == MLV_BUTTON_LEFT)
                    {
                        if(listen != TRUE) {
                            cmp = lastHovered(0, 0, height, width, components, components_size, x, y);
                            switch(cmp.type)
                            {
                                case COMPONENT_BUTTON:
                                    button = componentToButtonComponent(cmp, buttons, buttons_size);
                                    takeAction(button.action_type, &quit, &page, &actualise, &recreate);
                                    break;
                                case COMPONENT_KEY:
                                    key = componentToKeyComponent(cmp, keys, keys_size);
                                    stylesheet = STYLESHEET_HIDE(0,0,height,width);
                                    createFrame(components, &components_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0);
                                    stylesheet = STYLESHEET_HIDE_TEXT(0,0,height,width);
                                    createText(components, &components_size, texts, &texts_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0, "Appuyez sur une touche de votre clavier.");
                                    listen = TRUE;
                                    actualise = TRUE;
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                    break;
                case MLV_MOUSE_MOTION:
                    break;
                default:
                    break;
            }
        } while((event != MLV_NONE)&&!quit);
        clock_gettime(CLOCK_REALTIME, &end);
        if((fps)-((end.tv_nsec)/1000000-(start.tv_nsec)/1000000)>0) MLV_wait_milliseconds((fps)-((end.tv_nsec)/1000000-(start.tv_nsec)/1000000));

        actualise |= hover(0, 0, height, width, components, components_size, x, y, fps);
        if(display != NULL) {
            cmp = lastHovered(0, 0, height, width, components, components_size, x, y);
            if(cmp.type == COMPONENT_BUTTON || cmp.type == COMPONENT_KEY)
            {
                if(current_cursor != cursor_pointer) {
                    XDefineCursor(display, window, cursor_pointer);
                    current_cursor = cursor_pointer;
                    XFlush(display);
                }
            } else {
                if(current_cursor != cursor_default) {
                    XDefineCursor(display, window, cursor_default);
                    current_cursor = cursor_default;
                    XFlush(display);
                }
            }
        }
        if(recreate == TRUE) {
            createComponents(page, 0, 0, height, width, components, &components_size, buttons, &buttons_size, texts, &texts_size, keys, &keys_size);
            recreate = FALSE;
            listen = FALSE;
        }
        if(actualise == TRUE)
        {
            drawComponents(0, 0, height, width, components, components_size, texts, texts_size, keys, keys_size);
            MLV_actualise_window();
            actualise = FALSE;
        }
    }
    if(display != NULL) {
        XFreeCursor(display, cursor_default);
        XFreeCursor(display, cursor_pointer);
        XCloseDisplay(display);
    }
    MLV_free_window();
    
    exit(EXIT_SUCCESS);
}