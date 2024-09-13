/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** event.c
*/

#include "SFML/System/Vector2.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"
#include <stdio.h>

static
void get_player_pos(all_t *all)
{
    PLAYER->pos = sfSprite_getPosition(PLAYER->sprite);
}

static
void set_player_pos(all_t *all, int x, int y, int life)
{
    PLAYER->pos.x = x;
    PLAYER->pos.y = y;
    PLAYER->life = life;
    sfSprite_setPosition(PLAYER->sprite, PLAYER->pos);
    sfView_setCenter(CAMERA->view, sfSprite_getPosition(PLAYER->sprite));
    sfRenderWindow_setView(GAME->window, CAMERA->view);
    update_view(all);
}

static
void set_ennemy_life(all_t *all, int racoon, int frog)
{
    RACOON->is_alive = racoon ? true : false;
    FROG->is_alive = frog ? true : false;
}

/**
* This function is used to load the game
* @param all The struct containing the game
* @return SUCCESS or ERROR
*/
int load_game(all_t *all)
{
    FILE *file = fopen("save.txt", "r");
    sfVector2u pos;
    int life = 0;
    int is_dialog = 0;
    int racoon = 0;
    int frog = 0;

    if (!file)
        return ERROR;
    fscanf(file, "%d:%d:%d", &pos.x, &pos.y, &life);
    fgetc(file);
    fscanf(file, "%d:%d:%d", &is_dialog, &QUEST_FOLLOW->is_active,
        &OLDMAN->player_dialog);
    fgetc(file);
    fscanf(file, "%d:%d", &racoon, &frog);
    OLDMAN->is_dialog = is_dialog;
    set_ennemy_life(all, racoon, frog);
    set_player_pos(all, pos.x, pos.y, life);
    fclose(file);
    return SUCCESS;
}

/**
* This function is used to save the game
* @param all The struct containing the game
* @return SUCCESS or ERROR
*/
int save_game(all_t *all)
{
    FILE *file = fopen("save.txt", "w");

    if (!file)
        return ERROR;
    get_player_pos(all);
    fprintf(file, "%d:%d:%d\n", (int)PLAYER->pos.x, (int)PLAYER->pos.y,
        PLAYER->life);
    fprintf(file, "%d:%d:%d\n", OLDMAN->is_dialog, QUEST_FOLLOW->is_active,
        OLDMAN->player_dialog);
    fprintf(file, "%d:%d\n", RACOON->is_alive, FROG->is_alive);
    fclose(file);
    return SUCCESS;
}
