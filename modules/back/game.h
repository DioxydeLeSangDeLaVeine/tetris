#ifndef H_GAME_BACKMODULE
#define H_GAME_BACKMODULE

#define GAME_HEIGHT 20
#define GAME_WIDTH 10

#include "../util/util.h"

typedef struct {
    rgba grid [GAME_HEIGHT][GAME_WIDTH];
    tetrimino actual_tetr;
    int32_t pos_x;
    int32_t pos_y;
    uint32_t score;
    gamemode mode;
    uint32_t time;
    uint8_t level;
} game;

void resetGrid(game *g);

#endif