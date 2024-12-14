#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <string.h>
#include "ui.h"
#include "../util/util.h"
#include "../back/game.h"


/**
 * Returns button component from a component.
 *
 * @param {component} cmp
 * @param {button_component} buttons[]
 * @param {uint32_t} buttons_size
 *
 * @returns {button_component}
 */
button_component componentToButtonComponent(component cmp, button_component buttons[], uint32_t buttons_size)
{
    uint32_t i;
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


/**
 * Returns text component from a component.
 *
 * @param {component} cmp
 * @param {text_component} texts[]
 * @param {uint32_t} texts_size
 *
 * @returns {text_component}
 */
text_component componentToTextComponent(component cmp, text_component texts[], uint32_t texts_size)
{
    uint32_t i;
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


/**
 * Returns key component from a component.
 *
 * @param {component} cmp
 * @param {key_component} keys[]
 * @param {uint32_t} keys_size
 *
 * @returns {key_component}
 */
key_component componentToKeyComponent(component cmp, key_component keys[], uint32_t keys_size)
{
    uint32_t i;
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


/**
 * Returns image component from a component.
 *
 * @param {component} cmp
 * @param {image_component} images[]
 * @param {uint32_t} images_size
 *
 * @returns {image_component}
 */
image_component componentToImageComponent(component cmp, image_component images[], uint32_t images_size)
{
    uint32_t i;
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


/**
 * Calculate the transition between stylesheet and hovered stylesheet.
 *
 * @param {component} cmp
 *
 * @returns {style}
 */
style styleTransition(component cmp)
{
    style stylesheet;
    if(cmp.is_hoverable==FALSE) {
        if(cmp.stylesheet.border_radius_top_left != 0)
        {
            if(cmp.stylesheet.border_radius_top_left>cmp.stylesheet.height/2||cmp.stylesheet.border_radius_top_left>cmp.stylesheet.width/2) cmp.stylesheet.border_radius_top_left = __min(cmp.stylesheet.width/2, cmp.stylesheet.height/2);
        }
        if(cmp.stylesheet.border_radius_top_right != 0)
        {
            if(cmp.stylesheet.border_radius_top_right>cmp.stylesheet.height/2||cmp.stylesheet.border_radius_top_right>cmp.stylesheet.width/2) cmp.stylesheet.border_radius_top_right = __min(cmp.stylesheet.width/2, cmp.stylesheet.height/2);
        }
        if(cmp.stylesheet.border_radius_bottom_left != 0)
        {
            if(cmp.stylesheet.border_radius_bottom_left>cmp.stylesheet.height/2||cmp.stylesheet.border_radius_bottom_left>cmp.stylesheet.width/2) cmp.stylesheet.border_radius_bottom_left = __min(cmp.stylesheet.width/2, cmp.stylesheet.height/2);
        }
        if(cmp.stylesheet.border_radius_bottom_right != 0)
        {
            if(cmp.stylesheet.border_radius_bottom_right>cmp.stylesheet.height/2||cmp.stylesheet.border_radius_bottom_right>cmp.stylesheet.width/2) cmp.stylesheet.border_radius_bottom_right = __min(cmp.stylesheet.width/2, cmp.stylesheet.height/2);
        }
        return cmp.stylesheet;
    }

    stylesheet.background_color.r = (int32_t)(cmp.stylesheet.background_color.r*(1-cmp.__transition)+cmp.hover_stylesheet.background_color.r*cmp.__transition);
    stylesheet.background_color.g = (int32_t)(cmp.stylesheet.background_color.g*(1-cmp.__transition)+cmp.hover_stylesheet.background_color.g*cmp.__transition);
    stylesheet.background_color.b = (int32_t)(cmp.stylesheet.background_color.b*(1-cmp.__transition)+cmp.hover_stylesheet.background_color.b*cmp.__transition);
    stylesheet.background_color.a = (int32_t)(cmp.stylesheet.background_color.a*(1-cmp.__transition)+cmp.hover_stylesheet.background_color.a*cmp.__transition);
    stylesheet.color.r = (int32_t)(cmp.stylesheet.color.r*(1-cmp.__transition)+cmp.hover_stylesheet.color.r*cmp.__transition);
    stylesheet.color.g = (int32_t)(cmp.stylesheet.color.g*(1-cmp.__transition)+cmp.hover_stylesheet.color.g*cmp.__transition);
    stylesheet.color.b = (int32_t)(cmp.stylesheet.color.b*(1-cmp.__transition)+cmp.hover_stylesheet.color.b*cmp.__transition);
    stylesheet.color.a = (int32_t)(cmp.stylesheet.color.a*(1-cmp.__transition)+cmp.hover_stylesheet.color.a*cmp.__transition);
    if(cmp.__transition>0.5)
    {
        stylesheet.childs_direction = cmp.hover_stylesheet.childs_direction;
        stylesheet.component_justify = cmp.hover_stylesheet.component_justify;
        stylesheet.unit_top = cmp.hover_stylesheet.unit_top;
        stylesheet.unit_left = cmp.hover_stylesheet.unit_left;
        stylesheet.unit_height = cmp.hover_stylesheet.unit_height;
        stylesheet.unit_width = cmp.hover_stylesheet.unit_width;
        strcpy(stylesheet.font_family, cmp.hover_stylesheet.font_family);
    } else {
        stylesheet.childs_direction = cmp.stylesheet.childs_direction;
        stylesheet.component_justify = cmp.stylesheet.component_justify;
        stylesheet.unit_top = cmp.stylesheet.unit_top;
        stylesheet.unit_left = cmp.stylesheet.unit_left;
        stylesheet.unit_height = cmp.stylesheet.unit_height;
        stylesheet.unit_width = cmp.stylesheet.unit_width;
        strcpy(stylesheet.font_family, cmp.stylesheet.font_family);
    }
    stylesheet.font_size = (int32_t)(cmp.stylesheet.font_size*(1-cmp.__transition)+cmp.hover_stylesheet.font_size*cmp.__transition);
    stylesheet.font_horizontal_align = (horizontal_align)(cmp.stylesheet.font_horizontal_align*(1-cmp.__transition)+cmp.hover_stylesheet.font_horizontal_align*cmp.__transition);
    stylesheet.font_vertical_align = (vertical_align)(cmp.stylesheet.font_vertical_align*(1-cmp.__transition)+cmp.hover_stylesheet.font_vertical_align*cmp.__transition);
    stylesheet.padding = (int32_t)(cmp.stylesheet.padding*(1-cmp.__transition)+cmp.hover_stylesheet.padding*cmp.__transition);
    stylesheet.gap = (int32_t)(cmp.stylesheet.padding*(1-cmp.__transition)+cmp.hover_stylesheet.padding*cmp.__transition);
    stylesheet.top = (int32_t)(cmp.stylesheet.top*(1-cmp.__transition)+cmp.hover_stylesheet.top*cmp.__transition);
    stylesheet.left = (int32_t)(cmp.stylesheet.left*(1-cmp.__transition)+cmp.hover_stylesheet.left*cmp.__transition);
    stylesheet.height = (int32_t)(cmp.stylesheet.height*(1-cmp.__transition)+cmp.hover_stylesheet.height*cmp.__transition);
    stylesheet.width = (int32_t)(cmp.stylesheet.width*(1-cmp.__transition)+cmp.hover_stylesheet.width*cmp.__transition);
    stylesheet.border_radius_top_left = (int32_t)(cmp.stylesheet.border_radius_top_left*(1-cmp.__transition)+cmp.hover_stylesheet.border_radius_top_left*cmp.__transition);
    stylesheet.border_radius_top_right = (int32_t)(cmp.stylesheet.border_radius_top_right*(1-cmp.__transition)+cmp.hover_stylesheet.border_radius_top_right*cmp.__transition);
    stylesheet.border_radius_bottom_left = (int32_t)(cmp.stylesheet.border_radius_bottom_left*(1-cmp.__transition)+cmp.hover_stylesheet.border_radius_bottom_left*cmp.__transition);
    stylesheet.border_radius_bottom_right = (int32_t)(cmp.stylesheet.border_radius_bottom_right*(1-cmp.__transition)+cmp.hover_stylesheet.border_radius_bottom_right*cmp.__transition);
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


/**
 * Recalculate a unit from a cmp.
 *
 * @param {int32_t} *value
 * @param {unit} *value_unit
 * @param {int32_t} reference ( Value from the parent component )
 *
 * @returns {style}
 */
void transformUnit(int32_t *value, unit *value_unit, int32_t reference)
{
    switch(*value_unit)
    {
        case UNIT_PERCENTAGE:
            *value = (int32_t)(((float)(*value)/100)*reference);
            *value_unit = UNIT_PX;
        default:
            break;
    }
}


/**
 * Recalculate the units of the cmp.
 *
 * @param {style} stylesheet
 * @param {style} parentStylesheet
 *
 * @returns {style}
 */
style transformUnits(style stylesheet, style parentStylesheet)
{
    transformUnit(&(stylesheet.top), &(stylesheet.unit_top), parentStylesheet.height+parentStylesheet.padding);
    transformUnit(&(stylesheet.left), &(stylesheet.unit_left), parentStylesheet.width+parentStylesheet.padding);
    transformUnit(&(stylesheet.height), &(stylesheet.unit_height), parentStylesheet.height-2*parentStylesheet.padding);
    transformUnit(&(stylesheet.width), &(stylesheet.unit_width), parentStylesheet.width-2*parentStylesheet.padding);
    return stylesheet;
}


/**
 * Call functions to recalculate the units of the component
 * and changes his coordinates according to the coordinates
 * and the flex direction of his parent.
 *
 * @param {int32_t} top
 * @param {int32_t} left
 * @param {int32_t} height
 * @param {int32_t} width
 * @param {component} components[]
 * @param {uint32_t} components_size
 * @param {component} cmp
 *
 * @returns {style}
 */
style autoLayout(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t components_size, component cmp)
{
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

    if(cmp.parent_id == 0)
    {
        cmp.stylesheet = transformUnits(cmp.stylesheet, rootStylesheet);
        cmp.hover_stylesheet = transformUnits(cmp.hover_stylesheet, rootStylesheet);
    }
    if(cmp.parent_id>=cmp.id || cmp.parent_id == 0) return styleTransition(cmp);
    while((i<cmp.id)&&i<components_size&&!stop)
    {
        if(components[i].parent_id != 0)
        {
            /* Transform units with parent stylesheet as reference */
            tmp_cmp = components[i];
            tmp_cmp.stylesheet = transformUnits(tmp_cmp.stylesheet, stylesheets[components[i].parent_id-1]);
            tmp_cmp.hover_stylesheet = transformUnits(tmp_cmp.hover_stylesheet, stylesheets[components[i].parent_id-1]);
            stylesheets[i] = styleTransition(tmp_cmp);

            /*
                Put the child component inside his parents at the correct offset and increment/decrement
                the offset according to the flex direction and the child justification
            */
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

                            stylesheets[i].top = offsets[components[i].parent_id-1].top_offset+stylesheets[i].top;
                            stylesheets[i].left = offsets[components[i].parent_id-1].left_offset+stylesheets[i].left;
                            offsets[components[i].parent_id-1].left_offset += stylesheets[i].width+stylesheets[components[i].parent_id-1].gap;
                            break;
                        case JUSTIFY_END:
                            offsets[i].top_offset = offsets[components[i].parent_id-1].top_offset+stylesheets[i].top+stylesheets[i].padding;
                            offsets[i].left_offset = offsets[components[i].parent_id-1].right_offset-(stylesheets[i].left+stylesheets[i].width-stylesheets[i].padding);
                            offsets[i].bottom_offset = offsets[components[i].parent_id-1].top_offset+stylesheets[i].top+stylesheets[i].height-stylesheets[i].padding;
                            offsets[i].right_offset = offsets[components[i].parent_id-1].right_offset-stylesheets[i].padding+stylesheets[i].left;

                            stylesheets[i].top = offsets[components[i].parent_id-1].top_offset+stylesheets[i].top;
                            stylesheets[i].left = offsets[components[i].parent_id-1].right_offset-stylesheets[i].width+stylesheets[i].left;
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

                            stylesheets[i].top = offsets[components[i].parent_id-1].top_offset+stylesheets[i].top;
                            stylesheets[i].left = offsets[components[i].parent_id-1].left_offset+stylesheets[i].left;
                            offsets[components[i].parent_id-1].top_offset += stylesheets[i].height+stylesheets[components[i].parent_id-1].gap;
                            break;
                        case JUSTIFY_END:
                            offsets[i].top_offset = offsets[components[i].parent_id-1].bottom_offset-(stylesheets[i].top+stylesheets[i].height-stylesheets[i].padding);
                            offsets[i].left_offset = offsets[components[i].parent_id-1].left_offset+stylesheets[i].left+stylesheets[i].padding;
                            offsets[i].bottom_offset = offsets[components[i].parent_id-1].bottom_offset-stylesheets[i].padding+stylesheets[i].top;
                            offsets[i].right_offset = offsets[components[i].parent_id-1].left_offset+stylesheets[i].left+stylesheets[i].width-stylesheets[i].padding;

                            stylesheets[i].top = offsets[components[i].parent_id-1].bottom_offset-stylesheets[i].height+stylesheets[i].top;
                            stylesheets[i].left = offsets[components[i].parent_id-1].left_offset+stylesheets[i].left;
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


/**
 * Returns TRUE or FALSE according to if yes or
 * not the cursor ( x, y ) is inside the idbox of
 * that describe the stylesheet.
 *
 * @param {style} stylesheet
 * @param {int32_t} x
 * @param {int32_t} y
 *
 * @returns {boolean}
 */
boolean idboxComponent(style stylesheet, int32_t x, int32_t y)
{
    int32_t dx, dy, rt, rl, rr, rb;

    if(stylesheet.height == 0 || stylesheet.width == 0)return FALSE;
    if(stylesheet.border_radius_top_left!=0||stylesheet.border_radius_top_right!=0||stylesheet.border_radius_bottom_left!=0||stylesheet.border_radius_bottom_right!=0)
    {
        /* Permit us to know the greater border_radius between two corner in the same direction ( useful ) */
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

        /* Idbox calculations for corners if the border radius is greater than 0 */
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


/**
 * Call functions to draw every components based on their real
 * stylesheet and the type of component it is.
 *
 * @param {settings} set
 * @param {int32_t} top
 * @param {int32_t} left
 * @param {int32_t} height
 * @param {int32_t} width
 * @param {component} components[]
 * @param {uint32_t} components_size
 * @param {game} g
 * @param {text_component} texts[]
 * @param {uint32_t} texts_size
 * @param {key_component} keys[]
 * @param {uint32_t} keys_size
 * @param {image_component} images[]
 * @param {uint32_t} images_size
 *
 * @returns {void}
 */
void drawComponents(settings set, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t components_size, game g, text_component texts[], uint32_t texts_size, key_component keys[], uint32_t keys_size, image_component images[], uint32_t images_size)
{
    uint32_t i;

    for(i = 0; i<components_size; i++)
    {
        drawComponent(set, components[i], autoLayout(top, left, height, width, components, components_size, components[i]), g, texts, texts_size, keys, keys_size, images, images_size);
    }
}


/**
 * Allows drawing a single component based on its stylesheet
 * and the type of component it is.
 *
 * @param {settings} set
 * @param {component} cmp
 * @param {style} stylesheet
 * @param {game} g
 * @param {text_component} texts[]
 * @param {uint32_t} texts_size
 * @param {key_component} keys[]
 * @param {uint32_t} keys_size
 * @param {image_component} images[]
 * @param {uint32_t} images_size
 *
 * @returns {void}
 */
void drawComponent(settings set, component cmp, style stylesheet, game g, text_component texts[], uint32_t texts_size, key_component keys[], uint32_t keys_size, image_component images[], uint32_t images_size)
{
    MLV_Image *mlv_img;
    MLV_Font *font_family;
    int32_t font_height = 0, font_width = 0, image_height = 0, image_width = 0, horizontal_align = 0, vertical_align = 0, rt, rl, rr, rb;
    int32_t i, j;
    float image_ratio;
    key_component key_cmp;
    text_component txt_cmp;
    image_component img_cmp;
    char content[64];
    MLV_Color background_color;

    style stylesheet_edit;
    component cmp_edit;
    rgba tmp_color;

    /* Not drawing anything if not visible */
    if(stylesheet.height == 0 || stylesheet.width == 0)return;
    if(cmp.type == COMPONENT_GAME)
    {
        cmp_edit.type = COMPONENT_FRAME;
        stylesheet_edit = stylesheet;

        for(i = 0; i<GAME_HEIGHT; i++)
        {
            stylesheet.left = stylesheet_edit.left;
            for(j = 0; j<GAME_WIDTH; j++)
            {
                if(g.grid[i][j].a == 0) stylesheet.background_color = stylesheet_edit.background_color;
                else stylesheet.background_color = g.grid[i][j];

                if(g.actual_tetr.idbox != 0)
                {
                    if(g.actual_tetr.idbox == 1)
                    {
                        if(g.pos_y == i && g.pos_x == j)
                        {
                            tmp_color = g.actual_tetr.map[(i-g.pos_y)*g.actual_tetr.idbox+(j-g.pos_x)];
                            if(tmp_color.a != 0)
                            {
                                stylesheet.background_color = tmp_color;
                            }
                        }
                    } else {
                        if(g.pos_y-g.actual_tetr.idbox+1<=i && g.pos_y>=i
                        && g.pos_x-g.actual_tetr.idbox+1<=j && g.pos_x>=j)
                        {
                            tmp_color = g.actual_tetr.map[(i-(g.pos_y-g.actual_tetr.idbox+1))*g.actual_tetr.idbox+(j-(g.pos_x-g.actual_tetr.idbox+1))];
                            if(tmp_color.a != 0)
                            {
                                stylesheet.background_color = tmp_color;
                            }
                        }
                    }
                }

                if(i == 0 && j == 0) stylesheet.border_radius_top_left = stylesheet_edit.border_radius_top_left;
                else stylesheet.border_radius_top_left = 0;
                if(i == 0 && j == GAME_WIDTH-1) stylesheet.border_radius_top_right = stylesheet_edit.border_radius_top_right;
                else stylesheet.border_radius_top_right = 0;
                if(i == GAME_HEIGHT-1 && j == 0) stylesheet.border_radius_bottom_left = stylesheet_edit.border_radius_bottom_left;
                else stylesheet.border_radius_bottom_left = 0;
                if(i == GAME_HEIGHT-1 && j == GAME_WIDTH-1) stylesheet.border_radius_bottom_right = stylesheet_edit.border_radius_bottom_right;
                else stylesheet.border_radius_bottom_right = 0;

                drawComponent(set, cmp_edit, stylesheet, g, texts, texts_size, keys, keys_size, images, images_size);
                stylesheet.left += stylesheet.gap+stylesheet.width;
            }
            stylesheet.top += stylesheet.gap+stylesheet.height;
        }
    } else if(cmp.type == COMPONENT_IMAGE)
    {
        img_cmp = componentToImageComponent(cmp, images, images_size);
        if(MLV_path_exists(img_cmp.path))
        {
            mlv_img = MLV_load_image(img_cmp.path);
            if(mlv_img != NULL)
            {
                /* Resizing calculations to fit max width and max height */
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
                MLV_draw_image(mlv_img, stylesheet.left+stylesheet.width/2-image_width/2, stylesheet.top+stylesheet.height/2-image_height/2);

                MLV_free_image(mlv_img);
            }
        }
    } else {
        /* Not drawing frame if not visible */
        if(stylesheet.background_color.a != 0)
        {
            background_color = MLV_rgba(stylesheet.background_color.r, stylesheet.background_color.g, stylesheet.background_color.b, stylesheet.background_color.a);
            if(set.graphics_border_radius==TRUE&&(stylesheet.border_radius_top_left!=0||stylesheet.border_radius_top_right!=0||stylesheet.border_radius_bottom_left!=0||stylesheet.border_radius_bottom_right!=0))
            {
                if(stylesheet.border_radius_top_left==stylesheet.border_radius_top_right&&stylesheet.border_radius_top_right==stylesheet.border_radius_bottom_left&&stylesheet.border_radius_bottom_left==stylesheet.border_radius_bottom_right)
                {
                    /* Optimized border radius if there are all the same */
                    MLV_draw_filled_rectangle(stylesheet.left+stylesheet.border_radius_top_left, stylesheet.top, stylesheet.width-2*stylesheet.border_radius_top_left, stylesheet.height, background_color);
                    MLV_draw_filled_rectangle(stylesheet.left, stylesheet.top+stylesheet.border_radius_top_left, stylesheet.width, stylesheet.height-stylesheet.border_radius_top_left*2, background_color);
                    
                    MLV_draw_filled_circle(stylesheet.left+stylesheet.border_radius_top_left, stylesheet.top+stylesheet.border_radius_top_left-1, stylesheet.border_radius_top_left-1, background_color);
                    MLV_draw_filled_circle(stylesheet.left+stylesheet.border_radius_bottom_left, stylesheet.top+stylesheet.height-stylesheet.border_radius_bottom_left, stylesheet.border_radius_bottom_left-1, background_color);
                    MLV_draw_filled_circle(stylesheet.left+stylesheet.width-stylesheet.border_radius_top_right-1, stylesheet.top+stylesheet.border_radius_top_right-1, stylesheet.border_radius_top_right-1, background_color);
                    MLV_draw_filled_circle(stylesheet.left+stylesheet.width-stylesheet.border_radius_bottom_right-1, stylesheet.top+stylesheet.height-stylesheet.border_radius_bottom_right, stylesheet.border_radius_bottom_right-1, background_color);
                } else {
                    /* Independant border radius */

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
                }
            } else {
                /* No border radius */
                MLV_draw_filled_rectangle(stylesheet.left, stylesheet.top, stylesheet.width, stylesheet.height, background_color);
            }
        }
        
        if(cmp.type == COMPONENT_TEXT || cmp.type == COMPONENT_KEY)
        {
            switch(cmp.type)
            {
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
            if(MLV_path_exists(stylesheet.font_family))
            {
                font_family = MLV_load_font(stylesheet.font_family, stylesheet.font_size);
                MLV_get_size_of_text_with_font(content, &font_width, &font_height, font_family);
                
                switch(stylesheet.font_horizontal_align)
                {
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
                switch(stylesheet.font_vertical_align)
                {
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


/**
 * Initialisation of basic component structure.
 *
 * @param {uint32_t} id
 * @param {component_type} type
 * @param {uint32_t} parent_id
 * @param {style} stylesheet
 * @param {boolean} is_hoverable
 * @param {boolean} ignore_hover ( let parent component take the hover )
 * @param {style} hover_stylesheet
 * @param {uint32_t} transition_duration
 *
 * @returns {component}
 */
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


/**
 * Initialisation of frame component structure.
 *
 * @param {component} components[]
 * @param {uint32_t} *components_size
 * @param {uint32_t} parent_id
 * @param {style} stylesheet
 * @param {boolean} is_hoverable
 * @param {boolean} ignore_hover ( let parent component take the hover )
 * @param {style} hover_stylesheet
 * @param {uint32_t} transition_duration
 *
 * @returns {void}
 */
void createFrame(component components[], uint32_t *components_size, uint32_t parent_id, style stylesheet, boolean is_hoverable, boolean ignore_hover, style hover_stylesheet, uint32_t transition_duration)
{
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;
    components[*components_size] = initComponent((*components_size)+1, COMPONENT_FRAME, parent_id, stylesheet, is_hoverable, ignore_hover, hover_stylesheet, transition_duration);
    (*components_size)++;
}


/**
 * Initialisation of button component structure.
 *
 * @param {component} components[]
 * @param {uint32_t} *components_size
 * @param {button_component} buttons[]
 * @param {uint32_t} *buttons_size
 * @param {uint32_t} parent_id
 * @param {style} stylesheet
 * @param {boolean} is_hoverable
 * @param {boolean} ignore_hover ( let parent component take the hover )
 * @param {style} hover_stylesheet
 * @param {uint32_t} transition_duration
 * @param {button_action_type} action_type
 * @param {char} path[]
 *
 * @returns {void}
 */
void createButton(component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, uint32_t parent_id, style stylesheet, boolean is_hoverable, boolean ignore_hover, style hover_stylesheet, uint32_t transition_duration, button_action_type action_type, char path[])
{
    button_component btn_cmp;
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;

    btn_cmp.id = (*components_size)+1;
    btn_cmp.action_type = action_type;
    strcpy(btn_cmp.path, path);
    components[*components_size] = initComponent((*components_size)+1, COMPONENT_BUTTON, parent_id, stylesheet, is_hoverable, ignore_hover, hover_stylesheet, transition_duration);
    (*components_size)++;
    buttons[*buttons_size] = btn_cmp;
    (*buttons_size)++;
}


/**
 * Initialisation of text component structure.
 *
 * @param {component} components[]
 * @param {uint32_t} *components_size
 * @param {text_component} texts[]
 * @param {uint32_t} *texts_size
 * @param {uint32_t} parent_id
 * @param {style} stylesheet
 * @param {boolean} is_hoverable
 * @param {boolean} ignore_hover ( let parent component take the hover )
 * @param {style} hover_stylesheet
 * @param {uint32_t} transition_duration
 * @param {char} content[]
 *
 * @returns {void}
 */
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


/**
 * Initialisation of key component structure.
 *
 * @param {component} components[]
 * @param {uint32_t} *components_size
 * @param {key_component} keys[]
 * @param {uint32_t} *keys_size
 * @param {uint32_t} parent_id
 * @param {style} stylesheet
 * @param {boolean} is_hoverable
 * @param {boolean} ignore_hover ( let parent component take the hover )
 * @param {style} hover_stylesheet
 * @param {uint32_t} transition_duration
 * @param {key_take_type} take_type
 * @param {char} content[]
 *
 * @returns {void}
 */
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


/**
 * Initialisation of image component structure.
 *
 * @param {component} components[]
 * @param {uint32_t} *components_size
 * @param {image_component} images[]
 * @param {uint32_t} *images_size
 * @param {uint32_t} parent_id
 * @param {style} stylesheet
 * @param {boolean} is_hoverable
 * @param {boolean} ignore_hover ( let parent component take the hover )
 * @param {style} hover_stylesheet
 * @param {uint32_t} transition_duration
 * @param {char} path[]
 *
 * @returns {void}
 */
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

/**
 * Initialisation of grab component structure.
 *
 * @param {component} components[]
 * @param {uint32_t} *components_size
 * @param {uint32_t} parent_id
 * @param {style} stylesheet
 * @param {boolean} is_hoverable
 * @param {boolean} ignore_hover ( let parent component take the hover )
 * @param {style} hover_stylesheet
 * @param {uint32_t} transition_duration
 *
 * @returns {void}
 */
void createGrab(component components[], uint32_t *components_size, uint32_t parent_id, style stylesheet, boolean is_hoverable, boolean ignore_hover, style hover_stylesheet, uint32_t transition_duration)
{
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;
    components[*components_size] = initComponent((*components_size)+1, COMPONENT_GRAB, parent_id, stylesheet, is_hoverable, ignore_hover, hover_stylesheet, transition_duration);
    (*components_size)++;
}

/**
 * Initialisation of game component structure.
 *
 * @param {component} components[]
 * @param {uint32_t} *components_size
 * @param {uint32_t} parent_id
 * @param {style} stylesheet
 *
 * @returns {void}
 */
void createGame(component components[], uint32_t *components_size, uint32_t parent_id, style stylesheet)
{
    if((*components_size)+1 >= COMPONENTS_MAX_SIZE)return;

    components[*components_size] = initComponent((*components_size)+1, COMPONENT_GAME, parent_id, stylesheet, FALSE, TRUE, stylesheet, 0);
    (*components_size)++;
}