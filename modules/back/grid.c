#include"../ui/ui.h"
#define HEIGHT 20
#define WIDTH 10

struct grid
{
    boolean is_occupated[HEIGHT][WIDTH];
    rgba color[HEIGHT][WIDTH];
};

typedef struct grid grid;

void new_grid(grid* container){
    int i, j;
    for(i = 0; i < HEIGHT; i++){
        for(j = 0; j < WIDTH; j++){
            container->is_occupated[i][j] = FALSE;
            container->color[i][j].r = 0;
            container->color[i][j].g = 0;
            container->color[i][j].b = 0;
            container->color[i][j].a = 0;
        }
    }
}

void new_game(int* score, grid* containeur){
    *score = 0;
    new_grid(containeur);
    start_game()
}

void close_game(/**/){
    /**/
}

void pause_game(/**/){
    /**/
}

void load_game(/**/){
    /**/
}

void save_game(/**/){
    /**/
}