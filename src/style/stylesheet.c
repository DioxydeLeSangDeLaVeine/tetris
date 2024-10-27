#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <string.h>
#include "../../modules/ui/ui.h"
#include "stylesheet.h"

rgba ROOT_PRIMARY_COLOR() {
    rgba color;
    color.r = 255;
    color.g = 70;
    color.b = 84;
    color.a = 255;
    return color;
}
rgba ROOT_BUTTON_COLOR() {
    rgba color;
    color.r = 29;
    color.g = 33;
    color.b = 46;
    color.a = 255;
    return color;
}
rgba ROOT_SECONDARY_COLOR() {
    rgba color;
    color.r = 19;
    color.g = 23;
    color.b = 34;
    color.a = 255;
    return color;
}
rgba ROOT_BLACK_COLOR() {
    rgba color;
    color.r = 10;
    color.g = 14;
    color.b = 22;
    color.a = 255;
    return color;
}
rgba ROOT_WHITE_COLOR() {
    rgba color;
    color.r = 245;
    color.g = 245;
    color.b = 255;
    color.a = 255;
    return color;
}

style STYLESHEET_BODY(int top, int left, int height, int width) {
    style stylesheet;
    stylesheet.background_color = ROOT_BLACK_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, FONT_POPPINS_MEDIUM);
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    stylesheet.top = top;
    stylesheet.left = left;
    stylesheet.height = height;
    stylesheet.width = width;
    return stylesheet;
}

style STYLESHEET_SIDEBAR(int top, int left, int height, int width) {
    style stylesheet;
    style stylesheet_body;
    stylesheet.background_color = ROOT_SECONDARY_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, FONT_POPPINS_MEDIUM);
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.border_radius_top_left = 32;
    stylesheet.border_radius_top_right = 32;
    stylesheet.border_radius_bottom_left = 32;
    stylesheet.border_radius_bottom_right = 32;
    stylesheet_body = STYLESHEET_BODY(top, left, height, width);
    stylesheet.top = stylesheet_body.top+40;
    stylesheet.left = stylesheet_body.left+40;
    stylesheet.height = stylesheet_body.height-40*2;
    stylesheet.width = 300;
    return stylesheet;
}

style STYLESHEET_CONTAINER(int top, int left, int height, int width) {
    style stylesheet;
    style stylesheet_body;
    style stylesheet_sidebar;
    stylesheet.background_color = ROOT_SECONDARY_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    stylesheet_sidebar = STYLESHEET_SIDEBAR(top,left,height,width);
    strcpy(stylesheet.font_family, stylesheet_sidebar.font_family);
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.border_radius_top_left = 32;
    stylesheet.border_radius_top_right = 32;
    stylesheet.border_radius_bottom_left = 32;
    stylesheet.border_radius_bottom_right = 32;
    stylesheet_body = STYLESHEET_BODY(top, left, height, width);
    stylesheet.top = stylesheet_body.top+40;
    stylesheet.left = stylesheet_sidebar.left+stylesheet_sidebar.width+40;
    stylesheet.height = stylesheet_body.height-40*2;
    stylesheet.width = stylesheet_body.width-stylesheet_sidebar.left-stylesheet_sidebar.width-40*2;
    return stylesheet;
}

style STYLESHEET_SIDEBAR_BUTTONS(int top, int left, int height, int width) {
    style stylesheet;
    style stylesheet_sidebar;
    stylesheet.background_color = ROOT_BUTTON_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    stylesheet_sidebar = STYLESHEET_SIDEBAR(top,left,height,width);
    strcpy(stylesheet.font_family, stylesheet_sidebar.font_family);
    stylesheet.font_size = 20;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.border_radius_top_left = stylesheet_sidebar.border_radius_top_left/2;
    stylesheet.border_radius_top_right = stylesheet_sidebar.border_radius_top_right/2;
    stylesheet.border_radius_bottom_left = stylesheet_sidebar.border_radius_bottom_left/2;
    stylesheet.border_radius_bottom_right = stylesheet_sidebar.border_radius_bottom_right/2;
    stylesheet.top = 0;
    stylesheet.left = stylesheet_sidebar.left+20;
    stylesheet.height = 64;
    stylesheet.width = stylesheet_sidebar.width-20*2;
    return stylesheet;
}

style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS(int top, int left, int height, int width) {
    style stylesheet;
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS(top, left, height, width);
    stylesheet.background_color = ROOT_PRIMARY_COLOR();
    return stylesheet;
}

void createMenuComponents(int top, int left, int height, int width, component components[], int *components_size, button_component buttons[], int *buttons_size)
{
    style stylesheet, hover_stylesheet;
    (*components_size) = 0;
    (*buttons_size) = 0;
    stylesheet = STYLESHEET_BODY(top, left, height, width);
    MLV_clear_window(MLV_rgba(stylesheet.background_color.r, stylesheet.background_color.g, stylesheet.background_color.b, stylesheet.background_color.a));
    createFrame(components, components_size, "", stylesheet, FALSE, stylesheet, 0);
    stylesheet = STYLESHEET_SIDEBAR(top, left, height, width);
    createFrame(components, components_size, "", stylesheet, FALSE, stylesheet, 0);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS(top, left, height, width);
    hover_stylesheet.top = height-40-20-hover_stylesheet.height;
    createButton(components, components_size, buttons, buttons_size, "Quitter", hover_stylesheet, FALSE, hover_stylesheet, 0, BUTTON_ACTION_QUIT);
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS(top, left, height, width);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS(top, left, height, width);
    stylesheet.top = (stylesheet.height+10)*0+40+20;
    hover_stylesheet.top = (hover_stylesheet.height+10)*0+40+20;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    hover_stylesheet.border_radius_bottom_left = 0;
    hover_stylesheet.border_radius_bottom_right = 0;
    createButton(components, components_size, buttons, buttons_size, "Jouer", stylesheet, TRUE, hover_stylesheet, 64, BUTTON_ACTION_NONE);
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS(top, left, height, width);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS(top, left, height, width);
    stylesheet.top = (stylesheet.height+10)*1+40+20;
    hover_stylesheet.top = (hover_stylesheet.height+10)*1+40+20;
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    hover_stylesheet.border_radius_top_left = 0;
    hover_stylesheet.border_radius_top_right = 0;
    hover_stylesheet.border_radius_bottom_left = 0;
    hover_stylesheet.border_radius_bottom_right = 0;
    createButton(components, components_size, buttons, buttons_size, "Paramètres", stylesheet, TRUE, hover_stylesheet, 64, BUTTON_ACTION_CREATE_SETTINGS_COMPONENTS);
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS(top, left, height, width);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS(top, left, height, width);
    stylesheet.top = (stylesheet.height+10)*2+40+20;
    hover_stylesheet.top = (hover_stylesheet.height+10)*2+40+20;
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    hover_stylesheet.border_radius_top_left = 0;
    hover_stylesheet.border_radius_top_right = 0;
    createButton(components, components_size, buttons, buttons_size, "Scoreboard", stylesheet, TRUE, hover_stylesheet, 64, BUTTON_ACTION_NONE);
}

void createSettingsComponents(int top, int left, int height, int width, component components[], int *components_size, button_component buttons[], int *buttons_size)
{
    style stylesheet, hover_stylesheet;
    (*components_size) = 0;
    (*buttons_size) = 0;
    
    stylesheet = STYLESHEET_BODY(top, left, height, width);
    MLV_clear_window(MLV_rgba(stylesheet.background_color.r, stylesheet.background_color.g, stylesheet.background_color.b, stylesheet.background_color.a));
    createFrame(components, components_size, "", stylesheet, FALSE, stylesheet, 0);
    stylesheet = STYLESHEET_SIDEBAR(top, left, height, width);
    createFrame(components, components_size, "", stylesheet, FALSE, stylesheet, 0);
    stylesheet = STYLESHEET_CONTAINER(top, left, height, width);
    createFrame(components, components_size, "", stylesheet, FALSE, stylesheet, 0);
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS(top, left, height, width);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS(top, left, height, width);
    stylesheet.top = (stylesheet.height+10)*0+40+20;
    hover_stylesheet.top = (hover_stylesheet.height+10)*0+40+20;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    hover_stylesheet.border_radius_bottom_left = 0;
    hover_stylesheet.border_radius_bottom_right = 0;
    createButton(components, components_size, buttons, buttons_size, "Retour", stylesheet, TRUE, hover_stylesheet, 64, BUTTON_ACTION_CREATE_MENU_COMPONENTS);
}