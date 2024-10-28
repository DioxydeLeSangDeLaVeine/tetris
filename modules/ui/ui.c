#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <string.h>
#include "ui.h"

int32_t __min(int32_t a, int32_t b) {
    return a<=b?a:b;
}
int32_t __max(int32_t a, int32_t b) {
    return a>=b?a:b;
}

button_component componentToButtonComponent(component cmp, button_component buttons[], int buttons_size) {
    int i;
    button_component button;
    button.id = 0;
    button.action_type = BUTTON_ACTION_UNDEFINED;

    for(i = 0; i<buttons_size; i++)
    {
        if(cmp.id == buttons[i].id)
        {
            button = buttons[i];
        }
    }
    return button;
}

text_component componentToTextComponent(component cmp, text_component texts[], int texts_size) {
    int i;
    text_component text;
    text.id = 0;
    strcpy(text.content, "");

    for(i = 0; i<texts_size; i++)
    {
        if(cmp.id == texts[i].id)
        {
            text = texts[i];
        }
    }
    return text;
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

    stylesheet.background_color.r = (int32_t)(component.stylesheet.background_color.r*(1-component.__transition)+component.hover_stylesheet.background_color.r*component.__transition);
    stylesheet.background_color.g = (int32_t)(component.stylesheet.background_color.g*(1-component.__transition)+component.hover_stylesheet.background_color.g*component.__transition);
    stylesheet.background_color.b = (int32_t)(component.stylesheet.background_color.b*(1-component.__transition)+component.hover_stylesheet.background_color.b*component.__transition);
    stylesheet.background_color.a = (int32_t)(component.stylesheet.background_color.a*(1-component.__transition)+component.hover_stylesheet.background_color.a*component.__transition);
    stylesheet.color.r = (int32_t)(component.stylesheet.color.r*(1-component.__transition)+component.hover_stylesheet.color.r*component.__transition);
    stylesheet.color.g = (int32_t)(component.stylesheet.color.g*(1-component.__transition)+component.hover_stylesheet.color.g*component.__transition);
    stylesheet.color.b = (int32_t)(component.stylesheet.color.b*(1-component.__transition)+component.hover_stylesheet.color.b*component.__transition);
    stylesheet.color.a = (int32_t)(component.stylesheet.color.a*(1-component.__transition)+component.hover_stylesheet.color.a*component.__transition);
    if(component.__transition>0.5) {
        stylesheet.childs_direction = component.hover_stylesheet.childs_direction;
        stylesheet.component_justify = component.hover_stylesheet.component_justify;
        stylesheet.unit_top = component.hover_stylesheet.unit_top;
        stylesheet.unit_left = component.hover_stylesheet.unit_left;
        stylesheet.unit_height = component.hover_stylesheet.unit_height;
        stylesheet.unit_width = component.hover_stylesheet.unit_width;
        strcpy(stylesheet.font_family, component.hover_stylesheet.font_family);
    }
    else {
        stylesheet.childs_direction = component.stylesheet.childs_direction;
        stylesheet.component_justify = component.stylesheet.component_justify;
        stylesheet.unit_top = component.stylesheet.unit_top;
        stylesheet.unit_left = component.stylesheet.unit_left;
        stylesheet.unit_height = component.stylesheet.unit_height;
        stylesheet.unit_width = component.stylesheet.unit_width;
        strcpy(stylesheet.font_family, component.stylesheet.font_family);
    }
    stylesheet.font_size = (int32_t)(component.stylesheet.font_size*(1-component.__transition)+component.hover_stylesheet.font_size*component.__transition);
    stylesheet.font_horizontal_align = (horizontal_align)(component.stylesheet.font_horizontal_align*(1-component.__transition)+component.hover_stylesheet.font_horizontal_align*component.__transition);
    stylesheet.font_vertical_align = (vertical_align)(component.stylesheet.font_vertical_align*(1-component.__transition)+component.hover_stylesheet.font_vertical_align*component.__transition);
    stylesheet.padding = (int32_t)(component.stylesheet.padding*(1-component.__transition)+component.hover_stylesheet.padding*component.__transition);
    stylesheet.gap = (int32_t)(component.stylesheet.padding*(1-component.__transition)+component.hover_stylesheet.padding*component.__transition);
    stylesheet.top = (int32_t)(component.stylesheet.top*(1-component.__transition)+component.hover_stylesheet.top*component.__transition);
    stylesheet.left = (int32_t)(component.stylesheet.left*(1-component.__transition)+component.hover_stylesheet.left*component.__transition);
    stylesheet.height = (int32_t)(component.stylesheet.height*(1-component.__transition)+component.hover_stylesheet.height*component.__transition);
    stylesheet.width = (int32_t)(component.stylesheet.width*(1-component.__transition)+component.hover_stylesheet.width*component.__transition);
    stylesheet.border_radius_top_left = (int32_t)(component.stylesheet.border_radius_top_left*(1-component.__transition)+component.hover_stylesheet.border_radius_top_left*component.__transition);
    stylesheet.border_radius_top_right = (int32_t)(component.stylesheet.border_radius_top_right*(1-component.__transition)+component.hover_stylesheet.border_radius_top_right*component.__transition);
    stylesheet.border_radius_bottom_left = (int32_t)(component.stylesheet.border_radius_bottom_left*(1-component.__transition)+component.hover_stylesheet.border_radius_bottom_left*component.__transition);
    stylesheet.border_radius_bottom_right = (int32_t)(component.stylesheet.border_radius_bottom_right*(1-component.__transition)+component.hover_stylesheet.border_radius_bottom_right*component.__transition);
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

void transformUnit(int *value, unit *value_unit, int reference) {
    switch(*value_unit) {
        case UNIT_PERCENTAGE:
            *value = (int)(((float)(*value)/100)*reference);
            *value_unit = UNIT_PX;
        default:
            break;
    }
}

style transformUnits(style stylesheet, style parentStylesheet) {
    transformUnit(&(stylesheet.top), &(stylesheet.unit_top), parentStylesheet.height+parentStylesheet.padding);
    transformUnit(&(stylesheet.left), &(stylesheet.unit_left), parentStylesheet.width+parentStylesheet.padding);
    transformUnit(&(stylesheet.height), &(stylesheet.unit_height), parentStylesheet.height-2*parentStylesheet.padding);
    transformUnit(&(stylesheet.width), &(stylesheet.unit_width), parentStylesheet.width-2*parentStylesheet.padding);
    return stylesheet;
}

style styleReal(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t components_size, component cmp) {
    uint32_t i = 0;
    style stylesheets[COMPONENTS_MAX_SIZE];
    style rootStylesheet;
    __component_offset offsets[COMPONENTS_MAX_SIZE];
    boolean stop = FALSE;
    component tmp_cmp;

    rootStylesheet.unit_top = UNIT_PX;
    rootStylesheet.top = top;
    rootStylesheet.unit_left = UNIT_PX;
    rootStylesheet.left = left;
    rootStylesheet.unit_height = UNIT_PX;
    rootStylesheet.height = height;
    rootStylesheet.unit_width = UNIT_PX;
    rootStylesheet.width = width;

    if(cmp.parent_id == 0) {
        cmp.stylesheet = transformUnits(cmp.stylesheet, rootStylesheet);
        cmp.hover_stylesheet = transformUnits(cmp.hover_stylesheet, rootStylesheet);
    }
    if(cmp.parent_id>=cmp.id || cmp.parent_id == 0) return styleTransition(cmp);
    while((i<cmp.id)&&i<components_size&&!stop) {
        if(components[i].parent_id != 0) {
            tmp_cmp = components[i];
            tmp_cmp.stylesheet = transformUnits(tmp_cmp.stylesheet, stylesheets[components[i].parent_id-1]);
            tmp_cmp.hover_stylesheet = transformUnits(tmp_cmp.hover_stylesheet, stylesheets[components[i].parent_id-1]);
            stylesheets[i] = styleTransition(tmp_cmp);
            switch(stylesheets[components[i].parent_id-1].childs_direction)
            {
                case DIRECTION_ROW:
                    switch(stylesheets[i].component_justify)
                    {
                        case JUSTIFY_START:
                            offsets[i].top_offset = offsets[components[i].parent_id-1].top_offset+stylesheets[i].top+stylesheets[i].padding;
                            offsets[i].left_offset = offsets[components[i].parent_id-1].left_offset+stylesheets[i].left+stylesheets[i].padding;
                            offsets[i].bottom_offset = offsets[components[i].parent_id-1].top_offset+stylesheets[i].top+stylesheets[i].height-stylesheets[i].padding;
                            offsets[i].right_offset = offsets[components[i].parent_id-1].left_offset+stylesheets[i].left+stylesheets[i].width-stylesheets[i].padding;

                            stylesheets[i].top = offsets[components[i].parent_id-1].top_offset;
                            stylesheets[i].left = offsets[components[i].parent_id-1].left_offset;
                            offsets[components[i].parent_id-1].left_offset += stylesheets[i].width+stylesheets[components[i].parent_id-1].gap;
                            break;
                        case JUSTIFY_END:
                            offsets[i].top_offset = offsets[components[i].parent_id-1].top_offset+stylesheets[i].top+stylesheets[i].padding;
                            offsets[i].left_offset = offsets[components[i].parent_id-1].right_offset-(stylesheets[i].left+stylesheets[i].width-stylesheets[i].padding);
                            offsets[i].bottom_offset = offsets[components[i].parent_id-1].top_offset+stylesheets[i].top+stylesheets[i].height-stylesheets[i].padding;
                            offsets[i].right_offset = offsets[components[i].parent_id-1].right_offset-stylesheets[i].padding+stylesheets[i].left;

                            stylesheets[i].top = offsets[components[i].parent_id-1].top_offset;
                            stylesheets[i].left = offsets[components[i].parent_id-1].right_offset-stylesheets[i].width;
                            offsets[components[i].parent_id-1].right_offset -= stylesheets[i].width+stylesheets[components[i].parent_id-1].gap;
                            break;
                    }
                    break;
                case DIRECTION_COLUMN:
                    switch(stylesheets[i].component_justify)
                    {
                        case JUSTIFY_START:
                            offsets[i].top_offset = offsets[components[i].parent_id-1].top_offset+stylesheets[i].top+stylesheets[i].padding;
                            offsets[i].left_offset = offsets[components[i].parent_id-1].left_offset+stylesheets[i].left+stylesheets[i].padding;
                            offsets[i].bottom_offset = offsets[components[i].parent_id-1].top_offset+stylesheets[i].top+stylesheets[i].height-stylesheets[i].padding;
                            offsets[i].right_offset = offsets[components[i].parent_id-1].left_offset+stylesheets[i].left+stylesheets[i].width-stylesheets[i].padding;

                            stylesheets[i].top = offsets[components[i].parent_id-1].top_offset;
                            stylesheets[i].left = offsets[components[i].parent_id-1].left_offset;
                            offsets[components[i].parent_id-1].top_offset += stylesheets[i].height+stylesheets[components[i].parent_id-1].gap;
                            break;
                        case JUSTIFY_END:
                            offsets[i].top_offset = offsets[components[i].parent_id-1].bottom_offset-(stylesheets[i].top+stylesheets[i].height-stylesheets[i].padding);
                            offsets[i].left_offset = offsets[components[i].parent_id-1].left_offset+stylesheets[i].left+stylesheets[i].padding;
                            offsets[i].bottom_offset = offsets[components[i].parent_id-1].bottom_offset-stylesheets[i].padding+stylesheets[i].top;
                            offsets[i].right_offset = offsets[components[i].parent_id-1].left_offset+stylesheets[i].left+stylesheets[i].width-stylesheets[i].padding;

                            stylesheets[i].top = offsets[components[i].parent_id-1].bottom_offset-stylesheets[i].height;
                            stylesheets[i].left = offsets[components[i].parent_id-1].left_offset;
                            offsets[components[i].parent_id-1].bottom_offset -= stylesheets[i].height+stylesheets[components[i].parent_id-1].gap;
                            break;
                    }
                    break;
            }
        } else {
            stylesheets[i] = styleTransition(components[i]);
            offsets[i].top_offset = stylesheets[i].top+stylesheets[i].padding;
            offsets[i].left_offset = stylesheets[i].left+stylesheets[i].padding;
            offsets[i].bottom_offset = stylesheets[i].top+stylesheets[i].height-stylesheets[i].padding;
            offsets[i].right_offset = stylesheets[i].left+stylesheets[i].width-stylesheets[i].padding;
        }
        if(cmp.id==i) stop = TRUE;
        i++;
    }
    if(cmp.id!=i) return styleTransition(cmp);
    return stylesheets[i-1];
}

boolean idboxComponent(style stylesheet, int32_t x, int32_t y)
{
    int32_t dx, dy, rt, rl, rr, rb;

    if(stylesheet.height == 0 || stylesheet.width == 0)return FALSE;
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

void drawComponents(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t components_size, text_component texts[], uint32_t texts_size) {
    uint32_t i;

    for(i = 0; i<components_size; i++) {
        drawComponent(components[i], styleReal(top, left, height, width, components, components_size, components[i]), texts, texts_size);
    }
}

void drawComponent(component cmp, style stylesheet, text_component texts[], uint32_t texts_size)
{
    FILE* file;
    MLV_Font *font_family;
    int32_t font_height = 0, font_width = 0, horizontal_align = 0, vertical_align = 0, rt, rl, rr, rb;
    MLV_Color background_color;

    if(stylesheet.height == 0 || stylesheet.width == 0)return;
    if(stylesheet.background_color.a != 0) {
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
    }
    
    if(cmp.type == COMPONENT_TEXT) {
        text_component txt_cmp;
        txt_cmp = componentToTextComponent(cmp, texts, texts_size);
        file = fopen(stylesheet.font_family, "r");
        if(file != NULL && strcmp(txt_cmp.content,"") != 0)
        {
            font_family = MLV_load_font(stylesheet.font_family, stylesheet.font_size);
            MLV_get_size_of_text_with_font(txt_cmp.content, &font_width, &font_height, font_family);
            
            switch(stylesheet.font_horizontal_align) {
                case HORIZONTAL_LEFT:
                    horizontal_align = stylesheet.left+stylesheet.padding;
                    break;
                case HORIZONTAL_CENTER:
                    horizontal_align = stylesheet.left+(stylesheet.width/2)-(font_width/2);
                    break;
                case HORIZONTAL_RIGHT:
                    horizontal_align = stylesheet.left+stylesheet.width-font_width-stylesheet.padding;
                    break;
            }    
            switch(stylesheet.font_vertical_align) {
                case VERTICAL_TOP:
                    vertical_align = stylesheet.top+stylesheet.padding;
                    break;
                case VERTICAL_CENTER:
                    vertical_align = stylesheet.top+(stylesheet.height/2)-(font_height/2);
                    break;
                case VERTICAL_BOTTOM:
                    vertical_align = stylesheet.top+stylesheet.height-font_height-stylesheet.padding;
                    break;
            }

            MLV_draw_text_with_font(horizontal_align, vertical_align, txt_cmp.content, font_family, MLV_rgba(stylesheet.color.r, stylesheet.color.g, stylesheet.color.b, stylesheet.color.a));
            
            MLV_free_font(font_family);
        }
    }
}

component initComponent(uint32_t id, component_type type, uint32_t parent_id, style stylesheet, boolean is_hoverable, boolean ignore_hover, style hover_stylesheet, uint32_t transition_duration)
{
    component cmp;
    cmp.id = id;
    cmp.type = type;
    cmp.parent_id = parent_id,
    cmp.stylesheet = stylesheet;
    cmp.is_hoverable = is_hoverable;
    cmp.ignore_hover = ignore_hover;
    cmp.is_hovered = FALSE;
    cmp.hover_stylesheet = hover_stylesheet;
    cmp.transition_duration = transition_duration;
    cmp.__transition = 0;
    return cmp;
}

void createFrame(component components[], uint32_t *components_size, uint32_t parent_id, style stylesheet, boolean is_hoverable, boolean ignore_hover, style hover_stylesheet, uint32_t transition_duration)
{
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;
    components[*components_size] = initComponent((*components_size)+1, COMPONENT_FRAME, parent_id, stylesheet, is_hoverable, ignore_hover, hover_stylesheet, transition_duration);
    (*components_size)++;
}

void createButton(component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, uint32_t parent_id, style stylesheet, boolean is_hoverable, boolean ignore_hover, style hover_stylesheet, uint32_t transition_duration, button_action_type action_type)
{
    button_component btn_cmp;
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;

    btn_cmp.id = (*components_size)+1;
    btn_cmp.action_type = action_type;
    components[*components_size] = initComponent((*components_size)+1, COMPONENT_BUTTON, parent_id, stylesheet, is_hoverable, ignore_hover, hover_stylesheet, transition_duration);
    (*components_size)++;
    buttons[*buttons_size] = btn_cmp;
    (*buttons_size)++;
}

void createText(component components[], uint32_t *components_size, text_component texts[], uint32_t *texts_size, uint32_t parent_id, style stylesheet, boolean is_hoverable, boolean ignore_hover, style hover_stylesheet, uint32_t transition_duration, char content[])
{
    text_component txt_cmp;
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;

    txt_cmp.id = (*components_size)+1;
    strcpy(txt_cmp.content, content);
    components[*components_size] = initComponent((*components_size)+1, COMPONENT_TEXT, parent_id, stylesheet, is_hoverable, ignore_hover, hover_stylesheet, transition_duration);
    (*components_size)++;
    texts[*texts_size] = txt_cmp;
    (*texts_size)++;
}