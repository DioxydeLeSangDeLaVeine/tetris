#ifndef H_STYLESHEET
#define H_STYLESHEET

#include "../../modules/ui/ui.h"
#include "../../modules/util/util.h"

typedef enum {
    MENU_COMPONENTS,
    PLAY_COMPONENTS,
    LOAD_COMPONENTS,
    GAME_COMPONENTS,
    GAME_END_COMPONENTS,
    GAME_POPUP_COMPONENTS,
    SCOREBOARD_COMPONENTS,
    SETTINGS_KEYBOARD_COMPONENTS,
    SETTINGS_VIDEO_COMPONENTS,
    SETTINGS_GRAPHICS_COMPONENTS
} page_components;

rgba ROOT_PRIMARY_COLOR();
rgba ROOT_GREY_COLOR();
rgba ROOT_BUTTON_COLOR();
rgba ROOT_SECONDARY_COLOR();
rgba ROOT_BLACK_COLOR();
rgba ROOT_WHITE_COLOR();

style STYLESHEET_BODY(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_SIDEBAR();
style STYLESHEET_LOGO(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_GAME(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_PODIUM(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_BOARD(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_SCORE();
style STYLESHEET_SCORE_NUM();
style STYLESHEET_CONTAINER(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_MINI_CONTAINER(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_ROW();
style STYLESHEET_SIDEBAR_BUTTONS();
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS();
style STYLESHEET_SIDEBAR_BUTTONS_TOP();
style STYLESHEET_SIDEBAR_BUTTONS_MIDDLE();
style STYLESHEET_SIDEBAR_BUTTONS_BOTTOM();
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_TOP();
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_MIDDLE();
style STYLESHEET_PRIMARY_SIDEBAR_BUTTONS_BOTTOM();
style STYLESHEET_TEXT();
style STYLESHEET_KEY();
style STYLESHEET_HOVERED_KEY();
style STYLESHEET_BUTTONS_TEXT();
style STYLESHEET_MINI_TITLE();
style STYLESHEET_TITLE();
style STYLESHEET_HIDE(int32_t top, int32_t left, int32_t height, int32_t width);
style STYLESHEET_HIDE_TEXT(int32_t top, int32_t left, int32_t height, int32_t width);

void createComponents(page_components page, button_action_type lastPage, load games[64], uint32_t games_size, double scroll, int32_t top, int32_t left, int32_t height, int32_t width, game g, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, key_component keys[], uint32_t *keys_size, image_component images[], uint32_t *images_size, choice_component choices[], uint32_t *choices_size, settings set);
void createComponentsWithSidebar(page_components page, button_action_type lastPage, load games[64], uint32_t games_size, double scroll, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, key_component keys[], uint32_t *keys_size, image_component images[], uint32_t *images_size, choice_component choices[], uint32_t *choices_size, settings set);
void createMenuComponents(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, image_component images[], uint32_t *images_size);
void createPlayComponents(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, image_component images[], uint32_t *images_size);
void createLoadComponents(button_action_type lastPage, load games[64], uint32_t games_size, double scroll, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, image_component images[], uint32_t *images_size);
void createGameComponents(page_components page, int32_t top, int32_t left, int32_t height, int32_t width, game g, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size);
void createGamePopupComponents(int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size);
void createGameEndComponents(int32_t top, int32_t left, int32_t height, int32_t width, game g, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size);
void createScoreboardComponents(button_action_type lastPage, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, image_component images[], uint32_t *images_size);
void createSettingsComponents(page_components page, button_action_type lastPage, int32_t top, int32_t left, int32_t height, int32_t width, component components[], uint32_t *components_size, button_component buttons[], uint32_t *buttons_size, text_component texts[], uint32_t *texts_size, key_component keys[], uint32_t *keys_size, choice_component choices[], uint32_t *choices_size, settings set);
void createSettingsKeyboardComponents(component components[], uint32_t *components_size, text_component texts[], uint32_t *texts_size, key_component keys[], uint32_t *keys_size, settings set);
void createSettingsVideoComponents(component components[], uint32_t *components_size, text_component texts[], uint32_t *texts_size);
void createSettingsGraphicsComponents(component components[], uint32_t *components_size, text_component texts[], uint32_t *texts_size, choice_component choices[], uint32_t *choices_size, settings set);

#endif