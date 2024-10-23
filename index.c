#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

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



int main(int argc, char *argv[])
{
    MLV_Event event = MLV_NONE;
    MLV_Keyboard_button sym = MLV_KEYBOARD_NONE;
    MLV_Keyboard_modifier mod = MLV_KEYBOARD_KMOD_NONE;
    MLV_Button_state state;
    int x = 0, y = 0, quit = 0, width = 640, height = 480;

    MLV_create_window("Tetris", "tetris", width, height);
    menu(width, height);

    MLV_actualise_window();
    do
    {
        event = MLV_get_event( 
            &sym, &mod, NULL,
            NULL, NULL, &x,
            &y, NULL, &state
        );
        switch(event)
        {
            case MLV_NONE:
                break;
            case MLV_KEY:
                if(state == MLV_PRESSED) {

                }
                break;
            case MLV_MOUSE_BUTTON: 
                if(state == MLV_PRESSED) {

                }
                break;
            case MLV_MOUSE_MOTION:
                break;
            default:
                break;
        }
    } while(1);
    MLV_free_window();
    
    exit(EXIT_SUCCESS);
}