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

void addComponent(ButtonComponent components[], int size, int top, int left, int width, int height, int radius, rgb color)
{
    /**
     * @param {ButtonComponent} components
     * @param {int} size
     * @param {int} top
     * @param {int} left
     * @param {int} width
     * @param {int} height
     * @param {int} radius
     * @param {rgb} color
     */
    
    components[size].top = top;
    components[size].left = left;
    components[size].width = width;
    components[size].height = height;
    components[size].radius = radius;
    components[size].bg_color.r = color.r;
    components[size].bg_color.g = color.g;
    components[size].bg_color.b = color.b;

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
    
    int size = 0;
    int frame1_width = __min(300, __max(width/75, 500));
    int frame1_padding = 20, frame1_gap = 20, frame1_button_height = 65;
    rgb primary_color, secondary_color, tertiary_color;
    MLV_Image *logo = MLV_load_image("./src/img/logo.png");
    float logo_width, logo_height, logo_ratio;
    if(logo == NULL) return -1;
    
    logo_width = (float)MLV_get_image_width(logo);
    logo_height = (float)MLV_get_image_height(logo);

    logo_ratio = logo_height/logo_width;
    logo_width = __min(800, width-frame1_width-200);
    logo_height = (int)(logo_width*logo_ratio);
    MLV_resize_image(logo, logo_width, logo_height);

    primary_color.r = 255;
    primary_color.g = 80;
    primary_color.b = 96;
    secondary_color.r = 10;
    secondary_color.g = 14;
    secondary_color.b = 24;
    tertiary_color.r = 5;
    tertiary_color.g = 7;
    tertiary_color.b = 12;

    MLV_draw_filled_rectangle(0, 0, width, height, MLV_rgba(tertiary_color.r, tertiary_color.g, tertiary_color.b, 255));
    MLV_draw_filled_rectangle(0, 0, frame1_width, height, MLV_rgba(secondary_color.r,secondary_color.g,secondary_color.b,255));

    MLV_draw_image(logo, frame1_width+((width-frame1_width)/2)-(logo_width/2), (height/2)-(logo_height/2));

    addComponent(components, size++, frame1_padding+(0*(frame1_button_height+frame1_gap)), frame1_padding, frame1_width-(2*frame1_padding), frame1_button_height, 16, primary_color);
    addComponent(components, size++, frame1_padding+(1*(frame1_button_height+frame1_gap)), frame1_padding, frame1_width-(2*frame1_padding), frame1_button_height, 16, primary_color);
    addComponent(components, size++, frame1_padding+(2*(frame1_button_height+frame1_gap)), frame1_padding, frame1_width-(2*frame1_padding), frame1_button_height, 16, primary_color);
    
    addComponent(components, size++, height-frame1_padding-frame1_button_height, frame1_padding, frame1_width-(2*frame1_padding), frame1_button_height, 16, primary_color);
    return size;
}