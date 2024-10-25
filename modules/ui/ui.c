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

boolean idboxComponent(component component, int x, int y)
{
    style stylesheet;
    int dx, dy;
    stylesheet = (component.is_hovered==TRUE&&component.is_hoverable==TRUE)?component.hover_stylesheet:component.stylesheet;

    if(stylesheet.top <= y
    && stylesheet.top + stylesheet.height >= y
    && stylesheet.left + stylesheet.border_radius <= x
    && stylesheet.left + stylesheet.width - (2 * stylesheet.border_radius) >= x) return TRUE;
    if(stylesheet.top + stylesheet.border_radius <= y
    && stylesheet.top + stylesheet.height - (2 * stylesheet.border_radius) >= y
    && stylesheet.left <= x
    && stylesheet.left + stylesheet.width >= x) return TRUE;

    dx = x - (stylesheet.left+stylesheet.border_radius);
    dy = y - (stylesheet.top+stylesheet.border_radius-1);
    if((dx*dx+dy*dy)<=(stylesheet.border_radius*stylesheet.border_radius)) return TRUE;
    dx = x - (stylesheet.left+stylesheet.border_radius);
    dy = y - (stylesheet.top+stylesheet.height-stylesheet.border_radius);
    if((dx*dx+dy*dy)<=(stylesheet.border_radius*stylesheet.border_radius)) return TRUE;
    dx = x - (stylesheet.left+stylesheet.width-stylesheet.border_radius-1);
    dy = y - (stylesheet.top+stylesheet.border_radius-1);
    if((dx*dx+dy*dy)<=(stylesheet.border_radius*stylesheet.border_radius)) return TRUE;
    dx = x - (stylesheet.left+stylesheet.width-stylesheet.border_radius-1);
    dy = y - (stylesheet.top+stylesheet.height-stylesheet.border_radius);
    if((dx*dx+dy*dy)<=(stylesheet.border_radius*stylesheet.border_radius)) return TRUE;
    return FALSE;
}

void drawComponents(component components[], int components_size) {
    int i;
    for(i = 0; i<components_size; i++)
    {
        drawComponent(components[i]);
    }
}

void drawComponent(component component)
{
    FILE* file;
    MLV_Font *font_family;
    style stylesheet;
    int font_height = 0;

    stylesheet = (component.is_hovered==TRUE&&component.is_hoverable==TRUE)?component.hover_stylesheet:component.stylesheet;

    if(stylesheet.border_radius>stylesheet.height/2||stylesheet.border_radius>stylesheet.width/2) stylesheet.border_radius = __min(stylesheet.width/2, stylesheet.height/2);

    /*
        CONTENT OF THE COMPONENT
    */
    MLV_draw_filled_rectangle(stylesheet.left+stylesheet.border_radius, stylesheet.top, stylesheet.width-(2*stylesheet.border_radius), stylesheet.height, MLV_rgba(stylesheet.background_color.r, stylesheet.background_color.g, stylesheet.background_color.b, stylesheet.background_color.a));
    MLV_draw_filled_rectangle(stylesheet.left, stylesheet.top+stylesheet.border_radius, stylesheet.width, stylesheet.height-(2*stylesheet.border_radius), MLV_rgba(stylesheet.background_color.r, stylesheet.background_color.g, stylesheet.background_color.b, stylesheet.background_color.a));

    /*
        BORDER RADIUS OF THE COMPONENT
    */
    MLV_draw_filled_circle(stylesheet.left+stylesheet.border_radius, stylesheet.top+stylesheet.border_radius-1, stylesheet.border_radius-1, MLV_rgba(stylesheet.background_color.r, stylesheet.background_color.g, stylesheet.background_color.b, stylesheet.background_color.a));
    MLV_draw_filled_circle(stylesheet.left+stylesheet.border_radius, stylesheet.top+stylesheet.height-stylesheet.border_radius, stylesheet.border_radius-1, MLV_rgba(stylesheet.background_color.r, stylesheet.background_color.g, stylesheet.background_color.b, stylesheet.background_color.a));
    MLV_draw_filled_circle(stylesheet.left+stylesheet.width-stylesheet.border_radius-1, stylesheet.top+stylesheet.border_radius-1, stylesheet.border_radius-1, MLV_rgba(stylesheet.background_color.r, stylesheet.background_color.g, stylesheet.background_color.b, stylesheet.background_color.a));
    MLV_draw_filled_circle(stylesheet.left+stylesheet.width-stylesheet.border_radius-1, stylesheet.top+stylesheet.height-stylesheet.border_radius, stylesheet.border_radius-1, MLV_rgba(stylesheet.background_color.r, stylesheet.background_color.g, stylesheet.background_color.b, stylesheet.background_color.a));
    
    file = fopen(stylesheet.font_family, "r");
    if(file != NULL) {
        fclose(file);
        font_family = MLV_load_font(stylesheet.font_family, stylesheet.font_size);
        MLV_get_size_of_text_with_font(component.content, NULL, &font_height, font_family);
        MLV_draw_text_with_font(stylesheet.left+20, stylesheet.top+(stylesheet.height/2)-(font_height/2), component.content, font_family, MLV_rgba(stylesheet.color.r, stylesheet.color.g, stylesheet.color.b, stylesheet.color.a));
        
        MLV_free_font(font_family);
    }
}

void createFrame(component components[], int *components_size, style stylesheet, boolean is_hoverable, style hover_stylesheet, int top, int left, int height, int width)
{
    component cmp;
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;

    cmp.id = (*components_size)+1;
    cmp.type = COMPONENT_BUTTON;
    strcpy(cmp.content, "");
    stylesheet.top = top;
    stylesheet.left = left;
    stylesheet.width = width;
    stylesheet.height = height;
    hover_stylesheet.top = top;
    hover_stylesheet.left = left;
    hover_stylesheet.width = width;
    hover_stylesheet.height = height;
    cmp.stylesheet = stylesheet;
    cmp.is_hoverable = is_hoverable;
    cmp.is_hovered = FALSE;
    cmp.hover_stylesheet = hover_stylesheet;

    components[(*components_size)++] = cmp;
}

void createButton(component components[], int *components_size, button_component buttons[], int *buttons_size, char content[], style stylesheet, boolean is_hoverable, style hover_stylesheet, button_action_type action_type, int top, int left, int height, int width)
{
    component cmp;
    button_component btn_cmp;
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;

    cmp.id = (*components_size)+1;
    cmp.type = COMPONENT_BUTTON;
    strcpy(cmp.content, content);
    stylesheet.top = top;
    stylesheet.left = left;
    stylesheet.width = width;
    stylesheet.height = height;
    hover_stylesheet.top = top;
    hover_stylesheet.left = left;
    hover_stylesheet.width = width;
    hover_stylesheet.height = height;
    cmp.stylesheet = stylesheet;
    cmp.is_hoverable = is_hoverable;
    cmp.is_hovered = FALSE;
    cmp.hover_stylesheet = hover_stylesheet;

    btn_cmp.id = (*components_size)+1;
    btn_cmp.action_type = action_type;
    components[(*components_size)++] = cmp;
    buttons[(*buttons_size)++] = btn_cmp;
}