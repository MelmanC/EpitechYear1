/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** map.c
*/

#include "SFML/Window/Event.h"
#include "SFML/Config.h"
#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/Sprite.h"
#include "SFML/System/Vector2.h"
#include "SFML/Window/Keyboard.h"
#include "SFML/Window/Mouse.h"
#include "SFML/Window/Window.h"
#include "functions.h"
#include "macros.h"
#include <stdbool.h>
#include <stdio.h>

static
void draw_eneny_quest(all_t *all)
{
    for (int i = 0; i < all->nb_enemy; i++)
        if (ENEMY[i]->is_alive == true) {
            sfSprite_setPosition(M_MAP->quest, (sfVector2f) {
                    ((ENEMY[i]->pos.x * 2240) / 19200) + M_MAP->pos.x - 1120,
                    ((ENEMY[i]->pos.y * 1344) / 14400) + M_MAP->pos.y - 672});
            sfRenderWindow_drawSprite(GAME->window, M_MAP->quest, NULL);
        }
}

static
void draw_quest_follow(all_t *all)
{
    if (QUEST_FOLLOW->is_active == true && OLDMAN->player_dialog == 1) {
        draw_eneny_quest(all);
        if (RACOON->is_alive == true) {
            sfSprite_setPosition(M_MAP->quest, (sfVector2f)
                    {M_MAP->pos.x - 55, M_MAP->pos.y - 500});
            sfRenderWindow_drawSprite(GAME->window, M_MAP->quest, NULL);
        }
        if (FROG->is_alive == true) {
            sfSprite_setPosition(M_MAP->quest, (sfVector2f)
                    {M_MAP->pos.x + 250, M_MAP->pos.y + 190});
            sfRenderWindow_drawSprite(GAME->window, M_MAP->quest, NULL);
        }
    }
    if (OLDMAN->player_dialog == 2) {
        sfSprite_setPosition(M_MAP->quest, (sfVector2f)
            {M_MAP->pos.x - 600, M_MAP->pos.y - 190});
        sfRenderWindow_drawSprite(GAME->window, M_MAP->quest, NULL);
    }
}

void draw_mini_map(all_t *all)
{
    sfShader *shader;
    sfRenderStates states = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};
    double x = ((PLAYER->pos.x * 2240) / 19200) + M_MAP->pos.x - 1120;
    double y = ((PLAYER->pos.y * 1344) / 14400) + M_MAP->pos.y - 672;

    if (M_MAP->is_active == false)
        return;
    shader = sfShader_createFromFile(NULL, NULL, "src/blur");
    states = (sfRenderStates){sfBlendAlpha, sfTransform_Identity, NULL,
        shader};
    if (!shader)
        return;
    blur(all, shader, states);
    M_MAP->pos = sfView_getCenter(CAMERA->view);
    sfSprite_setPosition(M_MAP->sprite, M_MAP->pos);
    sfRenderWindow_drawSprite(GAME->window, M_MAP->sprite, NULL);
    sfSprite_setPosition(M_MAP->player, (sfVector2f){x, y});
    sfRenderWindow_drawSprite(GAME->window, M_MAP->player, NULL);
    draw_quest_follow(all);
}

static
void init_sprite(mini_map_t *mini_map)
{
    mini_map->sprite = sfSprite_create();
    sfSprite_setTexture(mini_map->sprite, mini_map->texture, sfTrue);
    sfSprite_setOrigin(mini_map->sprite, (sfVector2f){3200, 2400});
    sfSprite_setScale(mini_map->sprite, (sfVector2f){0.35, 0.28});
    mini_map->player = sfSprite_create();
    sfSprite_setTexture(mini_map->player, mini_map->player_t, sfTrue);
    sfSprite_setOrigin(mini_map->player, (sfVector2f){8, 8});
    sfSprite_setTextureRect(mini_map->player, (sfIntRect){0, 0, 16, 16});
    sfSprite_setScale(mini_map->player, (sfVector2f){2.5, 2.5});
    mini_map->quest = sfSprite_create();
    sfSprite_setTexture(mini_map->quest, mini_map->quest_t, sfTrue);
    sfSprite_setOrigin(mini_map->quest, (sfVector2f){216.5, 288.5});
    sfSprite_setScale(mini_map->quest, (sfVector2f){0.15, 0.15});
}

mini_map_t *init_mini_map(void)
{
    mini_map_t *mini_map = malloc(sizeof(mini_map_t));

    mini_map->texture = sfTexture_createFromFile(MAPPNG, NULL);
    mini_map->player_t = sfTexture_createFromFile(SPRITESHEET, NULL);
    mini_map->quest_t = sfTexture_createFromFile(QUESTSHEET, NULL);
    if (!mini_map->texture || !mini_map->player_t || !mini_map->quest_t)
        return NULL;
    mini_map->pos = (sfVector2f){0, 0};
    mini_map->is_active = false;
    init_sprite(mini_map);
    return mini_map;
}
