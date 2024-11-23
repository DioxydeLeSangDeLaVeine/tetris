#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <time.h>

#include "./modules/ui/ui.h"
#include "./modules/util/util.h"
#include "./src/style/stylesheet.h"
#include "./modules/back/game.h"

/**
 * Every functions in this project need to contain
 * upside, a comment like this one,
 * containing every @param, and @returns.
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
        if(idboxComponent(autoLayout(top, left, height, width, components, components_size, components[i]), x, y) == TRUE)
        {
            if(!components[i].ignore_hover) cmp = components[i];
        }
    }
    return cmp;
}

boolean hover(settings set, int32_t top, int32_t left, int32_t height, int32_t width, component components[], int components_size, int x, int y, int fps)
{
    int i;
    component cmp;
    boolean change = FALSE;
    cmp = lastHovered(top, left, height, width, components, components_size, x, y);

    for(i = 0; i<components_size; i++)
    {
        if(components[i].id != cmp.id)
        {
            if(components[i].is_hoverable == TRUE)
            {
                if(components[i].is_hovered != FALSE)
                {
                    change = TRUE;
                    components[i].is_hovered = FALSE;
                }
                if(components[i].__transition != 0)
                {
                    change = TRUE;
                    if(set.video_animations == FALSE) components[i].__transition = 0;
                    else {
                        if(components[i].transition_duration==0) components[i].__transition = 0;
                        else {
                            if(components[i].__transition-(float)fps/components[i].transition_duration < 0) components[i].__transition = 0;
                            else components[i].__transition-=(float)fps/components[i].transition_duration;
                        }
                    }
                }
            }
        } else {
            if(components[i].is_hoverable == TRUE)
            {
                if(components[i].is_hovered != TRUE)
                {
                    change = TRUE;
                    components[i].is_hovered = TRUE;
                }
                if(components[i].__transition != 1)
                {
                    change = TRUE;
                    if(set.video_animations == FALSE) components[i].__transition = 1;
                    else {
                        if(components[i].transition_duration==0) components[i].__transition = 1;
                        else {
                            if(components[i].__transition+(float)fps/components[i].transition_duration > 1) components[i].__transition = 1;
                            else components[i].__transition+=(float)fps/components[i].transition_duration;
                        }
                    }
                }
            }
        }
    }
    return change;
}

void buttonAction(button_action_type action_type, boolean *quit, page_components *page, boolean *actualise, boolean *recreate)
{
    switch(action_type)
        {
            case BUTTON_ACTION_QUIT:
                *quit = TRUE;
                break;
            case BUTTON_ACTION_CREATE_MENU_COMPONENTS:
                if(*page != MENU_COMPONENTS)
                {
                    *page = MENU_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                }
                break;
            case BUTTON_ACTION_CREATE_PLAY_COMPONENTS:
                if(*page != PLAY_COMPONENTS)
                {
                    *page = PLAY_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                }
                break;
            case BUTTON_ACTION_CREATE_GAME_SURVIVAL_COMPONENTS:
            case BUTTON_ACTION_CREATE_GAME_MARATHON_COMPONENTS:
            case BUTTON_ACTION_CREATE_GAME_ULTRA_COMPONENTS:
                if(*page != GAME_COMPONENTS)
                {
                    *page = GAME_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                }
                break;
            case BUTTON_ACTION_CREATE_SCOREBOARD_COMPONENTS:
                if(*page != SCOREBOARD_COMPONENTS)
                {
                    *page = SCOREBOARD_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                }
                break;
            case BUTTON_ACTION_CREATE_SETTINGS_KEYBOARD_COMPONENTS:
                if(*page != SETTINGS_KEYBOARD_COMPONENTS)
                {
                    *page = SETTINGS_KEYBOARD_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                }
                break;
            case BUTTON_ACTION_CREATE_SETTINGS_VIDEO_COMPONENTS:
                if(*page != SETTINGS_VIDEO_COMPONENTS)
                {
                    *page = SETTINGS_VIDEO_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                }
                break;
            case BUTTON_ACTION_CREATE_SETTINGS_GRAPHICS_COMPONENTS:
                if(*page != SETTINGS_GRAPHICS_COMPONENTS)
                {
                    *page = SETTINGS_GRAPHICS_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                }
                break;
            case BUTTON_ACTION_CREATE_SETTINGS_AUDIO_COMPONENTS:
                if(*page != SETTINGS_AUDIO_COMPONENTS)
                {
                    *page = SETTINGS_AUDIO_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                }
                break;
            default:
                break;
        }
}

int main()
{
    MLV_Event event = 0;
    MLV_Keyboard_button sym = 0;
    MLV_Keyboard_modifier mod = 0;
    MLV_Mouse_button mouse = 0;
    MLV_Button_state state = 0;

    boolean recreate = FALSE, actualise = FALSE, quit = FALSE, listen = FALSE, error = FALSE;
    int32_t x = 0, y = 0, width, height;
    uint32_t i = 0, clicked_cmp_id = 0, components_size = 0, buttons_size = 0, texts_size = 0, keys_size = 0, images_size = 0;
    page_components page = MENU_COMPONENTS;
    settings set;
    struct timespec start, end;

    component components[COMPONENTS_MAX_SIZE];
    button_component buttons[COMPONENTS_MAX_SIZE];
    text_component texts[COMPONENTS_MAX_SIZE];
    key_component keys[COMPONENTS_MAX_SIZE];
    image_component images[COMPONENTS_MAX_SIZE];
    component cmp;
    button_component button;
    key_component key;
    style stylesheet;

    game g;

    width = MLV_get_desktop_width(),
    height = MLV_get_desktop_height();

    resetGrid(&g);
    set = readSettings();

    MLV_create_full_screen_window("Tetris", "tetris", width, height);
    createComponents(page, 0, 0, height, width, components, &components_size, buttons, &buttons_size, texts, &texts_size, keys, &keys_size, images, &images_size, set);
    drawComponents(set, 0, 0, height, width, components, components_size, g, texts, texts_size, keys, keys_size, images, images_size);
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
                    if(state == MLV_RELEASED)
                    {
                        if(listen == TRUE) {
                            getKeyFromMLV(sym, key.content);
                            if(strcmp(key.content, "") != 0) {
                                for(i = 0; i<keys_size; i++) {
                                    if(keys[i].take_type == key.take_type) {
                                        strcpy(keys[i].content, key.content);
                                    }
                                }
                                switch(key.take_type) {
                                    case KEY_TAKE_MOVE_LEFT:
                                        set.keyboard_move_left = sym;
                                        break;
                                    case KEY_TAKE_MOVE_RIGHT:
                                        set.keyboard_move_right = sym;
                                        break;
                                    case KEY_TAKE_TURN_LEFT:
                                        set.keyboard_turn_left = sym;
                                        break;
                                    case KEY_TAKE_TURN_RIGHT:
                                        set.keyboard_turn_right = sym;
                                        break;
                                    case KEY_TAKE_CONFIRM:
                                        set.keyboard_confirm = sym;
                                        break;
                                    case KEY_TAKE_PAUSE:
                                        set.keyboard_pause = sym;
                                        break;
                                    default:
                                        break;
                                }
                                writeSettings(set);
                                components_size-=2;
                                texts_size-=1;
                                listen = FALSE;
                                actualise = TRUE;
                            }
                        } else if(error == TRUE) {
                            components_size-=2;
                            error = FALSE;
                            actualise = TRUE;
                        }
                    }
                    break;
                case MLV_MOUSE_BUTTON:
                    if(state == MLV_PRESSED && mouse == MLV_BUTTON_LEFT) {
                        clicked_cmp_id = lastHovered(0, 0, height, width, components, components_size, x, y).id;
                    }
                    if(state == MLV_RELEASED && mouse == MLV_BUTTON_LEFT)
                    {
                        if(listen == FALSE && error == FALSE) {
                            cmp = lastHovered(0, 0, height, width, components, components_size, x, y);
                            if(cmp.id == clicked_cmp_id) {
                                switch(cmp.type)
                                {
                                    case COMPONENT_BUTTON:
                                        button = componentToButtonComponent(cmp, buttons, buttons_size);
                                        if(button.action_type == BUTTON_ACTION_NONE) {
                                            stylesheet = STYLESHEET_HIDE(0,0,height,width);
                                            createFrame(components, &components_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0);
                                            stylesheet = STYLESHEET_HIDE_TEXT(0,0,height,width);
                                            createText(components, &components_size, texts, &texts_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0, "Error 404 : Not found");
                                            error = TRUE;
                                            actualise = TRUE;
                                        } else {
                                            buttonAction(button.action_type, &quit, &page, &actualise, &recreate);
                                        }
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
                        } else if(error == TRUE) {
                            components_size-=2;
                            error = FALSE;
                            actualise = TRUE;
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
        if((1000/set.video_fps)-((end.tv_nsec)/1000000-(start.tv_nsec)/1000000)>0) MLV_wait_milliseconds((1000/set.video_fps)-((end.tv_nsec)/1000000-(start.tv_nsec)/1000000));

        actualise |= hover(set, 0, 0, height, width, components, components_size, x, y, 1000/set.video_fps);
        if(recreate == TRUE) {
            createComponents(page, 0, 0, height, width, components, &components_size, buttons, &buttons_size, texts, &texts_size, keys, &keys_size, images, &images_size, set);
            MLV_flush_event_queue();
            recreate = FALSE;
            if(listen == TRUE) {
                components_size-=2;
                texts_size-=1;
                listen = FALSE;
            }
        }
        if(actualise == TRUE)
        {
            drawComponents(set, 0, 0, height, width, components, components_size, g, texts, texts_size, keys, keys_size, images, images_size);
            MLV_actualise_window();
            actualise = FALSE;
        }
    }
    MLV_free_window();
    
    exit(EXIT_SUCCESS);
}