#ifndef H_GAME_BACKMODULE
#define H_GAME_BACKMODULE

#define GAME_HEIGHT 20
#define GAME_WIDTH 10

#include "../util/util.h"

typedef struct {
    int32_t id;
    char name[24];
    int64_t time;
    uint32_t score;
    uint32_t lines;
    char path[320];
} load;

typedef struct {
    rgba grid [GAME_HEIGHT][GAME_WIDTH];
    tetrimino actual_tetr;
    int32_t pos_y;
    int32_t pos_x;
    uint32_t score;
    uint32_t lines;
    gamemode mode;
    uint64_t time;
    uint8_t level;
    double drop;
    boolean fastdrop;
} game;

void newGrid(game *g);
void newGame(game *g);
void loadGame(game *g, char path[320]);
uint32_t loadGames(load tab[64]);
void moveRight(game *g);
void moveLeft(game *g);
void turnRight(game *g);
void turnLeft(game *g);
void fastDrop(game *g);
boolean tick(game *g, tetrimino tab[64], uint32_t tab_size, uint64_t framerate, boolean *actualise);

#endif