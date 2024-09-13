/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** enemy.c
*/

#include "SFML/Graphics/Rect.h"
#include "SFML/Graphics/Sprite.h"
#include "SFML/Graphics/Types.h"
#include "SFML/System/Vector2.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

static
void set_direction(enemy_t *enemy, sfVector2f player_pos)
{
    if (enemy->pos.x < player_pos.x) {
        if (enemy->pos.x + 1.0 < enemy->hitbox.left + enemy->hitbox.width)
            enemy->pos.x += 1;
    }
    if (enemy->pos.x > player_pos.x) {
        if (enemy->pos.x - 1.0 > enemy->hitbox.left)
            enemy->pos.x -= 1;
    }
    if (enemy->pos.y < player_pos.y) {
        if (enemy->pos.y + 1.0 < enemy->hitbox.top + enemy->hitbox.height)
            enemy->pos.y += 1;
    }
    if (enemy->pos.y > player_pos.y) {
        if (enemy->pos.y - 1.0 > enemy->hitbox.top)
            enemy->pos.y -= 1;
    }
}

static
void enemy_attacking(all_t *all, int i)
{
    if (ENEMY[i]->is_attacking != true) {
        ENEMY[i]->is_attacking = true;
        ENEMY[i]->rect.left = 0;
        ENEMY[i]->rect.top = 0;
    }
}

void move_enemy(all_t *all)
{
    for (int i = 0; i < all->nb_enemy; i++) {
        if (ENEMY[i]->is_alive == true &&
            sfFloatRect_contains(&ENEMY[i]->hitbox,
                PLAYER->pos.x, PLAYER->pos.y)) {
            set_direction(ENEMY[i], PLAYER->pos);
            sfSprite_setPosition(ENEMY[i]->sprite, ENEMY[i]->pos);
            enemy_attacking(all, i);
            break;
        }
        if (ENEMY[i]->is_attacking != false) {
            ENEMY[i]->is_attacking = false;
            ENEMY[i]->rect.left = 0;
            ENEMY[i]->rect.top = 0;
        }
    }
}

static
void moove_rect(enemy_t *enemy)
{
    if (enemy->is_attacking == true) {
        if (enemy->rect.top == 48)
            enemy->rect.top = 0;
        else
            enemy->rect.top += 16;
    } else {
        if (enemy->rect.left == 48)
            enemy->rect.left = 0;
        else
            enemy->rect.left += 16;
    }
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
}

void draw_enemy(all_t *all)
{
    for (int i = 0; i < all->nb_enemy; i++) {
        ENEMY[i]->anim_clock_sec =
                SF_SECONDS(sfClock_getElapsedTime(ENEMY[i]->anim_clock));
        if (ENEMY[i]->anim_clock_sec > 1.5 / ANIM_FPS) {
            moove_rect(ENEMY[i]);
            sfClock_restart(ENEMY[i]->anim_clock);
        }
        if (ENEMY[i]->is_alive == true)
            sfRenderWindow_drawSprite(GAME->window, ENEMY[i]->sprite, NULL);
    }
}

static
void check_alive(all_t *all, int i)
{
    if (ENEMY[i]->life <= 0) {
        ENEMY[i]->is_alive = false;
        PLAYER->enemy_kill += 1;
        DEATH->draw = true;
        sfSprite_setPosition(DEATH->sprite, ENEMY[i]->pos);
        PLAYER->xp += 2;
    }
}

void attack_enemy(all_t *all)
{
    sfFloatRect player_rect = sfSprite_getGlobalBounds(PLAYER->weapon_s);
    sfFloatRect enemy_rect;

    for (int i = 0; i < all->nb_enemy; i++) {
        if (ENEMY[i]->is_alive == false)
            continue;
        enemy_rect = sfSprite_getGlobalBounds(ENEMY[i]->sprite);
        if (sfFloatRect_intersects(&player_rect,
                &enemy_rect, NULL) == sfTrue) {
            ENEMY[i]->life -= PLAYER->attack;
            STATES->hit = true;
            damage(all, ENEMY[i]->pos, 1);
            check_alive(all, i);
        }
    }
}
