/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** gameboy.c
*/

#include "functions.h"

void init_gameboy(gameboy_t *gameboy)
{
    gameboy->pos.x = 500;
    gameboy->pos.y = 250;
    gameboy->scale.x = (float)0.5;
    gameboy->scale.y = (float)0.5;
    gameboy->texture = sfTexture_createFromFile(GAMEBOY, NULL);
    gameboy->sprite = sfSprite_create();
    sfSprite_setTexture(gameboy->sprite, gameboy->texture, sfTrue);
}

void draw_gameboy(sfRenderWindow *window, gameboy_t *gameboy)
{
    sfSprite_setPosition(gameboy->sprite, gameboy->pos);
    sfSprite_setScale(gameboy->sprite, gameboy->scale);
    sfRenderWindow_drawSprite(window, gameboy->sprite, NULL);
}
