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

style styleTransition(component component) {
    style stylesheet;
    if(component.is_hoverable==FALSE) {
        if(component.stylesheet.border_radius_top_left != 0)
        {
            if(component.stylesheet.border_radius_top_left>component.stylesheet.height/2||component.stylesheet.border_radius_top_left>component.stylesheet.width/2) component.stylesheet.border_radius_top_left = __min(component.stylesheet.width/2, component.stylesheet.height/2);
        }
        if(component.stylesheet.border_radius_top_right != 0)
        {
            if(component.stylesheet.border_radius_top_right>component.stylesheet.height/2||component.stylesheet.border_radius_top_right>component.stylesheet.width/2) component.stylesheet.border_radius_top_right = __min(component.stylesheet.width/2, component.stylesheet.height/2);
        }
        if(component.stylesheet.border_radius_bottom_left != 0)
        {
            if(component.stylesheet.border_radius_bottom_left>component.stylesheet.height/2||component.stylesheet.border_radius_bottom_left>component.stylesheet.width/2) component.stylesheet.border_radius_bottom_left = __min(component.stylesheet.width/2, component.stylesheet.height/2);
        }
        if(component.stylesheet.border_radius_bottom_right != 0)
        {
            if(component.stylesheet.border_radius_bottom_right>component.stylesheet.height/2||component.stylesheet.border_radius_bottom_right>component.stylesheet.width/2) component.stylesheet.border_radius_bottom_right = __min(component.stylesheet.width/2, component.stylesheet.height/2);
        }
        return component.stylesheet;
    }

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
    stylesheet.font_horizontal_align = (horizontal_align)(component.stylesheet.font_horizontal_align*(1-component.__transition)+component.hover_stylesheet.font_horizontal_align*component.__transition);
    stylesheet.font_vertical_align = (vertical_align)(component.stylesheet.font_vertical_align*(1-component.__transition)+component.hover_stylesheet.font_vertical_align*component.__transition);
    stylesheet.top = (int)(component.stylesheet.top*(1-component.__transition)+component.hover_stylesheet.top*component.__transition);
    stylesheet.left = (int)(component.stylesheet.left*(1-component.__transition)+component.hover_stylesheet.left*component.__transition);
    stylesheet.height = (int)(component.stylesheet.height*(1-component.__transition)+component.hover_stylesheet.height*component.__transition);
    stylesheet.width = (int)(component.stylesheet.width*(1-component.__transition)+component.hover_stylesheet.width*component.__transition);
    stylesheet.border_radius_top_left = (int)(component.stylesheet.border_radius_top_left*(1-component.__transition)+component.hover_stylesheet.border_radius_top_left*component.__transition);
    stylesheet.border_radius_top_right = (int)(component.stylesheet.border_radius_top_right*(1-component.__transition)+component.hover_stylesheet.border_radius_top_right*component.__transition);
    stylesheet.border_radius_bottom_left = (int)(component.stylesheet.border_radius_bottom_left*(1-component.__transition)+component.hover_stylesheet.border_radius_bottom_left*component.__transition);
    stylesheet.border_radius_bottom_right = (int)(component.stylesheet.border_radius_bottom_right*(1-component.__transition)+component.hover_stylesheet.border_radius_bottom_right*component.__transition);
    if(stylesheet.border_radius_top_left != 0)
    {
        if(stylesheet.border_radius_top_left>stylesheet.height/2||stylesheet.border_radius_top_left>stylesheet.width/2) stylesheet.border_radius_top_left = __min(stylesheet.width/2, stylesheet.height/2);
    }
    if(stylesheet.border_radius_top_right != 0)
    {
        if(stylesheet.border_radius_top_right>stylesheet.height/2||stylesheet.border_radius_top_right>stylesheet.width/2) stylesheet.border_radius_top_right = __min(stylesheet.width/2, stylesheet.height/2);
    }
    if(stylesheet.border_radius_bottom_left != 0)
    {
        if(stylesheet.border_radius_bottom_left>stylesheet.height/2||stylesheet.border_radius_bottom_left>stylesheet.width/2) stylesheet.border_radius_bottom_left = __min(stylesheet.width/2, stylesheet.height/2);
    }
    if(stylesheet.border_radius_bottom_right != 0)
    {
        if(stylesheet.border_radius_bottom_right>stylesheet.height/2||stylesheet.border_radius_bottom_right>stylesheet.width/2) stylesheet.border_radius_bottom_right = __min(stylesheet.width/2, stylesheet.height/2);
    }

    return stylesheet;
}

boolean idboxComponent(component component, int x, int y)
{
    int dx, dy, rt, rl, rr, rb;
    style stylesheet;
    stylesheet = styleTransition(component);

    if(stylesheet.border_radius_top_left!=0||stylesheet.border_radius_top_right!=0||stylesheet.border_radius_bottom_left!=0||stylesheet.border_radius_bottom_right!=0)
    {
        rt = __max(stylesheet.border_radius_top_left, stylesheet.border_radius_top_right);
        rl = __max(stylesheet.border_radius_top_left, stylesheet.border_radius_bottom_left);
        rr = __max(stylesheet.border_radius_top_right, stylesheet.border_radius_bottom_right);
        rb = __max(stylesheet.border_radius_bottom_left, stylesheet.border_radius_bottom_right);

        if(stylesheet.left+rl<=x
        && stylesheet.top+rt<=y
        && ((stylesheet.left+stylesheet.width-rr)?0:(stylesheet.left+stylesheet.width-rr))>=x
        && ((stylesheet.top+stylesheet.height-rb)?0:(stylesheet.top+stylesheet.height-rb))>=y) return TRUE;
        if(stylesheet.left+stylesheet.border_radius_top_left<=x
        && stylesheet.top<=y
        && stylesheet.left+stylesheet.width-stylesheet.border_radius_top_right>=x
        && stylesheet.top+stylesheet.height/2>=y) return TRUE;
        if(stylesheet.left<=x
        && stylesheet.top+stylesheet.border_radius_top_left<=y
        && stylesheet.left+stylesheet.width/2>=x
        && stylesheet.top+stylesheet.height-stylesheet.border_radius_bottom_left>=y) return TRUE;
        if(stylesheet.left+stylesheet.border_radius_bottom_left<=x
        && stylesheet.top+stylesheet.height/2<=y
        && stylesheet.left+stylesheet.width-stylesheet.border_radius_bottom_right>=x
        && stylesheet.top+stylesheet.height>=y) return TRUE;
        if(stylesheet.left+stylesheet.width/2<=x
        && stylesheet.top+stylesheet.border_radius_top_right<=y
        && stylesheet.left+stylesheet.width>=x
        && stylesheet.top+stylesheet.height-stylesheet.border_radius_bottom_right>=y) return TRUE;

        if(stylesheet.border_radius_top_left != 0)
        {
            dx = x - (stylesheet.left+stylesheet.border_radius_top_left);
            dy = y - (stylesheet.top+stylesheet.border_radius_top_left-1);
            if((dx*dx+dy*dy)<=((stylesheet.border_radius_top_left-1)*(stylesheet.border_radius_top_left-1))) return TRUE;
        }
        if(stylesheet.border_radius_bottom_left != 0)
        {
            dx = x - (stylesheet.left+stylesheet.border_radius_bottom_left);
            dy = y - (stylesheet.top+stylesheet.height-stylesheet.border_radius_bottom_left);
            if((dx*dx+dy*dy)<=((stylesheet.border_radius_bottom_left-1)*(stylesheet.border_radius_bottom_left-1))) return TRUE;
        }
            if(stylesheet.border_radius_top_right != 0)
            {
            dx = x - (stylesheet.left+stylesheet.width-stylesheet.border_radius_top_right-1);
            dy = y - (stylesheet.top+stylesheet.border_radius_top_right-1);
            if((dx*dx+dy*dy)<=((stylesheet.border_radius_top_right-1)*(stylesheet.border_radius_top_right-1))) return TRUE;
        }
        if(stylesheet.border_radius_bottom_right != 0)
        {
            dx = x - (stylesheet.left+stylesheet.width-stylesheet.border_radius_bottom_right-1);
            dy = y - (stylesheet.top+stylesheet.height-stylesheet.border_radius_bottom_right);
            if((dx*dx+dy*dy)<=((stylesheet.border_radius_bottom_right-1)*(stylesheet.border_radius_bottom_right-1))) return TRUE;
        }
    } else {
        if(stylesheet.top <= y
        && stylesheet.top + stylesheet.height >= y
        && stylesheet.left <= x
        && stylesheet.left + stylesheet.width >= x) return TRUE;
    }
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
    int font_height = 0, font_width = 0, horizontal_align = 0, vertical_align = 0, rt, rl, rr, rb;
    
    style stylesheet;
    MLV_Color background_color;

    stylesheet = styleTransition(component);
    background_color = MLV_rgba(stylesheet.background_color.r, stylesheet.background_color.g, stylesheet.background_color.b, stylesheet.background_color.a);

    if(stylesheet.border_radius_top_left!=0||stylesheet.border_radius_top_right!=0||stylesheet.border_radius_bottom_left!=0||stylesheet.border_radius_bottom_right!=0)
    {
        rt = __max(stylesheet.border_radius_top_left, stylesheet.border_radius_top_right);
        rl = __max(stylesheet.border_radius_top_left, stylesheet.border_radius_bottom_left);
        rr = __max(stylesheet.border_radius_top_right, stylesheet.border_radius_bottom_right);
        rb = __max(stylesheet.border_radius_bottom_left, stylesheet.border_radius_bottom_right);

        MLV_draw_filled_rectangle(stylesheet.left+stylesheet.border_radius_top_left, stylesheet.top, stylesheet.width-stylesheet.border_radius_top_right-stylesheet.border_radius_top_left, stylesheet.height/2, background_color);
        MLV_draw_filled_rectangle(stylesheet.left, stylesheet.top+stylesheet.border_radius_top_left, stylesheet.width/2, stylesheet.height-stylesheet.border_radius_bottom_left-stylesheet.border_radius_top_left, background_color);
        MLV_draw_filled_rectangle(stylesheet.left+stylesheet.border_radius_bottom_left, stylesheet.top+stylesheet.height/2, stylesheet.width-stylesheet.border_radius_bottom_right-stylesheet.border_radius_bottom_left, stylesheet.height/2, background_color);
        MLV_draw_filled_rectangle(stylesheet.left+stylesheet.width/2, stylesheet.top+stylesheet.border_radius_top_right, stylesheet.width/2, stylesheet.height-stylesheet.border_radius_bottom_right-stylesheet.border_radius_top_right, background_color);
        MLV_draw_filled_rectangle(stylesheet.left+rl, stylesheet.top+rt, (stylesheet.width-rl-rr)<0?0:(stylesheet.width-rl-rr), (stylesheet.height-rt-rb)<0?0:(stylesheet.height-rt-rb), background_color);

        if(stylesheet.border_radius_top_left != 0)
        {
            MLV_draw_filled_circle(stylesheet.left+stylesheet.border_radius_top_left, stylesheet.top+stylesheet.border_radius_top_left-1, stylesheet.border_radius_top_left-1, background_color);
        }
        if(stylesheet.border_radius_bottom_left != 0)
        {
            MLV_draw_filled_circle(stylesheet.left+stylesheet.border_radius_bottom_left, stylesheet.top+stylesheet.height-stylesheet.border_radius_bottom_left, stylesheet.border_radius_bottom_left-1, background_color);
        }
        if(stylesheet.border_radius_top_right != 0)
        {
            MLV_draw_filled_circle(stylesheet.left+stylesheet.width-stylesheet.border_radius_top_right-1, stylesheet.top+stylesheet.border_radius_top_right-1, stylesheet.border_radius_top_right-1, background_color);
        }
        if(stylesheet.border_radius_bottom_right != 0)
        {
            MLV_draw_filled_circle(stylesheet.left+stylesheet.width-stylesheet.border_radius_bottom_right-1, stylesheet.top+stylesheet.height-stylesheet.border_radius_bottom_right, stylesheet.border_radius_bottom_right-1, background_color);
        }
    } else {
        MLV_draw_filled_rectangle(stylesheet.left, stylesheet.top, stylesheet.width, stylesheet.height, background_color);
    }
    file = fopen(stylesheet.font_family, "r");
    if(file != NULL && strcmp(component.content,"") != 0)
    {
        font_family = MLV_load_font(stylesheet.font_family, stylesheet.font_size);
        MLV_get_size_of_text_with_font(component.content, &font_width, &font_height, font_family);
        
        switch(stylesheet.font_horizontal_align) {
            case HORIZONTAL_LEFT:
                horizontal_align = stylesheet.left+20;
                break;
            case HORIZONTAL_CENTER:
                horizontal_align = stylesheet.left+(stylesheet.width/2)-(font_width/2);
                break;
            case HORIZONTAL_RIGHT:
                horizontal_align = stylesheet.left+stylesheet.width-font_width-20;
                break;
        }    
        switch(stylesheet.font_vertical_align) {
            case VERTICAL_TOP:
                vertical_align = stylesheet.top+20;
                break;
            case VERTICAL_CENTER:
                vertical_align = stylesheet.top+(stylesheet.height/2)-(font_height/2);
                break;
            case VERTICAL_BOTTOM:
                vertical_align = stylesheet.top+stylesheet.height-font_height-20;
                break;
        }

        MLV_draw_text_with_font(horizontal_align, vertical_align, component.content, font_family, MLV_rgba(stylesheet.color.r, stylesheet.color.g, stylesheet.color.b, stylesheet.color.a));
        
        MLV_free_font(font_family);
    }
}

component initComponent(int id, char content[], style stylesheet, boolean is_hoverable, style hover_stylesheet, int transition_duration)
{
    component cmp;
    cmp.id = id;
    cmp.type = COMPONENT_BUTTON;
    strcpy(cmp.content, content);
    cmp.stylesheet = stylesheet;
    cmp.is_hoverable = is_hoverable;
    cmp.is_hovered = FALSE;
    cmp.hover_stylesheet = hover_stylesheet;
    cmp.transition_duration = transition_duration;
    cmp.__transition = 0;
    return cmp;
}

void createFrame(component components[], int *components_size, char content[], style stylesheet, boolean is_hoverable, style hover_stylesheet, int transition_duration)
{
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;
    components[*components_size] = initComponent((*components_size)+1, content, stylesheet, is_hoverable, hover_stylesheet, transition_duration);
    (*components_size)++;
}

void createButton(component components[], int *components_size, button_component buttons[], int *buttons_size, char content[], style stylesheet, boolean is_hoverable, style hover_stylesheet, int transition_duration, button_action_type action_type)
{
    button_component btn_cmp;
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;

    btn_cmp.id = (*components_size)+1;
    btn_cmp.action_type = action_type;
    components[*components_size] = initComponent((*components_size)+1, content, stylesheet, is_hoverable, hover_stylesheet, transition_duration);
    (*components_size)++;
    buttons[*buttons_size] = btn_cmp;
    (*buttons_size)++;
}

void createContainer(component components[], int *components_size, container_component contain_components[], int *contain_components_size, char content[], style stylesheet, boolean is_hoverable, style hover_stylesheet, int transition_duration)
{
    container_component contain_cmp;
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;

    contain_cmp.id = (*components_size)+1;
    contain_cmp.components_size = 0;
    components[*components_size] = initComponent((*components_size)+1, content, stylesheet, is_hoverable, hover_stylesheet, transition_duration);
    (*components_size)++;
    contain_components[*contain_components_size] = contain_cmp;
    (*contain_components_size)++;
}