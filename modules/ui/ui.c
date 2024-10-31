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

void getKeyFromMLV(MLV_Keyboard_button sym, char response[]) {
    switch(sym)
    {
        case MLV_KEYBOARD_a: strcpy(response, "A"); break;
        case MLV_KEYBOARD_b: strcpy(response, "B"); break;
        case MLV_KEYBOARD_c: strcpy(response, "C"); break;
        case MLV_KEYBOARD_d: strcpy(response, "D"); break;
        case MLV_KEYBOARD_e: strcpy(response, "E"); break;
        case MLV_KEYBOARD_f: strcpy(response, "F"); break;
        case MLV_KEYBOARD_g: strcpy(response, "G"); break;
        case MLV_KEYBOARD_h: strcpy(response, "H"); break;
        case MLV_KEYBOARD_i: strcpy(response, "I"); break;
        case MLV_KEYBOARD_j: strcpy(response, "J"); break;
        case MLV_KEYBOARD_k: strcpy(response, "K"); break;
        case MLV_KEYBOARD_l: strcpy(response, "L"); break;
        case MLV_KEYBOARD_m: strcpy(response, "M"); break;
        case MLV_KEYBOARD_n: strcpy(response, "N"); break;
        case MLV_KEYBOARD_o: strcpy(response, "O"); break;
        case MLV_KEYBOARD_p: strcpy(response, "P"); break;
        case MLV_KEYBOARD_q: strcpy(response, "Q"); break;
        case MLV_KEYBOARD_r: strcpy(response, "R"); break;
        case MLV_KEYBOARD_s: strcpy(response, "S"); break;
        case MLV_KEYBOARD_t: strcpy(response, "T"); break;
        case MLV_KEYBOARD_u: strcpy(response, "U"); break;
        case MLV_KEYBOARD_v: strcpy(response, "V"); break;
        case MLV_KEYBOARD_w: strcpy(response, "W"); break;
        case MLV_KEYBOARD_x: strcpy(response, "X"); break;
        case MLV_KEYBOARD_y: strcpy(response, "Y"); break;
        case MLV_KEYBOARD_z: strcpy(response, "Z"); break;
        case MLV_KEYBOARD_0: strcpy(response, "0"); break;
        case MLV_KEYBOARD_1: strcpy(response, "1"); break;
        case MLV_KEYBOARD_2: strcpy(response, "2"); break;
        case MLV_KEYBOARD_3: strcpy(response, "3"); break;
        case MLV_KEYBOARD_4: strcpy(response, "4"); break;
        case MLV_KEYBOARD_5: strcpy(response, "5"); break;
        case MLV_KEYBOARD_6: strcpy(response, "6"); break;
        case MLV_KEYBOARD_7: strcpy(response, "7"); break;
        case MLV_KEYBOARD_8: strcpy(response, "8"); break;
        case MLV_KEYBOARD_9: strcpy(response, "9"); break;
        case MLV_KEYBOARD_LALT: strcpy(response, "LEFT_ALT"); break;
        case MLV_KEYBOARD_RALT: strcpy(response, "RIGHT_ALT"); break;
        case MLV_KEYBOARD_LSHIFT: strcpy(response, "LEFT_SHIFT"); break;
        case MLV_KEYBOARD_RSHIFT: strcpy(response, "RIGHT_SHIFT"); break;
        case MLV_KEYBOARD_LCTRL: strcpy(response, "LEFT_CTRL"); break;
        case MLV_KEYBOARD_RCTRL: strcpy(response, "RIGHT_CTRL"); break;
        case MLV_KEYBOARD_SPACE: strcpy(response, "SPACE"); break;
        case MLV_KEYBOARD_RETURN: strcpy(response, "ENTER"); break;
        case MLV_KEYBOARD_BACKSPACE: strcpy(response, "BACKSPACE"); break;
        case MLV_KEYBOARD_TAB: strcpy(response, "TAB"); break;
        case MLV_KEYBOARD_CAPSLOCK: strcpy(response, "CAPS_LOCK"); break;
        case MLV_KEYBOARD_ESCAPE: strcpy(response, "ESCAPE"); break;
        case MLV_KEYBOARD_UP: strcpy(response, "UP_ARROW"); break;
        case MLV_KEYBOARD_DOWN: strcpy(response, "DOWN_ARROW"); break;
        case MLV_KEYBOARD_LEFT: strcpy(response, "LEFT_ARROW"); break;
        case MLV_KEYBOARD_RIGHT: strcpy(response, "RIGHT_ARROW"); break;
        case MLV_KEYBOARD_KP0: strcpy(response, "NUMPAD_0"); break;
        case MLV_KEYBOARD_KP1: strcpy(response, "NUMPAD_1"); break;
        case MLV_KEYBOARD_KP2: strcpy(response, "NUMPAD_2"); break;
        case MLV_KEYBOARD_KP3: strcpy(response, "NUMPAD_3"); break;
        case MLV_KEYBOARD_KP4: strcpy(response, "NUMPAD_4"); break;
        case MLV_KEYBOARD_KP5: strcpy(response, "NUMPAD_5"); break;
        case MLV_KEYBOARD_KP6: strcpy(response, "NUMPAD_6"); break;
        case MLV_KEYBOARD_KP7: strcpy(response, "NUMPAD_7"); break;
        case MLV_KEYBOARD_KP8: strcpy(response, "NUMPAD_8"); break;
        case MLV_KEYBOARD_KP9: strcpy(response, "NUMPAD_9"); break;
        case MLV_KEYBOARD_KP_DIVIDE: strcpy(response, "NUMPAD_DIVIDE"); break;
        case MLV_KEYBOARD_KP_MULTIPLY: strcpy(response, "NUMPAD_MULTIPLY"); break;
        case MLV_KEYBOARD_KP_MINUS: strcpy(response, "NUMPAD_MINUS"); break;
        case MLV_KEYBOARD_KP_PLUS: strcpy(response, "NUMPAD_PLUS"); break;
        case MLV_KEYBOARD_KP_ENTER: strcpy(response, "NUMPAD_ENTER"); break;
        case MLV_KEYBOARD_KP_PERIOD: strcpy(response, "NUMPAD_PERIOD"); break;
        case MLV_KEYBOARD_F1: strcpy(response, "F1"); break;
        case MLV_KEYBOARD_F2: strcpy(response, "F2"); break;
        case MLV_KEYBOARD_F3: strcpy(response, "F3"); break;
        case MLV_KEYBOARD_F4: strcpy(response, "F4"); break;
        case MLV_KEYBOARD_F5: strcpy(response, "F5"); break;
        case MLV_KEYBOARD_F6: strcpy(response, "F6"); break;
        case MLV_KEYBOARD_F7: strcpy(response, "F7"); break;
        case MLV_KEYBOARD_F8: strcpy(response, "F8"); break;
        case MLV_KEYBOARD_F9: strcpy(response, "F9"); break;
        case MLV_KEYBOARD_F10: strcpy(response, "F10"); break;
        case MLV_KEYBOARD_F11: strcpy(response, "F11"); break;
        case MLV_KEYBOARD_F12: strcpy(response, "F12"); break;
        default: strcpy(response, ""); break;
    }
}
MLV_Keyboard_button getMLVFromKey(char key[]) {
    if (strcmp(key, "A") == 0) return MLV_KEYBOARD_a;
    else if (strcmp(key, "B") == 0) return MLV_KEYBOARD_b;
    else if (strcmp(key, "C") == 0) return MLV_KEYBOARD_c;
    else if (strcmp(key, "D") == 0) return MLV_KEYBOARD_d;
    else if (strcmp(key, "E") == 0) return MLV_KEYBOARD_e;
    else if (strcmp(key, "F") == 0) return MLV_KEYBOARD_f;
    else if (strcmp(key, "G") == 0) return MLV_KEYBOARD_g;
    else if (strcmp(key, "H") == 0) return MLV_KEYBOARD_h;
    else if (strcmp(key, "I") == 0) return MLV_KEYBOARD_i;
    else if (strcmp(key, "J") == 0) return MLV_KEYBOARD_j;
    else if (strcmp(key, "K") == 0) return MLV_KEYBOARD_k;
    else if (strcmp(key, "L") == 0) return MLV_KEYBOARD_l;
    else if (strcmp(key, "M") == 0) return MLV_KEYBOARD_m;
    else if (strcmp(key, "N") == 0) return MLV_KEYBOARD_n;
    else if (strcmp(key, "O") == 0) return MLV_KEYBOARD_o;
    else if (strcmp(key, "P") == 0) return MLV_KEYBOARD_p;
    else if (strcmp(key, "Q") == 0) return MLV_KEYBOARD_q;
    else if (strcmp(key, "R") == 0) return MLV_KEYBOARD_r;
    else if (strcmp(key, "S") == 0) return MLV_KEYBOARD_s;
    else if (strcmp(key, "T") == 0) return MLV_KEYBOARD_t;
    else if (strcmp(key, "U") == 0) return MLV_KEYBOARD_u;
    else if (strcmp(key, "V") == 0) return MLV_KEYBOARD_v;
    else if (strcmp(key, "W") == 0) return MLV_KEYBOARD_w;
    else if (strcmp(key, "X") == 0) return MLV_KEYBOARD_x;
    else if (strcmp(key, "Y") == 0) return MLV_KEYBOARD_y;
    else if (strcmp(key, "Z") == 0) return MLV_KEYBOARD_z;
    else if (strcmp(key, "0") == 0) return MLV_KEYBOARD_0;
    else if (strcmp(key, "1") == 0) return MLV_KEYBOARD_1;
    else if (strcmp(key, "2") == 0) return MLV_KEYBOARD_2;
    else if (strcmp(key, "MLV_KEYBOARD_QUOTE") == 0) return MLV_KEYBOARD_QUOTE;
    else if (strcmp(key, "3") == 0) return MLV_KEYBOARD_3;
    else if (strcmp(key, "4") == 0) return MLV_KEYBOARD_4;
    else if (strcmp(key, "5") == 0) return MLV_KEYBOARD_5;
    else if (strcmp(key, "6") == 0) return MLV_KEYBOARD_6;
    else if (strcmp(key, "7") == 0) return MLV_KEYBOARD_7;
    else if (strcmp(key, "8") == 0) return MLV_KEYBOARD_8;
    else if (strcmp(key, "9") == 0) return MLV_KEYBOARD_9;
    else if (strcmp(key, "LEFT_ALT") == 0) return MLV_KEYBOARD_LALT;
    else if (strcmp(key, "RIGHT_ALT") == 0) return MLV_KEYBOARD_RALT;
    else if (strcmp(key, "LEFT_SHIFT") == 0) return MLV_KEYBOARD_LSHIFT;
    else if (strcmp(key, "RIGHT_SHIFT") == 0) return MLV_KEYBOARD_RSHIFT;
    else if (strcmp(key, "LEFT_CTRL") == 0) return MLV_KEYBOARD_LCTRL;
    else if (strcmp(key, "RIGHT_CTRL") == 0) return MLV_KEYBOARD_RCTRL;
    else if (strcmp(key, "SPACE") == 0) return MLV_KEYBOARD_SPACE;
    else if (strcmp(key, "ENTER") == 0) return MLV_KEYBOARD_RETURN;
    else if (strcmp(key, "BACKSPACE") == 0) return MLV_KEYBOARD_BACKSPACE;
    else if (strcmp(key, "TAB") == 0) return MLV_KEYBOARD_TAB;
    else if (strcmp(key, "CAPS_LOCK") == 0) return MLV_KEYBOARD_CAPSLOCK;
    else if (strcmp(key, "ESCAPE") == 0) return MLV_KEYBOARD_ESCAPE;
    else if (strcmp(key, "UP_ARROW") == 0) return MLV_KEYBOARD_UP;
    else if (strcmp(key, "DOWN_ARROW") == 0) return MLV_KEYBOARD_DOWN;
    else if (strcmp(key, "LEFT_ARROW") == 0) return MLV_KEYBOARD_LEFT;
    else if (strcmp(key, "RIGHT_ARROW") == 0) return MLV_KEYBOARD_RIGHT;
    else if (strcmp(key, "NUMPAD_0") == 0) return MLV_KEYBOARD_KP0;
    else if (strcmp(key, "NUMPAD_1") == 0) return MLV_KEYBOARD_KP1;
    else if (strcmp(key, "NUMPAD_2") == 0) return MLV_KEYBOARD_KP2;
    else if (strcmp(key, "NUMPAD_3") == 0) return MLV_KEYBOARD_KP3;
    else if (strcmp(key, "NUMPAD_4") == 0) return MLV_KEYBOARD_KP4;
    else if (strcmp(key, "NUMPAD_5") == 0) return MLV_KEYBOARD_KP5;
    else if (strcmp(key, "NUMPAD_6") == 0) return MLV_KEYBOARD_KP6;
    else if (strcmp(key, "NUMPAD_7") == 0) return MLV_KEYBOARD_KP7;
    else if (strcmp(key, "NUMPAD_8") == 0) return MLV_KEYBOARD_KP8;
    else if (strcmp(key, "NUMPAD_9") == 0) return MLV_KEYBOARD_KP9;
    else if (strcmp(key, "NUMPAD_DIVIDE") == 0) return MLV_KEYBOARD_KP_DIVIDE;
    else if (strcmp(key, "NUMPAD_MULTIPLY") == 0) return MLV_KEYBOARD_KP_MULTIPLY;
    else if (strcmp(key, "NUMPAD_MINUS") == 0) return MLV_KEYBOARD_KP_MINUS;
    else if (strcmp(key, "NUMPAD_PLUS") == 0) return MLV_KEYBOARD_KP_PLUS;
    else if (strcmp(key, "NUMPAD_ENTER") == 0) return MLV_KEYBOARD_KP_ENTER;
    else if (strcmp(key, "NUMPAD_PERIOD") == 0) return MLV_KEYBOARD_KP_PERIOD;
    else if (strcmp(key, "F1") == 0) return MLV_KEYBOARD_F1;
    else if (strcmp(key, "F2") == 0) return MLV_KEYBOARD_F2;
    else if (strcmp(key, "F3") == 0) return MLV_KEYBOARD_F3;
    else if (strcmp(key, "F4") == 0) return MLV_KEYBOARD_F4;
    else if (strcmp(key, "F5") == 0) return MLV_KEYBOARD_F5;
    else if (strcmp(key, "F6") == 0) return MLV_KEYBOARD_F6;
    else if (strcmp(key, "F7") == 0) return MLV_KEYBOARD_F7;
    else if (strcmp(key, "F8") == 0) return MLV_KEYBOARD_F8;
    else if (strcmp(key, "F9") == 0) return MLV_KEYBOARD_F9;
    else if (strcmp(key, "F10") == 0) return MLV_KEYBOARD_F10;
    else if (strcmp(key, "F11") == 0) return MLV_KEYBOARD_F11;
    else if (strcmp(key, "F12") == 0) return MLV_KEYBOARD_F12;
    else return MLV_KEYBOARD_UNKNOWN;
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

key_component componentToKeyComponent(component cmp, key_component keys[], int keys_size) {
    int i;
    key_component key;
    key.id = 0;
    key.take_type = KEY_TAKE_UNDEFINED;
    strcpy(key.content, "");

    for(i = 0; i<keys_size; i++)
    {
        if(cmp.id == keys[i].id)
        {
            key = keys[i];
        }
    }
    return key;
}

image_component componentToImageComponent(component cmp, image_component images[], int images_size) {
    int i;
    image_component image;
    image.id = 0;
    strcpy(image.path, "");

    for(i = 0; i<images_size; i++)
    {
        if(cmp.id == images[i].id)
        {
            image = images[i];
        }
    }
    return image;
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

void drawComponents(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t components_size, text_component texts[], uint32_t texts_size, key_component keys[], uint32_t keys_size, image_component images[], uint32_t images_size) {
    uint32_t i;

    for(i = 0; i<components_size; i++) {
        drawComponent(components[i], styleReal(top, left, height, width, components, components_size, components[i]), texts, texts_size, keys, keys_size, images, images_size);
    }
}

void drawComponent(component cmp, style stylesheet, text_component texts[], uint32_t texts_size, key_component keys[], uint32_t keys_size, image_component images[], uint32_t images_size)
{
    FILE* file;
    MLV_Image *mlv_img;
    MLV_Font *font_family;
    int32_t font_height = 0, font_width = 0, image_height = 0, image_width = 0, horizontal_align = 0, vertical_align = 0, rt, rl, rr, rb;
    float image_ratio;
    key_component key_cmp;
    text_component txt_cmp;
    image_component img_cmp;
    char content[64];
    MLV_Color background_color;

    if(stylesheet.height == 0 || stylesheet.width == 0)return;
    if(cmp.type == COMPONENT_IMAGE) {
        img_cmp = componentToImageComponent(cmp, images, images_size);
        mlv_img = MLV_load_image(img_cmp.path);
        if(mlv_img != NULL)
        {
            MLV_get_image_size(mlv_img, &image_width, &image_height);
            image_ratio = ((float)image_width)/image_height;
            if(image_width > stylesheet.width || image_height > stylesheet.height)
            {
                if(image_height > stylesheet.height)
                {
                    image_height = stylesheet.height;
                    image_width = (int)(stylesheet.height * image_ratio);
                }
                if(image_width > stylesheet.width)
                {
                    image_width = stylesheet.width;
                    image_height = (int)(stylesheet.width / image_ratio);
                }
            }
            MLV_resize_image(mlv_img, image_width, image_height);
            MLV_draw_image(mlv_img, stylesheet.left, stylesheet.top);

            MLV_free_image(mlv_img);
        }
    } else {
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
        
        if(cmp.type == COMPONENT_TEXT || cmp.type == COMPONENT_KEY) {
            switch(cmp.type) {
                case COMPONENT_TEXT:
                    txt_cmp = componentToTextComponent(cmp, texts, texts_size);
                    strcpy(content, txt_cmp.content);
                    break;
                case COMPONENT_KEY:
                    key_cmp = componentToKeyComponent(cmp, keys, keys_size);
                    strcpy(content, key_cmp.content);
                    break;
                default:
                    strcpy(content, "");
                    break;
            }
            file = fopen(stylesheet.font_family, "r");
            if(file != NULL && strcmp(content, "") != 0)
            {
                font_family = MLV_load_font(stylesheet.font_family, stylesheet.font_size);
                MLV_get_size_of_text_with_font(content, &font_width, &font_height, font_family);
                
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

                MLV_draw_text_with_font(horizontal_align, vertical_align, content, font_family, MLV_rgba(stylesheet.color.r, stylesheet.color.g, stylesheet.color.b, stylesheet.color.a));
                
                MLV_free_font(font_family);
            }
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

void createKey(component components[], uint32_t *components_size, key_component keys[], uint32_t *keys_size, uint32_t parent_id, style stylesheet, boolean is_hoverable, boolean ignore_hover, style hover_stylesheet, uint32_t transition_duration, key_take_type take_type, char content[])
{
    key_component key_cmp;
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;

    key_cmp.id = (*components_size)+1;
    key_cmp.take_type = take_type;
    strcpy(key_cmp.content, content);
    components[*components_size] = initComponent((*components_size)+1, COMPONENT_KEY, parent_id, stylesheet, is_hoverable, ignore_hover, hover_stylesheet, transition_duration);
    (*components_size)++;
    keys[*keys_size] = key_cmp;
    (*keys_size)++;
}

void createImage(component components[], uint32_t *components_size, image_component images[], uint32_t *images_size, uint32_t parent_id, style stylesheet, boolean is_hoverable, boolean ignore_hover, style hover_stylesheet, uint32_t transition_duration, char path[])
{
    image_component img_cmp;
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;

    img_cmp.id = (*components_size)+1;
    strcpy(img_cmp.path, path);
    components[*components_size] = initComponent((*components_size)+1, COMPONENT_IMAGE, parent_id, stylesheet, is_hoverable, ignore_hover, hover_stylesheet, transition_duration);
    (*components_size)++;
    images[*images_size] = img_cmp;
    (*images_size)++;
}