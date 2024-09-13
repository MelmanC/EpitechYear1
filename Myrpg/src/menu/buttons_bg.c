/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-nolann.dubos
** File description:
** buttons_bg header
*/

#include "functions.h"

void init_buttons_bg(buttons_bg_t *menubutton)
{
    menubutton->pos.x = 730;
    menubutton->pos.y = 300;
    menubutton->scale.x = 9;
    menubutton->scale.y = 9;
    menubutton->texture = sfTexture_createFromFile(BUTTONS_BG_PNG, NULL);
    menubutton->sprite = sfSprite_create();
    sfSprite_setTexture(menubutton->sprite, menubutton->texture, sfTrue);
}

void draw_buttons_bg(sfRenderWindow *window, buttons_bg_t *buttons_bg)
{
    sfSprite_setPosition(buttons_bg->sprite, buttons_bg->pos);
    sfSprite_setScale(buttons_bg->sprite, buttons_bg->scale);
    sfRenderWindow_drawSprite(window, buttons_bg->sprite, NULL);
}
