#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <math.h>

#include "./modules/ui/ui.h"



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



ButtonComponent buttonHovered(ButtonComponent components[], int components_size, int x, int y)
{
    int i = 0, found = 0, dx, dy;
    ButtonComponent button;

    while(i < components_size && found == 0)
    {
        button = components[i];

        if(button.top <= y
        && button.top + button.height >= y
        && button.left + button.radius <= x
        && button.left + button.width - (2 * button.radius) >= x) found = 1;
        if(button.top + button.radius <= y
        && button.top + button.height - (2 * button.radius) >= y
        && button.left <= x
        && button.left + button.width >= x) found = 1;

        dx = x - (button.left+button.radius);
        dy = y - (button.top+button.radius-1);
        if((dx*dx+dy*dy)<=(button.radius*button.radius)) found = 1;
        dx = x - (button.left+button.radius);
        dy = y - (button.top+button.height-button.radius);
        if((dx*dx+dy*dy)<=(button.radius*button.radius)) found = 1;
        dx = x - (button.left+button.width-button.radius-1);
        dy = y - (button.top+button.radius-1);
        if((dx*dx+dy*dy)<=(button.radius*button.radius)) found = 1;
        dx = x - (button.left+button.width-button.radius-1);
        dy = y - (button.top+button.height-button.radius);
        if((dx*dx+dy*dy)<=(button.radius*button.radius)) found = 1;

        i++;
    }
    if(!found) button.action_type = -1;
    return button;
}

int main()
{
    MLV_Event event = MLV_NONE;
    MLV_Keyboard_button sym = MLV_KEYBOARD_NONE;
    MLV_Keyboard_modifier mod = MLV_KEYBOARD_KMOD_NONE;
    MLV_Mouse_button mouse;
    MLV_Button_state state;
    ButtonComponent components[100];
    int x = 0, y = 0, quit = 0, width = MLV_get_desktop_width(), height = MLV_get_desktop_height(), components_size = 0;

    MLV_create_full_screen_window("Tetris", "tetris", width, height);
    components_size = menu(width, height, components);

    MLV_actualise_window();
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
                    ButtonComponent button = buttonHovered(components, components_size, x, y);
                    switch(button.action_type)
                    {
                        case 0:
                            quit = 1;
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
    } while(!quit);
    MLV_free_window();
    
    exit(EXIT_SUCCESS);
}