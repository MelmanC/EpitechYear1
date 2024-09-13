/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** weapon.c
*/

#include "functions.h"

void draw_weapon(all_t *all)
{
    if (STATES->attacking == true) {
        sfRenderWindow_drawSprite(GAME->window, PLAYER->weapon_s, NULL);
        STATES->freezed = true;
    }
}

void define_weapon_direc(all_t *all)
{
    if (STATES->direction == UP) {
        sfSprite_setRotation(PLAYER->weapon_s, 180);
        sfSprite_setPosition(PLAYER->weapon_s, (sfVector2f)
                {PLAYER->pos.x - 6, PLAYER->pos.y - 32});
    }
    if (STATES->direction == DOWN) {
        sfSprite_setRotation(PLAYER->weapon_s, 0);
        sfSprite_setPosition(PLAYER->weapon_s, (sfVector2f)
                {PLAYER->pos.x - 16, PLAYER->pos.y + 32});
    }
    if (STATES->direction == LEFT) {
        sfSprite_setRotation(PLAYER->weapon_s, 90);
        sfSprite_setPosition(PLAYER->weapon_s, (sfVector2f)
                {PLAYER->pos.x - 32, PLAYER->pos.y + 6});
    }
    if (STATES->direction == RIGHT) {
        sfSprite_setRotation(PLAYER->weapon_s, -90);
        sfSprite_setPosition(PLAYER->weapon_s, (sfVector2f)
                {PLAYER->pos.x + 32, PLAYER->pos.y + 26});
    }
}
