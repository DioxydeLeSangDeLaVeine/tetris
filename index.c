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

component lastHovered(component components[], int components_size, int x, int y)
{
    int i;
    component cmp;
    cmp.id = 0;
    for(i = 0; i<components_size; i++)
    {
        if(idboxComponent(components[i], x, y) == TRUE)
        {
            cmp = components[i];
        }
    }
    return cmp;
}

button_component componentToButtonComponent(component component, button_component buttons[], int buttons_size) {
    int i;
    button_component button;
    button.id = 0;
    button.action_type = BUTTON_ACTION_UNDEFINED;

    for(i = 0; i<buttons_size; i++)
    {
        if(component.id == buttons[i].id)
        {
            button = buttons[i];
        }
    }
    return button;
}

boolean hover(component components[], int components_size, int x, int y, int fps)
{
    int i;
    component cmp;
    boolean change = FALSE;

    cmp = lastHovered(components, components_size, x, y);

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

    int x = 0, y = 0, fps = 1000/256, recreate = FALSE, actualise = FALSE, quit = FALSE, components_size = 0, buttons_size = 0,
    width = MLV_get_desktop_width(),
    height = MLV_get_desktop_height();
    page_components page = MENU_COMPONENTS;

    struct timespec start, end;

    component components[COMPONENTS_MAX_SIZE];
    button_component buttons[COMPONENTS_MAX_SIZE];
    button_component button;

    MLV_create_full_screen_window("Tetris", "tetris", width, height);

    if(display != NULL) {
        window = DefaultRootWindow(display);
        cursor_default = XCreateFontCursor(display, XC_arrow);
        cursor_pointer = XCreateFontCursor(display, XC_hand2);
        XDefineCursor(display, window, cursor_default);
        current_cursor = cursor_default;
        XFlush(display);
    }
    createMenuComponents(0, 0, height, width, components, &components_size, buttons, &buttons_size);
    drawComponents(components, components_size);
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
                        
                    }
                    break;
                case MLV_MOUSE_BUTTON:
                    if(state == MLV_PRESSED && mouse == MLV_BUTTON_LEFT)
                    {
                        button = componentToButtonComponent(lastHovered(components, components_size, x, y), buttons, buttons_size);
                        switch(button.action_type)
                        {
                            case BUTTON_ACTION_QUIT:
                                quit = TRUE;
                                break;
                            case BUTTON_ACTION_CREATE_MENU_COMPONENTS:
                                page = MENU_COMPONENTS;
                                recreate = TRUE;
                                actualise = TRUE;
                                break;
                            case BUTTON_ACTION_CREATE_SETTINGS_COMPONENTS:
                                page = SETTINGS_COMPONENTS;
                                recreate = TRUE;
                                actualise = TRUE;
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case MLV_MOUSE_MOTION:
                    break;
                default:
                    break;
            }
        } while(event != MLV_NONE);
        clock_gettime(CLOCK_REALTIME, &end);
        if((fps)-((end.tv_nsec)/1000000-(start.tv_nsec)/1000000)>0) MLV_wait_milliseconds((fps)-((end.tv_nsec)/1000000-(start.tv_nsec)/1000000));

        actualise |= hover(components, components_size, x, y, fps);
        if(display != NULL) {
            button = componentToButtonComponent(lastHovered(components, components_size, x, y), buttons, buttons_size);
            if(button.action_type != BUTTON_ACTION_UNDEFINED)
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
            switch(page) {
                case SETTINGS_COMPONENTS:
                    createSettingsComponents(0, 0, height, width, components, &components_size, buttons, &buttons_size);
                    break;
                default:
                    createMenuComponents(0, 0, height, width, components, &components_size, buttons, &buttons_size);
                    break;
            }
            recreate = FALSE;
        }
        if(actualise == TRUE)
        {
            drawComponents(components, components_size);
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