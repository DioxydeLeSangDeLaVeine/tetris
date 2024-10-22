#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#define HEIGHT 480
#define WIDTH 640

int main(int argc, char *argv[]) {
    MLV_create_window( "beginner - 2 - shapes", "shapes", WIDTH, HEIGHT );
    MLV_draw_filled_rectangle( 0, 0, 50, HEIGHT, MLV_rgba(0,0,255,255) );

    MLV_actualise_window();
    MLV_wait_seconds( 10 );
    MLV_free_window();
    
    exit(EXIT_SUCCESS);
}