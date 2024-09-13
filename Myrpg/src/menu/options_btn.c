/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-nolann.dubos
** File description:
** option.c
*/

#include "functions.h"

void init_option_btn(options_t *option)
{
    option->pos.x = 845;
    option->pos.y = 422;
    option->scale.x = 5.5;
    option->scale.y = 5.5;
    option->texture = sfTexture_createFromFile(OPTIONS_PNG, NULL);
    option->sprite = sfSprite_create();
    sfSprite_setTexture(option->sprite, option->texture, sfTrue);
}

void draw_option_btn(sfRenderWindow *window, options_t *option)
{
    sfSprite_setPosition(option->sprite, option->pos);
    sfSprite_setScale(option->sprite, option->scale);
    sfRenderWindow_drawSprite(window, option->sprite, NULL);
}

void check_option_btn_click(sfRenderWindow *window, options_t *option,
    menu_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect option_bounds = sfSprite_getGlobalBounds(option->sprite);
    sfColor gray = sfColor_fromRGBA(225, 225, 225, 225);
    sfTexture *click = sfTexture_createFromFile(OPTIONS_CLICK_PNG, NULL);

    if (sfFloatRect_contains(&option_bounds, mouse_pos.x, mouse_pos.y))
        sfSprite_setColor(option->sprite, gray);
    else
        sfSprite_setColor(option->sprite, sfWhite);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&option_bounds, (float)mouse_pos.x,
        (float)mouse_pos.y)) {
            sfSprite_setTexture(option->sprite, click, sfTrue);
            menu->state = OPTIONS;
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 0)
        sfSprite_setTexture(option->sprite, option->texture, sfTrue);
}
