#ifndef H_UTIL_MODULE
#define H_UTIL_MODULE

typedef enum {
    FALSE,
    TRUE
} boolean;

typedef struct {
    MLV_Keyboard_button keyboard_move_left;
    MLV_Keyboard_button keyboard_move_right;
    MLV_Keyboard_button keyboard_turn_left;
    MLV_Keyboard_button keyboard_turn_right;
    MLV_Keyboard_button keyboard_confirm;
    MLV_Keyboard_button keyboard_pause;
    uint32_t video_fps;
    boolean video_animations;
    boolean graphics_border_radius;
} settings;

typedef struct {
    char unsigned day;
    char unsigned month;
    uint32_t year;
} date;

typedef struct {
    uint32_t score;
    date when;
} score;

typedef enum {
    GAMEMODE_SURVIVAL,
    GAMEMODE_MARATHON,
    GAMEMODE_ULTRA
} gamemode;

int32_t __min(int32_t a, int32_t b);
int32_t __max(int32_t a, int32_t b);
void getMonth(char unsigned month, char result[32]);
date getDate();

void getKeyFromMLV(MLV_Keyboard_button sym, char response[]);
MLV_Keyboard_button getMLVFromKey(char key[]);

settings defaultSettings();
void writeSettings(settings set);
settings readSettings();
void readScoreboard(score tab[10]);
void writeScoreboard(score s);

#endif