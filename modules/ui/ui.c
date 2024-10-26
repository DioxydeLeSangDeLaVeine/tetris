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

style styleTransition(component component) {
    style stylesheet;
    if(component.is_hoverable==FALSE) return component.stylesheet;

    stylesheet.background_color.r = (int)(component.stylesheet.background_color.r*(1-component.__transition)+component.hover_stylesheet.background_color.r*component.__transition);
    stylesheet.background_color.g = (int)(component.stylesheet.background_color.g*(1-component.__transition)+component.hover_stylesheet.background_color.g*component.__transition);
    stylesheet.background_color.b = (int)(component.stylesheet.background_color.b*(1-component.__transition)+component.hover_stylesheet.background_color.b*component.__transition);
    stylesheet.background_color.a = (int)(component.stylesheet.background_color.a*(1-component.__transition)+component.hover_stylesheet.background_color.a*component.__transition);
    stylesheet.color.r = (int)(component.stylesheet.color.r*(1-component.__transition)+component.hover_stylesheet.color.r*component.__transition);
    stylesheet.color.g = (int)(component.stylesheet.color.g*(1-component.__transition)+component.hover_stylesheet.color.g*component.__transition);
    stylesheet.color.b = (int)(component.stylesheet.color.b*(1-component.__transition)+component.hover_stylesheet.color.b*component.__transition);
    stylesheet.color.a = (int)(component.stylesheet.color.a*(1-component.__transition)+component.hover_stylesheet.color.a*component.__transition);
    if(component.__transition>0.5) strcpy(stylesheet.font_family, component.hover_stylesheet.font_family);
    else strcpy(stylesheet.font_family, component.stylesheet.font_family);
    stylesheet.font_size = (int)(component.stylesheet.font_size*(1-component.__transition)+component.hover_stylesheet.font_size*component.__transition);
    stylesheet.border_radius = (int)(component.stylesheet.border_radius*(1-component.__transition)+component.hover_stylesheet.border_radius*component.__transition);

    stylesheet.top = (int)(component.stylesheet.top*(1-component.__transition)+component.hover_stylesheet.top*component.__transition);
    stylesheet.left = (int)(component.stylesheet.left*(1-component.__transition)+component.hover_stylesheet.left*component.__transition);
    stylesheet.height = (int)(component.stylesheet.height*(1-component.__transition)+component.hover_stylesheet.height*component.__transition);
    stylesheet.width = (int)(component.stylesheet.width*(1-component.__transition)+component.hover_stylesheet.width*component.__transition);

    return stylesheet;
}

void drawComponent(component component)
{
    FILE* file;
    MLV_Font *font_family;
    style stylesheet;
    int font_height = 0;

    stylesheet = styleTransition(component);

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

void createFrame(component components[], int *components_size, style stylesheet, boolean is_hoverable, style hover_stylesheet, int transition_duration, int top, int left, int height, int width)
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
    cmp.transition_duration = transition_duration;
    cmp.__transition = 0;

    components[(*components_size)++] = cmp;
}

void createButton(component components[], int *components_size, button_component buttons[], int *buttons_size, char content[], style stylesheet, boolean is_hoverable, style hover_stylesheet, int transition_duration, button_action_type action_type, int top, int left, int height, int width)
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
    cmp.transition_duration = transition_duration;
    cmp.__transition = 0;

    btn_cmp.id = (*components_size)+1;
    btn_cmp.action_type = action_type;
    components[(*components_size)++] = cmp;
    buttons[(*buttons_size)++] = btn_cmp;
}