#include"../ui/ui.h"
#define HEIGHT 20
#define WIDTH 10

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