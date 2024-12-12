#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <time.h>
#include <dirent.h>
#include "util.h"


/**
 * Minimum of a and b.
 *
 * @param {int32_t} a
 * @param {int32_t} b
 *
 * @returns {int32_t}
 */
int32_t __min(int32_t a, int32_t b)
{
    return a<=b?a:b;
}


/**
 * Maximum of a and b.
 *
 * @param {int32_t} a
 * @param {int32_t} b
 *
 * @returns {int32_t}
 */
int32_t __max(int32_t a, int32_t b)
{
    return a>=b?a:b;
}

void getMonth(char unsigned month, char result[32])
{
    switch(month%12)
    {
        case 0:
            strcpy(result, "Janvier");
            break;
        case 1:
            strcpy(result, "Février");
            break;
        case 2:
            strcpy(result, "Mars");
            break;
        case 3:
            strcpy(result, "Avril");
            break;
        case 4:
            strcpy(result, "Mai");
            break;
        case 5:
            strcpy(result, "Juin");
            break;
        case 6:
            strcpy(result, "Juillet");
            break;
        case 7:
            strcpy(result, "Août");
            break;
        case 8:
            strcpy(result, "Septembre");
            break;
        case 9:
            strcpy(result, "Octobre");
            break;
        case 10:
            strcpy(result, "Novembre");
            break;
        case 11:
            strcpy(result, "Décembre");
            break;
        default:
            strcpy(result, "???");
            break;
    }
}


date getDate()
{
    date when;
    time_t current_time;
    struct tm *local_time;

    time(&current_time);

    local_time = localtime(&current_time);

    when.day = (char)local_time->tm_mday;
    when.month = (char)(local_time->tm_mon);
    when.year = (int32_t)(local_time->tm_year + 1900);
    return when;
}


/**
 * Returns char[] from a MLV_Keyboard_button.
 *
 * @param {MLV_Keyboard_button} sym
 * @param {char} response[]
 *
 * @returns {void}
 */
void getKeyFromMLV(MLV_Keyboard_button sym, char response[])
{
    switch(sym)
    {
        case MLV_KEYBOARD_a: strcpy(response, "A"); break;
        case MLV_KEYBOARD_b: strcpy(response, "B"); break;
        case MLV_KEYBOARD_c: strcpy(response, "C"); break;
        case MLV_KEYBOARD_d: strcpy(response, "D"); break;
        case MLV_KEYBOARD_e: strcpy(response, "E"); break;
        case MLV_KEYBOARD_f: strcpy(response, "F"); break;
        case MLV_KEYBOARD_g: strcpy(response, "G"); break;
        case MLV_KEYBOARD_h: strcpy(response, "H"); break;
        case MLV_KEYBOARD_i: strcpy(response, "I"); break;
        case MLV_KEYBOARD_j: strcpy(response, "J"); break;
        case MLV_KEYBOARD_k: strcpy(response, "K"); break;
        case MLV_KEYBOARD_l: strcpy(response, "L"); break;
        case MLV_KEYBOARD_m: strcpy(response, "M"); break;
        case MLV_KEYBOARD_n: strcpy(response, "N"); break;
        case MLV_KEYBOARD_o: strcpy(response, "O"); break;
        case MLV_KEYBOARD_p: strcpy(response, "P"); break;
        case MLV_KEYBOARD_q: strcpy(response, "Q"); break;
        case MLV_KEYBOARD_r: strcpy(response, "R"); break;
        case MLV_KEYBOARD_s: strcpy(response, "S"); break;
        case MLV_KEYBOARD_t: strcpy(response, "T"); break;
        case MLV_KEYBOARD_u: strcpy(response, "U"); break;
        case MLV_KEYBOARD_v: strcpy(response, "V"); break;
        case MLV_KEYBOARD_w: strcpy(response, "W"); break;
        case MLV_KEYBOARD_x: strcpy(response, "X"); break;
        case MLV_KEYBOARD_y: strcpy(response, "Y"); break;
        case MLV_KEYBOARD_z: strcpy(response, "Z"); break;
        case MLV_KEYBOARD_0: strcpy(response, "0"); break;
        case MLV_KEYBOARD_1: strcpy(response, "1"); break;
        case MLV_KEYBOARD_2: strcpy(response, "2"); break;
        case MLV_KEYBOARD_3: strcpy(response, "3"); break;
        case MLV_KEYBOARD_4: strcpy(response, "4"); break;
        case MLV_KEYBOARD_5: strcpy(response, "5"); break;
        case MLV_KEYBOARD_6: strcpy(response, "6"); break;
        case MLV_KEYBOARD_7: strcpy(response, "7"); break;
        case MLV_KEYBOARD_8: strcpy(response, "8"); break;
        case MLV_KEYBOARD_9: strcpy(response, "9"); break;
        case MLV_KEYBOARD_LALT: strcpy(response, "LEFT_ALT"); break;
        case MLV_KEYBOARD_RALT: strcpy(response, "RIGHT_ALT"); break;
        case MLV_KEYBOARD_LSHIFT: strcpy(response, "LEFT_SHIFT"); break;
        case MLV_KEYBOARD_RSHIFT: strcpy(response, "RIGHT_SHIFT"); break;
        case MLV_KEYBOARD_LCTRL: strcpy(response, "LEFT_CTRL"); break;
        case MLV_KEYBOARD_RCTRL: strcpy(response, "RIGHT_CTRL"); break;
        case MLV_KEYBOARD_SPACE: strcpy(response, "SPACE"); break;
        case MLV_KEYBOARD_RETURN: strcpy(response, "ENTER"); break;
        case MLV_KEYBOARD_BACKSPACE: strcpy(response, "BACKSPACE"); break;
        case MLV_KEYBOARD_TAB: strcpy(response, "TAB"); break;
        case MLV_KEYBOARD_CAPSLOCK: strcpy(response, "CAPS_LOCK"); break;
        case MLV_KEYBOARD_ESCAPE: strcpy(response, "ESCAPE"); break;
        case MLV_KEYBOARD_UP: strcpy(response, "UP_ARROW"); break;
        case MLV_KEYBOARD_DOWN: strcpy(response, "DOWN_ARROW"); break;
        case MLV_KEYBOARD_LEFT: strcpy(response, "LEFT_ARROW"); break;
        case MLV_KEYBOARD_RIGHT: strcpy(response, "RIGHT_ARROW"); break;
        case MLV_KEYBOARD_EXCLAIM: strcpy(response, "!"); break;
        case MLV_KEYBOARD_COMMA: strcpy(response, "?"); break;
        case MLV_KEYBOARD_SEMICOLON: strcpy(response, ";"); break;
        case MLV_KEYBOARD_COLON: strcpy(response, ":"); break;
        case MLV_KEYBOARD_EQUALS: strcpy(response, "="); break;
        case MLV_KEYBOARD_ASTERISK: strcpy(response, "*"); break;
        case MLV_KEYBOARD_DOLLAR: strcpy(response, "$"); break;
        case MLV_KEYBOARD_KP0: strcpy(response, "NUMPAD_0"); break;
        case MLV_KEYBOARD_KP1: strcpy(response, "NUMPAD_1"); break;
        case MLV_KEYBOARD_KP2: strcpy(response, "NUMPAD_2"); break;
        case MLV_KEYBOARD_KP3: strcpy(response, "NUMPAD_3"); break;
        case MLV_KEYBOARD_KP4: strcpy(response, "NUMPAD_4"); break;
        case MLV_KEYBOARD_KP5: strcpy(response, "NUMPAD_5"); break;
        case MLV_KEYBOARD_KP6: strcpy(response, "NUMPAD_6"); break;
        case MLV_KEYBOARD_KP7: strcpy(response, "NUMPAD_7"); break;
        case MLV_KEYBOARD_KP8: strcpy(response, "NUMPAD_8"); break;
        case MLV_KEYBOARD_KP9: strcpy(response, "NUMPAD_9"); break;
        case MLV_KEYBOARD_KP_DIVIDE: strcpy(response, "NUMPAD_DIVIDE"); break;
        case MLV_KEYBOARD_KP_MULTIPLY: strcpy(response, "NUMPAD_MULTIPLY"); break;
        case MLV_KEYBOARD_KP_MINUS: strcpy(response, "NUMPAD_MINUS"); break;
        case MLV_KEYBOARD_KP_PLUS: strcpy(response, "NUMPAD_PLUS"); break;
        case MLV_KEYBOARD_KP_ENTER: strcpy(response, "NUMPAD_ENTER"); break;
        case MLV_KEYBOARD_KP_PERIOD: strcpy(response, "NUMPAD_PERIOD"); break;
        case MLV_KEYBOARD_F1: strcpy(response, "F1"); break;
        case MLV_KEYBOARD_F2: strcpy(response, "F2"); break;
        case MLV_KEYBOARD_F3: strcpy(response, "F3"); break;
        case MLV_KEYBOARD_F4: strcpy(response, "F4"); break;
        case MLV_KEYBOARD_F5: strcpy(response, "F5"); break;
        case MLV_KEYBOARD_F6: strcpy(response, "F6"); break;
        case MLV_KEYBOARD_F7: strcpy(response, "F7"); break;
        case MLV_KEYBOARD_F8: strcpy(response, "F8"); break;
        case MLV_KEYBOARD_F9: strcpy(response, "F9"); break;
        case MLV_KEYBOARD_F10: strcpy(response, "F10"); break;
        case MLV_KEYBOARD_F11: strcpy(response, "F11"); break;
        case MLV_KEYBOARD_F12: strcpy(response, "F12"); break;
        default: strcpy(response, ""); break;
    }
}


/**
 * Returns MLV_Keyboard_button from a char[].
 *
 * @param {char} key[]
 *
 * @returns {MLV_Keyboard_button}
 */
MLV_Keyboard_button getMLVFromKey(char key[])
{
    if (strcmp(key, "A") == 0) return MLV_KEYBOARD_a;
    else if (strcmp(key, "B") == 0) return MLV_KEYBOARD_b;
    else if (strcmp(key, "C") == 0) return MLV_KEYBOARD_c;
    else if (strcmp(key, "D") == 0) return MLV_KEYBOARD_d;
    else if (strcmp(key, "E") == 0) return MLV_KEYBOARD_e;
    else if (strcmp(key, "F") == 0) return MLV_KEYBOARD_f;
    else if (strcmp(key, "G") == 0) return MLV_KEYBOARD_g;
    else if (strcmp(key, "H") == 0) return MLV_KEYBOARD_h;
    else if (strcmp(key, "I") == 0) return MLV_KEYBOARD_i;
    else if (strcmp(key, "J") == 0) return MLV_KEYBOARD_j;
    else if (strcmp(key, "K") == 0) return MLV_KEYBOARD_k;
    else if (strcmp(key, "L") == 0) return MLV_KEYBOARD_l;
    else if (strcmp(key, "M") == 0) return MLV_KEYBOARD_m;
    else if (strcmp(key, "N") == 0) return MLV_KEYBOARD_n;
    else if (strcmp(key, "O") == 0) return MLV_KEYBOARD_o;
    else if (strcmp(key, "P") == 0) return MLV_KEYBOARD_p;
    else if (strcmp(key, "Q") == 0) return MLV_KEYBOARD_q;
    else if (strcmp(key, "R") == 0) return MLV_KEYBOARD_r;
    else if (strcmp(key, "S") == 0) return MLV_KEYBOARD_s;
    else if (strcmp(key, "T") == 0) return MLV_KEYBOARD_t;
    else if (strcmp(key, "U") == 0) return MLV_KEYBOARD_u;
    else if (strcmp(key, "V") == 0) return MLV_KEYBOARD_v;
    else if (strcmp(key, "W") == 0) return MLV_KEYBOARD_w;
    else if (strcmp(key, "X") == 0) return MLV_KEYBOARD_x;
    else if (strcmp(key, "Y") == 0) return MLV_KEYBOARD_y;
    else if (strcmp(key, "Z") == 0) return MLV_KEYBOARD_z;
    else if (strcmp(key, "0") == 0) return MLV_KEYBOARD_0;
    else if (strcmp(key, "1") == 0) return MLV_KEYBOARD_1;
    else if (strcmp(key, "2") == 0) return MLV_KEYBOARD_2;
    else if (strcmp(key, "3") == 0) return MLV_KEYBOARD_3;
    else if (strcmp(key, "4") == 0) return MLV_KEYBOARD_4;
    else if (strcmp(key, "5") == 0) return MLV_KEYBOARD_5;
    else if (strcmp(key, "6") == 0) return MLV_KEYBOARD_6;
    else if (strcmp(key, "7") == 0) return MLV_KEYBOARD_7;
    else if (strcmp(key, "8") == 0) return MLV_KEYBOARD_8;
    else if (strcmp(key, "9") == 0) return MLV_KEYBOARD_9;
    else if (strcmp(key, "LEFT_ALT") == 0) return MLV_KEYBOARD_LALT;
    else if (strcmp(key, "RIGHT_ALT") == 0) return MLV_KEYBOARD_RALT;
    else if (strcmp(key, "LEFT_SHIFT") == 0) return MLV_KEYBOARD_LSHIFT;
    else if (strcmp(key, "RIGHT_SHIFT") == 0) return MLV_KEYBOARD_RSHIFT;
    else if (strcmp(key, "LEFT_CTRL") == 0) return MLV_KEYBOARD_LCTRL;
    else if (strcmp(key, "RIGHT_CTRL") == 0) return MLV_KEYBOARD_RCTRL;
    else if (strcmp(key, "SPACE") == 0) return MLV_KEYBOARD_SPACE;
    else if (strcmp(key, "ENTER") == 0) return MLV_KEYBOARD_RETURN;
    else if (strcmp(key, "BACKSPACE") == 0) return MLV_KEYBOARD_BACKSPACE;
    else if (strcmp(key, "TAB") == 0) return MLV_KEYBOARD_TAB;
    else if (strcmp(key, "CAPS_LOCK") == 0) return MLV_KEYBOARD_CAPSLOCK;
    else if (strcmp(key, "ESCAPE") == 0) return MLV_KEYBOARD_ESCAPE;
    else if (strcmp(key, "UP_ARROW") == 0) return MLV_KEYBOARD_UP;
    else if (strcmp(key, "DOWN_ARROW") == 0) return MLV_KEYBOARD_DOWN;
    else if (strcmp(key, "LEFT_ARROW") == 0) return MLV_KEYBOARD_LEFT;
    else if (strcmp(key, "RIGHT_ARROW") == 0) return MLV_KEYBOARD_RIGHT;
    else if (strcmp(key, "!") == 0) return MLV_KEYBOARD_EXCLAIM;
    else if (strcmp(key, "?") == 0) return MLV_KEYBOARD_COMMA;
    else if (strcmp(key, ";") == 0) return MLV_KEYBOARD_SEMICOLON;
    else if (strcmp(key, ":") == 0) return MLV_KEYBOARD_COLON;
    else if (strcmp(key, "=") == 0) return MLV_KEYBOARD_EQUALS;
    else if (strcmp(key, "*") == 0) return MLV_KEYBOARD_ASTERISK;
    else if (strcmp(key, "$") == 0) return MLV_KEYBOARD_DOLLAR;
    else if (strcmp(key, "NUMPAD_0") == 0) return MLV_KEYBOARD_KP0;
    else if (strcmp(key, "NUMPAD_1") == 0) return MLV_KEYBOARD_KP1;
    else if (strcmp(key, "NUMPAD_2") == 0) return MLV_KEYBOARD_KP2;
    else if (strcmp(key, "NUMPAD_3") == 0) return MLV_KEYBOARD_KP3;
    else if (strcmp(key, "NUMPAD_4") == 0) return MLV_KEYBOARD_KP4;
    else if (strcmp(key, "NUMPAD_5") == 0) return MLV_KEYBOARD_KP5;
    else if (strcmp(key, "NUMPAD_6") == 0) return MLV_KEYBOARD_KP6;
    else if (strcmp(key, "NUMPAD_7") == 0) return MLV_KEYBOARD_KP7;
    else if (strcmp(key, "NUMPAD_8") == 0) return MLV_KEYBOARD_KP8;
    else if (strcmp(key, "NUMPAD_9") == 0) return MLV_KEYBOARD_KP9;
    else if (strcmp(key, "NUMPAD_DIVIDE") == 0) return MLV_KEYBOARD_KP_DIVIDE;
    else if (strcmp(key, "NUMPAD_MULTIPLY") == 0) return MLV_KEYBOARD_KP_MULTIPLY;
    else if (strcmp(key, "NUMPAD_MINUS") == 0) return MLV_KEYBOARD_KP_MINUS;
    else if (strcmp(key, "NUMPAD_PLUS") == 0) return MLV_KEYBOARD_KP_PLUS;
    else if (strcmp(key, "NUMPAD_ENTER") == 0) return MLV_KEYBOARD_KP_ENTER;
    else if (strcmp(key, "NUMPAD_PERIOD") == 0) return MLV_KEYBOARD_KP_PERIOD;
    else if (strcmp(key, "F1") == 0) return MLV_KEYBOARD_F1;
    else if (strcmp(key, "F2") == 0) return MLV_KEYBOARD_F2;
    else if (strcmp(key, "F3") == 0) return MLV_KEYBOARD_F3;
    else if (strcmp(key, "F4") == 0) return MLV_KEYBOARD_F4;
    else if (strcmp(key, "F5") == 0) return MLV_KEYBOARD_F5;
    else if (strcmp(key, "F6") == 0) return MLV_KEYBOARD_F6;
    else if (strcmp(key, "F7") == 0) return MLV_KEYBOARD_F7;
    else if (strcmp(key, "F8") == 0) return MLV_KEYBOARD_F8;
    else if (strcmp(key, "F9") == 0) return MLV_KEYBOARD_F9;
    else if (strcmp(key, "F10") == 0) return MLV_KEYBOARD_F10;
    else if (strcmp(key, "F11") == 0) return MLV_KEYBOARD_F11;
    else if (strcmp(key, "F12") == 0) return MLV_KEYBOARD_F12;
    else return MLV_KEYBOARD_UNKNOWN;
}

settings defaultSettings()
{
    settings set;
    set.keyboard_move_left = MLV_KEYBOARD_q;
    set.keyboard_move_right = MLV_KEYBOARD_d;
    set.keyboard_turn_left = MLV_KEYBOARD_a;
    set.keyboard_turn_right = MLV_KEYBOARD_e;
    set.keyboard_fast_drop = MLV_KEYBOARD_SPACE;
    set.keyboard_pause = MLV_KEYBOARD_ESCAPE;
    set.keyboard_scroll_up = MLV_KEYBOARD_UP;
    set.keyboard_scroll_down = MLV_KEYBOARD_DOWN;
    set.video_fps = 30;
    set.video_animations = TRUE;
    set.graphics_border_radius = TRUE;
    return set;
}

void writeSettings(settings set)
{
    FILE *file = fopen("./data/settings.txt", "w");
    char response[64];

    if(file == NULL)
    {
        return;
    }

    fprintf(file, "### KEYBOARD ###\n");
    getKeyFromMLV(set.keyboard_move_left, response);
    fprintf(file, "KEY_MOVE_LEFT=%s\n", response);
    getKeyFromMLV(set.keyboard_move_right, response);
    fprintf(file, "KEY_MOVE_RIGHT=%s\n", response);
    getKeyFromMLV(set.keyboard_turn_left, response);
    fprintf(file, "KEY_TURN_LEFT=%s\n", response);
    getKeyFromMLV(set.keyboard_turn_right, response);
    fprintf(file, "KEY_TURN_RIGHT=%s\n", response);
    getKeyFromMLV(set.keyboard_fast_drop, response);
    fprintf(file, "KEY_FAST_DROP=%s\n", response);
    getKeyFromMLV(set.keyboard_pause, response);
    fprintf(file, "KEY_PAUSE=%s\n\n", response);
    getKeyFromMLV(set.keyboard_scroll_up, response);
    fprintf(file, "KEY_SCROLL_UP=%s\n\n", response);
    getKeyFromMLV(set.keyboard_scroll_down, response);
    fprintf(file, "KEY_SCROLL_DOWN=%s\n\n", response);

    fprintf(file, "### VIDEO ###\n");
    fprintf(file, "FPS=%u\n", set.video_fps);
    if(set.video_animations == TRUE) fprintf(file, "ANIMATIONS=TRUE\n\n");
    else fprintf(file, "ANIMATIONS=FALSE\n\n");
    fprintf(file, "### GRAPHICS ###\n");
    if(set.graphics_border_radius == TRUE) fprintf(file, "BORDER_RADIUS=TRUE\n\n");
    else fprintf(file, "BORDER_RADIUS=FALSE\n\n");
    fprintf(file, "### AUDIO ###\n");

    fclose(file);
}

settings readSettings()
{
    FILE *file = fopen("./data/settings.txt", "r");
    MLV_Keyboard_button key;
    settings set;
    char setting_name[65], setting_value[65];
    char line[130];
    int i, j;
    boolean is_value;

    set = defaultSettings();
    
    if(file == NULL)
    {
        writeSettings(set);
        return set;
    }

    while(fgets(line, 130, file) != NULL)
    {
        i = 0;
        j = 0;
        is_value = FALSE;
        strcpy(setting_name, "");
        strcpy(setting_value, "");
        if(line[0] != '\0'&&line[0] != '\n'&&line[0] != ' '&&line[0] != '#')
        {
            while(line[i] != '\0'&&line[i] != '\n')
            {
                if(is_value == FALSE)
                {
                    if(line[i]=='=')
                    {
                        is_value = TRUE;
                        setting_name[i] = '\0';
                    } else {
                        setting_name[i]=line[i];
                    }
                } else {
                    setting_value[j]=line[i];
                    j++;
                }
                i++;
            }
            setting_value[j]='\0';
            if(strcmp(setting_name, "KEY_MOVE_LEFT") == 0)
            {
                key = getMLVFromKey(setting_value);
                if(key != MLV_KEYBOARD_UNKNOWN) {
                    set.keyboard_move_left = key;
                }
            } else if(strcmp(setting_name, "KEY_MOVE_RIGHT") == 0)
            {
                key = getMLVFromKey(setting_value);
                if(key != MLV_KEYBOARD_UNKNOWN) {
                    set.keyboard_move_right = key;
                }
            } else if(strcmp(setting_name, "KEY_TURN_LEFT") == 0)
            {
                key = getMLVFromKey(setting_value);
                if(key != MLV_KEYBOARD_UNKNOWN) {
                    set.keyboard_turn_left = key;
                }
            } else if(strcmp(setting_name, "KEY_TURN_RIGHT") == 0)
            {
                key = getMLVFromKey(setting_value);
                if(key != MLV_KEYBOARD_UNKNOWN) {
                    set.keyboard_turn_right = key;
                }
            } else if(strcmp(setting_name, "KEY_FAST_DROP") == 0)
            {
                key = getMLVFromKey(setting_value);
                if(key != MLV_KEYBOARD_UNKNOWN) {
                    set.keyboard_fast_drop = key;
                }
            } else if(strcmp(setting_name, "KEY_PAUSE") == 0)
            {
                key = getMLVFromKey(setting_value);
                if(key != MLV_KEYBOARD_UNKNOWN) {
                    set.keyboard_pause = key;
                }
            } else if(strcmp(setting_name, "KEY_SCROLL_UP") == 0)
            {
                key = getMLVFromKey(setting_value);
                if(key != MLV_KEYBOARD_UNKNOWN) {
                    set.keyboard_scroll_up = key;
                }
            } else if(strcmp(setting_name, "KEY_SCROLL_DOWN") == 0)
            {
                key = getMLVFromKey(setting_value);
                if(key != MLV_KEYBOARD_UNKNOWN) {
                    set.keyboard_scroll_down = key;
                }
            } else if(strcmp(setting_name, "FPS") == 0)
            {
                if(atoi(setting_value) > 0) {
                    set.video_fps = atoi(setting_value);
                }
            } else if(strcmp(setting_name, "ANIMATIONS") == 0)
            {
                if(strcmp(setting_value, "TRUE") == 0) set.video_animations = TRUE;
                else set.video_animations = FALSE;
            } else if(strcmp(setting_name, "BORDER_RADIUS") == 0)
            {
                if(strcmp(setting_value, "TRUE") == 0) set.graphics_border_radius = TRUE;
                else set.graphics_border_radius = FALSE;
            }
        }
    }
    fclose(file);
    writeSettings(set);
    return set;
}

void readScoreboard(score tab[10])
{
    FILE *file = fopen("./data/scoreboard.save", "rb");
    int byte, i = 0, j = 0;
    uint32_t tmp_score;
    boolean useful, equal;
    
    if(file == NULL)
    {
        return;
    }

    for(i = 0; i<10; i++) {
        tab[i].score = 0;
        tab[i].when.day = 0;
        tab[i].when.month = 0;
        tab[i].when.year = 0;
    }

    byte = fgetc(file);
    i = 0;
    while(byte != EOF)
    {
        tmp_score = byte<<24;
        byte = fgetc(file);
        if(byte == EOF)break;
        tmp_score|=byte<<16;
        byte = fgetc(file);
        if(byte == EOF)break;
        tmp_score|=byte<<8;
        byte = fgetc(file);
        if(byte == EOF)break;
        tmp_score|=byte;

        useful = FALSE;
        equal = FALSE;
        for(j = 0; j<10; j++) {
            if(tab[j].score == tmp_score)
            {
                equal = TRUE;
                break;
            }
        }
        j = ((i-1)<10)?(i-1):9;
        if(equal == FALSE)
        {
            for(j = (i<10)?i:9; j>=0; j--)
            {
                if(tab[j].score > tmp_score) break;
                useful = TRUE;
                if(j+1<10)
                {
                    tab[j+1] = tab[j];
                }
                tab[j].score = 0;
                tab[j].when.day = 0;
                tab[j].when.month = 0;
                tab[j].when.year = 0;
            }
        }
        j++;
        if(useful == TRUE) tab[j].score = tmp_score;
        byte = fgetc(file);
        if(byte == EOF)break;
        if(useful == TRUE) tab[j].when.day = byte;
        byte = fgetc(file);
        if(byte == EOF)break;
        if(useful == TRUE) tab[j].when.month = byte;
        
        byte = fgetc(file);
        if(byte == EOF)break;
        if(useful == TRUE) tab[j].when.year = byte<<24;
        byte = fgetc(file);
        if(byte == EOF)break;
        if(useful == TRUE) tab[j].when.year|=byte<<16;
        byte = fgetc(file);
        if(byte == EOF)break;
        if(useful == TRUE) tab[j].when.year|=byte<<8;
        byte = fgetc(file);
        if(byte == EOF)break;
        if(useful == TRUE) tab[j].when.year|=byte;
        i++;
        byte = fgetc(file);
    }
    fclose(file);
}

void writeScoreboard(score s)
{
    FILE *file;
    score tab[10];
    int32_t i, value;

    readScoreboard(tab);
    file = fopen("./data/scoreboard.save", "wb");

    if(file == NULL)
    {
        return;
    }
    
    value = (s.score>>24)&0xFF;
    fwrite(&value, sizeof(char), 1, file);
    value = (s.score>>16)&0xFF;
    fwrite(&value, sizeof(char), 1, file);
    value = (s.score>>8)&0xFF;
    fwrite(&value, sizeof(char), 1, file);
    value = (s.score)&0xFF;
    fwrite(&value, sizeof(char), 1, file);
    value = s.when.day;
    fwrite(&value, sizeof(char), 1, file);
    value = s.when.month;
    fwrite(&value, sizeof(char), 1, file);
    value = (s.when.year>>24)&0xFF;
    fwrite(&value, sizeof(char), 1, file);
    value = (s.when.year>>16)&0xFF;
    fwrite(&value, sizeof(char), 1, file);
    value = (s.when.year>>8)&0xFF;
    fwrite(&value, sizeof(char), 1, file);
    value = (s.when.year)&0xFF;
    fwrite(&value, sizeof(char), 1, file);
    for(i = 0; i<10; i++)
    {
        value = (tab[i].score>>24)&0xFF;
        fwrite(&value, sizeof(char), 1, file);
        value = (tab[i].score>>16)&0xFF;
        fwrite(&value, sizeof(char), 1, file);
        value = (tab[i].score>>8)&0xFF;
        fwrite(&value, sizeof(char), 1, file);
        value = (tab[i].score)&0xFF;
        fwrite(&value, sizeof(char), 1, file);
        value = tab[i].when.day;
        fwrite(&value, sizeof(char), 1, file);
        value = tab[i].when.month;
        fwrite(&value, sizeof(char), 1, file);
        value = (tab[i].when.year>>24)&0xFF;
        fwrite(&value, sizeof(char), 1, file);
        value = (tab[i].when.year>>16)&0xFF;
        fwrite(&value, sizeof(char), 1, file);
        value = (tab[i].when.year>>8)&0xFF;
        fwrite(&value, sizeof(char), 1, file);
        value = (tab[i].when.year)&0xFF;
        fwrite(&value, sizeof(char), 1, file);
    }
    fclose(file);
}

tetrimino loadTetrimino(char path[320])
{
    FILE *file = fopen(path, "rb");
    tetrimino tetr;
    int byte, j;

    strcpy(tetr.path, path);
    tetr.idbox = 0;
    if(file == NULL) {
        return tetr;
    }
    byte = fgetc(file);
    j = 0;
    while(byte != EOF && j<16)
    {
        tetr.map[j].r = byte;
        byte = fgetc(file);
        if(byte == EOF)break;
        tetr.map[j].g = byte;
        byte = fgetc(file);
        if(byte == EOF)break;
        tetr.map[j].b = byte;
        byte = fgetc(file);
        if(byte == EOF)break;
        tetr.map[j].a = byte;
        j++;
        if(j == 16) tetr.idbox = 4;
        else
        {
            if(j >= 9) tetr.idbox = 3;
            else
            {
                if(j >= 4) tetr.idbox = 2;
                else
                {
                    if(j >= 1) tetr.idbox = 1;
                }
            }
        }
        byte = fgetc(file);
    }
    fclose(file);

    return tetr;
}

uint32_t loadTetriminos(tetrimino tab[64])
{
    DIR *folder = opendir("./data/tetrimino");
    struct dirent *entry;
    int i;

    if(folder == NULL) {
        return 0;
    }
    for(i = 0; i<64; i++)
    {
        tab[i].idbox = 0;
        tab[i].path[0] = '\0';
    }

    i = 0;
    while((entry = readdir(folder)) != NULL && i < 64)
    {
        if(entry->d_type == DT_REG)
        {
            snprintf(tab[i].path, sizeof(tab[i].path), "./data/tetrimino/%s", entry->d_name);
            tab[i] = loadTetrimino(tab[i].path);
            if(tab[i].idbox != 0)
            {
                i++;
            }
        }
    }
    closedir(folder);
    return i;
}