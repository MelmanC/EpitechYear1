/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** life.c
*/

#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/Text.h"
#include "SFML/System/Vector2.h"
#include "functions.h"
#include "macros.h"
#include <stdio.h>

void draw_damage(all_t *all)
{
    sfTime elapsed = sfClock_getElapsedTime(PLAYER->damage_clock);

    if (STATES->hit == true) {
        if (sfTime_asSeconds(elapsed) < 0.5)
            sfRenderWindow_drawText(GAME->window, PLAYER->damage, NULL);
        else
            STATES->hit = false;
    } else
        sfClock_restart(PLAYER->damage_clock);
}

void damage(all_t *all, sfVector2f pos, int type)
{
    char buff[20];

    sprintf(buff, "-%d", PLAYER->attack);
    sfText_setFont(PLAYER->damage, PLAYER->font);
    sfText_setCharacterSize(PLAYER->damage, 40);
    sfText_setString(PLAYER->damage, buff);
    sfText_setColor(PLAYER->damage, sfRed);
    if (type == 1)
        sfText_setPosition(PLAYER->damage, (sfVector2f)
            {pos.x + 20, pos.y - 60});
    else
        sfText_setPosition(PLAYER->damage, (sfVector2f)
            {pos.x + 60, pos.y - 100});
}

static
void draw_8_life(all_t *all)
{
    sfVector2f pos = sfSprite_getPosition(PLAYER->life_s);

    if (PLAYER->life > 4) {
        PLAYER->life_rect.left = 0;
        sfSprite_setTextureRect(PLAYER->life_s, PLAYER->life_rect);
        sfRenderWindow_drawSprite(GAME->window, PLAYER->life_s, NULL);
        PLAYER->life_rect.left = 16 * (8 - PLAYER->life);
        sfSprite_setTextureRect(PLAYER->life_s, PLAYER->life_rect);
        sfSprite_setPosition(PLAYER->life_s, (sfVector2f){pos.x + 90, pos.y});
        sfRenderWindow_drawSprite(GAME->window, PLAYER->life_s, NULL);
    } else {
        PLAYER->life_rect.left = 16 * (4 - PLAYER->life);
        sfSprite_setTextureRect(PLAYER->life_s, PLAYER->life_rect);
        sfRenderWindow_drawSprite(GAME->window, PLAYER->life_s, NULL);
        PLAYER->life_rect.left = 64;
        sfSprite_setTextureRect(PLAYER->life_s, PLAYER->life_rect);
        sfSprite_setPosition(PLAYER->life_s, (sfVector2f){pos.x + 90, pos.y});
        sfRenderWindow_drawSprite(GAME->window, PLAYER->life_s, NULL);
    }
    sfSprite_setPosition(PLAYER->life_s, pos);
}

void draw_life(all_t *all)
{
    if (PLAYER->max_life == 8)
        draw_8_life(all);
    else {
        PLAYER->life_rect.left = 16 * (4 - PLAYER->life);
        sfSprite_setTextureRect(PLAYER->life_s, PLAYER->life_rect);
        sfRenderWindow_drawSprite(GAME->window, PLAYER->life_s, NULL);
    }
}

void check_colision_enemy(all_t *all)
{
    sfFloatRect enemy_rect;

    for (int i = 0; i < all->nb_enemy; i++) {
        if (ENEMY[i]->is_alive == false)
            continue;
        enemy_rect = sfSprite_getGlobalBounds(ENEMY[i]->sprite);
        if (sfFloatRect_contains(&enemy_rect, PLAYER->pos.x, PLAYER->pos.y)
            == sfTrue && ENEMY[i]->hit == false) {
            ENEMY[i]->hit = true;
            PLAYER->life -= 1;
        }
        if (sfFloatRect_contains(&enemy_rect, PLAYER->pos.x, PLAYER->pos.y)
            == sfFalse && ENEMY[i]->hit == true) {
            ENEMY[i]->hit = false;
        }
    }
}
