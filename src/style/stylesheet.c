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

rgba ROOT_TRANSPARENT_COLOR() {
    rgba color;
    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 0;
    return color;
}

style STYLESHEET_SIDEBAR(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    (void)width; /* Anti-Unused */

    stylesheet.background_color = ROOT_SECONDARY_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, "");
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = 16;
    stylesheet.border_radius_top_right = 16;
    stylesheet.border_radius_bottom_left = 16;
    stylesheet.border_radius_bottom_right = 16;
    stylesheet.childs_direction = DIRECTION_COLUMN;
    stylesheet.padding = 20;
    stylesheet.gap = 10;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = top+40;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = left+40;
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = height-40*2;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 324;
    return stylesheet;
}

style STYLESHEET_CONTAINER(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    style stylesheet_sidebar;
    stylesheet.background_color = ROOT_SECONDARY_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    stylesheet_sidebar = STYLESHEET_SIDEBAR(top,left,height,width);
    strcpy(stylesheet.font_family, "");
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = stylesheet_sidebar.border_radius_top_left;
    stylesheet.border_radius_top_right = stylesheet_sidebar.border_radius_top_right;
    stylesheet.border_radius_bottom_left = stylesheet_sidebar.border_radius_bottom_left;
    stylesheet.border_radius_bottom_right = stylesheet_sidebar.border_radius_bottom_right;
    stylesheet.childs_direction = DIRECTION_COLUMN;
    stylesheet.padding = 20;
    stylesheet.gap = 20;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = top+40;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = stylesheet_sidebar.left+stylesheet_sidebar.width+40;
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = height-40*2;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = width-stylesheet_sidebar.left-stylesheet_sidebar.width-40*2;
    return stylesheet;
}

style STYLESHEET_SIDEBAR_BUTTONS(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    style stylesheet_sidebar;
    stylesheet.background_color = ROOT_BUTTON_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    stylesheet_sidebar = STYLESHEET_SIDEBAR(top,left,height,width);
    strcpy(stylesheet.font_family, "");
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = stylesheet_sidebar.border_radius_top_left/2;
    stylesheet.border_radius_top_right = stylesheet_sidebar.border_radius_top_right/2;
    stylesheet.border_radius_bottom_left = stylesheet_sidebar.border_radius_bottom_left/2;
    stylesheet.border_radius_bottom_right = stylesheet_sidebar.border_radius_bottom_right/2;
    stylesheet.childs_direction = DIRECTION_ROW;
    stylesheet.padding = 20;
    stylesheet.gap = 20;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 64;
    stylesheet.unit_width = UNIT_PERCENTAGE;
    stylesheet.width = 100;
    return stylesheet;
}
style STYLESHEET_TEXT() {
    style stylesheet;
    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, FONT_POPPINS_MEDIUM);
    stylesheet.font_size = 18;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    stylesheet.childs_direction = DIRECTION_ROW;
    stylesheet.padding = 0;
    stylesheet.gap = 0;
    stylesheet.unit_top = UNIT_PERCENTAGE;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PERCENTAGE;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PERCENTAGE;
    stylesheet.height = 100;
    stylesheet.unit_width = UNIT_PERCENTAGE;
    stylesheet.width = 100;
    return stylesheet;
}

style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS(top, left, height, width);
    stylesheet.background_color = ROOT_PRIMARY_COLOR();
    return stylesheet;
}
style STYLESHEET_SIDEBAR_BUTTONS_TOP(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS(top, left, height, width);
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    return stylesheet;
}
style STYLESHEET_SIDEBAR_BUTTONS_MIDDLE(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS(top, left, height, width);
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    return stylesheet;
}
style STYLESHEET_SIDEBAR_BUTTONS_BOTTOM(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS(top, left, height, width);
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    return stylesheet;
}
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_TOP(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS(top, left, height, width);
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    return stylesheet;
}
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS(top, left, height, width);
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    return stylesheet;
}
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS(top, left, height, width);
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    return stylesheet;
}

void createMenuComponents(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size)
{
    style stylesheet, hover_stylesheet, text_stylesheet;
    rgba color;
    (*components_size) = 0;
    (*buttons_size) = 0;
    (*texts_size) = 0;
    
    color = ROOT_BLACK_COLOR();
    MLV_clear_window(MLV_rgba(color.r, color.g, color.b, color.a));
    MLV_draw_filled_rectangle(0, 0, width, top, MLV_rgba(color.r, color.g, color.b, color.a));
    stylesheet = STYLESHEET_SIDEBAR(top, left, height, width);
    createFrame(components, components_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0);

    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_TOP(top, left, height, width);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_TOP(top, left, height, width);
    createButton(components, components_size, buttons, buttons_size, 1, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_NONE);
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_MIDDLE(top, left, height, width);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE(top, left, height, width);
    createButton(components, components_size, buttons, buttons_size, 1, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_NONE);
    createButton(components, components_size, buttons, buttons_size, 1, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_CREATE_SETTINGS_COMPONENTS);
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_BOTTOM(top, left, height, width);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM(top, left, height, width);
    createButton(components, components_size, buttons, buttons_size, 1, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_NONE);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS(top, left, height, width);
    hover_stylesheet.component_justify = JUSTIFY_END;
    createButton(components, components_size, buttons, buttons_size, 1, hover_stylesheet, FALSE, FALSE, hover_stylesheet, 0, BUTTON_ACTION_QUIT);

    text_stylesheet = STYLESHEET_TEXT();
    createText(components, components_size, texts, texts_size, 2, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Nouvelle partie");
    createText(components, components_size, texts, texts_size, 3, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Reprendre une partie");
    createText(components, components_size, texts, texts_size, 4, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres");
    createText(components, components_size, texts, texts_size, 5, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Scoreboard");
    createText(components, components_size, texts, texts_size, 6, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Quitter");
}

void createSettingsComponents(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size)
{
    style stylesheet, hover_stylesheet, text_stylesheet;
    rgba color;
    (*components_size) = 0;
    (*buttons_size) = 0;
    (*texts_size) = 0;
    
    color = ROOT_BLACK_COLOR();
    MLV_clear_window(MLV_rgba(color.r, color.g, color.b, color.a));
    MLV_draw_filled_rectangle(0, 0, width, top, MLV_rgba(color.r, color.g, color.b, color.a));
    stylesheet = STYLESHEET_SIDEBAR(top, left, height, width);
    createFrame(components, components_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0);
    stylesheet = STYLESHEET_CONTAINER(top, left, height, width);
    createFrame(components, components_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0);
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_TOP(top, left, height, width);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_TOP(top, left, height, width);
    createButton(components, components_size, buttons, buttons_size, 1, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_CREATE_MENU_COMPONENTS);
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_MIDDLE(top, left, height, width);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE(top, left, height, width);
    createButton(components, components_size, buttons, buttons_size, 1, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_NONE);
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_MIDDLE(top, left, height, width);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE(top, left, height, width);
    createButton(components, components_size, buttons, buttons_size, 1, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_NONE);
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_MIDDLE(top, left, height, width);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE(top, left, height, width);
    createButton(components, components_size, buttons, buttons_size, 1, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_NONE);
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_BOTTOM(top, left, height, width);
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM(top, left, height, width);
    createButton(components, components_size, buttons, buttons_size, 1, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_NONE);


    text_stylesheet = STYLESHEET_TEXT();
    createText(components, components_size, texts, texts_size, 3, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Retour");
    createText(components, components_size, texts, texts_size, 4, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Clavier & Souris");
    createText(components, components_size, texts, texts_size, 5, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres vidéo");
    createText(components, components_size, texts, texts_size, 6, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres graphique");
    createText(components, components_size, texts, texts_size, 7, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres audio");
}