#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <string.h>
#include "ui.h"

int __min(int a, int b) {
    return a<=b?a:b;
}
int __max(int a, int b) {
    return a>=b?a:b;
}

void drawButton(ButtonComponent button, int hovered) {
    MLV_Font *txt_font = MLV_load_font(button.font, button.font_size);
    int font_height = 0;
    rgb bg_color;
    rgb font_color;

    bg_color = (hovered==1||!button.hoverable)?button.hovered_bg_color:button.bg_color;
    font_color = (hovered==1||!button.hoverable)?button.hovered_font_color:button.font_color;
    /*
        CONTENT OF THE BUTTON
    */
    MLV_draw_filled_rectangle(button.left+button.radius, button.top, button.width-(2*button.radius), button.height, MLV_rgba(bg_color.r, bg_color.g, bg_color.b, 255));
    MLV_draw_filled_rectangle(button.left, button.top+button.radius, button.width, button.height-(2*button.radius), MLV_rgba(bg_color.r, bg_color.g, bg_color.b, 255));

    /*
        BORDER RADIUS OF THE BUTTON
    */
    MLV_draw_filled_circle(button.left+button.radius, button.top+button.radius-1, button.radius-1, MLV_rgba(bg_color.r, bg_color.g, bg_color.b, 255));
    MLV_draw_filled_circle(button.left+button.radius, button.top+button.height-button.radius, button.radius-1, MLV_rgba(bg_color.r, bg_color.g, bg_color.b, 255));
    MLV_draw_filled_circle(button.left+button.width-button.radius-1, button.top+button.radius-1, button.radius-1, MLV_rgba(bg_color.r, bg_color.g, bg_color.b, 255));
    MLV_draw_filled_circle(button.left+button.width-button.radius-1, button.top+button.height-button.radius, button.radius-1, MLV_rgba(bg_color.r, bg_color.g, bg_color.b, 255));

    if(txt_font != NULL) {
        MLV_get_size_of_text_with_font(button.content, NULL, &font_height, txt_font);
        MLV_draw_text_with_font(button.left+20, button.top+(button.height/2)-(font_height/2), button.content, txt_font, MLV_rgba(font_color.r, font_color.g, font_color.b, 255));
        
        MLV_free_font(txt_font);
    }
}

void addComponent(ButtonComponent components[], int components_size, int action_type, int hoverable, int top, int left, int width, int height, int radius, rgb bg_color, rgb hovered_bg_color, char content[], char font[], int font_size, rgb font_color, rgb hovered_font_color)
{
    ButtonComponent button;
    button.id = components_size+1;
    button.action_type = action_type;
    button.hoverable = hoverable;
    button.top = top;
    button.left = left;
    button.width = width;
    button.height = height;
    button.radius = radius;
    button.bg_color = bg_color;
    button.hovered_bg_color = hovered_bg_color;
    strcpy(button.content, content);
    strcpy(button.font, font);
    button.font_size = font_size;
    button.font_color = font_color;
    button.hovered_font_color = hovered_font_color;
    
    components[components_size] = button;

    drawButton(button, 0);
}

int menu(int width, int height, ButtonComponent components[])
{
    /**
     * Returns the numbers of ButtonComponents
     *
     * @param {int} width
     * @param {int} height
     * @param {ButtonComponent} components
     * @returns {int}
     */
    
    int components_size = 0;

    /*
        DEFINE SIDEBAR FRAME
    */

    int sidebar_frame_width = __min(300, __max(width/75, 500));
    int sidebar_frame_height = height;
    int sidebar_frame_padding = 20;
    int sidebar_frame_gap = 20;

    /*
        DEFINE BUTTONS STYLE
    */

    int button_height = 65;
    int button_width = sidebar_frame_width-(2*sidebar_frame_padding);

    /*
        DEFINE LOGO
    */

    MLV_Image *logo = MLV_load_image("./src/img/logo2.png");
    float logo_width, logo_height, logo_ratio;

    /*
        DEFINE ROOT COLORS
    */

    rgb primary_color, secondary_color, black_color, button_color, white_color, danger_color;
    primary_color.r = 0;
    primary_color.g = 160;
    primary_color.b = 224;

    secondary_color.r = 10;
    secondary_color.g = 14;
    secondary_color.b = 24;

    black_color.r = 5;
    black_color.g = 7;
    black_color.b = 12;

    button_color.r = 19;
    button_color.g = 25;
    button_color.b = 41;

    white_color.r = 245;
    white_color.g = 245;
    white_color.b = 255;

    danger_color.r = 234;
    danger_color.g = 10;
    danger_color.b = 42;

    /*
        RESIZE LOGO
    */

    if(logo != NULL) {
        logo_width = (float)MLV_get_image_width(logo);
        logo_height = (float)MLV_get_image_height(logo);

        logo_ratio = logo_height/logo_width;
        logo_width = __min(800, width-sidebar_frame_width-200);
        logo_height = (int)(logo_width*logo_ratio);
        MLV_resize_image(logo, logo_width, logo_height);
    }

    /*
        CONTENT OF THE MENU PAGE
    */

    MLV_draw_filled_rectangle(0, 0, width, height, MLV_rgba(black_color.r, black_color.g, black_color.b, 255));
    MLV_draw_filled_rectangle(0, 0, sidebar_frame_width, sidebar_frame_height, MLV_rgba(secondary_color.r,secondary_color.g,secondary_color.b,255));
    
    if(logo != NULL) {
        MLV_draw_image(logo, sidebar_frame_width+((width-sidebar_frame_width)/2)-(logo_width/2), (height/2)-(logo_height/2));
        MLV_free_image(logo);
    }

    addComponent(components, components_size++, 1, 1, sidebar_frame_padding+(0*(button_height+sidebar_frame_gap)), sidebar_frame_padding, button_width, button_height, 16, primary_color, black_color, "Jouer", POPPINS_MEDIUM, 20, white_color, white_color);
    addComponent(components, components_size++, -1, 0, sidebar_frame_padding+(1*(button_height+sidebar_frame_gap)), sidebar_frame_padding, button_width, button_height, 16, button_color, button_color, "Paramètres", POPPINS_MEDIUM, 20, white_color, white_color);
    addComponent(components, components_size++, -1, 0, sidebar_frame_padding+(2*(button_height+sidebar_frame_gap)), sidebar_frame_padding, button_width, button_height, 16, button_color, button_color, "Scoreboard", POPPINS_MEDIUM, 20, white_color, white_color);
    
    addComponent(components, components_size++, 0, 0, height-sidebar_frame_padding-button_height, sidebar_frame_padding, button_width, button_height, 16, danger_color, danger_color, "Quitter", POPPINS_MEDIUM, 20, white_color, white_color);
    
    return components_size;
}