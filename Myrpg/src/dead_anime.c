/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** dead_anime.c
*/

#include "SFML/Graphics/Rect.h"
#include "SFML/Graphics/Sprite.h"
#include "SFML/Graphics/Types.h"
#include "SFML/System/Vector2.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

static
void moove_rect(death_t *death)
{
    if (death->rect.left >= 128) {
        death->rect.left = 0;
        death->draw = false;
    } else
        death->rect.left += 32;
    sfSprite_setTextureRect(death->sprite, death->rect);
}

void death_anim(all_t *all)
{
    if (DEATH->draw == false)
        return;
    DEATH->anim_clock_sec =
            SF_SECONDS(sfClock_getElapsedTime(DEATH->anim_clock));
    if (DEATH->anim_clock_sec > 3.0 / ANIM_FPS) {
        moove_rect(DEATH);
        sfClock_restart(DEATH->anim_clock);
    }
    sfRenderWindow_drawSprite(GAME->window, DEATH->sprite, NULL);
}

death_t *init_death(void)
{
    death_t *death = malloc(sizeof(death_t));

    death->texture = sfTexture_createFromFile(DEADSHEET, NULL);
    if (!death->texture)
        return NULL;
    death->sprite = sfSprite_create();
    death->rect = (sfIntRect){0, 0, 32, 32};
    sfSprite_setTexture(death->sprite, death->texture, sfTrue);
    sfSprite_setScale(death->sprite, (sfVector2f){4, 4});
    sfSprite_setOrigin(death->sprite, (sfVector2f) {16, 16});
    sfSprite_setTextureRect(death->sprite, death->rect);
    death->anim_clock = sfClock_create();
    death->anim_clock_sec = 0;
    return death;
}
