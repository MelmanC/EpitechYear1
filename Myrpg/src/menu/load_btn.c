/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-nolann.dubos
** File description:
** load.c
*/

#include "functions.h"

static
void init_texture_load(load_t *load)
{
    load->texture = sfTexture_createFromFile(LOAD_PNG, NULL);
    load->lockedTexture = sfTexture_createFromFile(LOAD_LOCK_PNG, NULL);
}

static
void init_sprite_load(load_t *load)
{
    load->sprite = sfSprite_create();
    sfSprite_setTexture(load->sprite
    , load->isLocked == true ? load->lockedTexture : load->texture, sfTrue);
}

void init_load_btn(load_t *load)
{
    load->pos.x = 845;
    load->pos.y = 503;
    load->scale.x = 5.5;
    load->scale.y = 5.5;
    load->isLocked = access("save.txt", F_OK) ? true : false;
    init_texture_load(load);
    init_sprite_load(load);
}

void draw_load_btn(sfRenderWindow *window, load_t *load)
{
    sfSprite_setPosition(load->sprite, load->pos);
    sfSprite_setScale(load->sprite, load->scale);
    sfRenderWindow_drawSprite(window, load->sprite, NULL);
}

static
void load_btn_click(menu_t *menu, load_t *load, sfRenderWindow *window)
{
    if (load->isLocked == false) {
        menu->state = INGAME;
        sfRenderWindow_close(window);
        rpg(menu, 1);
    }
}

void check_load_click(sfRenderWindow *window, load_t *load, menu_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect load_bounds = sfSprite_getGlobalBounds(load->sprite);
    sfColor gray = sfColor_fromRGBA(225, 225, 225, 225);
    sfTexture *click = sfTexture_createFromFile(LOAD_CLICK_PNG, NULL);

    if (sfFloatRect_contains(&load_bounds, mouse_pos.x, mouse_pos.y))
        sfSprite_setColor(load->sprite, gray);
    else
        sfSprite_setColor(load->sprite, sfWhite);
    if (CLICK && LEFT_CLICK) {
        if (sfFloatRect_contains(&load_bounds, (float)mouse_pos.x,
        (float)mouse_pos.y)) {
            sfSprite_setTexture(load->sprite, click, sfTrue);
            load_btn_click(menu, load, window);
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 0)
        sfSprite_setTexture(load->sprite, load->isLocked == true ?
        load->lockedTexture : load->texture, sfTrue);
}
