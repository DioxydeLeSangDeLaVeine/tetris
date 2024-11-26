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
    (*g).pos_y = 0;
    (*g).pos_x = 0;
    (*g).drop = 0;
    (*g).fastdrop = FALSE;
}

void loadGame(game *g, char path[320])
{
    FILE *file = fopen(path, "rb");
    int byte, i, j, size = 0;

    newGame(g);
    if(file == NULL)
    {
        return;
    }

    byte = fgetc(file);
    if(byte == EOF)return;
    switch(byte)
    {
        case 1:
            (*g).mode = GAMEMODE_MARATHON;
            break;
        case 2:
            (*g).mode = GAMEMODE_ULTRA;
            break;
        default:
            (*g).mode = GAMEMODE_SURVIVAL;
    }
    for(i = 7; i>=0; i--)
    {
        byte = fgetc(file);
        if(byte == EOF)return;
        (*g).time|=byte<<(8*i);
    }
    for(i = 3; i>=0; i--)
    {
        byte = fgetc(file);
        if(byte == EOF)return;
        (*g).score|=byte<<(8*i);
    }
    for(i = 3; i>=0; i--)
    {
        byte = fgetc(file);
        if(byte == EOF)return;
        (*g).lines|=byte<<(8*i);
    }
    byte = fgetc(file);
    if(byte == EOF)return;
    (*g).level = byte;

    for(i = 3; i>=0; i--)
    {
        byte = fgetc(file);
        if(byte == EOF)return;
        (*g).pos_y|=byte<<(8*i);
    }
    for(i = 3; i>=0; i--)
    {
        byte = fgetc(file);
        if(byte == EOF)return;
        (*g).pos_x|=byte<<(8*i);
    }

    byte = fgetc(file);
    if(byte == EOF)return;
    size = byte<<8;
    byte = fgetc(file);
    if(byte == EOF)return;
    size|=byte;

    for(i = 0; i<size; i++)
    {
        byte = fgetc(file);
        if(byte == EOF)break;
        (*g).actual_tetr.path[i] = byte;
    }
    (*g).actual_tetr.path[i] = '\0';
    (*g).actual_tetr = loadTetrimino((*g).actual_tetr.path);

    for(i = 0; i<GAME_HEIGHT; i++)
    {
        for(j = 0; j<GAME_WIDTH; j++)
        {
            byte = fgetc(file);
            if(byte == EOF)return;
            (*g).grid[i][j].r = byte;
            byte = fgetc(file);
            if(byte == EOF)return;
            (*g).grid[i][j].g = byte;
            byte = fgetc(file);
            if(byte == EOF)return;
            (*g).grid[i][j].b = byte;
            byte = fgetc(file);
            if(byte == EOF)return;
            (*g).grid[i][j].a = byte;
        }
    }
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
    if((*g).fastdrop == TRUE)
    {
        (*g).fastdrop = FALSE;
    } else {
        (*g).fastdrop = TRUE;
    }
}

boolean tick(game *g, tetrimino tab[64], uint32_t tab_size, uint64_t framerate, boolean *actualise)
{
    if((*g).actual_tetr.idbox == 0)
    {
        /* Ajout d'un tetrimino random + vérifications */
    } else {
        if((*g).drop >= 100) {
            /* Drop d'une case + vérifications */
            (*g).pos_y+=1;
            (*g).drop-=100.;
            *actualise = TRUE;
        } else {
            if((*g).fastdrop == TRUE)
            {
                (*g).drop += 100;
            } else {
                (*g).drop += framerate/10.; /* /1000*100 -> /10, 1000 = seconde d'attente avant drop, 100 = pourcentage */
            }
        }
    }

    return FALSE;
}