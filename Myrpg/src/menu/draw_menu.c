/*
** EPITECH PROJECT, 2023
** Workshop-MYRPG-Parallax
** File description:
** play.c
*/

#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/View.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

static
void draw_menu(menu_t *menu, all_t *all)
{
    if (menu->state == GAMEBOY_MENU) {
        draw_gameboy(GAME->window, menu->gameboy);
        draw_play_game_btn(GAME->window, menu->buttonplay);
    }
    if (menu->state == MENU) {
        draw_buttons_bg(GAME->window, menu->buttons_bg);
        draw_start_btn(GAME->window, menu->start);
        draw_option_btn(GAME->window, menu->option);
        draw_load_btn(GAME->window, menu->load);
        draw_exit_btn(GAME->window, menu->exit);
    }
    if (menu->state == OPTIONS) {
        draw_options_bg(GAME->window, menu->options_bg);
        draw_close_cross(GAME->window, menu->close);
        draw_volume_bar_btn(GAME->window, menu->option->volume);
        draw_volume_up_btn(GAME->window, menu->option->volume);
        draw_volume_down_btn(GAME->window, menu->option->volume);
        draw_arrow_keybinds(GAME->window, menu->option->keybinds);
    }
}

static
void draw_bg(menu_t *menu, all_t *all)
{
    draw_parallax(GAME->window, menu->parallax);
    draw_particle(GAME->window, menu->particles);
    draw_bear(GAME->window, menu->bear);
}

void draw_gb_and_menu(menu_t *menu, all_t *all, int *current_frame,
    int *current_frame_bear)
{
    GAME->seconds = sfClock_getElapsedTime(GAME->clock).microseconds /
            1000000.0;
    if (GAME->seconds > 0.005) {
        sfRenderWindow_clear(GAME->window, sfBlack);
        move_parallax(menu->parallax);
        move_particle(menu->particles);
        move_bear(menu->bear);
        animate_bear(menu->bear, current_frame, current_frame_bear);
        draw_bg(menu, all);
        draw_menu(menu, all);
        sfRenderWindow_display(GAME->window);
        sfClock_restart(GAME->clock);
    }
}
