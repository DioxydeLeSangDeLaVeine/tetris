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
} settings;

int32_t __min(int32_t a, int32_t b);
int32_t __max(int32_t a, int32_t b);

void getKeyFromMLV(MLV_Keyboard_button sym, char response[]);
MLV_Keyboard_button getMLVFromKey(char key[]);

#endif