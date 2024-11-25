#include <stdio.h>
#include <stdlib.h>
#include "./game.h"
#include "../ui/ui.h"
#include "../util/util.h"

void newGrid(game *g)
{
    int i, j;
    rgba color;

    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 0;

    for(i = 0; i<GAME_HEIGHT; i++)
    {
        for(j = 0; j<GAME_WIDTH; j++)
        {
            g->grid[i][j] = color;
        }
    }
}

void newGame(game *g)
{
    newGrid(g);

    (*g).time = 0;
    (*g).score = 0;
    (*g).lines = 0;
    (*g).level = 0;

    (*g).actual_tetr.idbox = 0;
    (*g).drop = 0;
    (*g).fastdrop = FALSE;
}

void moveRight(game *g)
{

}
void moveLeft(game *g)
{

}
void turnRight(game *g)
{

}
void turnLeft(game *g)
{

}
void fastDrop(game *g)
{
    (*g).fastdrop = TRUE;
}

boolean tick(game *g, tetrimino tab[64], uint32_t tab_size, uint64_t framerate)
{
    if((*g).actual_tetr.idbox == 0)
    {
        /* Ajout d'un tetrimino random + vérifications */
    } else {
        if((*g).drop >= 100) {
            /* Drop d'une case + vérifications */
            (*g).drop = 0;
        } else {
            if((*g).fastdrop == TRUE)
            {
                (*g).drop += 2*(framerate/10);
            } else {
                (*g).drop += framerate/10; /* /1000*100 -> /10, 1000 = seconde d'attente avant drop, 100 = pourcentage */
            }
        }
    }
    (*g).fastdrop = FALSE;

    return FALSE;
}