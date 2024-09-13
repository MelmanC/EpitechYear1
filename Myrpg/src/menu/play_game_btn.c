/*
** EPITECH PROJECT, 2024
** EPITECH | WORKSHOP | CSFML
** File description:
** mon_rpg.c
*/

#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/View.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

void init_play_btn(play_game_btn_t *button)
{
    button->pos.x = 744;
    button->pos.y = 405;
    button->scale.x = (float)0.5;
    button->scale.y = (float)0.5;
    button->texture = sfTexture_createFromFile(PLAY_BUTTON, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
}

void draw_play_game_btn(sfRenderWindow *window, play_game_btn_t *button)
{
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setScale(button->sprite, button->scale);
    sfRenderWindow_drawSprite(window, button->sprite, NULL);
}

void check_play_btn_click(sfRenderWindow *window, play_game_btn_t *button,
    menu_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect button_bounds = sfSprite_getGlobalBounds(button->sprite);
    sfColor gray = sfColor_fromRGBA(125, 125, 125, 125);

    if (sfFloatRect_contains(&button_bounds, (float)mouse_pos.x,
    (float)mouse_pos.y))
        sfSprite_setColor(button->sprite, gray);
    else
        sfSprite_setColor(button->sprite, sfWhite);
    if (CLICK && LEFT_CLICK && sfFloatRect_contains(&button_bounds,
    (float)mouse_pos.x, (float)mouse_pos.y)) {
        menu->state = MENU;
    }
}
