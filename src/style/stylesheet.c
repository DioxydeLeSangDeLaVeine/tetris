#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <string.h>
#include <math.h>
#include "../../modules/back/game.h"
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
rgba ROOT_GREY_COLOR() {
    rgba color;
    color.r = 39;
    color.g = 43;
    color.b = 58;
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
    stylesheet.top = (stylesheet_body.height/2)-(1000/2);
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = (stylesheet_body.width-(stylesheet_sidebar.left+stylesheet_sidebar.width+stylesheet_body.padding*2+stylesheet_body.gap))/2-(1000/2)+(stylesheet_sidebar.left+stylesheet_sidebar.width+stylesheet_body.padding+stylesheet_body.gap);
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 1000;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 1000;
    return stylesheet;
}

style STYLESHEET_GAME(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    style stylesheet_body;

    int32_t tmp_height, tmp_width;

    stylesheet.background_color = ROOT_BUTTON_COLOR();
    stylesheet.color = ROOT_TRANSPARENT_COLOR();
    stylesheet_body = STYLESHEET_BODY(top, left, height, width);
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
    stylesheet.padding = 0;
    stylesheet.gap = 10;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = stylesheet_body.padding;

    tmp_height = stylesheet_body.height-2*stylesheet_body.padding;

    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = (tmp_height-((GAME_HEIGHT-1)*stylesheet.gap))/GAME_HEIGHT;

    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = stylesheet.height;

    tmp_width = GAME_WIDTH*stylesheet.width+(GAME_WIDTH-1)*stylesheet.gap;

    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = (stylesheet_body.width/2)-(tmp_width/2);
    return stylesheet;
}

style STYLESHEET_PODIUM(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    style stylesheet_body;

    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.color = ROOT_TRANSPARENT_COLOR();
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
    stylesheet.top = -300;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = (stylesheet_body.width/2)-(2000/2);
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 1000;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 2000;
    return stylesheet;
}

style STYLESHEET_BOARD(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    style stylesheet_body;

    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.color = ROOT_TRANSPARENT_COLOR();
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
    stylesheet.gap = 20;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = 600;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = (stylesheet_body.width/2)-(600/2);
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 1000;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 600;
    return stylesheet;
}
style STYLESHEET_SCORE() {
    style stylesheet;
    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.color = ROOT_TRANSPARENT_COLOR();
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
    stylesheet.padding = 0;
    stylesheet.gap = 20;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 35;
    stylesheet.unit_width = UNIT_PERCENTAGE;
    stylesheet.width = 100;
    return stylesheet;
}
style STYLESHEET_SCORE_NUM() {
    style stylesheet;
    stylesheet.background_color = ROOT_WHITE_COLOR();
    stylesheet.color = ROOT_TRANSPARENT_COLOR();
    strcpy(stylesheet.font_family, "");
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = 100;
    stylesheet.border_radius_top_right = 100;
    stylesheet.border_radius_bottom_left = 100;
    stylesheet.border_radius_bottom_right = 100;
    stylesheet.childs_direction = DIRECTION_COLUMN;
    stylesheet.padding = 0;
    stylesheet.gap = 0;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 35;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 35;
    return stylesheet;
}

style STYLESHEET_SCORE_NUM_TEXT() {
    style stylesheet;
    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.color = ROOT_BLACK_COLOR();
    strcpy(stylesheet.font_family, FONT_POPPINS_BOLD);
    stylesheet.font_size = 20;
    stylesheet.font_horizontal_align = HORIZONTAL_CENTER;
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

style STYLESHEET_SCORE_TEXT() {
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

style STYLESHEET_SCORE_DATE_TEXT() {
    style stylesheet;
    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.color = ROOT_GREY_COLOR();
    strcpy(stylesheet.font_family, FONT_POPPINS_MEDIUM);
    stylesheet.font_size = 16;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_END;
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
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 0;
    return stylesheet;
}

style STYLESHEET_SCROLL() {
    style stylesheet;
    stylesheet.background_color = ROOT_GREY_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    strcpy(stylesheet.font_family, "");
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = 50;
    stylesheet.border_radius_top_right = 50;
    stylesheet.border_radius_bottom_left = 50;
    stylesheet.border_radius_bottom_right = 50;
    stylesheet.childs_direction = DIRECTION_COLUMN;
    stylesheet.padding = 0;
    stylesheet.gap = 0;
    stylesheet.unit_top = UNIT_PERCENTAGE;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PERCENTAGE;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PERCENTAGE;
    stylesheet.height = 100;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 15;
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

style STYLESHEET_MINI_CONTAINER(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    style stylesheet_container;
    stylesheet.background_color = ROOT_SECONDARY_COLOR();
    stylesheet.color = ROOT_WHITE_COLOR();
    stylesheet_container = STYLESHEET_CONTAINER(top, left, height, width);
    strcpy(stylesheet.font_family, "");
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = stylesheet_container.border_radius_top_left;
    stylesheet.border_radius_top_right = stylesheet_container.border_radius_top_right;
    stylesheet.border_radius_bottom_left = stylesheet_container.border_radius_bottom_left;
    stylesheet.border_radius_bottom_right = stylesheet_container.border_radius_bottom_right;
    stylesheet.childs_direction = DIRECTION_COLUMN;
    stylesheet.padding = 20;
    stylesheet.gap = 10;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PERCENTAGE;
    stylesheet.height = 100;
    stylesheet.unit_width = UNIT_PERCENTAGE;
    stylesheet.width = 100;
    return stylesheet;
}

style STYLESHEET_CONTAINER_ROW(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    style stylesheet_sidebar;
    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.color = ROOT_TRANSPARENT_COLOR();
    stylesheet_sidebar = STYLESHEET_SIDEBAR(top, left, height, width);
    strcpy(stylesheet.font_family, "");
    stylesheet.font_size = 0;
    stylesheet.font_horizontal_align = HORIZONTAL_LEFT;
    stylesheet.font_vertical_align = VERTICAL_CENTER;
    stylesheet.component_justify = JUSTIFY_START;
    stylesheet.border_radius_top_left = stylesheet_sidebar.border_radius_top_left;
    stylesheet.border_radius_top_right = stylesheet_sidebar.border_radius_top_right;
    stylesheet.border_radius_bottom_left = stylesheet_sidebar.border_radius_bottom_left;
    stylesheet.border_radius_bottom_right = stylesheet_sidebar.border_radius_bottom_right;
    stylesheet.childs_direction = DIRECTION_ROW;
    stylesheet.padding = 50;
    stylesheet.gap = 15;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PERCENTAGE;
    stylesheet.height = 100;
    stylesheet.unit_width = UNIT_PERCENTAGE;
    stylesheet.width = 100;
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

style STYLESHEET_BOX(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    style stylesheet_sidebar;
    stylesheet.background_color = ROOT_BUTTON_COLOR();
    stylesheet.color = ROOT_TRANSPARENT_COLOR();
    stylesheet_sidebar = STYLESHEET_SIDEBAR(top, left, height, width);
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
    stylesheet.padding = 25;
    stylesheet.gap = 15;
    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PERCENTAGE;
    stylesheet.height = 100;
    stylesheet.unit_width = UNIT_PX;
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
    stylesheet.border_radius_top_left = 8;
    stylesheet.border_radius_top_right = 8;
    stylesheet.border_radius_bottom_left = 8;
    stylesheet.border_radius_bottom_right = 8;
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
    stylesheet.height = 100;
    stylesheet.unit_width = UNIT_PERCENTAGE;
    stylesheet.width = 100;
    return stylesheet;
}

style STYLESHEET_HIDE(int32_t top, int32_t left, int32_t height, int32_t width) {
    style stylesheet;
    stylesheet.background_color.r = 0;
    stylesheet.background_color.g = 0;
    stylesheet.background_color.b = 0;
    stylesheet.background_color.a = 182;
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

style STYLESHEET_VOID() {
    style stylesheet;
    stylesheet.background_color.r = 0;
    stylesheet.background_color.g = 0;
    stylesheet.background_color.b = 0;
    stylesheet.background_color.a = 0;
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
    stylesheet.top = 0;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = 0;
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = 0;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 0;
    return stylesheet;
}

void createComponents(page_components page, button_action_type lastPage, double scroll, int32_t top, int32_t left, int32_t height, int32_t width, game g, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, key_component keys[], uint32_t *keys_size, image_component images[], uint32_t *images_size, settings set) {
    style stylesheet;
    (*components_size) = 0;
    (*buttons_size) = 0;
    (*texts_size) = 0;

    stylesheet = STYLESHEET_BODY(top, left, height, width);
    MLV_clear_window(MLV_COLOR_BLACK);
    createFrame(components, components_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 1 */

    switch(page) {
        case GAME_COMPONENTS:
        case GAME_POPUP_COMPONENTS:
        case GAME_END_COMPONENTS:
            createGameComponents(page, top, left, height, width, g, components, components_size, buttons, buttons_size, texts, texts_size);
            break;
        case MENU_COMPONENTS:
        case PLAY_COMPONENTS:
        case LOAD_COMPONENTS:
        case SCOREBOARD_COMPONENTS:
        case SETTINGS_KEYBOARD_COMPONENTS:
        case SETTINGS_VIDEO_COMPONENTS:
        case SETTINGS_GRAPHICS_COMPONENTS:
            createComponentsWithSidebar(page, lastPage, scroll, top, left, height, width, components, components_size, buttons, buttons_size, texts, texts_size, keys, keys_size, images, images_size, set);
            break;
        default:
            break;
    }
}

void createComponentsWithSidebar(page_components page, button_action_type lastPage, double scroll, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, key_component keys[], uint32_t *keys_size, image_component images[], uint32_t *images_size, settings set) {
    style stylesheet;
    stylesheet = STYLESHEET_SIDEBAR();
    if(page == SCOREBOARD_COMPONENTS)
    {
        stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
        stylesheet.border_radius_top_left = 0;
        stylesheet.border_radius_top_right = 0;
        stylesheet.border_radius_bottom_left = 0;
        stylesheet.border_radius_bottom_right = 0;
    }
    createFrame(components, components_size, 1, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 2 */

    switch(page) {
        case MENU_COMPONENTS:
            createMenuComponents(top, left, height, width, components, components_size, buttons, buttons_size, texts, texts_size, images, images_size);
            break;
        case PLAY_COMPONENTS:
            createPlayComponents(top, left, height, width, components, components_size, buttons, buttons_size, texts, texts_size, images, images_size);
            break;
        case LOAD_COMPONENTS:
            createLoadComponents(lastPage, scroll, top, left, height, width, components, components_size, buttons, buttons_size, texts, texts_size);
            break;
        case SCOREBOARD_COMPONENTS:
            createScoreboardComponents(lastPage, top, left, height, width, components, components_size, buttons, buttons_size, texts, texts_size, images, images_size);
            break;
        case SETTINGS_KEYBOARD_COMPONENTS:
        case SETTINGS_VIDEO_COMPONENTS:
        case SETTINGS_GRAPHICS_COMPONENTS:
            createSettingsComponents(page, lastPage, top, left, height, width, components, components_size, buttons, buttons_size, texts, texts_size, keys, keys_size, set);
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
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 100, BUTTON_ACTION_CREATE_PLAY_COMPONENTS, ""); /* id = 4 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_MIDDLE();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE();
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 100, BUTTON_ACTION_CREATE_LOAD_COMPONENTS, ""); /* id = 5 */
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 100, BUTTON_ACTION_CREATE_SETTINGS_KEYBOARD_COMPONENTS, ""); /* id = 6 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_BOTTOM();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM();
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 100, BUTTON_ACTION_CREATE_SCOREBOARD_COMPONENTS, ""); /* id = 7 */
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS();
    hover_stylesheet.component_justify = JUSTIFY_END;
    createButton(components, components_size, buttons, buttons_size, 2, hover_stylesheet, FALSE, FALSE, hover_stylesheet, 0, BUTTON_ACTION_QUIT, ""); /* id = 8 */

    text_stylesheet = STYLESHEET_BUTTONS_TEXT();
    createText(components, components_size, texts, texts_size, 4, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Nouvelle partie"); /* id = 8 */
    createText(components, components_size, texts, texts_size, 5, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Reprendre une partie"); /* id = 9 */
    createText(components, components_size, texts, texts_size, 6, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres"); /* id = 10 */
    createText(components, components_size, texts, texts_size, 7, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Scoreboard"); /* id = 11 */
    createText(components, components_size, texts, texts_size, 8, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Quitter"); /* id = 12 */
}

void createPlayComponents(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, image_component images[], uint32_t *images_size)
{
    style stylesheet, hover_stylesheet, text_stylesheet;
    
    stylesheet = STYLESHEET_LOGO(top, left, height, width);
    createImage(components, components_size, images, images_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0, "./src/img/logo.png"); /* id = 3 */

    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_TOP();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_TOP();
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 100, BUTTON_ACTION_CREATE_MENU_COMPONENTS, ""); /* id = 4 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_MIDDLE();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE();
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 100, BUTTON_ACTION_CREATE_GAME_SURVIVAL_COMPONENTS, ""); /* id = 5 */
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 100, BUTTON_ACTION_CREATE_GAME_MARATHON_COMPONENTS, ""); /* id = 6 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_BOTTOM();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM();
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 100, BUTTON_ACTION_CREATE_GAME_ULTRA_COMPONENTS, ""); /* id = 7 */

    text_stylesheet = STYLESHEET_BUTTONS_TEXT();
    createText(components, components_size, texts, texts_size, 4, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Retour"); /* id = 8 */
    createText(components, components_size, texts, texts_size, 5, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Mode survie"); /* id = 9 */
    createText(components, components_size, texts, texts_size, 6, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Mode marathon"); /* id = 10 */
    createText(components, components_size, texts, texts_size, 7, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Mode ultra"); /* id = 11 */
}

void createLoadComponents(button_action_type lastPage, double scroll, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size)
{
    style body_stylesheet, stylesheet, stylesheet2, stylesheet3, hover_stylesheet, text_stylesheet;
    int font_height = 0, font_width = 0;
    int id = 0, tmp_id = -1, i, j;
    uint32_t tab_size = 0;
    load tab[64];
    MLV_Font *font_family;
    
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS();
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 100, lastPage, ""); /* id = 3 */

    text_stylesheet = STYLESHEET_BUTTONS_TEXT();
    createText(components, components_size, texts, texts_size, 3, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Retour"); /* id = 4 */

    stylesheet = STYLESHEET_CONTAINER(top, left, height, width);
    stylesheet.padding = 0;
    stylesheet.gap = 0;
    createFrame(components, components_size, 1, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 5 */
    
    text_stylesheet = STYLESHEET_TITLE();
    if(MLV_path_exists(text_stylesheet.font_family))
    {
        font_family = MLV_load_font(text_stylesheet.font_family, text_stylesheet.font_size);
        MLV_get_size_of_text_with_font("Charger une sauvegarde", &font_width, &font_height, font_family);
    }
    stylesheet = STYLESHEET_CONTAINER(top, left, height, width);
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = font_height+stylesheet.padding*2;
    stylesheet.unit_width = UNIT_PERCENTAGE;
    stylesheet.width = 100;
    stylesheet.padding = 0;
    stylesheet.gap = 0;
    createFrame(components, components_size, 5, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 6 */

    stylesheet2 = STYLESHEET_CONTAINER_ROW(top, left, height, width);
    body_stylesheet = STYLESHEET_BODY(top, left, height, width);
    stylesheet2.unit_height = UNIT_PX;
    stylesheet2.height = body_stylesheet.height-2*body_stylesheet.padding-stylesheet.height;
    stylesheet2.border_radius_top_left = 0;
    stylesheet2.border_radius_top_right = 0;
    stylesheet2.border_radius_bottom_left = 0;
    stylesheet2.border_radius_bottom_right = 0;
    createFrame(components, components_size, 5, stylesheet2, FALSE, FALSE, stylesheet2, 0); /* id = 7 */

    stylesheet = STYLESHEET_CONTAINER(top, left, height, width);
    stylesheet.width -= stylesheet2.gap+2*stylesheet2.padding+15;
    stylesheet2.width = stylesheet.width;
    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    stylesheet.padding = 0;
    createFrame(components, components_size, 7, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 8 */

    tab_size = loadGames(tab);

    stylesheet = STYLESHEET_SCROLL();
    createFrame(components, components_size, 7, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 9 */
    stylesheet.background_color = ROOT_WHITE_COLOR();
    stylesheet3 = STYLESHEET_ROW();
    stylesheet3.height = 200;
    stylesheet2.height -= 100;
    stylesheet.height = (int32_t)((stylesheet2.height*100)/(stylesheet3.height*ceil(tab_size/3.)+stylesheet3.gap*(ceil(tab_size/3.)-1)));
    if(stylesheet.height >= 100) {
        stylesheet.height = 100;
        stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    } else if(stylesheet.height <= 0) {
        stylesheet.height = 1;
    }
    if(tab_size == 0) stylesheet.height = 0;
    stylesheet.unit_height = UNIT_PERCENTAGE;
    stylesheet.top = (scroll*(100-stylesheet.height));
    createGrab(components, components_size, 9, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 10 */
    id = 10;

    for(i = 0; i<ceil(tab_size/3.); i++)
    {
        stylesheet = STYLESHEET_ROW();
        stylesheet.unit_top = UNIT_PX;
        stylesheet.top = -((int32_t)(((stylesheet3.height*ceil(tab_size/3.)+stylesheet3.gap*(ceil(tab_size/3.)-1))-stylesheet2.height)*scroll));
        if(stylesheet.top > 0) stylesheet.top = 0;

        stylesheet.height = stylesheet3.height;
        stylesheet2.gap = stylesheet3.gap;

        if((i*(stylesheet.height+stylesheet.gap))+stylesheet.top+stylesheet.height>=-50) {
            if((i*(stylesheet.height+stylesheet.gap))+stylesheet.top+stylesheet.height<=stylesheet2.height+stylesheet3.height+50) {
                createFrame(components, components_size, 8, stylesheet, FALSE, FALSE, stylesheet, 0);
                id++;
                for(j = 0; j<3; j++)
                {
                    if(tab[i*3+j].id != 0) {
                        stylesheet = STYLESHEET_BOX(top, left, height, width);
                        stylesheet.width = (stylesheet2.width-2*stylesheet2.gap)/3;
                        hover_stylesheet = stylesheet;
                        hover_stylesheet.background_color = ROOT_GREY_COLOR();
                        createButton(components, components_size, buttons, buttons_size, id-2*j, stylesheet, TRUE, FALSE, hover_stylesheet, 100, BUTTON_ACTION_LOAD_GAME, tab[i*3+j].path);
                        id++;

                        text_stylesheet = STYLESHEET_BUTTONS_TEXT();
                        text_stylesheet.font_vertical_align = VERTICAL_TOP;
                        text_stylesheet.font_size = 24;
                        createText(components, components_size, texts, texts_size, id, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, tab[i*3+j].name);
                        id++;
                    }
                }
            }
        } else {
            if(tmp_id == -1) {
                createFrame(components, components_size, 8, stylesheet, FALSE, FALSE, stylesheet, 0);
                tmp_id = id;
                id++;
            } else {
                components[tmp_id].stylesheet.height += stylesheet3.height+stylesheet3.gap;
                components[tmp_id].hover_stylesheet.height += stylesheet3.height+stylesheet3.gap;
            }
        }
    }

    stylesheet = STYLESHEET_CONTAINER(top, left, height, width);
    stylesheet.width-= stylesheet2.gap+2*stylesheet2.padding+10;

    stylesheet = STYLESHEET_BODY(top, left, height, width);
    stylesheet.height = stylesheet.padding;
    stylesheet.padding = 0;
    stylesheet.gap = 0;
    createFrame(components, components_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0);
    id++;
    stylesheet.top = height-stylesheet.height;
    createFrame(components, components_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0);
    id++;

    stylesheet = STYLESHEET_CONTAINER(top, left, height, width);
    text_stylesheet = STYLESHEET_TITLE();

    stylesheet.unit_height = UNIT_PERCENTAGE;
    stylesheet.height = 100;
    stylesheet.unit_width = UNIT_PERCENTAGE;
    stylesheet.width = 100;
    stylesheet.padding = 50;
    stylesheet.gap = 0;

    createFrame(components, components_size, 6, stylesheet, FALSE, FALSE, stylesheet, 0);
    id++;
    createText(components, components_size, texts, texts_size, id, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Charger une sauvegarde");
}

void createGameComponents(page_components page, int32_t top, int32_t left, int32_t height, int32_t width, game g, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size)
{
    style stylesheet, container_stylesheet, game_stylesheet, body_stylesheet, title_stylesheet, text_stylesheet;
    char text[64];
    int hours, minutes, seconds;

    game_stylesheet = STYLESHEET_GAME(top, left, height, width);
    createGame(components, components_size, 0, game_stylesheet); /* id = 3 */

    container_stylesheet = STYLESHEET_CONTAINER(top, left, height, width);
    body_stylesheet = STYLESHEET_BODY(top, left, height, width);

    container_stylesheet.unit_top = UNIT_PX;
    container_stylesheet.top = body_stylesheet.padding;
    container_stylesheet.unit_width = UNIT_PX;
    container_stylesheet.width = game_stylesheet.left-body_stylesheet.gap-body_stylesheet.padding;
    container_stylesheet.unit_height = UNIT_PX;
    container_stylesheet.height = 450;
    container_stylesheet.gap = 35;
    container_stylesheet.padding = 20;

    container_stylesheet.unit_left = UNIT_PX;
    container_stylesheet.left = body_stylesheet.padding;

    container_stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    container_stylesheet.border_radius_top_left = 0;
    container_stylesheet.border_radius_top_right = 0;
    container_stylesheet.border_radius_bottom_left = 0;
    container_stylesheet.border_radius_bottom_right = 0;

    createFrame(components, components_size, 0, container_stylesheet, FALSE, FALSE, container_stylesheet, 0); /* id = 3 */

    stylesheet =  STYLESHEET_MINI_CONTAINER(top, left, height, width);
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = (container_stylesheet.height-container_stylesheet.gap-2*container_stylesheet.padding)/2;
    stylesheet.gap = 0;
    stylesheet.padding = 0;
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 4 */

    stylesheet.border_radius_top_left = 0;
    stylesheet.border_radius_top_right = 0;
    stylesheet.border_radius_bottom_left = 0;
    stylesheet.border_radius_bottom_right = 0;
    stylesheet.background_color = ROOT_TRANSPARENT_COLOR();
    stylesheet.childs_direction = DIRECTION_ROW;
    stylesheet.gap = 35;
    stylesheet.padding = 0;
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 5 */

    stylesheet =  STYLESHEET_MINI_CONTAINER(top, left, height, width);
    stylesheet.unit_height = UNIT_PERCENTAGE;
    stylesheet.height = 100;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = (container_stylesheet.width-container_stylesheet.gap-2*container_stylesheet.padding)/2;
    stylesheet.gap = 0;
    stylesheet.padding = 0;
    createFrame(components, components_size, 5, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 6 */
    createFrame(components, components_size, 5, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 7 */

    title_stylesheet = STYLESHEET_BUTTONS_TEXT();
    title_stylesheet.font_horizontal_align = HORIZONTAL_CENTER;
    title_stylesheet.height = 40;
    text_stylesheet = STYLESHEET_TITLE();
    text_stylesheet.font_vertical_align = VERTICAL_CENTER;
    text_stylesheet.font_horizontal_align = HORIZONTAL_CENTER;
    text_stylesheet.unit_height = UNIT_PERCENTAGE;
    text_stylesheet.height = 40;
    text_stylesheet.font_size = 60;

    createText(components, components_size, texts, texts_size, 4, title_stylesheet, FALSE, TRUE, title_stylesheet, 0, "Temps de jeu"); /* id = 8 */
    g.time = g.time / 10000;
    hours = g.time / 3600;
    minutes = (g.time % 3600) / 60;
    seconds = g.time % 60;
    sprintf(text, "%02d:%02d:%02d", hours, minutes, seconds);
    createText(components, components_size, texts, texts_size, 4, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, text); /* id = 9 */

    createText(components, components_size, texts, texts_size, 6, title_stylesheet, FALSE, TRUE, title_stylesheet, 0, "Score"); /* id = 10 */
    sprintf(text, "%d", g.score);
    createText(components, components_size, texts, texts_size, 6, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, text); /* id = 11 */

    createText(components, components_size, texts, texts_size, 7, title_stylesheet, FALSE, TRUE, title_stylesheet, 0, "Lignes"); /* id = 12 */
    sprintf(text, "%d", g.lines);
    createText(components, components_size, texts, texts_size, 7, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, text); /* id = 13 */

    if(page == GAME_POPUP_COMPONENTS) createGamePopupComponents(top, left, height, width, components, components_size, buttons, buttons_size, texts, texts_size);
    if(page == GAME_END_COMPONENTS) createGameEndComponents(top, left, height, width, g, components, components_size, buttons, buttons_size, texts, texts_size);
}

void createGamePopupComponents(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size)
{
    style stylesheet, body_stylesheet, button_stylesheet, button_hover_stylesheet, text_stylesheet;
    
    body_stylesheet = STYLESHEET_HIDE(top, left, height, width);
    createFrame(components, components_size, 0, body_stylesheet, FALSE, FALSE, body_stylesheet, 0); /* id = 14 */

    button_stylesheet = STYLESHEET_SIDEBAR_BUTTONS_TOP();
    button_hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_TOP();

    stylesheet = STYLESHEET_MINI_CONTAINER(top, left, height, width);
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = stylesheet.padding*2+stylesheet.gap*4+button_stylesheet.height*5;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 400;

    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = body_stylesheet.height/2-stylesheet.height/2;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = body_stylesheet.width/2-stylesheet.width/2;
    createFrame(components, components_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 15 */

    createButton(components, components_size, buttons, buttons_size, 15, button_stylesheet, TRUE, FALSE, button_hover_stylesheet, 100, BUTTON_ACTION_RESUME_GAME, ""); /* id = 16 */
    button_stylesheet = STYLESHEET_SIDEBAR_BUTTONS_MIDDLE();
    button_hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE();
    createButton(components, components_size, buttons, buttons_size, 15, button_stylesheet, TRUE, FALSE, button_hover_stylesheet, 100, BUTTON_ACTION_CREATE_SETTINGS_KEYBOARD_COMPONENTS, ""); /* id = 17 */
    createButton(components, components_size, buttons, buttons_size, 15, button_stylesheet, TRUE, FALSE, button_hover_stylesheet, 100, BUTTON_ACTION_CREATE_SCOREBOARD_COMPONENTS, ""); /* id = 18 */
    createButton(components, components_size, buttons, buttons_size, 15, button_stylesheet, TRUE, FALSE, button_hover_stylesheet, 100, BUTTON_ACTION_CREATE_MENU_COMPONENTS, ""); /* id = 19 */
    button_hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM();
    createButton(components, components_size, buttons, buttons_size, 15, button_hover_stylesheet, FALSE, FALSE, button_hover_stylesheet, 0, BUTTON_ACTION_CREATE_MENU_COMPONENTS, ""); /* id = 20 */

    text_stylesheet = STYLESHEET_BUTTONS_TEXT();
    /* text_stylesheet.font_horizontal_align = HORIZONTAL_CENTER; */

    createText(components, components_size, texts, texts_size, 16, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Reprendre"); /* id = 21 */
    createText(components, components_size, texts, texts_size, 17, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres"); /* id = 22 */
    createText(components, components_size, texts, texts_size, 18, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Scoreboard"); /* id = 23 */
    createText(components, components_size, texts, texts_size, 19, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Sauvegarder et quitter"); /* id = 24 */
    createText(components, components_size, texts, texts_size, 20, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Quitter la partie"); /* id = 25 */
}

void createGameEndComponents(int32_t top, int32_t left, int32_t height, int32_t width, game g, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size)
{
    style stylesheet, body_stylesheet, button_stylesheet, button_hover_stylesheet, text_stylesheet;
    button_action_type action_type = BUTTON_ACTION_CREATE_GAME_SURVIVAL_COMPONENTS;
    
    body_stylesheet = STYLESHEET_HIDE(top, left, height, width);
    createFrame(components, components_size, 0, body_stylesheet, FALSE, FALSE, body_stylesheet, 0); /* id = 14 */

    button_stylesheet = STYLESHEET_SIDEBAR_BUTTONS_TOP();
    button_hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_TOP();

    stylesheet = STYLESHEET_MINI_CONTAINER(top, left, height, width);
    stylesheet.unit_height = UNIT_PX;
    stylesheet.height = stylesheet.padding*2+stylesheet.gap*1+button_stylesheet.height*2;
    stylesheet.unit_width = UNIT_PX;
    stylesheet.width = 400;

    stylesheet.unit_top = UNIT_PX;
    stylesheet.top = body_stylesheet.height/2-stylesheet.height/2;
    stylesheet.unit_left = UNIT_PX;
    stylesheet.left = body_stylesheet.width/2-stylesheet.width/2;
    createFrame(components, components_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 15 */

    if(g.mode == GAMEMODE_SURVIVAL) action_type = BUTTON_ACTION_CREATE_GAME_SURVIVAL_COMPONENTS;
    if(g.mode == GAMEMODE_MARATHON) action_type = BUTTON_ACTION_CREATE_GAME_MARATHON_COMPONENTS;
    if(g.mode == GAMEMODE_ULTRA) action_type = BUTTON_ACTION_CREATE_GAME_ULTRA_COMPONENTS;
    createButton(components, components_size, buttons, buttons_size, 15, button_stylesheet, TRUE, FALSE, button_hover_stylesheet, 100, action_type, ""); /* id = 16 */
    button_hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM();
    createButton(components, components_size, buttons, buttons_size, 15, button_hover_stylesheet, FALSE, FALSE, button_hover_stylesheet, 0, BUTTON_ACTION_CREATE_MENU_COMPONENTS, ""); /* id = 17 */

    text_stylesheet = STYLESHEET_BUTTONS_TEXT();
    /* text_stylesheet.font_horizontal_align = HORIZONTAL_CENTER; */

    createText(components, components_size, texts, texts_size, 16, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Réessayer"); /* id = 18 */
    createText(components, components_size, texts, texts_size, 17, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Quitter la partie"); /* id = 19 */
}

void createScoreboardComponents(button_action_type lastPage, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, image_component images[], uint32_t *images_size)
{
    int i, id;
    style stylesheet, hover_stylesheet, text_num_stylesheet, text_stylesheet, text_date_stylesheet, stylesheet_body;
    char num[4];
    char text[64];
    char month[32];
    score tab[10];
    MLV_Font *font_family;
    int32_t font_width;
    
    readScoreboard(tab);

    stylesheet = STYLESHEET_PODIUM(top, left, height, width);
    createImage(components, components_size, images, images_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0, "./src/img/podium.png"); /* id = 3 */

    stylesheet = STYLESHEET_SIDEBAR_BUTTONS();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS();
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 100, lastPage, ""); /* id = 4 */

    text_stylesheet = STYLESHEET_BUTTONS_TEXT();
    createText(components, components_size, texts, texts_size, 4, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Retour"); /* id = 5 */

    stylesheet = STYLESHEET_BOARD(top, left, height, width);
    createFrame(components, components_size, 0, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 6 */

    stylesheet = STYLESHEET_SCORE();
    hover_stylesheet = STYLESHEET_SCORE_NUM();
    text_num_stylesheet = STYLESHEET_SCORE_NUM_TEXT();
    text_stylesheet = STYLESHEET_SCORE_TEXT();
    text_date_stylesheet = STYLESHEET_SCORE_DATE_TEXT();
    id = 6;
    for(i = 4; i<=10; i++) {
        createFrame(components, components_size, 6, stylesheet, FALSE, FALSE, stylesheet, 0);
        id++;
        sprintf(num, "%d", i);
        createFrame(components, components_size, id, hover_stylesheet, FALSE, FALSE, hover_stylesheet, 0);
        id++;
        createText(components, components_size, texts, texts_size, id, text_num_stylesheet, FALSE, TRUE, text_num_stylesheet, 0, num);
        id++;
        getMonth(tab[i-1].when.month, month);
        if(tab[i-1].score == 0) sprintf(text, "---");
        else sprintf(text, "%d", tab[i-1].score);
        createText(components, components_size, texts, texts_size, id-2, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, text);
        id++;

        if(tab[i-1].score != 0)
        {
            sprintf(text, "%d %s %d", tab[i-1].when.day, month, tab[i-1].when.year);
            
            if(MLV_path_exists(text_date_stylesheet.font_family))
            {
                font_family = MLV_load_font(text_date_stylesheet.font_family, text_date_stylesheet.font_size);
                MLV_get_size_of_text_with_font(text, &font_width, NULL, font_family);
                text_date_stylesheet.unit_width = UNIT_PX;
                text_date_stylesheet.width = font_width;
            }
            createText(components, components_size, texts, texts_size, id-3, text_date_stylesheet, FALSE, TRUE, text_date_stylesheet, 0, text);
            id++;
        }
    }


    stylesheet_body = STYLESHEET_BODY(top, left, height, width);
    text_stylesheet = STYLESHEET_BUTTONS_TEXT();
    text_stylesheet.unit_top = UNIT_PX;
    text_stylesheet.top = 60;
    text_stylesheet.unit_left = UNIT_PX;
    text_stylesheet.left = (stylesheet_body.width/2)-(2000/2);
    text_stylesheet.unit_height = UNIT_PX;
    text_stylesheet.height = 125;
    text_stylesheet.unit_width = UNIT_PX;
    text_stylesheet.width = 2000;
    text_stylesheet.font_horizontal_align = HORIZONTAL_CENTER;
    text_stylesheet.color.r = 241;
    text_stylesheet.color.g = 204;
    text_stylesheet.color.b = 76;
    text_stylesheet.color.a = 255;
    strcpy(text_stylesheet.font_family, FONT_POPPINS_BLACK);
    text_stylesheet.font_size = 95;
    if(tab[0].score == 0) sprintf(text, "---");
    else sprintf(text, "%d", tab[0].score);
    createText(components, components_size, texts, texts_size, 0, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, text);
    text_stylesheet.top = 130;
    text_stylesheet.font_size = 22;
    text_stylesheet.color.r = 181;
    text_stylesheet.color.g = 153;
    text_stylesheet.color.b = 57;
    getMonth(tab[0].when.month, month);
    if(tab[0].score != 0)
    {
        sprintf(text, "%d %s %d", tab[0].when.day, month, tab[0].when.year);
        createText(components, components_size, texts, texts_size, 0, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, text);
    }
    text_stylesheet.top = 213;
    text_stylesheet.font_size = 52;
    text_stylesheet.width = 1500;
    text_stylesheet.color.r = 116;
    text_stylesheet.color.g = 117;
    text_stylesheet.color.b = 135;
    if(tab[1].score == 0) sprintf(text, "---");
    else sprintf(text, "%d", tab[1].score);
    createText(components, components_size, texts, texts_size, 0, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, text);
    text_stylesheet.top = 272;
    text_stylesheet.font_size = 18;
    text_stylesheet.width = 1475;
    getMonth(tab[1].when.month, month);
    if(tab[1].score != 0)
    {
        sprintf(text, "%d %s %d", tab[1].when.day, month, tab[1].when.year);
        createText(components, components_size, texts, texts_size, 0, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, text);
    }
    text_stylesheet.top = 278;
    text_stylesheet.font_size = 52;
    text_stylesheet.width = 2500;
    text_stylesheet.color.r = 189;
    text_stylesheet.color.g = 125;
    text_stylesheet.color.b = 78;
    if(tab[2].score == 0) sprintf(text, "---");
    else sprintf(text, "%d", tab[2].score);
    createText(components, components_size, texts, texts_size, 0, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, text);
    text_stylesheet.top = 337;
    text_stylesheet.font_size = 18;
    text_stylesheet.width = 2525;
    getMonth(tab[2].when.month, month);
    if(tab[2].score != 0)
    {
        sprintf(text, "%d %s %d", tab[2].when.day, month, tab[2].when.year);
        createText(components, components_size, texts, texts_size, 0, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, text);
    }
}

void createSettingsComponents(page_components page, button_action_type lastPage, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, key_component keys[], uint32_t *keys_size, settings set)
{
    style stylesheet, hover_stylesheet, text_stylesheet;

    stylesheet = STYLESHEET_CONTAINER(top, left, height, width);
    createFrame(components, components_size, 1, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 3 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_TOP();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_TOP();
    createButton(components, components_size, buttons, buttons_size, 2, stylesheet, TRUE, FALSE, hover_stylesheet, 100, lastPage, ""); /* id = 4 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_MIDDLE();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE();
    createButton(components, components_size, buttons, buttons_size, 2, (page==SETTINGS_KEYBOARD_COMPONENTS)?hover_stylesheet:stylesheet, (page==SETTINGS_KEYBOARD_COMPONENTS)?FALSE:TRUE, FALSE, hover_stylesheet, 100, BUTTON_ACTION_CREATE_SETTINGS_KEYBOARD_COMPONENTS, ""); /* id = 5 */
    createButton(components, components_size, buttons, buttons_size, 2, (page==SETTINGS_VIDEO_COMPONENTS)?hover_stylesheet:stylesheet, (page==SETTINGS_VIDEO_COMPONENTS)?FALSE:TRUE, FALSE, hover_stylesheet, 100, BUTTON_ACTION_CREATE_SETTINGS_VIDEO_COMPONENTS, ""); /* id = 6 */
    stylesheet = STYLESHEET_SIDEBAR_BUTTONS_BOTTOM();
    hover_stylesheet = STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM();
    createButton(components, components_size, buttons, buttons_size, 2, (page==SETTINGS_GRAPHICS_COMPONENTS)?hover_stylesheet:stylesheet, (page==SETTINGS_GRAPHICS_COMPONENTS)?FALSE:TRUE, FALSE, hover_stylesheet, 100, BUTTON_ACTION_CREATE_SETTINGS_GRAPHICS_COMPONENTS, ""); /* id = 7 */

    text_stylesheet = STYLESHEET_BUTTONS_TEXT();
    createText(components, components_size, texts, texts_size, 4, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Retour"); /* id = 8 */
    createText(components, components_size, texts, texts_size, 5, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Clavier & Souris"); /* id = 9 */
    createText(components, components_size, texts, texts_size, 6, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres vidéo"); /* id = 10 */
    createText(components, components_size, texts, texts_size, 7, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres graphique"); /* id = 11 */

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
        default:
            break;
    }
}

void createSettingsKeyboardComponents(component components[], uint32_t *components_size, text_component texts[], uint32_t *texts_size, key_component keys[], uint32_t *keys_size, settings set)
{
    style stylesheet, hover_stylesheet, text_stylesheet;
    MLV_Font *font_family;
    int font_height = 0;
    char key[16];

    text_stylesheet = STYLESHEET_TITLE();
    if(MLV_path_exists(text_stylesheet.font_family))
    {
        font_family = MLV_load_font(text_stylesheet.font_family, text_stylesheet.font_size);
        MLV_get_size_of_text_with_font("Scroll", NULL, &font_height, font_family);
    }
    text_stylesheet.height = font_height;
    createText(components, components_size, texts, texts_size, 3, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Commandes clavier & souris"); /* id = 12 */

    stylesheet = STYLESHEET_VOID();
    stylesheet.height = 20;
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 13 */

    text_stylesheet = STYLESHEET_MINI_TITLE();
    if(MLV_path_exists(text_stylesheet.font_family))
    {
        font_family = MLV_load_font(text_stylesheet.font_family, text_stylesheet.font_size);
        MLV_get_size_of_text_with_font("Déplacement", NULL, &font_height, font_family);
    }
    text_stylesheet.height = font_height;
    createText(components, components_size, texts, texts_size, 3, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Déplacement"); /* id = 14 */

    stylesheet = STYLESHEET_ROW();
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 15 */
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 16 */
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 17 */
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 18 */
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 19 */
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 20 */
    
    text_stylesheet = STYLESHEET_TEXT();
    createText(components, components_size, texts, texts_size, 15, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Déplacer à gauche"); /* id = 21 */
    createText(components, components_size, texts, texts_size, 16, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Déplacer à droite"); /* id = 22 */
    createText(components, components_size, texts, texts_size, 17, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Tourner à gauche"); /* id = 23 */
    createText(components, components_size, texts, texts_size, 18, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Tourner à droite"); /* id = 24 */
    createText(components, components_size, texts, texts_size, 19, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Descente rapide"); /* id = 25 */
    createText(components, components_size, texts, texts_size, 20, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Mettre pause"); /* id = 26 */

    stylesheet = STYLESHEET_KEY();
    hover_stylesheet = STYLESHEET_HOVERED_KEY();
    getKeyFromMLV(set.keyboard_move_left, key);
    createKey(components, components_size, keys, keys_size, 15, stylesheet, TRUE, FALSE, hover_stylesheet, 100, KEY_TAKE_MOVE_LEFT, key); /* id = 27 */
    getKeyFromMLV(set.keyboard_move_right, key);
    createKey(components, components_size, keys, keys_size, 16, stylesheet, TRUE, FALSE, hover_stylesheet, 100, KEY_TAKE_MOVE_RIGHT, key); /* id = 28 */
    getKeyFromMLV(set.keyboard_turn_left, key);
    createKey(components, components_size, keys, keys_size, 17, stylesheet, TRUE, FALSE, hover_stylesheet, 100, KEY_TAKE_TURN_LEFT, key); /* id = 29 */
    getKeyFromMLV(set.keyboard_turn_right, key);
    createKey(components, components_size, keys, keys_size, 18, stylesheet, TRUE, FALSE, hover_stylesheet, 100, KEY_TAKE_TURN_RIGHT, key); /* id = 30 */
    getKeyFromMLV(set.keyboard_fast_drop, key);
    createKey(components, components_size, keys, keys_size, 19, stylesheet, TRUE, FALSE, hover_stylesheet, 100, KEY_TAKE_FAST_DROP, key); /* id = 31 */
    getKeyFromMLV(set.keyboard_pause, key);
    createKey(components, components_size, keys, keys_size, 20, stylesheet, TRUE, FALSE, hover_stylesheet, 100, KEY_TAKE_PAUSE, key); /* id = 32 */

    stylesheet = STYLESHEET_VOID();
    stylesheet.height = 20;
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 33 */

    text_stylesheet = STYLESHEET_MINI_TITLE();
    if(MLV_path_exists(text_stylesheet.font_family))
    {
        font_family = MLV_load_font(text_stylesheet.font_family, text_stylesheet.font_size);
        MLV_get_size_of_text_with_font("Scroll", NULL, &font_height, font_family);
    }
    text_stylesheet.height = font_height;
    createText(components, components_size, texts, texts_size, 3, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Scroll"); /* id = 34 */

    stylesheet = STYLESHEET_ROW();
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 35 */
    createFrame(components, components_size, 3, stylesheet, FALSE, FALSE, stylesheet, 0); /* id = 36 */
    
    text_stylesheet = STYLESHEET_TEXT();
    createText(components, components_size, texts, texts_size, 35, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Scroll vers le haut"); /* id = 37 */
    createText(components, components_size, texts, texts_size, 36, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Scroll vers le bas"); /* id = 38 */

    stylesheet = STYLESHEET_KEY();
    hover_stylesheet = STYLESHEET_HOVERED_KEY();
    getKeyFromMLV(set.keyboard_scroll_up, key);
    createKey(components, components_size, keys, keys_size, 35, stylesheet, TRUE, FALSE, hover_stylesheet, 100, KEY_TAKE_SCROLL_UP, key); /* id = 39 */
    getKeyFromMLV(set.keyboard_scroll_down, key);
    createKey(components, components_size, keys, keys_size, 36, stylesheet, TRUE, FALSE, hover_stylesheet, 100, KEY_TAKE_SCROLL_DOWN, key); /* id = 40 */
}
void createSettingsVideoComponents(component components[], uint32_t *components_size, text_component texts[], uint32_t *texts_size)
{
    style text_stylesheet;

    text_stylesheet = STYLESHEET_TITLE();
    createText(components, components_size, texts, texts_size, 3, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres vidéo"); /* id = 12 */
}
void createSettingsGraphicsComponents(component components[], uint32_t *components_size, text_component texts[], uint32_t *texts_size)
{
    style text_stylesheet;

    text_stylesheet = STYLESHEET_TITLE();
    createText(components, components_size, texts, texts_size, 3, text_stylesheet, FALSE, TRUE, text_stylesheet, 0, "Paramètres graphique"); /* id = 12 */
}