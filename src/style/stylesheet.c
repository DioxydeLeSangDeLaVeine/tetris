#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <string.h>
#include "../../modules/ui/ui.h"
#include "../../modules/util/util.h"
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

style STYLESHEET_BODY(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    (void)width; /* Anti-Unused */

    stylesheet.background_color = ROOT_BLACK_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, "");
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    stylesheet.childs_direction = DIRECTION_ROW;
    stylesheet.padding = 40;
    stylesheet.gap = 40;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = top;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = left;
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = height;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = width;
    return stylesheet;
}

style STYLESHEET_SIDEBAR() {
    style stylesheet;

    stylesheet.background_color = ROOT_SECONDARY_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, "");
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = 32;
    stylesheet.border_radius_top_right = 32;
    stylesheet.border_radius_bottom_left = 32;
    stylesheet.border_radius_bottom_right = 32;
    stylesheet.childs_direction = DIRECTION_COLUMN;
    stylesheet.padding = 20;
    stylesheet.gap = 10;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PERCENTAGE;
    stylesheet.height = 100;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 324;
    return stylesheet;
}

style STYLESHEET_LOGO(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    style stylesheet_sidebar;
    style stylesheet_body;

    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.color = ROOT_TRANSPARENT_COLOR();
    stylesheet_sidebar = STYLESHEET_SIDEBAR();
    stylesheet_body = STYLESHEET_BODY(top, left, height, width);
    strcpy(stylesheet.font_family, "");
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    stylesheet.childs_direction = DIRECTION_COLUMN;
    stylesheet.padding = 0;
    stylesheet.gap = 0;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = (stylesheet_body.height/2)-(500/2);
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = (stylesheet_body.width-(stylesheet_sidebar.left+stylesheet_sidebar.width+stylesheet_body.padding*2+stylesheet_body.gap))/2-(500/2)+(stylesheet_sidebar.left+stylesheet_sidebar.width+stylesheet_body.padding+stylesheet_body.gap);
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 500;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 500;
    return stylesheet;
}

style STYLESHEET_CONTAINER(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    style stylesheet_sidebar;
    style stylesheet_body;
    stylesheet.background_color = ROOT_SECONDARY_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    stylesheet_sidebar = STYLESHEET_SIDEBAR();
    stylesheet_body = STYLESHEET_BODY(top, left, height, width);
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
    stylesheet.padding = 50;
    stylesheet.gap = 15;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PERCENTAGE;
    stylesheet.height = 100;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = stylesheet_body.width-stylesheet_sidebar.left-stylesheet_sidebar.width-stylesheet_body.padding*2-stylesheet_body.gap;
    return stylesheet;
}
style STYLESHEET_ROW() {
    style stylesheet;
    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, "");
    stylesheet.font_size = 50;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_TOP;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    stylesheet.childs_direction = DIRECTION_ROW;
    stylesheet.padding = 0;
    stylesheet.gap = 15;
    stylesheet.unit_top = UNIT_PERCENTAGE;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PERCENTAGE;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 60;
    stylesheet.unit_width = UNIT_PERCENTAGE;
    stylesheet.width = 100;
    return stylesheet;
}

style STYLESHEET_SIDEBAR_BUTTONS() {
    style stylesheet;
    style stylesheet_sidebar;
    stylesheet.background_color = ROOT_BUTTON_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    stylesheet_sidebar = STYLESHEET_SIDEBAR();
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
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS() {
    style stylesheet;
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS();
    stylesheet.background_color = ROOT_PRIMARY_COLOR();
    return stylesheet;
}
style STYLESHEET_SIDEBAR_BUTTONS_TOP() {
    style stylesheet;
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS();
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    return stylesheet;
}
style STYLESHEET_SIDEBAR_BUTTONS_MIDDLE() {
    style stylesheet;
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS();
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    return stylesheet;
}
style STYLESHEET_SIDEBAR_BUTTONS_BOTTOM() {
    style stylesheet;
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS();
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    return stylesheet;
}
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_TOP() {
    style stylesheet;
    stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS();
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    return stylesheet;
}
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE() {
    style stylesheet;
    stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS();
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    return stylesheet;
}
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM() {
    style stylesheet;
    stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS();
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    return stylesheet;
}

style STYLESHEET_TEXT() {
    style stylesheet;
    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, FONT_POPPINS_THIN);
    stylesheet.font_size = 24;
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
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 56;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 100;
    return stylesheet;
}

style STYLESHEET_KEY() {
    style stylesheet;
    stylesheet.background_color = ROOT_BUTTON_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, FONT_POPPINS_REGULAR);
    stylesheet.font_size = 20;
    stylesheet.font_horizontal_align = HORIZONTAL_CENTER;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_END;
    stylesheet.border_radius_top_left = 16;
    stylesheet.border_radius_top_right = 16;
    stylesheet.border_radius_bottom_left = 16;
    stylesheet.border_radius_bottom_right = 16;
    stylesheet.childs_direction = DIRECTION_ROW;
    stylesheet.padding = 30;
    stylesheet.gap = 0;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 56;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 200;
    return stylesheet;
}
style STYLESHEET_HOVERED_KEY() {
    style stylesheet;
    stylesheet = STYLESHEET_KEY();
    stylesheet.background_color = ROOT_PRIMARY_COLOR();
    return stylesheet;
}

style STYLESHEET_BUTTONS_TEXT() {
    style stylesheet;
    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, FONT_POPPINS_MEDIUM);
    stylesheet.font_size = 20;
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

style STYLESHEET_MINI_TITLE() {
    style stylesheet;
    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, FONT_POPPINS_MEDIUM);
    stylesheet.font_size = 35;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_TOP;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    stylesheet.childs_direction = DIRECTION_ROW;
    stylesheet.padding = 0;
    stylesheet.gap = 0;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 60;
    stylesheet.unit_width = UNIT_PERCENTAGE;
    stylesheet.width = 100;
    return stylesheet;
}
style STYLESHEET_TITLE() {
    style stylesheet;
    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, FONT_POPPINS_EXTRABOLD);
    stylesheet.font_size = 50;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_TOP;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    stylesheet.childs_direction = DIRECTION_ROW;
    stylesheet.padding = 0;
    stylesheet.gap = 0;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 150;
    stylesheet.unit_width = UNIT_PERCENTAGE;
    stylesheet.width = 100;
    return stylesheet;
}

style STYLESHEET_HIDE(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    stylesheet.background_color.r = 0;
    stylesheet.background_color.g = 0;
    stylesheet.background_color.b = 0;
    stylesheet.background_color.a = 192;
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, "");
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_TOP;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    stylesheet.childs_direction = DIRECTION_ROW;
    stylesheet.padding = 0;
    stylesheet.gap = 0;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = top;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = left;
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = height;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = width;
    return stylesheet;
}
style STYLESHEET_HIDE_TEXT(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    stylesheet.background_color = ROOT_BLACK_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, FONT_POPPINS_MEDIUM);
    stylesheet.font_size = 20;
    stylesheet.font_horizontal_align = HORIZONTAL_CENTER;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = 32;
    stylesheet.border_radius_top_right = 32;
    stylesheet.border_radius_bottom_left = 32;
    stylesheet.border_radius_bottom_right = 32;
    stylesheet.childs_direction = DIRECTION_ROW;
    stylesheet.padding = 0;
    stylesheet.gap = 0;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = top+(height/2)-(128/2);
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = left+(width/2)-(500/2);
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 128;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 500;
    return stylesheet;
}

void createComponents(page_components page, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, key_component keys[], uint32_t *keys_size, image_component images[], uint32_t *images_size, settings set) {
    style stylesheet;
    (*components_size) = 0;
    (*buttons_size) = 0;
    (*texts_size) = 0;

    stylesheet = STYLESHEET_BODY(top, left, height, width);
    MLV_clear_window(MLV_COLOR_BLACK);
    createFrame(components, components_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 1 */

    switch(page) {
        case MENU_COMPONENTS:
        case SETTINGS_KEYBOARD_COMPONENTS:
        case SETTINGS_VIDEO_COMPONENTS:
        case SETTINGS_GRAPHICS_COMPONENTS:
        case SETTINGS_AUDIO_COMPONENTS:
            createComponentsWithSidebar(page, top, left, height, width, components, components_size, buttons, buttons_size, texts, texts_size, keys, keys_size, images, images_size, set);
            break;
        default:
            break;
    }
}

void createComponentsWithSidebar(page_components page, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, key_component keys[], uint32_t *keys_size, image_component images[], uint32_t *images_size, settings set) {
    style stylesheet;
    stylesheet = STYLESHEET_SIDEBAR();
    createFrame(components, components_size, 1, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 2 */

    switch(page) {
        case MENU_COMPONENTS:
            createMenuComponents(top, left, height, width, components, components_size, buttons, buttons_size, texts, texts_size, images, images_size);
            break;
        case SETTINGS_KEYBOARD_COMPONENTS:
        case SETTINGS_VIDEO_COMPONENTS:
        case SETTINGS_GRAPHICS_COMPONENTS:
        case SETTINGS_AUDIO_COMPONENTS:
            createSettingsComponents(page, top, left, height, width, components, components_size, buttons, buttons_size, texts, texts_size, keys, keys_size, set);
            break;
        default:
            break;
    }
}

void createMenuComponents(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, image_component images[], uint32_t *images_size)
{
    style stylesheet, hover_stylesheet, text_stylesheet;
    
    stylesheet = STYLESHEET_LOGO(top, left, height, width);
    createImage(components, components_size, images, images_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0, "./src/img/logo.png"); /* id = 3 */

    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_TOP();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_TOP();
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_NONE); /* id = 4 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_MIDDLE();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE();
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_NONE); /* id = 5 */
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_CREATE_SETTINGS_KEYBOARD_COMPONENTS); /* id = 5 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_BOTTOM();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM();
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_NONE); /* id = 6 */
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS();
    hover_stylesheet.component_justify = JUSTIFY_END;
    createButton(components, components_size, buttons, buttons_size, 2, hover_stylesheet, FALSE, FALSE, hover_stylesheet, 0, BUTTON_ACTION_QUIT); /* id = 7 */

    text_stylesheet = STYLESHEET_BUTTONS_TEXT();
    createText(components, components_size, texts, texts_size, 4, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Nouvelle partie"); /* id = 8 */
    createText(components, components_size, texts, texts_size, 5, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Reprendre une partie"); /* id = 9 */
    createText(components, components_size, texts, texts_size, 6, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres"); /* id = 10 */
    createText(components, components_size, texts, texts_size, 7, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Scoreboard"); /* id = 11 */
    createText(components, components_size, texts, texts_size, 8, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Quitter"); /* id = 12 */


}

void createSettingsComponents(page_components page, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, key_component keys[], uint32_t *keys_size, settings set)
{
    style stylesheet, hover_stylesheet, text_stylesheet;

    stylesheet = STYLESHEET_CONTAINER(top, left, height, width);
    createFrame(components, components_size, 1, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 3 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_TOP();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_TOP();
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_CREATE_MENU_COMPONENTS); /* id = 4 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_MIDDLE();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE();
    createButton(components, components_size, buttons, buttons_size, 2, (page==SETTINGS_KEYBOARD_COMPONENTS)?hover_stylesheet:stylesheet, (page==SETTINGS_KEYBOARD_COMPONENTS)?FALSE:TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_CREATE_SETTINGS_KEYBOARD_COMPONENTS); /* id = 5 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_MIDDLE();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE();
    createButton(components, components_size, buttons, buttons_size, 2, (page==SETTINGS_VIDEO_COMPONENTS)?hover_stylesheet:stylesheet, (page==SETTINGS_VIDEO_COMPONENTS)?FALSE:TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_CREATE_SETTINGS_VIDEO_COMPONENTS); /* id = 6 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_MIDDLE();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE();
    createButton(components, components_size, buttons, buttons_size, 2, (page==SETTINGS_GRAPHICS_COMPONENTS)?hover_stylesheet:stylesheet, (page==SETTINGS_GRAPHICS_COMPONENTS)?FALSE:TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_CREATE_SETTINGS_GRAPHICS_COMPONENTS); /* id = 7 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_BOTTOM();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM();
    createButton(components, components_size, buttons, buttons_size, 2, (page==SETTINGS_AUDIO_COMPONENTS)?hover_stylesheet:stylesheet, (page==SETTINGS_AUDIO_COMPONENTS)?FALSE:TRUE, FALSE, hover_stylesheet, 64, BUTTON_ACTION_CREATE_SETTINGS_AUDIO_COMPONENTS); /* id = 8 */

    text_stylesheet = STYLESHEET_BUTTONS_TEXT();
    createText(components, components_size, texts, texts_size, 4, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Retour"); /* id = 9 */
    createText(components, components_size, texts, texts_size, 5, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Clavier & Souris"); /* id = 10 */
    createText(components, components_size, texts, texts_size, 6, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres vidéo"); /* id = 11 */
    createText(components, components_size, texts, texts_size, 7, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres graphique"); /* id = 12 */
    createText(components, components_size, texts, texts_size, 8, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres audio"); /* id = 13 */

    switch(page) {
        case SETTINGS_KEYBOARD_COMPONENTS:
            createSettingsKeyboardComponents(components, components_size, texts, texts_size, keys, keys_size, set);
            break;
        case SETTINGS_VIDEO_COMPONENTS:
            createSettingsVideoComponents(components, components_size, texts, texts_size);
            break;
        case SETTINGS_GRAPHICS_COMPONENTS:
            createSettingsGraphicsComponents(components, components_size, texts, texts_size);
            break;
        case SETTINGS_AUDIO_COMPONENTS:
            createSettingsAudioComponents(components, components_size, texts, texts_size);
            break;
        default:
            break;
    }
}

void createSettingsKeyboardComponents(component components[], uint32_t *components_size, text_component texts[], uint32_t *texts_size, key_component keys[], uint32_t *keys_size, settings set)
{
    style stylesheet, hover_stylesheet, text_stylesheet;
    char key[16];

    text_stylesheet = STYLESHEET_TITLE();
    createText(components, components_size, texts, texts_size, 3, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Commandes clavier & souris"); /* id = 14 */

    text_stylesheet = STYLESHEET_MINI_TITLE();
    createText(components, components_size, texts, texts_size, 3, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Déplacement"); /* id = 15 */

    stylesheet = STYLESHEET_ROW();
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 16 */
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 17 */
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 18 */
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 19 */
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 20 */
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 21 */
    
    text_stylesheet = STYLESHEET_TEXT();
    createText(components, components_size, texts, texts_size, 16, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Déplacer à gauche"); /* id = 22 */
    createText(components, components_size, texts, texts_size, 17, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Déplacer à droite"); /* id = 23 */
    createText(components, components_size, texts, texts_size, 18, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Tourner à gauche"); /* id = 24 */
    createText(components, components_size, texts, texts_size, 19, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Tourner à droite"); /* id = 25 */
    createText(components, components_size, texts, texts_size, 20, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Descente rapide"); /* id = 26 */
    createText(components, components_size, texts, texts_size, 21, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Mettre pause"); /* id = 27 */

    stylesheet = STYLESHEET_KEY();
    hover_stylesheet = STYLESHEET_HOVERED_KEY();
    getKeyFromMLV(set.keyboard_move_left, key);
    createKey(components, components_size, keys, keys_size, 16, stylesheet, TRUE, FALSE, hover_stylesheet, 64, KEY_TAKE_MOVE_LEFT, key); /* id = 27 */
    getKeyFromMLV(set.keyboard_move_right, key);
    createKey(components, components_size, keys, keys_size, 17, stylesheet, TRUE, FALSE, hover_stylesheet, 64, KEY_TAKE_MOVE_RIGHT, key); /* id = 28 */
    getKeyFromMLV(set.keyboard_turn_left, key);
    createKey(components, components_size, keys, keys_size, 18, stylesheet, TRUE, FALSE, hover_stylesheet, 64, KEY_TAKE_TURN_LEFT, key); /* id = 29 */
    getKeyFromMLV(set.keyboard_turn_right, key);
    createKey(components, components_size, keys, keys_size, 19, stylesheet, TRUE, FALSE, hover_stylesheet, 64, KEY_TAKE_TURN_RIGHT, key); /* id = 30 */
    getKeyFromMLV(set.keyboard_confirm, key);
    createKey(components, components_size, keys, keys_size, 20, stylesheet, TRUE, FALSE, hover_stylesheet, 64, KEY_TAKE_CONFIRM, key); /* id = 31 */
    getKeyFromMLV(set.keyboard_pause, key);
    createKey(components, components_size, keys, keys_size, 21, stylesheet, TRUE, FALSE, hover_stylesheet, 64, KEY_TAKE_PAUSE, key); /* id = 32 */
}
void createSettingsVideoComponents(component components[], uint32_t *components_size, text_component texts[], uint32_t *texts_size)
{
    style text_stylesheet;

    text_stylesheet = STYLESHEET_TITLE();
    createText(components, components_size, texts, texts_size, 3, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres vidéo"); /* id = 14 */
}
void createSettingsGraphicsComponents(component components[], uint32_t *components_size, text_component texts[], uint32_t *texts_size)
{
    style text_stylesheet;

    text_stylesheet = STYLESHEET_TITLE();
    createText(components, components_size, texts, texts_size, 3, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres graphique"); /* id = 14 */
}
void createSettingsAudioComponents(component components[], uint32_t *components_size, text_component texts[], uint32_t *texts_size)
{
    style text_stylesheet;

    text_stylesheet = STYLESHEET_TITLE();
    createText(components, components_size, texts, texts_size, 3, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres audio"); /* id = 14 */
}