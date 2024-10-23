#ifndef H_UI_MODULE
#define H_UI_MODULE

typedef struct {
    int r;
    int g;
    int b;
} rgb;

typedef struct {
    int action_type;
    int top;
    int left;
    int width;
    int height;
    int radius;
    rgb bg_color;
} ButtonComponent;

void addComponent(ButtonComponent components[], int components_size, int action_type, int top, int left, int width, int height, int radius, rgb color);
int menu(int width, int height, ButtonComponent components[]);

#endif