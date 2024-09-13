/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-nolann.dubos
** File description:
** handle_events header
*/

#include "functions.h"

void handle_sound(sfMusic **music, menu_t *menu)
{
    if (!*music) {
        *music = play_sound("assets/sound/corail.wav");
        menu->option->volume->music = *music;
    }
    if (menu->state == INGAME) {
        if (*music) {
            sfMusic_stop(*music);
            *music = NULL;
        }
    }
}

static
void enum_condition(menu_t *menu, sfRenderWindow *window)
{
    if (menu->state == GAMEBOY_MENU) {
        check_play_btn_click(window, menu->buttonplay, menu);
    }
    if (menu->state == MENU) {
        check_start_click(window, menu->start, menu);
        check_option_btn_click(window, menu->option, menu);
        check_load_click(window, menu->load, menu);
        check_exit_click(window, menu->exit, menu);
    }
    if (menu->state == OPTIONS) {
        check_close_click(window, menu->close, menu);
        check_volume_up_click(window, menu->option->volume);
        check_volume_down_click(window, menu->option->volume);
        check_up_arrow_keybinds_click(window, menu->option->keybinds);
        check_down_arrow_keybinds_click(window, menu->option->keybinds);
        check_left_arrow_keybinds_click(window, menu->option->keybinds);
        check_right_arrow_keybinds_click(window, menu->option->keybinds);
    }
}

static
bool exit_bindings(sfEvent event, keybinds_t *keybinds)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        keybinds->waiting_for_keybind_up = false;
        keybinds->waiting_for_keybind_down = false;
        keybinds->waiting_for_keybind_left = false;
        keybinds->waiting_for_keybind_right = false;
        return true;
    }
    return false;
}

static
void handle_u_d_keybindings(menu_t *menu, sfEvent event,
    keybinds_t *keybinds)
{
    if (menu->state == OPTIONS) {
        if (exit_bindings(event, keybinds) == true)
            return;
        if (event.type == sfEvtKeyPressed &&
        keybinds->waiting_for_keybind_up) {
            keybinds->key_up = event.key.code;
            keybinds->is_up_binded = true;
            keybinds->waiting_for_keybind_up = false;
        }
        if (event.type == sfEvtKeyPressed &&
        keybinds->waiting_for_keybind_down) {
            keybinds->key_down = event.key.code;
            keybinds->is_down_binded = true;
            keybinds->waiting_for_keybind_down = false;
        }
    }
}

static
void handle_l_r_keybindings(menu_t *menu, sfEvent event,
    keybinds_t *keybinds)
{
    if (menu->state == OPTIONS) {
        if (event.type == sfEvtKeyPressed &&
        keybinds->waiting_for_keybind_left) {
            keybinds->key_left = event.key.code;
            keybinds->is_left_binded = true;
            keybinds->waiting_for_keybind_left = false;
        }
        if (event.type == sfEvtKeyPressed &&
        keybinds->waiting_for_keybind_right) {
            keybinds->key_right = event.key.code;
            keybinds->is_right_binded = true;
            keybinds->waiting_for_keybind_right = false;
        }
    }
}

void switch_mode(all_t *all, sfEvent event)
{
    sfVideoMode mode = {1920, 1080, 32};

    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF) {
        sfRenderWindow_close(all->game->window);
        if (all->game->is_fullscreen == true) {
            all->game->window = sfRenderWindow_create(mode, "Wildland",
                sfResize | sfClose, NULL);
            all->game->is_fullscreen = false;
            return;
        }
        if (all->game->is_fullscreen == false) {
            all->game->window = sfRenderWindow_create(mode, "Wildland",
                sfFullscreen, NULL);
            all->game->is_fullscreen = true;
            return;
        }
    }
}

void handle_events(sfRenderWindow *window, menu_t *menu, sfMusic **music,
    all_t *all)
{
    while (sfRenderWindow_pollEvent(window, &menu->event)) {
        if (menu->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        handle_sound(music, menu);
        enum_condition(menu, window);
        handle_u_d_keybindings(menu, menu->event, menu->option->keybinds);
        handle_l_r_keybindings(menu, menu->event, menu->option->keybinds);
        switch_mode(all, menu->event);
    }
}
