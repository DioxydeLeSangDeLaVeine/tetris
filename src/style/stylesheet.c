#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <string.h>
#include "../../modules/ui/ui.h"
#include "stylesheet.h"

style getStylesheet(stylesheet_type type, boolean is_hovered)
{
    style stylesheet;
    stylesheet.top = 0;
    stylesheet.left = 0;
    stylesheet.width = 0;
    stylesheet.height = 0;

    switch(type)
    {
        case STYLESHEET_SIDEBAR_BUTTONS: case STYLESHEET_SIDEBAR_QUIT_BUTTON:
            switch(type)
            {
                case STYLESHEET_SIDEBAR_BUTTONS:
                    if(is_hovered == TRUE)
                    {
                        stylesheet.background_color.r = 255;
                        stylesheet.background_color.g = 70;
                        stylesheet.background_color.b = 84;
                        stylesheet.background_color.a = 255;
                    } else {
                        stylesheet.background_color.r = 29;
                        stylesheet.background_color.g = 33;
                        stylesheet.background_color.b = 46;
                        stylesheet.background_color.a = 255;
                    }
                    break;
                case STYLESHEET_SIDEBAR_QUIT_BUTTON:
                    stylesheet.background_color.r = 255;
                    stylesheet.background_color.g = 70;
                    stylesheet.background_color.b = 84;
                    stylesheet.background_color.a = 255;
                    break;
                default:
                    break;
            }
            stylesheet.color.r = 255;
            stylesheet.color.g = 255;
            stylesheet.color.b = 255;
            stylesheet.color.a = 255;
            strcpy(stylesheet.font_family, FONT_POPPINS_MEDIUM);
            stylesheet.font_size = 18;
            stylesheet.border_radius = 16;
            break;
        case STYLESHEET_SIDEBAR:
            stylesheet.background_color.r = 19;
            stylesheet.background_color.g = 23;
            stylesheet.background_color.b = 34;
            stylesheet.background_color.a = 255;
            stylesheet.color.r = 0;
            stylesheet.color.g = 0;
            stylesheet.color.b = 0;
            stylesheet.color.a = 0;
            strcpy(stylesheet.font_family, "");
            stylesheet.font_size = 0;
            stylesheet.border_radius = 32;
            break;
        case STYLESHEET_BODY:
            stylesheet.background_color.r = 10;
            stylesheet.background_color.g = 14;
            stylesheet.background_color.b = 22;
            stylesheet.background_color.a = 255;
            stylesheet.color.r = 0;
            stylesheet.color.g = 0;
            stylesheet.color.b = 0;
            stylesheet.color.a = 0;
            strcpy(stylesheet.font_family, "");
            stylesheet.font_size = 0;
            stylesheet.border_radius = 0;
            break;
        default:
            break;
    }
    return stylesheet;
}

void createMenuComponents(int height, int width, component components[], int *components_size, button_component buttons[], int *buttons_size)
{
    style stylesheet, hover_stylesheet;
    (*components_size) = 0;
    (*buttons_size) = 0;

    stylesheet = getStylesheet(STYLESHEET_BODY, FALSE);
    MLV_clear_window(MLV_rgba(stylesheet.background_color.r, stylesheet.background_color.g, stylesheet.background_color.b, stylesheet.background_color.a));
    createFrame(components, components_size, stylesheet, FALSE, stylesheet, 0, 0, 0, height, width);
    stylesheet = getStylesheet(STYLESHEET_SIDEBAR, FALSE);
    createFrame(components, components_size, stylesheet, FALSE, stylesheet, 0, 20, 20, height-40, 300);
    stylesheet = getStylesheet(STYLESHEET_SIDEBAR_QUIT_BUTTON, FALSE);
    createButton(components, components_size, buttons, buttons_size, "Quitter", stylesheet, FALSE, stylesheet, 0, BUTTON_ACTION_QUIT, height-40-65, 40, 65, 300-40);
    stylesheet = getStylesheet(STYLESHEET_SIDEBAR_BUTTONS, FALSE);
    hover_stylesheet = getStylesheet(STYLESHEET_SIDEBAR_BUTTONS, TRUE);
    createButton(components, components_size, buttons, buttons_size, "Jouer", stylesheet, TRUE, hover_stylesheet, 100, BUTTON_ACTION_NONE, (65+20)*0+40, 40, 65, 300-40);
    createButton(components, components_size, buttons, buttons_size, "Paramètres", stylesheet, TRUE, hover_stylesheet, 100, BUTTON_ACTION_NONE, (65+20)*1+40, 40, 65, 300-40);
    createButton(components, components_size, buttons, buttons_size, "Scoreboard", stylesheet, TRUE, hover_stylesheet, 100, BUTTON_ACTION_NONE, (65+20)*2+40, 40, 65, 300-40);
}