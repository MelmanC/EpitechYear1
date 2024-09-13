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

static
void define_pos_enemy(enemy_t *enemy, int num)
{
    if (num == 0)
        enemy->pos = (sfVector2f) {7302, 5638};
    if (num == 1)
        enemy->pos = (sfVector2f) {6672, 6678};
    if (num == 2)
        enemy->pos = (sfVector2f) {2896, 8156};
    if (num == 3)
        enemy->pos = (sfVector2f) {4880, 8620};
    if (num == 4)
        enemy->pos = (sfVector2f) {5472, 5164};
}

static
void set_sprite_enemy(enemy_t *enemy)
{
    enemy->sprite = sfSprite_create();
    sfSprite_setScale(enemy->sprite, (sfVector2f){4, 4});
    sfSprite_setOrigin(enemy->sprite, (sfVector2f){8, 8});
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfSprite_setPosition(enemy->sprite, enemy->pos);
    enemy->hitbox = (sfFloatRect) {enemy->pos.x - 250, enemy->pos.y - 250,
        500, 500};
}

enemy_t *init_enemy(int num)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    if (!enemy)
        return NULL;
    enemy->texture = sfTexture_createFromFile(ENEMYSHEET, NULL);
    if (!enemy->texture)
        return NULL;
    define_pos_enemy(enemy, num);
    enemy->rect = (sfIntRect) {0, 0, 16, 16};
    enemy->is_alive = true;
    enemy->life = 5;
    enemy->anim_clock = sfClock_create();
    enemy->anim_clock_sec = 0;
    enemy->is_attacking = false;
    enemy->hit = false;
    set_sprite_enemy(enemy);
    return enemy;
}
