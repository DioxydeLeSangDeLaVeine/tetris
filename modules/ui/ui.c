#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>



/**
 * Every functions in this module need to return
 * 1 or 0 depending or whether or not the UI is drawn
 * successfully or not.
 *
 * Notice that even if the function can't return 0,
 * return 1 anyway.
 */



int menu(int width, int height)
{
    /**
     * Returns 1 if the menu got successfully drawed,
     * if not it will returns 0.
     *
     * @param {int} width
     * @param {int} height
     * @returns {int}
     */

    MLV_draw_filled_rectangle(0, 0, width, height, MLV_rgba(255, 255, 255, 255));
    MLV_draw_filled_rectangle(0, 0, 150, height, MLV_rgba(0,0,255,255));

    return 1;
}