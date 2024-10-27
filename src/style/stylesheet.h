#ifndef H_STYLESHEET
#define H_STYLESHEET

#include "../../modules/ui/ui.h"

typedef enum {
    MENU_COMPONENTS,
    SETTINGS_COMPONENTS
} page_components;

rgba ROOT_PRIMARY_COLOR();
rgba ROOT_BUTTON_COLOR();
rgba ROOT_SECONDARY_COLOR();
rgba ROOT_BLACK_COLOR();
rgba ROOT_WHITE_COLOR();
style STYLESHEET_BODY(int top, int left, int height, int width);
style STYLESHEET_SIDEBAR(int top, int left, int height, int width);
style STYLESHEET_CONTAINER(int top, int left, int height, int width);
style STYLESHEET_SIDEBAR_BUTTONS(int top, int left, int height, int width);
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS(int top, int left, int height, int width);
void createMenuComponents(int top, int left, int height, int width, component components[], int *components_size, button_component buttons[], int *buttons_size);
void createSettingsComponents(int top, int left, int height, int width, component components[], int *components_size, button_component buttons[], int *buttons_size);

#endif