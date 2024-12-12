#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
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

    g->time = 0;
    g->score = 0;
    g->lines = 0;
    g->level = 0;

    g->actual_tetr.idbox = 0;
    g->pos_y = 0;
    g->pos_x = 0;
    g->drop = 0;
    g->fastdrop = FALSE;
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
            g->mode = GAMEMODE_MARATHON;
            break;
        case 2:
            g->mode = GAMEMODE_ULTRA;
            break;
        default:
            g->mode = GAMEMODE_SURVIVAL;
    }
    for(i = 7; i>=0; i--)
    {
        byte = fgetc(file);
        if(byte == EOF)return;
        g->time|=byte<<(8*i);
    }
    for(i = 3; i>=0; i--)
    {
        byte = fgetc(file);
        if(byte == EOF)return;
        g->score|=byte<<(8*i);
    }
    for(i = 3; i>=0; i--)
    {
        byte = fgetc(file);
        if(byte == EOF)return;
        g->lines|=byte<<(8*i);
    }
    byte = fgetc(file);
    if(byte == EOF)return;
    g->level = byte;

    for(i = 3; i>=0; i--)
    {
        byte = fgetc(file);
        if(byte == EOF)return;
        g->pos_y|=byte<<(8*i);
    }
    for(i = 3; i>=0; i--)
    {
        byte = fgetc(file);
        if(byte == EOF)return;
        g->pos_x|=byte<<(8*i);
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
        g->actual_tetr.path[i] = byte;
    }
    g->actual_tetr.path[i] = '\0';
    g->actual_tetr = loadTetrimino(g->actual_tetr.path);

    for(i = 0; i<GAME_HEIGHT; i++)
    {
        for(j = 0; j<GAME_WIDTH; j++)
        {
            byte = fgetc(file);
            if(byte == EOF)return;
            g->grid[i][j].r = byte;
            byte = fgetc(file);
            if(byte == EOF)return;
            g->grid[i][j].g = byte;
            byte = fgetc(file);
            if(byte == EOF)return;
            g->grid[i][j].b = byte;
            byte = fgetc(file);
            if(byte == EOF)return;
            g->grid[i][j].a = byte;
        }
    }
}

uint32_t loadGames(load tab[64])
{
    DIR *folder = opendir("./data/saves");
    struct dirent *entry;
    char *dot;
    int i;
    game g;

    if(folder == NULL) {
        return 0;
    }
    for(i = 0; i<64; i++)
    {
        tab[i].id = 0;
    }

    i = 0;
    while((entry = readdir(folder)) != NULL && i < 64)
    {
        if(entry->d_type == DT_REG)
        {
            snprintf(tab[i].path, sizeof(tab[i].path), "./data/saves/%s", entry->d_name);
            strcpy(tab[i].name, entry->d_name);
            dot = strrchr(tab[i].name, '.');
            if(dot != NULL)
            {
                *dot = '\0';
            }

            loadGame(&g, tab[i].path);

            tab[i].time = g.time;
            tab[i].score = g.score;
            tab[i].lines = g.lines;
            tab[i].id = i+1;
            i++;
        }
    }
    closedir(folder);

    return i;
}

int32_t LeftFromMap(tetrimino actual_tetr)
{
    int32_t i, j;
    for(i = 0; i<actual_tetr.idbox; i++)
    {
        for(j = 0; j<actual_tetr.idbox; j++)
        {
            if(actual_tetr.map[j*actual_tetr.idbox+i].a != 0)return i;
        }
    }
    return 0;
}
int32_t RightFromMap(tetrimino actual_tetr)
{
    int32_t i, j;
    for(i = actual_tetr.idbox-1; i>=0; i--)
    {
        for(j = 0; j<actual_tetr.idbox; j++)
        {
            if(actual_tetr.map[j*actual_tetr.idbox+i].a != 0)return (actual_tetr.idbox-1)-i;
        }
    }
    return 0;
}
int32_t BottomFromMap(tetrimino actual_tetr)
{
    int32_t i, j;
    for(i = actual_tetr.idbox-1; i>=0; i--)
    {
        for(j = 0; j<actual_tetr.idbox; j++)
        {
            if(actual_tetr.map[i*actual_tetr.idbox+j].a != 0)return (actual_tetr.idbox-1)-i;
        }
    }
    return 0;
}

boolean verifyLeft(game *g)
{
    int32_t i, j;
    for(i = 0; i<g->actual_tetr.idbox; i++)
    {
        for(j = 0; j<g->actual_tetr.idbox; j++)
        {
            if(g->actual_tetr.map[i*g->actual_tetr.idbox+j].a != 0)
            {
                if(g->pos_y-g->actual_tetr.idbox+i+1<GAME_HEIGHT)
                {
                    if(g->pos_x-g->actual_tetr.idbox+j>=0)
                    {
                        if(g->grid[g->pos_y-g->actual_tetr.idbox+i+1][g->pos_x-g->actual_tetr.idbox+j].a != 0)return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}
boolean verifyRight(game *g)
{
    int32_t i, j;
    for(i = 0; i<g->actual_tetr.idbox; i++)
    {
        for(j = 0; j<g->actual_tetr.idbox; j++)
        {
            if(g->actual_tetr.map[i*g->actual_tetr.idbox+j].a != 0)
            {
                if(g->pos_y-g->actual_tetr.idbox+i+1<GAME_HEIGHT)
                {
                    if(g->pos_x-g->actual_tetr.idbox+j+2<GAME_WIDTH)
                    {
                        if(g->grid[g->pos_y-g->actual_tetr.idbox+i+1][g->pos_x-g->actual_tetr.idbox+j+2].a != 0)return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}
boolean verifyBottom(game *g)
{
    int32_t i, j;
    for(i = 0; i<g->actual_tetr.idbox; i++)
    {
        for(j = 0; j<g->actual_tetr.idbox; j++)
        {
            if(g->actual_tetr.map[i*g->actual_tetr.idbox+j].a != 0)
            {
                if(g->pos_y-g->actual_tetr.idbox+i+2<GAME_HEIGHT)
                {
                    if(g->grid[g->pos_y-g->actual_tetr.idbox+i+2][g->pos_x-g->actual_tetr.idbox+j+1].a != 0)return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void moveRight(game *g)
{
    if(g->pos_x < GAME_WIDTH-1+RightFromMap(g->actual_tetr)&&!verifyRight(g))
    {
        g->pos_x++;
    }
}
void moveLeft(game *g)
{
    if(g->pos_x-g->actual_tetr.idbox >= 0-LeftFromMap(g->actual_tetr)&&!verifyLeft(g))
    {
        g->pos_x--;
    }
}
void turnRight(game *g)
{
    int32_t i, j, left_move = 0, right_move = 0;
    rgba newmap[16];
    rgba oldmap[16];

    if(g->actual_tetr.idbox%2 == 0)
    {
        for(i = 0; i<g->actual_tetr.idbox; i++)
        {
            for(j = 0; j<g->actual_tetr.idbox; j++)
            {
                oldmap[i*g->actual_tetr.idbox+j] = g->actual_tetr.map[i*g->actual_tetr.idbox+j];
                newmap[i*g->actual_tetr.idbox+j] = g->actual_tetr.map[j*g->actual_tetr.idbox+i];
            }
        }
        for(i = 0; i<g->actual_tetr.idbox; i++)
        {
            for(j = 0; j<g->actual_tetr.idbox; j++)
            {
                g->actual_tetr.map[i*g->actual_tetr.idbox+j] = newmap[i*g->actual_tetr.idbox+j];
            }
        }
    } else {
        for(i = 0; i<g->actual_tetr.idbox; i++)
        {
            for(j = 0; j<g->actual_tetr.idbox; j++)
            {
                oldmap[i*g->actual_tetr.idbox+j] = g->actual_tetr.map[i*g->actual_tetr.idbox+j];
                newmap[i*g->actual_tetr.idbox+j] = g->actual_tetr.map[j*g->actual_tetr.idbox+i];
            }
        }
        for(i = 0; i<g->actual_tetr.idbox; i++)
        {
            for(j = 0; j<g->actual_tetr.idbox; j++)
            {
                g->actual_tetr.map[i*g->actual_tetr.idbox+j] = newmap[i*g->actual_tetr.idbox+g->actual_tetr.idbox-j-1];
            }
        }
    }
    while(g->pos_x >= GAME_WIDTH+RightFromMap(g->actual_tetr))
    {
        g->pos_x--;
        left_move++;
    }
    while(g->pos_x-g->actual_tetr.idbox < 0-LeftFromMap(g->actual_tetr)-1)
    {
        g->pos_x++;
        right_move++;
    }
    if(verifyLose(g))
    {
        for(i = 0; i<g->actual_tetr.idbox; i++)
        {
            for(j = 0; j<g->actual_tetr.idbox; j++)
            {
                g->actual_tetr.map[i*g->actual_tetr.idbox+j] = oldmap[i*g->actual_tetr.idbox+j];
            }
        }
        for(i = 0; i<left_move; i++) {
            g->pos_x++;
        }
        for(i = 0; i<right_move; i++) {
            g->pos_x--;
        }
    }
} 

void turnLeft(game *g)
{
    int32_t i, j, left_move = 0, right_move = 0;
    rgba newmap[16];
    rgba oldmap[16];

    if(g->actual_tetr.idbox%2 == 0)
    {
        for(i = 0; i<g->actual_tetr.idbox; i++)
        {
            for(j = 0; j<g->actual_tetr.idbox; j++)
            {
                oldmap[i*g->actual_tetr.idbox+j] = g->actual_tetr.map[i*g->actual_tetr.idbox+j];
                newmap[i*g->actual_tetr.idbox+j] = g->actual_tetr.map[j*g->actual_tetr.idbox+i];
            }
        }
        for(i = 0; i<g->actual_tetr.idbox; i++)
        {
            for(j = 0; j<g->actual_tetr.idbox; j++)
            {
                g->actual_tetr.map[i*g->actual_tetr.idbox+j] = newmap[i*g->actual_tetr.idbox+j];
            }
        }
    } else {
        for(i = 0; i<g->actual_tetr.idbox; i++)
        {
            for(j = 0; j<g->actual_tetr.idbox; j++)
            {
                oldmap[i*g->actual_tetr.idbox+j] = g->actual_tetr.map[i*g->actual_tetr.idbox+j];
                newmap[i*g->actual_tetr.idbox+j] = g->actual_tetr.map[j*g->actual_tetr.idbox+i];
            }
        }
        for(i = 0; i<g->actual_tetr.idbox; i++)
        {
            for(j = 0; j<g->actual_tetr.idbox; j++)
            {
                g->actual_tetr.map[i*g->actual_tetr.idbox+j] = newmap[(g->actual_tetr.idbox-i-1)*g->actual_tetr.idbox+j];
            }
        }
    }
    while(g->pos_x >= GAME_WIDTH+RightFromMap(g->actual_tetr))
    {
        g->pos_x--;
        left_move++;
    }
    while(g->pos_x-g->actual_tetr.idbox < 0-LeftFromMap(g->actual_tetr)-1)
    {
        g->pos_x++;
        right_move++;
    }
    if(verifyLose(g))
    {
        for(i = 0; i<g->actual_tetr.idbox; i++)
        {
            for(j = 0; j<g->actual_tetr.idbox; j++)
            {
                g->actual_tetr.map[i*g->actual_tetr.idbox+j] = oldmap[i*g->actual_tetr.idbox+j];
            }
        }
        for(i = 0; i<left_move; i++) {
            g->pos_x++;
        }
        for(i = 0; i<right_move; i++) {
            g->pos_x--;
        }
    }

}
void fastDrop(game *g)
{
    g->fastdrop = TRUE;
}

void recalculateScore(game *g, boolean *actualise, boolean *recreate)
{
    int32_t i, j, k, lines = 0;
    boolean is_complete;

    for(i = 0; i<GAME_HEIGHT; i++)
    {
        is_complete = TRUE;
        for(j = 0; j<GAME_WIDTH; j++)
        {
            if(g->grid[i][j].a == 0)
            {
                is_complete = FALSE;
                break;
            }
        }
        if(is_complete == TRUE)
        {
            lines++;
            for(k = i; k>=1; k--)
            {
                for(j = 0; j<GAME_WIDTH; j++)
                {
                    g->grid[k][j] = g->grid[k-1][j];
                }
            }
            for(j = 0; j<GAME_WIDTH; j++)
            {
                g->grid[0][j].a = 0;
            }
        }
    }
    g->lines+=lines;
    if(lines==1) g->score+=40;
    if(lines==2) g->score+=100;
    if(lines==3) g->score+=300;
    if(lines>=4) g->score+=1200;
    if(lines>=0)
    {
        *recreate = TRUE;
        *actualise = TRUE;
    }
}

boolean verifyLose(game *g)
{
    int32_t i, j;
    for(i = 0; i<g->actual_tetr.idbox; i++)
    {
        for(j = 0; j<g->actual_tetr.idbox; j++)
        {
            if(g->actual_tetr.map[i*g->actual_tetr.idbox+j].a != 0) {
                if(g->pos_y-g->actual_tetr.idbox+i+1<GAME_HEIGHT) {
                    if(g->grid[g->pos_y-g->actual_tetr.idbox+i+1][g->pos_x-g->actual_tetr.idbox+j+1].a != 0)return TRUE;
                }
            }
        }
    }
    return FALSE;
}

boolean tick(game *g, tetrimino tab[64], uint32_t tab_size, uint64_t framerate, boolean *actualise, boolean *recreate)
{
    int32_t i, j;
    if(g->actual_tetr.idbox == 0)
    {
        g->actual_tetr = tab[rand()%tab_size];
        g->pos_x = ((GAME_WIDTH/2)-1)-((g->actual_tetr.idbox-RightFromMap(g->actual_tetr)-LeftFromMap(g->actual_tetr))/2)+g->actual_tetr.idbox-LeftFromMap(g->actual_tetr);
        g->pos_y = g->actual_tetr.idbox;

        if((g->actual_tetr.idbox-RightFromMap(g->actual_tetr)-LeftFromMap(g->actual_tetr))%2 == 1) g->pos_x--;

        if(verifyLose(g))
        {
            g->actual_tetr.idbox = 0;
            return TRUE;
        }
    } else {
        if(g->drop >= 100) {
            /* Drop d'une case + vérifications */

            if(g->pos_y >= GAME_HEIGHT-1+BottomFromMap(g->actual_tetr) || verifyBottom(g))
            {
                for(i = 0; i<g->actual_tetr.idbox; i++)
                {
                    for(j = 0; j<g->actual_tetr.idbox; j++)
                    {
                        if(g->actual_tetr.map[i*g->actual_tetr.idbox+j].a != 0) {
                            if(g->pos_y-g->actual_tetr.idbox+i+1<GAME_HEIGHT) {
                                g->grid[g->pos_y-g->actual_tetr.idbox+i+1][g->pos_x-g->actual_tetr.idbox+j+1] = g->actual_tetr.map[i*g->actual_tetr.idbox+j];
                            }
                        }
                    }
                }
                g->actual_tetr.idbox = 0;
                recalculateScore(g, actualise, recreate);
            } else {
                g->pos_y+=1;
                g->drop-=100.;
            }
            *actualise = TRUE;
        } else {
            if(g->fastdrop == TRUE)
            {
                g->drop += 75;
                g->fastdrop = FALSE;
            } else {
                g->drop += (framerate/1000.)*100;
            }
        }
    }

    return FALSE;
}