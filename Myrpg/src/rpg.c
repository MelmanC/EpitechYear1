/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** game.c
*/

#include "SFML/Window/Keyboard.h"
#include "SFML/Window/Mouse.h"
#include "functions.h"
#include <stdio.h>

void malloc_function(menu_t *menu)
{
    menu->parallax = malloc(sizeof(parallax_t));
    menu->gameboy = malloc(sizeof(gameboy_t));
    menu->particles = malloc(sizeof(particle_t));
    menu->button = malloc(sizeof(button_t));
    menu->buttonplay = malloc(sizeof(play_game_btn_t));
    menu->bear = malloc(sizeof(bear_t));
    menu->buttons_bg = malloc(sizeof(buttons_bg_t));
    menu->options_bg = malloc(sizeof(options_bg_t));
    menu->close = malloc(sizeof(close_t));
    menu->option = malloc(sizeof(options_t));
    menu->exit = malloc(sizeof(exit_t));
    menu->start = malloc(sizeof(start_t));
    menu->load = malloc(sizeof(load_t));
    menu->option->volume = malloc(sizeof(volume_t));
    menu->option->keybinds = malloc(sizeof(keybinds_t));
}

static
void fill_struct(all_t *all)
{
    STATES->direction = DOWN;
    STATES->attacking = false;
    STATES->freezed = false;
    STATES->hit = false;
    OLDMAN->is_dialog = 0;
    OLDMAN->is_moving = 0;
    OLDMAN->player_dialog = 0;
    OLDMAN->is_dialog = 0;
}

static
void init_struct_next(all_t *all)
{
    CLOCK = init_clock();
    GAME = init_window(1920, 1080);
    PLAYER = init_player();
    STATES = malloc(sizeof(states_t));
    OLDMAN = init_old();
    DIALOG = init_dialog();
    CAMERA = init_camera(all);
    MAP = init_map();
    MAPCOL = init_map_collision();
    QUEST_FOLLOW = init_quest_follow();
    INVENTORY = init_inventory(all);
    RACOON = init_racoon();
    FROG = init_frog();
    DEATH = init_death();
    PAUSE = init_pause_menu();
    M_MAP = init_mini_map();
    TUTO = init_tuto();
}

static
all_t *init_struct(void)
{
    all_t *all = malloc(sizeof(all_t));

    init_struct_next(all);
    all->nb_enemy = 5;
    ENEMY = malloc(sizeof(enemy_t *) * all->nb_enemy);
    for (int i = 0; i < all->nb_enemy; i++)
        ENEMY[i] = init_enemy(i);
    if (CLOCK == NULL || GAME == NULL || PLAYER == NULL || STATES == NULL
        || OLDMAN == NULL || DIALOG == NULL || CAMERA == NULL || MAP == NULL
        || MAPCOL == NULL || ENEMY == NULL || QUEST_FOLLOW == NULL
        || INVENTORY == NULL || RACOON == NULL || FROG == NULL
        || DEATH == NULL || PAUSE == NULL || M_MAP == NULL || TUTO == NULL)
            return NULL;
    fill_struct(all);
    return all;
}

int game_loop(menu_t *menu, all_t *all)
{
    int current_frame = 0;
    int current_frame_bear = 0;
    sfMusic *music = NULL;

    while (sfRenderWindow_isOpen(GAME->window)) {
        handle_events(GAME->window, menu, &music, all);
        draw_gb_and_menu(menu, all, &current_frame, &current_frame_bear);
    }
    return SUCCESS;
}

static
void draw_next(all_t *all)
{
    sfRenderWindow_drawSprite(GAME->window, MAP->sprite, NULL);
    sfRenderWindow_drawSprite(GAME->window, OLDMAN->sprite, NULL);
    draw_weapon(all);
    sfRenderWindow_drawSprite(GAME->window, PLAYER->sprite,
            NULL);
    draw_racoon(all);
    draw_frog(all);
    draw_enemy(all);
}

static
void draw_sprite(all_t *all)
{
    draw_next(all);
    death_anim(all);
    draw_damage(all);
    sfRenderWindow_drawSprite(GAME->window, MAP->layer, NULL);
    draw_life(all);
    display_dialog(all);
    draw_inventory(all);
    display_quest_follow(all);
    draw_mini_map(all);
    display_pause_menu(all);
    display_tuto(all);
}

static
void move_ennemy(all_t *all)
{
    move_enemy(all);
    move_frog(all);
    move_racoon(all);
}

static
void rpg_next(all_t *all)
{
    update_pause(all);
    update_tuto(all);
    move_ennemy(all);
    draw_sprite(all);
    verif_death(all);
    check_finish_dialog(all);
}

/**
* This function is used to launch the game
* @return SUCCESS or FAILURE
*/
int rpg(menu_t *menu, int value)
{
    all_t *all = init_struct();

    if (!all)
        return ERROR;
    update_view(all);
    if (value == 1)
        load_game(all);
    while (sfRenderWindow_isOpen(GAME->window)) {
        set_clock_var(CLOCK);
        if (CLOCK->window_sec > 1.0 / FPS) {
            sfRenderWindow_clear(GAME->window, sfWhite);
            is_attacking(all);
            input_handling(GAME->event, GAME, all, menu);
            rpg_next(all);
            sfRenderWindow_display(GAME->window);
            sfClock_restart(CLOCK->window);
        }
    }
    return SUCCESS;
}
