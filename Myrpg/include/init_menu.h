/*
** EPITECH PROJECT, 2024
** EPITECH | WORKSHOP | CSFML
** File description:
** mon_rpg.h
*/


#ifndef MENU_CSFML_H
    #define MENU_CSFML_H

//include
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <time.h>
    #include <stdbool.h>
    #include "struct.h"

// Number of elements
    #define NB_PARALLAX 4
    #define NB_PARTICLES 19
    #define NB_BUTTONS 4

// Structures

typedef struct buttons_bg_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} buttons_bg_t;

typedef struct options_bg_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} options_bg_t;

typedef struct person_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} person_t;

typedef struct button_s {
    sfSprite *sprite[NB_BUTTONS];
    sfTexture *texture[NB_BUTTONS];
    sfFloatRect bounds[NB_BUTTONS];
    sfVector2f pos;
    sfVector2f scale;
} button_t;

typedef struct bear_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} bear_t;

typedef struct gameboy_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    button_t *button;
} gameboy_t;

typedef struct parallax_s {
    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfSprite *sprites[NB_PARALLAX];
    sfTexture *textures[NB_PARALLAX];
    gameboy_t *gameboy;
} parallax_t;

typedef struct particle_s {
    sfSprite *sprites[NB_PARTICLES];
    sfTexture *textures[NB_PARTICLES];
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f speed;
} particle_t;

typedef struct buttonplay_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} play_game_btn_t;

typedef struct volume_s {
    sfSprite *bar_sprite;
    sfTexture *bar_texture;
    sfVector2f bar_pos;
    sfVector2f bar_scale;
    sfSprite *vol_up_s;
    sfTexture *vol_up_t;
    sfVector2f vol_up_pos;
    sfVector2f vol_up_scale;
    sfSprite *vol_down_s;
    sfTexture *vol_down_t;
    sfVector2f vol_down_pos;
    sfVector2f vol_down_scale;
    sfMusic *music;
    int volume;
} volume_t;

typedef struct keybinds_s {
    sfSprite *u_arrow_s;
    sfTexture *u_arrow_t;
    sfVector2f up_arrow_pos;
    sfVector2f up_arrow_scale;
    sfSprite *d_arrow_s;
    sfTexture *d_arrow_t;
    sfVector2f down_arrow_pos;
    sfVector2f down_arrow_scale;
    sfSprite *l_arrow_s;
    sfTexture *l_arrow_t;
    sfVector2f left_arrow_pos;
    sfVector2f left_arrow_scale;
    sfSprite *r_arrow_s;
    sfTexture *r_arrow_t;
    sfVector2f right_arrow_pos;
    sfVector2f right_arrow_scale;
    sfKeyCode key_up;
    sfKeyCode key_down;
    sfKeyCode key_left;
    sfKeyCode key_right;
    bool is_up_binded;
    bool is_down_binded;
    bool is_left_binded;
    bool is_right_binded;
    bool waiting_for_keybind_up;
    bool waiting_for_keybind_down;
    bool waiting_for_keybind_left;
    bool waiting_for_keybind_right;
} keybinds_t;

typedef struct options_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    volume_t *volume;
    keybinds_t *keybinds;
} options_t;

typedef struct start_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} start_t;

typedef struct close_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} close_t;

typedef struct exit_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} exit_t;

typedef struct load_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *lockedTexture;
    sfVector2f pos;
    sfVector2f scale;
    bool isLocked;
} load_t;

typedef enum state_s {
    GAMEBOY_MENU,
    MENU,
    OPTIONS,
    INGAME
} state_t;

typedef struct menu_t {
    load_t *load;
    options_t *option;
    start_t *start;
    close_t *close;
    exit_t *exit;
    buttons_bg_t *buttons_bg;
    options_bg_t *options_bg;
    play_game_btn_t *buttonplay;
    parallax_t *parallax;
    gameboy_t *gameboy;
    particle_t *particles;
    button_t *button;
    bear_t *bear;
    state_t state;
    sfEvent event;
} menu_t;

//Function Macro
    #define START_PNG "assets/buttons/start.png"
    #define START_CLICK_PNG "assets/buttons/clicking/start.png"
    #define CLOSE_PNG "assets/buttons/close.png"
    #define CLOSE_CLICK_PNG "assets/buttons/clicking/close.png"
    #define LOAD_PNG "assets/buttons/load.png"
    #define LOAD_CLICK_PNG "assets/buttons/clicking/load.png"
    #define LOAD_LOCK_PNG "assets/buttons/loadlock.png"
    #define BUTTONS_BG_PNG "assets/buttons/buttons_bg.png"
    #define OPTIONS_BG_PNG "assets/buttons/options_bg.png"
    #define OPTIONS_PNG "assets/buttons/options.png"
    #define OPTIONS_CLICK_PNG "assets/buttons/clicking/options.png"
    #define EXIT_CLICK_PNG "assets/buttons/clicking/exit.png"
    #define VOLUME_PNG "assets/buttons/sound_logo.png"
    #define VOLUME_UP_PNG "assets/buttons/volume_up.png"
    #define VOLUME_DOWN_PNG "assets/buttons/volume_down.png"
    #define VOL_UP_CLICK_PNG "assets/buttons/clicking/volume_up.png"
    #define VOL_DOWN_CLICK_PNG "assets/buttons/clicking/volume_down.png"
    #define UP_ARROW "assets/buttons/up_arrow.png"
    #define DOWN_ARROW "assets/buttons/down_arrow.png"
    #define LEFT_ARROW "assets/buttons/left_arrow.png"
    #define RIGHT_ARROW "assets/buttons/right_arrow.png"
    #define UP_ARROW_CLICK "assets/buttons/clicking/up_arrow.png"
    #define DOWN_ARROW_CLICK "assets/buttons/clicking/down_arrow.png"
    #define LEFT_ARROW_CLICK "assets/buttons/clicking/left_arrow.png"
    #define RIGHT_ARROW_CLICK "assets/buttons/clicking/right_arrow.png"
    #define CLICK menu->event.type == sfEvtMouseButtonPressed
    #define LEFT_CLICK menu->event.mouseButton.button == sfMouseLeft

// Function Button
void init_button(button_t *button);
int button_is_clicked(sfRenderWindow *window, button_t *button);
void check_play_btn_click(sfRenderWindow *window, play_game_btn_t *button,
    menu_t *menu);
void init_buttons_bg(buttons_bg_t *menubutton);
void draw_buttons_bg(sfRenderWindow *window, buttons_bg_t *buttons_bg);
void init_close_cross(close_t *close);
void init_start_btn(start_t *start);
void init_exit_btn(exit_t *exit);
void draw_start_btn(sfRenderWindow *window, start_t *start);
void draw_exit_btn(sfRenderWindow *window, exit_t *exit);
void check_exit_click(sfRenderWindow *window, exit_t *exit, menu_t *menu);
void check_close_click(sfRenderWindow *window, close_t *close, menu_t *menu);
void check_start_click(sfRenderWindow *window, start_t *start, menu_t *menu);
void draw_close_cross(sfRenderWindow *window, close_t *close);
void draw_load_btn(sfRenderWindow *window, load_t *load);
void init_load_btn(load_t *load);
void check_load_click(sfRenderWindow *window, load_t *load, menu_t *menu);

// Options
void init_options_bg(options_bg_t *options_bg);
void draw_options_bg(sfRenderWindow *window, options_bg_t *options_bg);
void init_option_btn(options_t *option);
void draw_option_btn(sfRenderWindow *window, options_t *option);
void check_option_btn_click(sfRenderWindow *window, options_t *option,
    menu_t *menu);
void init_volume_bar_btn(volume_t *volume);
void draw_volume_bar_btn(sfRenderWindow *window, volume_t *volume);
void init_volume_up_btn(volume_t *volume);
void draw_volume_up_btn(sfRenderWindow *window, volume_t *volume);
void check_volume_up_click(sfRenderWindow *window, volume_t *volume);
void init_volume_down_btn(volume_t *volume);
void draw_volume_down_btn(sfRenderWindow *window, volume_t *volume);
void check_volume_down_click(sfRenderWindow *window, volume_t *volume);
void init_arrow_keybinds(keybinds_t *keybinds);
void draw_arrow_keybinds(sfRenderWindow *window, keybinds_t *keybinds);
void check_up_arrow_keybinds_click(sfRenderWindow *window,
    keybinds_t *keybinds);
void check_down_arrow_keybinds_click(sfRenderWindow *window,
    keybinds_t *keybinds);
void check_left_arrow_keybinds_click(sfRenderWindow *window,
    keybinds_t *keybinds);
void check_right_arrow_keybinds_click(sfRenderWindow *window,
    keybinds_t *keybinds);



// Function parralax
void draw_parallax(sfRenderWindow *window, parallax_t *parallax);
void init_parallax(parallax_t *parallax);
void move_parallax(parallax_t *parallax);

// Function particle
void init_particle(particle_t *particle);
void draw_particle(sfRenderWindow *window, particle_t *particle);
void move_particle(particle_t *particle);
void create_particle(particle_t *particle, int i);
void delete_particle(particle_t *particle);

// Function prototypes
int init_resources(menu_t *menu, all_t *all);
//void handle_mouse_events(HANDLE);

// Function Gameboy
void draw_gameboy(sfRenderWindow *window, gameboy_t *gameboy);
void init_gameboy(gameboy_t *gameboy);

// Function sfMusic
sfMusic *play_sound(const char *filepath);

// Function prototypes
void handle_events(sfRenderWindow *window, menu_t *menu, sfMusic **music,
    all_t *all);
void draw_gb_and_menu(menu_t *menu, all_t *all, int *current_frame,
    int *current_frame_bear);
int game_loop(menu_t *menu, all_t *all);

// Bear
void draw_bear(sfRenderWindow *window, bear_t *bear);
void destroy_bear(bear_t *bear);
void init_bear(bear_t *bear);
int move_bear(bear_t *bear);
void animate_bear(bear_t *bear, int *current_frame, int *animation_counter);

// Button play
void draw_play_game_btn(sfRenderWindow *window, play_game_btn_t *button);
void init_play_btn(play_game_btn_t *button);

// Malloc
void malloc_function(menu_t *menu);

#endif // MENU_CSFML_H
