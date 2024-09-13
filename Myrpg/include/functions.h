/*
** EPITECH PROJECT, 2023
** functions.h
** File description:
** functions header file
*/

#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

    #include <stdio.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include "my.h"
    #include "init_menu.h"
    #include "struct.h"
    #include "macros.h"

    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/Graphics.h>
    #include "SFML/Window/Event.h"

    #define BLD     "\x1B[1m"
    #define DRK     "\x1B[2m"
    #define ITL     "\x1B[3m"
    #define UDL     "\x1B[4m"

    #define GRN     "\x1B[32m"
    #define CYN     "\x1B[36m"
    #define BLU     "\x1B[34m"
    #define MAG     "\x1B[35m"
    #define YEL     "\x1B[33m"
    #define RED     "\x1B[31m"
    #define WHT     "\x1B[37m"
    #define RESET   "\x1B[0m"

    #define SUCCESS 0
    #define ERROR 84
/* ./src/ */

// init.c
game_t *init_window(int hei, int len);
player_t *init_player(void);
old_man_t *init_old(void);
dialog_t *init_dialog(void);
camera_t *init_camera(all_t *all);

// life.c
void check_colision_enemy(all_t *all);
void draw_life(all_t *all);
void damage(all_t *all, sfVector2f pos, int type);
void draw_damage(all_t *all);

// enemy.c
void move_enemy(all_t *all);
void draw_enemy(all_t *all);
void attack_enemy(all_t *all);

// init_enemy.c
enemy_t *init_enemy(int num);

// init_quest.c
quest_follow_t *init_quest_follow(void);

// init_map.c
map_t *init_map(void);
map_col_t *init_map_collision(void);

// pause.c
pause_t *init_pause_menu(void);
void display_pause_menu(all_t *all);
void blur(all_t *all, sfShader *shader, sfRenderStates states);

// inventory.c
inventory_t *init_inventory(all_t *all);
void draw_inventory(all_t *all);

// oldman.c
int check_dialog(all_t *all);
int display_quest_follow(all_t *all);
void check_finish_dialog(all_t *all);

// game.c
int rpg(menu_t *menu, int value);
void switch_mode(all_t *all, sfEvent event);

// tuto.c
tuto_t *init_tuto(void);
void display_tuto(all_t *all);

// clock.c
wclock_t *init_clock(void);
void set_clock_var(wclock_t *clock);

// player.c
int move_player(all_t *all);
int is_moveable(sfVector2f pos_origin, sfImage *image, int direction);
void verif_death(all_t *all);

// attack.c
int attack_player(all_t *all);
void is_attacking(all_t *all);
void augment_attack(all_t *all);

// weapon.c
void define_weapon_direc(all_t *all);
void draw_weapon(all_t *all);

// save.c
int save_game(all_t *all);
int load_game(all_t *all);

// dialog.c
int display_dialog(all_t *all);

// event.c
int input_handling(sfEvent event, game_t *game, all_t *all, menu_t *menu);

// update_view.c
void update_view(all_t *all);
void update_pause(all_t *all);
void update_tuto(all_t *all);

// utils.c
void free_mem(all_t *all);
void help_message(void);

// racoon.c
racoon_t *init_racoon(void);
void attack_racoon(all_t *all);
void draw_racoon(all_t *all);
void move_racoon(all_t *all);
void check_colision_racoon(all_t *all);

// frog.c
frog_t *init_frog(void);
void draw_frog(all_t *all);
void move_frog(all_t *all);
void attack_frog(all_t *all);
void check_colision_frog(all_t *all);

// dead_anime.c
death_t *init_death(void);
void death_anim(all_t *all);

// map.c
void draw_mini_map(all_t *all);
mini_map_t *init_mini_map(void);

#endif
