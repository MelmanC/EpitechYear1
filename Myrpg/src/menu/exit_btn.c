/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-nolann.dubos
** File description:
** exit.c
*/

#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/View.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

static
void init_texture_exit(exit_t *exit)
{
    exit->texture = sfTexture_createFromFile("assets/buttons/exit.png", NULL);
}

static
void init_sprite_exit(exit_t *exit)
{
    exit->sprite = sfSprite_create();
    sfSprite_setTexture(exit->sprite, exit->texture, sfTrue);
}

void init_exit_btn(exit_t *exit)
{
    exit->pos.x = 845;
    exit->pos.y = 585;
    exit->scale.x = 5.5;
    exit->scale.y = 5.5;
    init_texture_exit(exit);
    init_sprite_exit(exit);
}

void draw_exit_btn(sfRenderWindow *window, exit_t *exit)
{
    sfSprite_setPosition(exit->sprite, exit->pos);
    sfSprite_setScale(exit->sprite, exit->scale);
    sfRenderWindow_drawSprite(window, exit->sprite, NULL);
}

void check_exit_click(sfRenderWindow *window, exit_t *exit, menu_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect exit_bounds = sfSprite_getGlobalBounds(exit->sprite);
    sfColor gray = sfColor_fromRGBA(225, 225, 225, 225);
    sfTexture *click = sfTexture_createFromFile(EXIT_CLICK_PNG, NULL);

    if (sfFloatRect_contains(&exit_bounds, mouse_pos.x, mouse_pos.y))
        sfSprite_setColor(exit->sprite, gray);
    else
        sfSprite_setColor(exit->sprite, sfWhite);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&exit_bounds, (float)mouse_pos.x,
        (float)mouse_pos.y)) {
            sfSprite_setTexture(exit->sprite, click, sfTrue);
            sfRenderWindow_close(window);
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 0)
        sfSprite_setTexture(exit->sprite, exit->texture, sfTrue);
}
