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
style STYLESHEET_BODY(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_SIDEBAR(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_CONTAINER(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_SIDEBAR_BUTTONS(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_SIDEBAR_BUTTONS_TOP(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_SIDEBAR_BUTTONS_MIDDLE(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_SIDEBAR_BUTTONS_BOTTOM(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_TOP(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM(int32_t top, int32_t left, int32_t height, int32_t width);
void createMenuComponents(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size);
void createSettingsComponents(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size);

#endif