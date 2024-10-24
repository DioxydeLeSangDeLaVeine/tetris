#ifndef H_UI_MODULE
#define H_UI_MODULE

#define POPPINS_BLACK "./src/font/Poppins-Black.ttf"
#define POPPINS_BLACK_ITALITC "./src/font/Poppins-BlackItalic.ttf"
#define POPPINS_BOLD "./src/font/Poppins-Bold.ttf"
#define POPPINS_BOLD_ITALIC "./src/font/Poppins-BoldItalic.ttf"
#define POPPINS_EXTRABOLD "./src/font/Poppins-ExtraBold.ttf"
#define POPPINS_EXTRABOLD_ITALIC "./src/font/Poppins-ExtraBoldItalic.ttf"
#define POPPINS_EXTRALIGHT "./src/font/Poppins-ExtraLight.ttf"
#define POPPINS_EXTRALIGHT_ITALIC "./src/font/Poppins-ExtraLightItalic.ttf"
#define POPPINS_ITALIC "./src/font/Poppins-Italic.ttf"
#define POPPINS_LIGHT "./src/font/Poppins-Light.ttf"
#define POPPINS_LIGHT_ITALIC "./src/font/Poppins-LightItalic.ttf"
#define POPPINS_MEDIUM "./src/font/Poppins-Medium.ttf"
#define POPPINS_MEDIUM_ITALIC "./src/font/Poppins-MediumItalic.ttf"
#define POPPINS_REGULAR "./src/font/Poppins-Regular.ttf"
#define POPPINS_SEMIBOLD "./src/font/Poppins-SemiBold.ttf"
#define POPPINS_SEMIBOLD_ITALIC "./src/font/Poppins-SemiBoldItalic.ttf"
#define POPPINS_THIN "./src/font/Poppins-Thin.ttf"
#define POPPINS_THIN_ITALIC "./src/font/Poppins-ThinItalic.ttf"

typedef struct {
    int r;
    int g;
    int b;
} rgb;

typedef struct {
    int id;
    int action_type;
    int exist;
    int hoverable;
    int top;
    int left;
    int width;
    int height;
    int radius;
    rgb bg_color;
    char content[100];
    char font[100];
    int font_size;
    rgb font_color;
    rgb hovered_bg_color;
    rgb hovered_font_color;
} ButtonComponent;
void drawButton(ButtonComponent button, int hovered);
void addComponent(ButtonComponent components[], int components_size, int action_type, int hoverable, int top, int left, int width, int height, int radius, rgb bg_color, rgb hovered_bg_color, char content[], char font[], int font_size, rgb font_color, rgb hovered_font_color);
int menu(int width, int height, ButtonComponent components[]);

#endif