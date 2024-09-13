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

void check_colision_racoon(all_t *all)
{
    sfFloatRect enemy_rect = sfSprite_getGlobalBounds(RACOON->sprite);

    if (RACOON->is_alive == false)
        return;
    if (sfFloatRect_contains(&enemy_rect, PLAYER->pos.x, PLAYER->pos.y)
        == sfTrue && PLAYER->in_racoon == false) {
        RACOON->is_attacking = true;
        RACOON->rect.left = 0;
        RACOON->offset = 180;
        PLAYER->in_racoon = true;
        PLAYER->life -= 2;
    }
    if (sfFloatRect_contains(&enemy_rect, PLAYER->pos.x, PLAYER->pos.y)
        == sfFalse && PLAYER->in_racoon == true) {
        PLAYER->in_racoon = false;
    }
}

static
void set_direction(racoon_t *enemy, sfVector2f player_pos)
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

void move_racoon(all_t *all)
{
    if (RACOON->is_alive == true &&
        sfFloatRect_contains(&RACOON->hitbox,
            PLAYER->pos.x, PLAYER->pos.y)) {
        set_direction(RACOON, PLAYER->pos);
        sfSprite_setPosition(RACOON->sprite, RACOON->pos);
        sfSprite_setPosition(RACOON->sprite_attack, RACOON->pos);
    }
}

void attack_racoon(all_t *all)
{
    sfFloatRect player_rect = sfSprite_getGlobalBounds(PLAYER->weapon_s);
    sfFloatRect enemy_rect = sfSprite_getGlobalBounds(RACOON->sprite);

    if (RACOON->is_alive == false)
        return;
    if (sfFloatRect_intersects(&player_rect,
        &enemy_rect, NULL) == sfTrue) {
        RACOON->life -= PLAYER->attack;
        STATES->hit = true;
        damage(all, RACOON->pos, 0);
    }
    if (RACOON->life <= 0) {
        sfSprite_setPosition(DEATH->sprite, RACOON->pos);
        DEATH->draw = true;
        RACOON->is_alive = false;
        PLAYER->xp += 10;
    }
}

static
void moove_rect(racoon_t *racoon, int offset)
{
    if (racoon->rect.left >= offset && racoon->is_attacking == true) {
        racoon->rect.left = 0;
        racoon->is_attacking = false;
    } else if (racoon->rect.left >= offset && racoon->is_attacking == false)
        racoon->rect.left = 0;
    else
        racoon->rect.left += 60;
    if (racoon->is_attacking == true)
        sfSprite_setTextureRect(racoon->sprite_attack, racoon->rect);
    else
        sfSprite_setTextureRect(racoon->sprite, racoon->rect);
}

void draw_racoon(all_t *all)
{
    if (RACOON->is_alive == false)
        return;
    RACOON->anim_clock_sec =
            SF_SECONDS(sfClock_getElapsedTime(RACOON->anim_clock));
    if (RACOON->anim_clock_sec > 1.5 / ANIM_FPS) {
        moove_rect(RACOON, RACOON->offset);
        sfClock_restart(RACOON->anim_clock);
    }
    if (RACOON->is_attacking == true)
        sfRenderWindow_drawSprite(GAME->window, RACOON->sprite_attack, NULL);
    else
        sfRenderWindow_drawSprite(GAME->window, RACOON->sprite, NULL);
}

static
void set_sprite_enemy(racoon_t *enemy)
{
    enemy->sprite = sfSprite_create();
    sfSprite_setScale(enemy->sprite, (sfVector2f){3, 3});
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setOrigin(enemy->sprite, (sfVector2f) {30, 30});
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfSprite_setPosition(enemy->sprite, enemy->pos);
    enemy->sprite_attack = sfSprite_create();
    sfSprite_setScale(enemy->sprite_attack, (sfVector2f){3, 3});
    sfSprite_setTexture(enemy->sprite_attack, enemy->texture_attack, sfTrue);
    sfSprite_setOrigin(enemy->sprite_attack, (sfVector2f) {30, 30});
    sfSprite_setTextureRect(enemy->sprite_attack, enemy->rect);
    enemy->hitbox = (sfFloatRect) {enemy->pos.x - 380, enemy->pos.y, 780, 600};
}

racoon_t *init_racoon(void)
{
    racoon_t *enemy = malloc(sizeof(racoon_t));

    if (!enemy)
        return NULL;
    enemy->texture = sfTexture_createFromFile(RACOONSHEET, NULL);
    enemy->texture_attack = sfTexture_createFromFile(RACOONATTACK, NULL);
    if (!enemy->texture || !enemy->texture_attack)
        return NULL;
    enemy->pos = (sfVector2f) {9100, 1500};
    enemy->rect = (sfIntRect) {0, 0, 60, 60};
    enemy->is_alive = true;
    enemy->life = 15;
    enemy->offset = 300;
    enemy->is_attacking = false;
    enemy->anim_clock = sfClock_create();
    enemy->anim_clock_sec = 0;
    set_sprite_enemy(enemy);
    return enemy;
}
