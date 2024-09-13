/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-nolann.dubos
** File description:
** options_bg header
*/

#include "functions.h"

void init_options_bg(options_bg_t *options_bg)
{
    options_bg->pos.x = 547;
    options_bg->pos.y = 111;
    options_bg->scale.x = 9;
    options_bg->scale.y = 9;
    options_bg->texture = sfTexture_createFromFile(OPTIONS_BG_PNG, NULL);
    options_bg->sprite = sfSprite_create();
    sfSprite_setTexture(options_bg->sprite, options_bg->texture, sfTrue);
}

void draw_options_bg(sfRenderWindow *window, options_bg_t *options_bg)
{
    sfSprite_setPosition(options_bg->sprite, options_bg->pos);
    sfSprite_setScale(options_bg->sprite, options_bg->scale);
    sfRenderWindow_drawSprite(window, options_bg->sprite, NULL);
}
