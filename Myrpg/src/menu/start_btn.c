/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-nolann.dubos
** File description:
** start header
*/

#include "functions.h"

void init_start_btn(start_t *start)
{
    start->pos.x = 845;
    start->pos.y = 340;
    start->scale.x = 5.5;
    start->scale.y = 5.5;
    start->texture = sfTexture_createFromFile(START_PNG, NULL);
    start->sprite = sfSprite_create();
    sfSprite_setTexture(start->sprite, start->texture, sfTrue);
}

void draw_start_btn(sfRenderWindow *window, start_t *start)
{
    sfSprite_setPosition(start->sprite, start->pos);
    sfSprite_setScale(start->sprite, start->scale);
    sfRenderWindow_drawSprite(window, start->sprite, NULL);
}

void check_start_click(sfRenderWindow *window, start_t *start, menu_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect start_bounds = sfSprite_getGlobalBounds(start->sprite);
    sfColor gray = sfColor_fromRGBA(225, 225, 225, 225);
    sfTexture *click = sfTexture_createFromFile(START_CLICK_PNG, NULL);

    if (sfFloatRect_contains(&start_bounds, mouse_pos.x, mouse_pos.y))
        sfSprite_setColor(start->sprite, gray);
    else
        sfSprite_setColor(start->sprite, sfWhite);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&start_bounds, (float)mouse_pos.x,
        (float)mouse_pos.y)) {
            menu->state = INGAME;
            sfSprite_setTexture(start->sprite, click, sfTrue);
            sfRenderWindow_close(window);
            rpg(menu, 0);
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 0)
        sfSprite_setTexture(start->sprite, start->texture, sfTrue);
}
