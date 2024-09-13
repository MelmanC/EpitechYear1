/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** event.c
*/

#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/Text.h"
#include "SFML/System/Vector2.h"
#include "functions.h"
#include "macros.h"
#include <stdio.h>

void verif_death(all_t *all)
{
    if (PLAYER->life <= 0) {
        PLAYER->life = PLAYER->max_life;
        PLAYER->pos = PLAYER->init_pos;
        OLDMAN->is_dialog = 0;
        OLDMAN->player_dialog = 0;
    }
}

static
sfVector2f check_direction_next(int direction, sfVector2f pos_origin)
{
    if (direction == 2) {
        pos_origin.y -= 5;
        pos_origin.x += -4;
    }
    if (direction == 3) {
        pos_origin.y -= 5;
        pos_origin.x += 4;
    }
    return pos_origin;
}

static
int check_direction(sfVector2f pos_origin, int direction, sfImage *image)
{
    sfColor color;

    if (direction == 0) {
        pos_origin.y -= 3;
        pos_origin.x += 3;
    }
    if (direction == 1) {
        pos_origin.y += 6;
        pos_origin.x += -3;
    }
    pos_origin = check_direction_next(direction, pos_origin);
    color = sfImage_getPixel(image, pos_origin.x, pos_origin.y);
    if (color.r == 255 && color.g == 255 && color.b == 255)
        return 1;
    return 0;
}

int is_moveable(sfVector2f pos_origin, sfImage *image, int direction)
{
    pos_origin.x /= 3;
    pos_origin.y /= 3;
    if (check_direction(pos_origin, direction, image) == 1)
        return 1;
    return 0;
}

/**
* This function is used to move the rect of the player
* @param rect the rect to move
* @param offset the offset to move
* @param max_value the max value of the rect
* @return void
* @debug remove the static if you need to use this function in another file
*/
static
void move_rect(sfIntRect *rect)
{
    int offset = 16;
    int max_value = 64;

    rect->top += offset;
    if (rect->top >= max_value)
        rect->top = 0;
}

static
int set_pos(player_t *player, states_t *state)
{
    float delta_time = 1.0 / ANIM_FPS;

    switch (state->direction) {
        case UP:
            player->pos.y -= 1 * player->speed * delta_time;
            break;
        case DOWN:
            player->pos.y += 1 * player->speed * delta_time;
            break;
        case LEFT:
            player->pos.x -= 1 * player->speed * delta_time;
            break;
        case RIGHT:
            player->pos.x += 1 * player->speed * delta_time;
            break;
    }
    sfSprite_setPosition(player->sprite, player->pos);
    sfClock_restart(player->clock);
    return SUCCESS;
}

int move(states_t *state, player_t *player)
{
    switch (state->direction) {
        case UP:
            player->rect.left = 16;
            break;
        case DOWN:
            player->rect.left = 0;
            break;
        case LEFT:
            player->rect.left = 32;
            break;
        case RIGHT:
            player->rect.left = 48;
            break;
    }
    move_rect(&player->rect);
    return SUCCESS;
}

/**
* This function is used to handle the player movement
* @param all the struct containing the game
* @param x the x axis movement (1, -1)
* @param y the y axis movement (1, -1)
* @return SUCCESS
*/
int move_player(all_t *all)
{
    set_pos(PLAYER, STATES);
    printf("x: %f y: %f\n", PLAYER->pos.x, PLAYER->pos.y);
    PLAYER->anim_clock_sec =
        SF_SECONDS(sfClock_getElapsedTime(PLAYER->anim_clock));
    update_view(all);
    if (PLAYER->anim_clock_sec > 1.0 / ANIM_FPS) {
        move(STATES, PLAYER);
        check_colision_enemy(all);
        check_colision_racoon(all);
        check_colision_frog(all);
        sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
        sfClock_restart(PLAYER->anim_clock);
    }
    return SUCCESS;
}
