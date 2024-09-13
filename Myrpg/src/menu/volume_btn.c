/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-nolann.dubos
** File description:
** volume_btn header
*/

#include "functions.h"

void init_volume_bar_btn(volume_t *volume)
{
    volume->bar_pos.x = 723;
    volume->bar_pos.y = 188;
    volume->bar_scale.x = (float)5.5;
    volume->bar_scale.y = (float)5.5;
    volume->bar_texture = sfTexture_createFromFile(VOLUME_PNG, NULL);
    volume->bar_sprite = sfSprite_create();
    sfSprite_setTexture(volume->bar_sprite, volume->bar_texture, sfTrue);
}

void draw_volume_bar_btn(sfRenderWindow *window, volume_t *volume)
{
    sfSprite_setPosition(volume->bar_sprite, volume->bar_pos);
    sfSprite_setScale(volume->bar_sprite, volume->bar_scale);
    sfRenderWindow_drawSprite(window, volume->bar_sprite, NULL);
}
