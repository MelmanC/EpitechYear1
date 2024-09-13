/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init.c
*/

#include "SFML/Graphics/Rect.h"
#include "SFML/Graphics/Sprite.h"
#include "SFML/Graphics/Texture.h"
#include "SFML/Graphics/Types.h"
#include "SFML/System/Vector2.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

map_col_t *init_map_collision(void)
{
    map_col_t *map_col = malloc(sizeof(map_col_t));

    map_col->sprite = sfSprite_create();
    map_col->texture = sfTexture_createFromFile(MAPCOLLISION, NULL);
    map_col->image = sfImage_createFromFile(MAPCOLLISION);
    if (!map_col->texture || !map_col->image)
        return NULL;
    sfSprite_setTexture(map_col->sprite, map_col->texture, sfTrue);
    sfSprite_setScale(map_col->sprite, (sfVector2f){3, 3});
    map_col->pos = (sfVector2f){0, 0};
    sfSprite_setPosition(map_col->sprite, map_col->pos);
    return map_col;
}

map_t *init_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    map->sprite = sfSprite_create();
    map->texture = sfTexture_createFromFile(MAPPNG, NULL);
    if (!map->texture)
        return NULL;
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    sfSprite_setScale(map->sprite, (sfVector2f){3, 3});
    map->pos = (sfVector2f){0, 0};
    sfSprite_setPosition(map->sprite, map->pos);
    map->layer = sfSprite_create();
    map->layer_t = sfTexture_createFromFile(MAPLAYER, NULL);
    if (!map->layer_t)
        return NULL;
    sfSprite_setTexture(map->layer, map->layer_t, sfTrue);
    sfSprite_setScale(map->layer, (sfVector2f){3, 3});
    sfSprite_setPosition(map->layer, map->pos);
    return map;
}
