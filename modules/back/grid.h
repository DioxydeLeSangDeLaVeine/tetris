#include"../ui/ui.h"

struct grid
{
    boolean is_occupated[HEIGHT][WIDTH];
    rgba color[HEIGHT][WIDTH];
};

typedef struct grid grid;