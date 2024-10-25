#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
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

button_component lastHovered(component components[], button_component buttons[], int buttons_size, int x, int y) {
    int i;
    button_component button;
    button.id = 0;
    button.action_type = BUTTON_ACTION_NONE;
    for(i = 0; i<buttons_size; i++) {
        if(idboxComponent(components[buttons[i].id-1], x, y) == TRUE) {
            button = buttons[i];
        }
    }
    return button;
}
boolean hover(component components[], int components_size, int x, int y) {
    int i;
    boolean change = FALSE;

    for(i = 0; i<components_size; i++) {
        if(components[i].is_hoverable == TRUE) {
            if(idboxComponent(components[i], x, y) == TRUE) {
                if(components[i].is_hovered != TRUE) change = TRUE;
                components[i].is_hovered = TRUE;
            } else {
                if(components[i].is_hovered != FALSE) change = TRUE;
                components[i].is_hovered = FALSE;
            }
        }
    }
    return change;
}

int main()
{
    MLV_Event event = MLV_NONE;
    MLV_Keyboard_button sym;
    MLV_Keyboard_modifier mod;
    MLV_Mouse_button mouse;
    MLV_Button_state state;
    int x = 0, y = 0, actualise = FALSE, quit = FALSE, components_size = 0, buttons_size = 0,
    width = MLV_get_desktop_width(),
    height = MLV_get_desktop_height();
    struct timespec start, end;

    component components[COMPONENTS_MAX_SIZE];
    button_component buttons[COMPONENTS_MAX_SIZE];
    button_component button;

    MLV_create_full_screen_window("Tetris", "tetris", width, height);
    
    createMenuComponents(height, width, components, &components_size, buttons, &buttons_size);
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
                        button = lastHovered(components, buttons, buttons_size, x, y);
                        if(button.action_type == BUTTON_ACTION_QUIT) {
                            quit = 1;
                        }
                    }
                    break;
                case MLV_MOUSE_MOTION:
                    actualise |= hover(components, components_size, x, y);
                    break;
                default:
                    break;
            }
        } while(event != MLV_NONE);
        clock_gettime(CLOCK_REALTIME, &end);
        MLV_wait_milliseconds((1000/60)-(end.tv_sec/10-start.tv_sec/10));
        if(actualise == TRUE) {
            drawComponents(components, components_size);
            MLV_actualise_window();
            actualise = FALSE;
        }
    }
    MLV_free_window();
    
    exit(EXIT_SUCCESS);
}