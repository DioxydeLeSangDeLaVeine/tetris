#ifndef H_STYLESHEET
#define H_STYLESHEET

#include "../../modules/ui/ui.h"

typedef enum {
    STYLESHEET_BODY,
    STYLESHEET_SIDEBAR,
    STYLESHEET_SIDEBAR_BUTTONS,
    STYLESHEET_SIDEBAR_QUIT_BUTTON
} stylesheet_type;

style getStylesheet(stylesheet_type type, boolean is_hovered);
void createMenuComponents(int height, int width, component components[], int *components_size, button_component buttons[], int *buttons_size);

#endif