#ifndef H_UI_MODULE
#define H_UI_MODULE

#define COMPONENTS_MAX_SIZE 64

#define FONT_POPPINS_BLACK "./src/font/Poppins-Black.ttf"
#define FONT_POPPINS_BLACK_ITALITC "./src/font/Poppins-BlackItalic.ttf"
#define FONT_POPPINS_BOLD "./src/font/Poppins-Bold.ttf"
#define FONT_POPPINS_BOLD_ITALIC "./src/font/Poppins-BoldItalic.ttf"
#define FONT_POPPINS_EXTRABOLD "./src/font/Poppins-ExtraBold.ttf"
#define FONT_POPPINS_EXTRABOLD_ITALIC "./src/font/Poppins-ExtraBoldItalic.ttf"
#define FONT_POPPINS_EXTRALIGHT "./src/font/Poppins-ExtraLight.ttf"
#define FONT_POPPINS_EXTRALIGHT_ITALIC "./src/font/Poppins-ExtraLightItalic.ttf"
#define FONT_POPPINS_ITALIC "./src/font/Poppins-Italic.ttf"
#define FONT_POPPINS_LIGHT "./src/font/Poppins-Light.ttf"
#define FONT_POPPINS_LIGHT_ITALIC "./src/font/Poppins-LightItalic.ttf"
#define FONT_POPPINS_MEDIUM "./src/font/Poppins-Medium.ttf"
#define FONT_POPPINS_MEDIUM_ITALIC "./src/font/Poppins-MediumItalic.ttf"
#define FONT_POPPINS_REGULAR "./src/font/Poppins-Regular.ttf"
#define FONT_POPPINS_SEMIBOLD "./src/font/Poppins-SemiBold.ttf"
#define FONT_POPPINS_SEMIBOLD_ITALIC "./src/font/Poppins-SemiBoldItalic.ttf"
#define FONT_POPPINS_THIN "./src/font/Poppins-Thin.ttf"
#define FONT_POPPINS_THIN_ITALIC "./src/font/Poppins-ThinItalic.ttf"

typedef enum {
    COMPONENT_UNDEFINED,
    COMPONENT_FRAME,
    COMPONENT_BUTTON,
    COMPONENT_POPUP
} component_type;

typedef enum {
    HORIZONTAL_LEFT,
    HORIZONTAL_CENTER,
    HORIZONTAL_RIGHT
} horizontal_align;

typedef enum {
    VERTICAL_TOP,
    VERTICAL_CENTER,
    VERTICAL_BOTTOM
} vertical_align;

typedef enum {
    BUTTON_ACTION_UNDEFINED,
    BUTTON_ACTION_NONE,
    BUTTON_ACTION_QUIT,
    BUTTON_ACTION_CREATE_MENU_COMPONENTS,
    BUTTON_ACTION_CREATE_SETTINGS_COMPONENTS
} button_action_type;

typedef enum {
    FALSE,
    TRUE
} boolean;

typedef struct {
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;
} rgba;

typedef struct {
    unsigned int r;
    unsigned int g;
    unsigned int b;
} rgb;

typedef struct {
    rgba background_color;
    rgba color;
    char font_family[64];
    int font_size;
    horizontal_align font_horizontal_align;
    vertical_align font_vertical_align;
    int top;
    int left;
    int width;
    int height;
    int border_radius_top_left;
    int border_radius_top_right;
    int border_radius_bottom_left;
    int border_radius_bottom_right;
} style;

typedef struct {
    int id;
    component_type type;
    char content[64];
    style stylesheet;
    boolean is_hoverable;
    boolean is_hovered;
    style hover_stylesheet;
    int transition_duration;
    float __transition;
} component;

typedef struct {
    int id; /* Equal to his component ID */
    button_action_type action_type;
} button_component;

typedef struct {
    int id; /* Equal to his component ID */
    component components[16];
    int components_size;
} container_component;


int __min(int a, int b);
int __max(int a, int b);

boolean idboxComponent(component component, int x, int y);
void drawComponents(component components[], int components_size);
style styleTransition(component component);
void drawComponent(component component);
component initComponent(int id, char content[], style stylesheet, boolean is_hoverable, style hover_stylesheet, int transition_duration);
void createFrame(component components[], int *components_size, char content[], style stylesheet, boolean is_hoverable, style hover_stylesheet, int transition_duration);
void createButton(component components[], int *components_size, button_component buttons[], int *buttons_size, char content[], style stylesheet, boolean is_hoverable, style hover_stylesheet, int transition_duration, button_action_type action_type);
void createContainer(component components[], int *components_size, container_component contain_components[], int *contain_components_size, char content[], style stylesheet, boolean is_hoverable, style hover_stylesheet, int transition_duration);

#endif