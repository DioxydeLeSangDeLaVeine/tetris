#ifndef H_STYLESHEET
#define H_STYLESHEET

#include "../../modules/ui/ui.h"

typedef enum {
    MENU_COMPONENTS,
    SETTINGS_KEYBOARD_COMPONENTS,
    SETTINGS_VIDEO_COMPONENTS,
    SETTINGS_GRAPHICS_COMPONENTS,
    SETTINGS_AUDIO_COMPONENTS
} page_components;

rgba ROOT_PRIMARY_COLOR();
rgba ROOT_BUTTON_COLOR();
rgba ROOT_SECONDARY_COLOR();
rgba ROOT_BLACK_COLOR();
rgba ROOT_WHITE_COLOR();

style STYLESHEET_BODY(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_SIDEBAR();
style STYLESHEET_CONTAINER(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_SIDEBAR_BUTTONS();
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS();
style STYLESHEET_SIDEBAR_BUTTONS_TOP();
style STYLESHEET_SIDEBAR_BUTTONS_MIDDLE();
style STYLESHEET_SIDEBAR_BUTTONS_BOTTOM();
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_TOP();
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE();
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM();

void createComponents(page_components page, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size);
void createComponentsWithSidebar(page_components page, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size);
void createMenuComponents(component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size);
void createSettingsComponents(page_components page, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size);
void createSettingsKeyboardComponents(component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size);
void createSettingsVideoComponents(component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size);
void createSettingsGraphicsComponents(component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size);
void createSettingsAudioComponents(component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size);

#endif