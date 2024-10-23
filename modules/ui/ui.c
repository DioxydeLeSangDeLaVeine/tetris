#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "ui.h"

int __min(int a, int b) {
    return a<=b?a:b;
}
int __max(int a, int b) {
    return a>=b?a:b;
}

void addComponent(ButtonComponent components[], int components_size, int action_type, int top, int left, int width, int height, int radius, rgb color)
{
    /**
     * @param {ButtonComponent} components
     * @param {int} components_size
     * @param {int} top
     * @param {int} left
     * @param {int} width
     * @param {int} height
     * @param {int} radius
     * @param {rgb} color
     */
    
    components[components_size].action_type = action_type;
    components[components_size].top = top;
    components[components_size].left = left;
    components[components_size].width = width;
    components[components_size].height = height;
    components[components_size].radius = radius;
    components[components_size].bg_color.r = color.r;
    components[components_size].bg_color.g = color.g;
    components[components_size].bg_color.b = color.b;

    /*
        CONTENT OF THE BUTTON
    */
    MLV_draw_filled_rectangle(left+radius, top, width-(2*radius), height, MLV_rgba(color.r, color.g, color.b, 255));
    MLV_draw_filled_rectangle(left, top+radius, width, height-(2*radius), MLV_rgba(color.r, color.g, color.b, 255));

    /*
        BORDER RADIUS OF THE BUTTON
    */
    MLV_draw_filled_circle(left+radius, top+radius-1, radius-1, MLV_rgba(color.r, color.g, color.b, 255));
    MLV_draw_filled_circle(left+radius, top+height-radius, radius-1, MLV_rgba(color.r, color.g, color.b, 255));
    MLV_draw_filled_circle(left+width-radius-1, top+radius-1, radius-1, MLV_rgba(color.r, color.g, color.b, 255));
    MLV_draw_filled_circle(left+width-radius-1, top+height-radius, radius-1, MLV_rgba(color.r, color.g, color.b, 255));
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
    }

    addComponent(components, components_size++, 1, sidebar_frame_padding+(0*(button_height+sidebar_frame_gap)), sidebar_frame_padding, button_width, button_height, 16, primary_color);
    addComponent(components, components_size++, -1, sidebar_frame_padding+(1*(button_height+sidebar_frame_gap)), sidebar_frame_padding, button_width, button_height, 16, button_color);
    addComponent(components, components_size++, -1, sidebar_frame_padding+(2*(button_height+sidebar_frame_gap)), sidebar_frame_padding, button_width, button_height, 16, button_color);
    
    addComponent(components, components_size++, 0, height-sidebar_frame_padding-button_height, sidebar_frame_padding, button_width, button_height, 16, danger_color);
    
    return components_size;
}