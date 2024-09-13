/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** game.c
*/

#include "SFML/Graphics/Image.h"
#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/Text.h"
#include "SFML/Graphics/Types.h"
#include "SFML/Graphics/View.h"
#include "SFML/System/Vector2.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"
#include <stdio.h>

/**
* This function is used to update the quest objective view
* @param all the struct of the game
* @return void
*/
static
void update_quest_life(all_t *all)
{
    sfVector2f player = sfSprite_getPosition(PLAYER->sprite);
    sfVector2f view_center = sfView_getCenter(CAMERA->view);
    sfVector2f position = {0, 0};

    PLAYER->life_pos = (sfVector2f) {player.x - 1100, player.y - 700};
    position.x = player.x + (PLAYER->life_pos.x -
        view_center.x);
    position.y = player.y + (PLAYER->life_pos.y -
        view_center.y);
    sfSprite_setPosition(PLAYER->life_s, position);
}

/**
* This function is used to update the quest objective view
* @param all the struct of the game
* @return void
*/
static
void update_quest_follow(all_t *all)
{
    sfVector2f player = sfSprite_getPosition(PLAYER->sprite);
    sfVector2f view_center = sfView_getCenter(CAMERA->view);
    sfVector2f position = {0, 0};

    QUEST_FOLLOW->pos = (sfVector2f) {player.x + 700, player.y - 670};
    position.x = player.x + (QUEST_FOLLOW->pos.x -
        view_center.x);
    position.y = player.y + (QUEST_FOLLOW->pos.y -
        view_center.y);
    sfSprite_setPosition(QUEST_FOLLOW->sprite, position);
    sfText_setPosition(QUEST_FOLLOW->text, (sfVector2f) {position.x + 10,
        position.y + 10});
}

/**
* This function is used to update the inventory view
* @param all the struct of the game
* @return void
*/
static
void update_inventory(all_t *all)
{
    sfVector2f player = sfSprite_getPosition(PLAYER->sprite);
    sfVector2f view_center = sfView_getCenter(CAMERA->view);
    sfVector2f position = {0, 0};

    for (int i = 0; i < 3; i++) {
        position.x = player.x + (PLAYER->pos.x + i * 200 -
            view_center.x - 250);
        position.y = player.y + (PLAYER->pos.y + 500 -
            view_center.y);
        sfSprite_setPosition(INVENTORY[i].sprite, position);
        sfSprite_setPosition(INVENTORY[i].weapon, (sfVector2f){position.x + 55,
            position.y + 25});
    }
}

static
void set_text(all_t *all)
{
    int niveau = 1;
    char buffer[50];

    if (PLAYER->xp >= 10)
        niveau = 2;
    if (PLAYER->xp >= 20)
        niveau = 3;
    if (PLAYER->xp >= 30)
        niveau = 4;
    if (PLAYER->xp >= 40)
        niveau = 5;
    sprintf(buffer, "Niveau : %d", niveau);
    sfText_setString(PAUSE->text_level, buffer);
    sprintf(buffer, "Attaque : %d", PLAYER->attack);
    sfText_setString(PAUSE->text_attack, buffer);
}

static
void set_pos(all_t *all, sfVector2f position)
{
    sfSprite_setPosition(PAUSE->save, (sfVector2f){position.x + 50,
        position.y + 50});
    sfSprite_setPosition(PAUSE->load, (sfVector2f){position.x + 59,
        position.y + 154});
    sfSprite_setPosition(PAUSE->settings, (sfVector2f){position.x + 53,
        position.y + 250});
    sfSprite_setPosition(PAUSE->chest, (sfVector2f){position.x + 500,
        position.y + 250});
    sfSprite_setPosition(PAUSE->weapon, (sfVector2f){position.x + 540,
        position.y + 120});
    sfSprite_setPosition(PAUSE->character, (sfVector2f){position.x + 605,
        position.y - 30});
    sfText_setPosition(PAUSE->text_level, (sfVector2f){position.x + 550,
        position.y - 70});
    sfText_setPosition(PAUSE->text_attack, (sfVector2f){position.x + 550,
        position.y + 60});
    sfSprite_setPosition(PAUSE->augment, (sfVector2f){position.x + 770,
        position.y + 50});
}

void update_pause(all_t *all)
{
    sfVector2f player = sfSprite_getPosition(PLAYER->sprite);
    sfVector2f view_center = sfView_getCenter(CAMERA->view);
    sfVector2f position = {0, 0};

    set_text(all);
    position.x = player.x + (PLAYER->pos.x - 400 -
        view_center.x);
    position.y = player.y + (PLAYER->pos.y - 200 -
        view_center.y);
    sfSprite_setPosition(PAUSE->background, position);
    set_pos(all, position);
}

void update_tuto(all_t *all)
{
    sfVector2f player = sfSprite_getPosition(PLAYER->sprite);
    sfVector2f view_center = sfView_getCenter(CAMERA->view);
    sfVector2f position = {0, 0};

    position.x = player.x + (PLAYER->pos.x - 400 -
        view_center.x);
    position.y = player.y + (PLAYER->pos.y - 400 -
        view_center.y);
    sfSprite_setPosition(TUTO->sprite, position);
    sfText_setPosition(TUTO->text, (sfVector2f) {position.x + 80,
        position.y + 80});
}

/**
* This function is used to update the view of the game
* @param all the struct of the game
* @return void
* @debug remove the static if you need to use this function in another file
*/
void update_view(all_t *all)
{
    sfView_setCenter(CAMERA->view, sfSprite_getPosition(PLAYER->sprite));
    sfRenderWindow_setView(GAME->window, CAMERA->view);
    update_quest_follow(all);
    update_quest_life(all);
    update_inventory(all);
}
