/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-nolann.dubos
** File description:
** buttongame.c
*/

#include "functions.h"

void init_close_cross(close_t *close)
{
    close->pos.x = 1040 + 190;
    close->pos.y = 161;
    close->scale.x = 5.5;
    close->scale.y = 5.5;
    close->texture = sfTexture_createFromFile(CLOSE_PNG, NULL);
    close->sprite = sfSprite_create();
    sfSprite_setTexture(close->sprite, close->texture, sfTrue);
}

void draw_close_cross(sfRenderWindow *window, close_t *close)
{
    sfSprite_setPosition(close->sprite, close->pos);
    sfSprite_setScale(close->sprite, close->scale);
    sfRenderWindow_drawSprite(window, close->sprite, NULL);
}

void check_close_click(sfRenderWindow *window, close_t *close, menu_t *menu)
{
    sfVector2i mouse_pos = {0, 0};
    sfFloatRect close_bounds = {0, 0, 0, 0};

    if (CLICK && LEFT_CLICK) {
        mouse_pos = sfMouse_getPositionRenderWindow(window);
        close_bounds = sfSprite_getGlobalBounds(close->sprite);
        if (sfFloatRect_contains(&close_bounds, (float)mouse_pos.x,
        (float)mouse_pos.y) && menu->state == OPTIONS)
            menu->state = MENU;
    }
}
