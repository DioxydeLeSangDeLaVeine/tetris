#ifndef H_UI_MODULE
#define H_UI_MODULE

#define COMPONENTS_MAX_SIZE 64

#define FONT_POPPINS_BLACK "./src/font/Poppins-Black.ttf"
#define FONT_POPPINS_BLACK_ITALIC "./src/font/Poppins-BlackItalic.ttf"
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
    COMPONENT_TEXT
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
    JUSTIFY_START,
    JUSTIFY_END
} justify;

typedef enum {
    DIRECTION_ROW,
    DIRECTION_COLUMN
} direction;

typedef enum {
    BUTTON_ACTION_UNDEFINED,
    BUTTON_ACTION_NONE,
    BUTTON_ACTION_QUIT,
    BUTTON_ACTION_CREATE_MENU_COMPONENTS,
    BUTTON_ACTION_CREATE_SETTINGS_KEYBOARD_COMPONENTS,
    BUTTON_ACTION_CREATE_SETTINGS_VIDEO_COMPONENTS,
    BUTTON_ACTION_CREATE_SETTINGS_GRAPHICS_COMPONENTS,
    BUTTON_ACTION_CREATE_SETTINGS_AUDIO_COMPONENTS
} button_action_type;

typedef enum {
    UNIT_PX,
    UNIT_PERCENTAGE
} unit;

typedef enum {
    FALSE,
    TRUE
} boolean;

typedef struct {
    uint32_t r;
    uint32_t g;
    uint32_t b;
    uint32_t a;
} rgba;

typedef struct {
    rgba background_color;
    rgba color;
    char font_family[64];
    int32_t font_size;
    horizontal_align font_horizontal_align;
    vertical_align font_vertical_align;
    justify component_justify;
    int32_t padding;
    int32_t gap;
    direction childs_direction;
    unit unit_top;
    int32_t top;
    unit unit_left;
    int32_t left;
    unit unit_width;
    int32_t width;
    unit unit_height;
    int32_t height;
    int32_t border_radius_top_left;
    int32_t border_radius_top_right;
    int32_t border_radius_bottom_left;
    int32_t border_radius_bottom_right;
} style;

typedef struct {
    uint32_t id;
    uint32_t parent_id;
    component_type type;
    style stylesheet;
    boolean is_hoverable;
    boolean ignore_hover;
    boolean is_hovered;
    style hover_stylesheet;
    uint32_t transition_duration;
    float __transition;
} component;

typedef struct {
    unsigned short id; /* Equal to his component ID */
    button_action_type action_type;
} button_component;

typedef struct {
    unsigned short id; /* Equal to his component ID */
    char content[64];
} text_component;

typedef struct {
    int32_t top_offset;
    int32_t left_offset;
    int32_t bottom_offset;
    int32_t right_offset;
} __component_offset;

typedef struct {
    int32_t height;
    int32_t width;
} __ref;

int32_t __min(int32_t a, int32_t b);
int32_t __max(int32_t a, int32_t b);


button_component componentToButtonComponent(component component, button_component buttons[], int buttons_size);
text_component componentToTextComponent(component component, text_component texts[], int texts_size);
style styleTransition(component component);
void transformUnit(int32_t *value, unit *value_unit, int32_t reference);
style transformUnits(style stylesheet, style parentStylesheet);
style styleReal(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t components_size, component component);
boolean idboxComponent(style stylesheet, int32_t x, int32_t y);
void drawComponents(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t components_size, text_component texts[], uint32_t texts_size);
void drawComponent(component component, style stylesheet, text_component texts[], uint32_t texts_size);
component initComponent(uint32_t id, component_type type, uint32_t parent_id, style stylesheet, boolean is_hoverable, boolean ignore_hover, style hover_stylesheet, uint32_t transition_duration);
void createFrame(component components[], uint32_t *components_size, uint32_t parent_id, style stylesheet, boolean is_hoverable, boolean ignore_hover, style hover_stylesheet, uint32_t transition_duration);
void createButton(component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, uint32_t parent_id, style stylesheet, boolean is_hoverable, boolean ignore_hover, style hover_stylesheet, uint32_t transition_duration, button_action_type action_type);
void createText(component components[], uint32_t *components_size, text_component texts[], uint32_t *texts_size, uint32_t parent_id, style stylesheet, boolean is_hoverable, boolean ignore_hover, style hover_stylesheet, uint32_t transition_duration, char content[]);

#endif