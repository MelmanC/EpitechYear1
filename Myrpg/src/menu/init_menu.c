/*
** EPITECH PROJECT, 2024
** EPITECH | WORKSHOP | CSFML
** File description:
** mon_rpg.c
*/

#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/View.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

static
void init_options(menu_t *menu)
{
    init_options_bg(menu->options_bg);
    init_option_btn(menu->option);
    init_close_cross(menu->close);
    init_volume_bar_btn(menu->option->volume);
    init_volume_up_btn(menu->option->volume);
    init_volume_down_btn(menu->option->volume);
    init_arrow_keybinds(menu->option->keybinds);
    menu->option->keybinds->key_up = sfKeyZ;
    menu->option->keybinds->key_down = sfKeyS;
    menu->option->keybinds->key_left = sfKeyQ;
    menu->option->keybinds->key_right = sfKeyD;
}

static
void init_buttons(menu_t *menu, all_t *all)
{
    init_play_btn(menu->buttonplay);
    init_start_btn(menu->start);
    init_exit_btn(menu->exit);
    init_load_btn(menu->load);
    init_options(menu);
    all->game->is_fullscreen = false;
}

int init_resources(menu_t *menu, all_t *all)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfTime time = {0};

    menu->state = GAMEBOY_MENU;
    all->game = malloc(sizeof(*(all->game)));
    all->game->clock = sfClock_create();
    time = sfClock_getElapsedTime(all->game->clock);
    all->game->seconds = all->game->seconds;
    all->game->window = sfRenderWindow_create(SETTINGS);
    all->game->seconds = time.microseconds / 1000000.0;
    menu->option->volume->volume = 50;
    if (!all->game->window || !all->game->clock)
        return 84;
    init_parallax(menu->parallax);
    init_buttons_bg(menu->buttons_bg);
    init_particle(menu->particles);
    init_buttons(menu, all);
    init_gameboy(menu->gameboy);
    init_bear(menu->bear);
    return 0;
}
