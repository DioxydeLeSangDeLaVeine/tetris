#include "../ui/ui.h"
#include "./game.h"

void resetGrid(game *g)
{
    int i, j;
    rgba color;

    color.r = 0;
    color.g = 0;
    color.b = 0;

    g->actual_tetr.idbox = 0;

    for(i = 0; i<GAME_HEIGHT; i++)
    {
        for(j = 0; j<GAME_WIDTH; j++)
        {
            g->grid[i][j] = color;
        }
    }
}