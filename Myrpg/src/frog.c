/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** init_enemy.c
*/

#include "SFML/Graphics/Rect.h"
#include "SFML/Graphics/Sprite.h"
#include "SFML/Graphics/Types.h"
#include "SFML/System/Vector2.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

void check_colision_frog(all_t *all)
{
    sfFloatRect enemy_rect = sfSprite_getGlobalBounds(FROG->sprite);

    if (FROG->is_alive == false)
        return;
    if (sfFloatRect_contains(&enemy_rect, PLAYER->pos.x, PLAYER->pos.y)
        == sfTrue && PLAYER->in_frog == false) {
        FROG->is_charging = true;
        FROG->offset = 240;
        FROG->rect.left = 0;
        PLAYER->in_frog = true;
        PLAYER->life -= 2;
    }
    if (sfFloatRect_contains(&enemy_rect, PLAYER->pos.x, PLAYER->pos.y)
        == sfFalse && PLAYER->in_frog == true) {
        PLAYER->in_frog = false;
    }
}

static
void set_direction(frog_t *enemy, sfVector2f player_pos)
{
    if (enemy->pos.x < player_pos.x) {
        if (enemy->pos.x + 1.5 < enemy->hitbox.left + enemy->hitbox.width)
            enemy->pos.x += 1.5;
    }
    if (enemy->pos.x > player_pos.x) {
        if (enemy->pos.x - 1.5 > enemy->hitbox.left)
            enemy->pos.x -= 1.5;
    }
    if (enemy->pos.y < player_pos.y) {
        if (enemy->pos.y + 1.5 < enemy->hitbox.top + enemy->hitbox.height)
            enemy->pos.y += 1.5;
    }
    if (enemy->pos.y > player_pos.y) {
        if (enemy->pos.y - 1.5 > enemy->hitbox.top)
            enemy->pos.y -= 1.5;
    }
}

void move_frog(all_t *all)
{
    if (FROG->is_alive == true &&
        sfFloatRect_contains(&FROG->hitbox,
            PLAYER->pos.x, PLAYER->pos.y)) {
        set_direction(FROG, PLAYER->pos);
        sfSprite_setPosition(FROG->sprite, FROG->pos);
        sfSprite_setPosition(FROG->sprite_attack, FROG->pos);
        sfSprite_setPosition(FROG->sprite_charge, FROG->pos);
    }
}

void attack_frog(all_t *all)
{
    sfFloatRect player_rect = sfSprite_getGlobalBounds(PLAYER->weapon_s);
    sfFloatRect enemy_rect = sfSprite_getGlobalBounds(FROG->sprite);

    if (FROG->is_alive == false)
        return;
    if (sfFloatRect_intersects(&player_rect,
        &enemy_rect, NULL) == sfTrue) {
        FROG->life -= PLAYER->attack;
        STATES->hit = true;
        damage(all, FROG->pos, 0);
    }
    if (FROG->life <= 0) {
        sfSprite_setPosition(DEATH->sprite, FROG->pos);
        DEATH->draw = true;
        FROG->is_alive = false;
        PLAYER->xp += 10;
    }
}

static
void moove_rect(frog_t *frog, int offset)
{
    if (frog->rect.left >= offset) {
        if (frog->is_attacking == true) {
            frog->is_attacking = false;
            frog->offset = 160;
        }
        if (frog->is_charging == true) {
            frog->is_charging = false;
            frog->is_attacking = true;
            frog->offset = 80;
        }
        frog->rect.left = 0;
    } else
        frog->rect.left += 40;
    if (frog->is_charging == true)
        sfSprite_setTextureRect(frog->sprite_charge, frog->rect);
    if (frog->is_attacking == true)
        sfSprite_setTextureRect(frog->sprite_attack, frog->rect);
    if (frog->is_charging == false && frog->is_attacking == false)
        sfSprite_setTextureRect(frog->sprite, frog->rect);
}

void draw_frog(all_t *all)
{
    if (FROG->is_alive == false)
        return;
    FROG->anim_clock_sec =
            SF_SECONDS(sfClock_getElapsedTime(FROG->anim_clock));
    if (FROG->anim_clock_sec > 1.5 / ANIM_FPS) {
        moove_rect(FROG, FROG->offset);
        sfClock_restart(FROG->anim_clock);
    }
    if (FROG->is_attacking == true)
        sfRenderWindow_drawSprite(GAME->window, FROG->sprite_attack, NULL);
    if (FROG->is_charging == true)
        sfRenderWindow_drawSprite(GAME->window, FROG->sprite_charge, NULL);
    if (FROG->is_attacking == false && FROG->is_charging == false)
        sfRenderWindow_drawSprite(GAME->window, FROG->sprite, NULL);
}

static
void set_sprite_enemy(frog_t *enemy)
{
    enemy->sprite = sfSprite_create();
    sfSprite_setScale(enemy->sprite, (sfVector2f){3, 3});
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setOrigin(enemy->sprite, (sfVector2f) {20, 20});
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfSprite_setPosition(enemy->sprite, enemy->pos);
    enemy->sprite_attack = sfSprite_create();
    sfSprite_setScale(enemy->sprite_attack, (sfVector2f){3, 3});
    sfSprite_setTexture(enemy->sprite_attack, enemy->texture_attack, sfTrue);
    sfSprite_setOrigin(enemy->sprite_attack, (sfVector2f) {20, 20});
    sfSprite_setTextureRect(enemy->sprite_attack, enemy->rect);
    enemy->sprite_charge = sfSprite_create();
    sfSprite_setScale(enemy->sprite_charge, (sfVector2f){3, 3});
    sfSprite_setTexture(enemy->sprite_charge, enemy->texture_charge, sfTrue);
    sfSprite_setOrigin(enemy->sprite_charge, (sfVector2f) {20, 20});
    sfSprite_setTextureRect(enemy->sprite_charge, enemy->rect);
    enemy->hitbox = (sfFloatRect) {11168, 8657, 1083, 1040};
}

frog_t *init_frog(void)
{
    frog_t *enemy = malloc(sizeof(frog_t));

    enemy->texture = sfTexture_createFromFile(FROGSHEET, NULL);
    enemy->texture_attack = sfTexture_createFromFile(FROGATTACK, NULL);
    enemy->texture_charge = sfTexture_createFromFile(FROGCHARGE, NULL);
    if (!enemy->texture || !enemy->texture_attack || !enemy->texture_charge)
        return NULL;
    enemy->pos = (sfVector2f) {12117, 9265};
    enemy->rect = (sfIntRect) {0, 0, 40, 40};
    enemy->is_alive = true;
    enemy->life = 24;
    enemy->offset = 160;
    enemy->is_attacking = false;
    enemy->anim_clock = sfClock_create();
    enemy->anim_clock_sec = 0;
    set_sprite_enemy(enemy);
    return enemy;
}
