#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

int main(int argc, char *argv[]) {
    MLV_create_window( "beginner - 2 - shapes", "shapes", 640, 480 );
    MLV_draw_rectangle( 10, 50, 40, 20, MLV_COLOR_BLUE );

    MLV_actualise_window();
    MLV_wait_seconds( 10 );
    MLV_free_window();
    
    exit(EXIT_SUCCESS);
}