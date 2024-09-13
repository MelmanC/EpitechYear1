/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** event.c
*/

#include "SFML/Window/Event.h"
#include "SFML/Config.h"
#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/Sprite.h"
#include "SFML/Graphics/Types.h"
#include "SFML/System/Vector2.h"
#include "SFML/Window/Keyboard.h"
#include "SFML/Window/Mouse.h"
#include "SFML/Window/Window.h"
#include "functions.h"
#include "macros.h"
#include <stdbool.h>
#include <stdio.h>

static
void check_pnj(sfEvent event, all_t *all)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter) {
        if (OLDMAN->is_dialog == 1) {
            OLDMAN->is_dialog = 0;
            OLDMAN->player_dialog = 1;
            QUEST_FOLLOW->is_active = 1;
            STATES->freezed = 0;
            PLAYER->attack += 2;
        }
        if (OLDMAN->is_dialog == 2) {
            OLDMAN->is_dialog = 0;
            OLDMAN->player_dialog = 1;
            STATES->freezed = 0;
        }
        if (OLDMAN->player_dialog == 0 || OLDMAN->player_dialog == 2) {
            check_dialog(all);
        }
    }
}

static
void move_next(all_t *all, sfVector2f pos, menu_t *menu)
{
    if (sfKeyboard_isKeyPressed(KEY->key_left) && STATES->freezed == false &&
        is_moveable(pos, MAPCOL->image, LEFT)) {
        STATES->direction = LEFT;
        move_player(all);
        define_weapon_direc(all);
    }
    if (sfKeyboard_isKeyPressed(KEY->key_right) && STATES->freezed == false &&
        is_moveable(pos, MAPCOL->image, RIGHT)) {
        STATES->direction = RIGHT;
        move_player(all);
        define_weapon_direc(all);
    }
}

static
void move(all_t *all, menu_t *menu)
{
    sfVector2f pos = sfSprite_getPosition(PLAYER->sprite);

    if (sfKeyboard_isKeyPressed(KEY->key_up) && STATES->freezed == false &&
        is_moveable(pos, MAPCOL->image, UP)) {
        STATES->direction = UP;
        move_player(all);
        define_weapon_direc(all);
    }
    if (sfKeyboard_isKeyPressed(KEY->key_down) && STATES->freezed == false &&
        is_moveable(pos, MAPCOL->image, DOWN)) {
        STATES->direction = DOWN;
        move_player(all);
        define_weapon_direc(all);
    }
    move_next(all, pos, menu);
}

static
void mouse_event(sfEvent event, all_t *all)
{
    if (event.mouseButton.button == sfMouseLeft
        && OLDMAN->player_dialog == 1 && STATES->freezed == false) {
        if (STATES->direction == DOWN)
            attack_player(all);
        if (STATES->direction == UP)
            attack_player(all);
        if (STATES->direction == LEFT)
            attack_player(all);
        if (STATES->direction == RIGHT)
            attack_player(all);
    }
}

static
void check_button_paused_next(all_t *all, sfVector2f pos,
    sfFloatRect bounds_save, sfFloatRect bounds_load)
{
    if (sfFloatRect_contains(&bounds_save, pos.x, pos.y)) {
        save_game(all);
        PAUSE->is_paused = false;
        STATES->freezed = false;
    }
    if (sfFloatRect_contains(&bounds_load, pos.x, pos.y)) {
        load_game(all);
        PAUSE->is_paused = false;
        STATES->freezed = false;
    }
}

static
void check_button_paused(all_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(GAME->window);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(GAME->window, mouse,
        CAMERA->view);
    sfFloatRect bounds_save = {0, 0, 0, 0};
    sfFloatRect bounds_load = {0, 0, 0, 0};
    sfFloatRect bounds_settings = {0, 0, 0, 0};
    sfFloatRect bounds_augment = {0, 0, 0, 0};

    if (sfMouse_isButtonPressed(sfMouseLeft) && PAUSE->is_paused == true) {
        bounds_save = sfSprite_getGlobalBounds(PAUSE->save);
        bounds_load = sfSprite_getGlobalBounds(PAUSE->load);
        bounds_settings = sfSprite_getGlobalBounds(PAUSE->settings);
        bounds_augment = sfSprite_getGlobalBounds(PAUSE->augment);
        check_button_paused_next(all, pos, bounds_save, bounds_load);
        if (sfFloatRect_contains(&bounds_settings, pos.x, pos.y))
            printf("Settings\n");
        if (sfFloatRect_contains(&bounds_augment, pos.x, pos.y))
            augment_attack(all);
    }
}

static
void pause_game(sfEvent event, all_t *all)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        if (PAUSE->is_paused == false && STATES->freezed == false) {
            STATES->freezed = true;
            PAUSE->is_paused = true;
            return;
        }
        if (PAUSE->is_paused == true && STATES->freezed == true) {
            STATES->freezed = false;
            PAUSE->is_paused = false;
            return;
        }
    }
    check_button_paused(all);
}

static
void show_map(sfEvent event, all_t *all)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyM) {
        if (M_MAP->is_active == false) {
            M_MAP->is_active = true;
            STATES->freezed = true;
        } else {
            M_MAP->is_active = false;
            STATES->freezed = false;
        }
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyT) {
        if (TUTO->is_active == false) {
            TUTO->is_active = true;
            STATES->freezed = true;
        } else {
            TUTO->is_active = false;
            STATES->freezed = false;
        }
    }
}

static
void zoom(sfEvent event, all_t *all)
{
    if (event.type == sfEvtMouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0) {
            sfView_zoom(CAMERA->view, 0.9);
            sfRenderWindow_setView(GAME->window, CAMERA->view);
        }
        if (event.mouseWheelScroll.delta < 0) {
            sfView_zoom(CAMERA->view, 1.1);
            sfRenderWindow_setView(GAME->window, CAMERA->view);
        }
    }
}

/**
* This function is used to handle all the events in the game
* @param event The event of the game
* @param game The struct containing the game
* @return SUCCESS or FAILURE
*/
int input_handling(sfEvent event, game_t *game, all_t *all, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            mouse_event(event, all);
        if (event.type == sfEvtMouseMoved) {
            return SUCCESS;
        }
        show_map(event, all);
        zoom(event, all);
        pause_game(event, all);
        move(all, menu);
        check_pnj(event, all);
        switch_mode(all, event);
        sfView_setCenter(CAMERA->view, sfSprite_getPosition(PLAYER->sprite));
        sfRenderWindow_setView(game->window, CAMERA->view);
    }
    return SUCCESS;
}
