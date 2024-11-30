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

void buttonAction(button_action_type action_type, char path[320], game *g, tetrimino tab[64], uint32_t *tab_size, double *scroll, boolean *game_started, boolean *game_paused, boolean *quit, page_components *page, button_action_type *lastPage, boolean *actualise, boolean *recreate)
{
    switch(action_type)
        {
            case BUTTON_ACTION_QUIT:
                *quit = TRUE;
                *game_started = FALSE;
                break;
            case BUTTON_ACTION_CREATE_MENU_COMPONENTS:
                if(*page != MENU_COMPONENTS)
                {
                    *page = MENU_COMPONENTS;
                    *game_started = FALSE;
                    *lastPage = BUTTON_ACTION_CREATE_MENU_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                    *scroll = 0;
                }
                break;
            case BUTTON_ACTION_CREATE_PLAY_COMPONENTS:
                if(*page != PLAY_COMPONENTS)
                {
                    *page = PLAY_COMPONENTS;
                    *game_started = FALSE;
                    *recreate = TRUE;
                    *actualise = TRUE;
                    *scroll = 0;
                }
                break;
            case BUTTON_ACTION_CREATE_LOAD_COMPONENTS:
                if(*page != LOAD_COMPONENTS)
                {
                    *page = LOAD_COMPONENTS;
                    *game_started = FALSE;
                    *recreate = TRUE;
                    *actualise = TRUE;
                    *scroll = 0;
                }
                break;
            case BUTTON_ACTION_CREATE_GAME_SURVIVAL_COMPONENTS:
            case BUTTON_ACTION_CREATE_GAME_MARATHON_COMPONENTS:
            case BUTTON_ACTION_CREATE_GAME_ULTRA_COMPONENTS:
            case BUTTON_ACTION_RESUME_GAME:
                if(*page != GAME_COMPONENTS)
                {
                    *page = GAME_COMPONENTS;
                    *lastPage = BUTTON_ACTION_RESUME_GAME;
                    *game_started = TRUE;
                    *game_paused = FALSE;
                    *recreate = TRUE;
                    *actualise = TRUE;
                    *tab_size = loadTetriminos(tab);
                    *scroll = 0;

                    if(action_type != BUTTON_ACTION_RESUME_GAME)
                    {
                        switch(action_type)
                        {
                            case BUTTON_ACTION_CREATE_GAME_SURVIVAL_COMPONENTS:
                                (*g).mode = GAMEMODE_SURVIVAL;
                                break;
                            case BUTTON_ACTION_CREATE_GAME_MARATHON_COMPONENTS:
                                (*g).mode = GAMEMODE_MARATHON;
                                break;
                            case BUTTON_ACTION_CREATE_GAME_ULTRA_COMPONENTS:
                                (*g).mode = GAMEMODE_ULTRA;
                                break;
                            default:
                                break;
                        }
                        newGame(g);
                    }
                }
                break;
            case BUTTON_ACTION_LOAD_GAME:
                if(*page != GAME_COMPONENTS)
                {
                    *page = GAME_COMPONENTS;
                    *lastPage = BUTTON_ACTION_RESUME_GAME;
                    *game_started = TRUE;
                    *game_paused = FALSE;
                    *recreate = TRUE;
                    *actualise = TRUE;
                    *tab_size = loadTetriminos(tab);
                    loadGame(g, path);
                    *scroll = 0;
                }
                break;
            case BUTTON_ACTION_PAUSE_GAME:
                if(*page != GAME_POPUP_COMPONENTS)
                {
                    *page = GAME_POPUP_COMPONENTS;
                    *lastPage = BUTTON_ACTION_PAUSE_GAME;
                    *game_started = TRUE;
                    *game_paused = TRUE;
                    *recreate = TRUE;
                    *actualise = TRUE;
                    *scroll = 0;
                }
                break;
            case BUTTON_ACTION_CREATE_SCOREBOARD_COMPONENTS:
                if(*page != SCOREBOARD_COMPONENTS)
                {
                    *page = SCOREBOARD_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                    *game_started = FALSE;
                    *scroll = 0;
                }
                break;
            case BUTTON_ACTION_CREATE_SETTINGS_KEYBOARD_COMPONENTS:
                if(*page != SETTINGS_KEYBOARD_COMPONENTS)
                {
                    *page = SETTINGS_KEYBOARD_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                    *game_started = FALSE;
                    *scroll = 0;
                }
                break;
            case BUTTON_ACTION_CREATE_SETTINGS_VIDEO_COMPONENTS:
                if(*page != SETTINGS_VIDEO_COMPONENTS)
                {
                    *page = SETTINGS_VIDEO_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                    *game_started = FALSE;
                    *scroll = 0;
                }
                break;
            case BUTTON_ACTION_CREATE_SETTINGS_GRAPHICS_COMPONENTS:
                if(*page != SETTINGS_GRAPHICS_COMPONENTS)
                {
                    *page = SETTINGS_GRAPHICS_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                    *game_started = FALSE;
                    *scroll = 0;
                }
                break;
            case BUTTON_ACTION_CREATE_SETTINGS_AUDIO_COMPONENTS:
                if(*page != SETTINGS_AUDIO_COMPONENTS)
                {
                    *page = SETTINGS_AUDIO_COMPONENTS;
                    *recreate = TRUE;
                    *actualise = TRUE;
                    *game_started = FALSE;
                    *scroll = 0;
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

    boolean game_started = FALSE, game_paused = FALSE, recreate = FALSE, actualise = FALSE, quit = FALSE, listen = FALSE, error = FALSE, grab = FALSE;
    int32_t x = 0, y = 0, oldy = 0, width, height;
    uint32_t i = 0, tab_size = 0, components_size = 0, buttons_size = 0, texts_size = 0, keys_size = 0, images_size = 0, tmp_time, tmp_top;
    double scroll = 0, oldscroll = 0;
    page_components page = MENU_COMPONENTS;
    button_action_type lastPage = BUTTON_ACTION_CREATE_MENU_COMPONENTS;
    settings set;
    struct timespec start, end;

    component components[COMPONENTS_MAX_SIZE];
    button_component buttons[COMPONENTS_MAX_SIZE];
    text_component texts[COMPONENTS_MAX_SIZE];
    key_component keys[COMPONENTS_MAX_SIZE];
    image_component images[COMPONENTS_MAX_SIZE];
    component cmp, clicked_cmp;
    button_component button;
    key_component key;
    style stylesheet, grab_stylesheet;

    tetrimino tab[64];
    game g;

    srand(time(NULL));

    width = MLV_get_desktop_width(),
    height = MLV_get_desktop_height();

    set = readSettings();
    grab_stylesheet = STYLESHEET_BODY(0, 0, height, width);

    MLV_create_full_screen_window("Tetris", "tetris", width, height);
    createComponents(page, lastPage, scroll, 0, 0, height, width, g, components, &components_size, buttons, &buttons_size, texts, &texts_size, keys, &keys_size, images, &images_size, set);
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
                                    case KEY_TAKE_FAST_DROP:
                                        set.keyboard_fast_drop = sym;
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
                        } else if(game_started == TRUE) {
                            if(game_paused == TRUE)
                            {
                                if(sym == set.keyboard_pause)
                                {
                                    game_paused = FALSE;
                                    page = GAME_COMPONENTS;
                                    lastPage = BUTTON_ACTION_RESUME_GAME;

                                    recreate = TRUE;
                                    actualise = TRUE;
                                }
                            } else {
                                if(sym == set.keyboard_pause)
                                {
                                    game_paused = TRUE;
                                    page = GAME_POPUP_COMPONENTS;
                                    lastPage = BUTTON_ACTION_PAUSE_GAME;

                                    recreate = TRUE;
                                    actualise = TRUE;
                                } else if(sym == set.keyboard_move_right) {
                                    moveRight(&g);
                                    actualise = TRUE;
                                } else if(sym == set.keyboard_move_left) {
                                    moveLeft(&g);
                                    actualise = TRUE;
                                } else if(sym == set.keyboard_turn_right) {
                                    turnRight(&g);
                                    actualise = TRUE;
                                } else if(sym == set.keyboard_turn_left) {
                                    turnLeft(&g);
                                    actualise = TRUE;
                                } else if(sym == set.keyboard_fast_drop) {
                                    fastDrop(&g);
                                }
                            }
                        }
                    }
                    break;
                case MLV_MOUSE_BUTTON:
                    if(state == MLV_PRESSED && mouse == MLV_BUTTON_LEFT)
                    {
                        clicked_cmp = lastHovered(0, 0, height, width, components, components_size, x, y);
                        if(clicked_cmp.type == COMPONENT_GRAB)
                        {
                            tmp_top = clicked_cmp.stylesheet.top;
                            clicked_cmp.stylesheet.top = 0;
                            clicked_cmp.hover_stylesheet.top = 0;
                            grab_stylesheet = autoLayout(0, 0, height, width, components, components_size, clicked_cmp);
                            clicked_cmp.stylesheet.top = tmp_top;
                            clicked_cmp.hover_stylesheet.top = tmp_top;
                            oldy = y;
                            grab = TRUE;
                        } else {
                            grab = FALSE;
                        }
                    }
                    if(state == MLV_RELEASED && mouse == MLV_BUTTON_LEFT)
                    {
                        grab = FALSE;
                        if(listen == FALSE && error == FALSE) {
                            cmp = lastHovered(0, 0, height, width, components, components_size, x, y);
                            if(cmp.id == clicked_cmp.id) {
                                switch(cmp.type)
                                {
                                    case COMPONENT_BUTTON:
                                        button = componentToButtonComponent(cmp, buttons, buttons_size);
                                        buttonAction(button.action_type, button.path, &g, tab, &tab_size, &scroll, &game_started, &game_paused, &quit, &page, &lastPage, &actualise, &recreate);
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

        if(grab == TRUE)
        {
            oldscroll = scroll;
            scroll = (((grab_stylesheet.height*100.)/(clicked_cmp.stylesheet.height)*(clicked_cmp.stylesheet.top/100.))+(y-oldy))/(((grab_stylesheet.height*100.)/(clicked_cmp.stylesheet.height)*((100.-clicked_cmp.stylesheet.height)/100.)));

            if(scroll > 1) scroll = 1;
            else if(scroll < 0) scroll = 0;

            if(scroll != oldscroll)
            {
                recreate = TRUE;
                actualise = TRUE;
            }
        }

        if(game_started == TRUE && game_paused == FALSE)
        {
            tmp_time = g.time;
            g.time += (10000/set.video_fps);
            if(g.time/10000 != tmp_time/10000)
            {
                recreate = TRUE;
                actualise = TRUE;
            }
            if(tick(&g, tab, tab_size, 1000/set.video_fps, &actualise) == TRUE)
            {
                /* Finir le jeu en conséquence */
                game_started = FALSE;
                page = MENU_COMPONENTS;
                recreate = TRUE;
                actualise = TRUE;
            }
        }

        actualise |= hover(set, 0, 0, height, width, components, components_size, x, y, 1000/set.video_fps);
        if(recreate == TRUE) {
            createComponents(page, lastPage, scroll, 0, 0, height, width, g, components, &components_size, buttons, &buttons_size, texts, &texts_size, keys, &keys_size, images, &images_size, set);
            MLV_flush_event_queue();
            recreate = FALSE;
        }
        if(actualise == TRUE)
        {
            drawComponents(set, 0, 0, height, width, components, components_size, g, texts, texts_size, keys, keys_size, images, images_size);
            MLV_actualise_window();
            actualise = FALSE;
        }
        clock_gettime(CLOCK_REALTIME, &end);
        if((1000/set.video_fps)-(((end.tv_sec*1000)+(end.tv_nsec/1000000))-((start.tv_sec*1000)+(start.tv_nsec/1000000)))>0) MLV_wait_milliseconds((1000/set.video_fps)-(((end.tv_sec*1000)+(end.tv_nsec/1000000))-((start.tv_sec*1000)+(start.tv_nsec/1000000))));
        
    }
    MLV_free_window();
    
    exit(EXIT_SUCCESS);
}