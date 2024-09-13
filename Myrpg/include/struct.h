/*
** EPITECH PROJECT, 2024
** bs_paint
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include "SFML/Graphics/Types.h"
    #include "SFML/System/Vector2.h"
    #include "SFML/Window/Keyboard.h"
    #include "SFML/Window/Mouse.h"
    #include "my.h"
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/Graphics.h>
    #include <math.h>
    #include <stdbool.h>

typedef struct clock_s {
    sfClock *window;
    double window_sec;
} wclock_t;

typedef struct rpg_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    bool is_fullscreen;
    sfEvent event;
    sfClock *clock;
    float width;
    float height;
    sfTime time;
    float seconds;
} game_t;

typedef struct player_s {
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f pos;
    sfVector2f init_pos;
    sfIntRect rect;
    sfClock* clock;
    double clock_sec;
    sfClock* anim_clock;
    double anim_clock_sec;
    float speed;
    sfTexture *weapon_t;
    sfSprite *weapon_s;
    int life;
    sfVector2f life_pos;
    sfTexture *life_t;
    sfSprite *life_s;
    sfIntRect life_rect;
    sfText *damage;
    sfFont *font;
    sfClock* damage_clock;
    bool in_racoon;
    bool in_frog;
    sfClock *attack_clock;
    int enemy_kill;
    int xp;
    int attack;
    int max_life;
} player_t;

typedef struct old_man_s {
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock* clock;
    double clock_sec;
    sfClock* anim_clock;
    double anim_clock_sec;
    int is_dialog;
    int is_moving;
    int player_dialog;
} old_man_t;

typedef struct dialog_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfText *text;
    sfFont *font;
    int is_dialog;
    int player_dialog;
} dialog_t;

typedef struct quest_follow_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfText *text;
    sfFont *font;
    int is_active;
    int player_quest;
    int is_finish;
} quest_follow_t;

typedef struct camera_s {
    sfView *view;
    sfVector2f pos;
    sfVector2f center;
    sfVector2f size;
} camera_t;

typedef struct map_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    sfSprite *layer;
    sfTexture *layer_t;
    sfVector2f layer_pos;
    sfVector2f layer_size;
} map_t;

typedef struct map_col_s {
    sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
} map_col_t;

typedef struct death_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int draw;
    sfClock* anim_clock;
    double anim_clock_sec;
} death_t;

typedef struct racoon_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *sprite_attack;
    sfTexture *texture_attack;
    sfVector2f pos;
    sfIntRect rect;
    sfClock* anim_clock;
    int offset;
    double anim_clock_sec;
    sfFloatRect hitbox;
    int life;
    bool is_attacking;
    bool is_alive;
} racoon_t;

typedef struct frog_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *sprite_attack;
    sfTexture *texture_attack;
    sfSprite *sprite_charge;
    sfTexture *texture_charge;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *anim_clock;
    int offset;
    double anim_clock_sec;
    sfFloatRect hitbox;
    int life;
    bool is_attacking;
    bool is_charging;
    bool is_alive;
} frog_t;

typedef struct enemy_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfFloatRect hitbox;
    sfClock *anim_clock;
    double anim_clock_sec;
    int life;
    bool is_alive;
    bool is_attacking;
    bool hit;
} enemy_t;

typedef enum direction_s {
    UP,
    DOWN,
    LEFT,
    RIGHT,
} direction_t;

typedef struct inventory_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    sfSprite *weapon;
    sfTexture *weapont;
    sfVector2f weapon_pos;
    sfSprite *armor;
    sfTexture *armor_t;
    sfVector2f armor_pos;
} inventory_t;

/**
* @brief Structure that contains the states of the player
* attacking : 0 = not attacking, 1 = attacking, use it if the player can't move
during an animation, or something else.
*/
typedef struct states_s {
    bool hit;
    bool idle;
    bool attacking;
    bool freezed;
    direction_t direction;
} states_t;

typedef struct mini_map_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *player;
    sfTexture *player_t;
    sfSprite *quest;
    sfTexture *quest_t;
    sfVector2f pos;
    bool is_active;
} mini_map_t;

typedef struct pause_s {
    bool is_option;
    bool is_paused;
    sfSprite *background;
    sfTexture *background_t;
    sfVector2f background_pos;
    sfSprite *character;
    sfTexture *character_t;
    sfVector2f character_pos;
    sfSprite *save;
    sfTexture *save_t;
    sfVector2f save_pos;
    sfSprite *load;
    sfTexture *load_t;
    sfVector2f load_pos;
    sfSprite *settings;
    sfTexture *settings_t;
    sfVector2f settings_pos;
    sfSprite *chest;
    sfTexture *chest_t;
    sfVector2f chest_pos;
    sfSprite *weapon;
    sfTexture *weapon_t;
    sfVector2f weapon_pos;
    sfSprite *armor;
    sfTexture *armor_t;
    sfVector2f armor_pos;
    sfFont *font;
    sfText *text_level;
    sfVector2f text_level_pos;
    sfText *text_attack;
    sfVector2f text_attack_pos;
    sfSprite *augment;
    sfTexture *augment_t;
    sfVector2f augment_pos;
} pause_t;

typedef struct tuto_s {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f sprite_pos;
    bool is_active;
} tuto_t;

typedef struct all_s {
    wclock_t *clock;
    game_t *game;
    player_t *player;
    states_t *states;
    old_man_t *old;
    dialog_t *dialog;
    camera_t *camera;
    enemy_t **enemy;
    racoon_t *racoon;
    frog_t *frog;
    death_t *death;
    quest_follow_t *quest_follow;
    mini_map_t *mini_map;
    map_t *map;
    map_col_t *map_col;
    inventory_t *inventory;
    pause_t *pause;
    tuto_t *tuto;
    int nb_enemy;
} all_t;

#endif //STRUCT_H
