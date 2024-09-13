/*
** EPITECH PROJECT, 2023
** Workshop-MYRPG-Parallax
** File description:
** bear.c
*/

#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/View.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

static
int init_texture_bear(bear_t *bear)
{
    bear->texture = sfTexture_createFromFile(BEAR, NULL);
    if (!bear->texture)
        return 1;
    return 0;
}

static
int init_sprite_bear(bear_t *bear)
{
    sfVector2f scale = {3.2, 3.2};
    sfVector2f startPos = {0, 900};

    bear->sprite = sfSprite_create();
    if (!bear->sprite)
        return ERROR;
    sfSprite_setTexture(bear->sprite, bear->texture, sfTrue);
    sfSprite_setScale(bear->sprite, scale);
    sfSprite_setPosition(bear->sprite, startPos);
    return 0;
}

int move_bear(bear_t *bear)
{
    sfVector2f pos = sfSprite_getPosition(bear->sprite);

    if (pos.x > -204) {
        pos.x -= 1.5;
    } else {
        pos.x = 1920;
    }
    sfSprite_setPosition(bear->sprite, pos);
    return 0;
}

void animate_bear(bear_t *bear, int *current_frame, int *animation_counter)
{
    sfIntRect rect;

    rect.top = 0;
    rect.width = 64;
    rect.left = (*current_frame) * 64;
    rect.height = sfTexture_getSize(bear->texture).y;
    sfSprite_setTextureRect(bear->sprite, rect);
    (*animation_counter)++;
    if (*animation_counter >= 64) {
        (*current_frame)++;
        *animation_counter = 0;
    }
    if ((unsigned int)(*current_frame)
        * 64 >= sfTexture_getSize(bear->texture).x)
        *current_frame = 0;
}

void init_bear(bear_t *bear)
{
    init_texture_bear(bear);
    init_sprite_bear(bear);
}

void destroy_bear(bear_t *bear)
{
    sfTexture_destroy(bear->texture);
    sfSprite_destroy(bear->sprite);
    free(bear);
}

void draw_bear(sfRenderWindow *window, bear_t *bear)
{
    sfRenderWindow_drawSprite(window, bear->sprite, NULL);
}
