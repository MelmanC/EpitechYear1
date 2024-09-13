/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init.c
*/

#include "SFML/Graphics/Rect.h"
#include "SFML/Graphics/Sprite.h"
#include "SFML/Graphics/Types.h"
#include "SFML/System/Vector2.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

/**
* This function is used to initialize the game
* @param hei the height of the game
* @param len the length of the game
* @return the struct containing the game
*/
game_t *init_window(int hei, int len)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->width = hei;
    game->height = len;
    game->mode = (sfVideoMode){hei, len, 32};
    game->window = sfRenderWindow_create(game->mode, "Wildland",
            sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    return game;
}

static
void set_player_life(player_t *player)
{
    player->life_s = sfSprite_create();
    player->life_pos = (sfVector2f){-600, -200};
    sfSprite_setScale(player->life_s, (sfVector2f){5, 5});
    sfSprite_setTexture(player->life_s, player->life_t, sfTrue);
    sfSprite_setTextureRect(player->life_s, player->life_rect);
    sfSprite_setPosition(player->life_s, player->life_pos);
}

static
void set_player_weapon(player_t *player)
{
    player->weapon_s = sfSprite_create();
    sfSprite_setScale(player->weapon_s, (sfVector2f){4, 4});
    sfSprite_setTexture(player->weapon_s, player->weapon_t, sfTrue);
    sfSprite_setPosition(player->weapon_s, (sfVector2f)
            {player->pos.x + 16, player->pos.y + 60});
}

static
void set_player_sprite(player_t *player)
{
    player->sprite = sfSprite_create();
    sfSprite_setScale(player->sprite, (sfVector2f){4, 4});
    sfSprite_setOrigin(player->sprite, (sfVector2f){8, 8});
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, (sfVector2f){4438, 5116});
    player->pos = sfSprite_getPosition(player->sprite);
    player->init_pos = player->pos;
}

static
void next_player(player_t *player)
{
    player->enemy_kill = 0;
    player->xp = 0;
    player->attack = 0;
    player->speed = PLAYER_SPEED;
    player->max_life = 8;
    player->life = 8;
    player->in_racoon = false;
    player->in_frog = false;
    player->damage = sfText_create();
    player->clock = sfClock_create();
    player->anim_clock = sfClock_create();
    player->attack_clock = sfClock_create();
    player->damage_clock = sfClock_create();
}

/**
* This function is used to initialize the player
* @param player the struct containing the player
* @return SUCCESS or FAILURE
*/
player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->texture = sfTexture_createFromFile(SPRITESHEET, NULL);
    player->weapon_t = sfTexture_createFromFile(WEAPON, NULL);
    player->life_t = sfTexture_createFromFile(LIFE, NULL);
    player->font = sfFont_createFromFile(FONT);
    if (!player->texture || !player->weapon_t || !player->life_t
        || !player->font)
        return NULL;
    player->rect = (sfIntRect){0, 0, 16, 16};
    player->life_rect = (sfIntRect){0, 0, 16, 16};
    set_player_sprite(player);
    set_player_weapon(player);
    set_player_life(player);
    next_player(player);
    return player;
}

old_man_t *init_old(void)
{
    old_man_t *old = malloc(sizeof(old_man_t));

    if (!old)
        return NULL;
    old->texture = sfTexture_createFromFile(OLDSHEET, NULL);
    if (!old->texture)
        return NULL;
    old->sprite = sfSprite_create();
    old->rect = (sfIntRect){0, 0, 16, 16};
    old->pos = (sfVector2f){4433, 5046};
    sfSprite_setScale(old->sprite, (sfVector2f){4, 4});
    sfSprite_setTexture(old->sprite, old->texture, sfTrue);
    sfSprite_setTextureRect(old->sprite, old->rect);
    sfSprite_setPosition(old->sprite, old->pos);
    old->clock = sfClock_create();
    old->anim_clock = sfClock_create();
    return old;
}

dialog_t *init_dialog(void)
{
    dialog_t *dialog = malloc(sizeof(dialog_t));
    char *text = NULL;

    dialog->sprite = sfSprite_create();
    dialog->text = sfText_create();
    dialog->font = sfFont_createFromFile(FONT);
    dialog->pos = (sfVector2f) {100, 600};
    dialog->texture = sfTexture_createFromFile(DIALOGBOX, NULL);
    if (!dialog->font || !dialog->texture)
        return NULL;
    sfSprite_setTexture(dialog->sprite, dialog->texture, sfTrue);
    sfSprite_setScale(dialog->sprite, (sfVector2f){3.5, 3.5});
    sfSprite_setPosition(dialog->sprite, (sfVector2f) {20, 500});
    sfText_setFont(dialog->text, dialog->font);
    sfText_setCharacterSize(dialog->text, 20);
    sfText_setPosition(dialog->text, dialog->pos);
    sfText_setString(dialog->text, text);
    sfText_setColor(dialog->text, sfBlack);
    return dialog;
}

camera_t *init_camera(all_t *all)
{
    camera_t *camera = malloc(sizeof(camera_t));

    camera->view = sfView_create();
    camera->pos = (sfVector2f){0, 0};
    camera->size = (sfVector2f){2560, 1440};
    sfView_setSize(camera->view, camera->size);
    sfView_setCenter(camera->view, sfSprite_getPosition(PLAYER->sprite));
    sfRenderWindow_setView(GAME->window, camera->view);
    return camera;
}
