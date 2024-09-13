/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** event.c
*/

#include "SFML/System/Clock.h"
#include "SFML/System/Time.h"
#include "functions.h"
#include <stdio.h>

/**
* This function is used to check if the player is attacking
* @param all The struct containing the game
* @return SUCCESS
*/
void is_attacking(all_t *all)
{
    sfTime elapsed = sfClock_getElapsedTime(PLAYER->attack_clock);

    if (STATES->attacking == true) {
        if (sfTime_asSeconds(elapsed) < 0.5);
        else {
            STATES->attacking = false;
            STATES->freezed = false;
            PLAYER->rect.top = 32;
            sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
            attack_racoon(all);
            attack_frog(all);
            attack_enemy(all);
        }
    } else {
        sfClock_restart(PLAYER->attack_clock);
    }
}

static
int augment_attack_next(all_t *all, int attack)
{
    if (PLAYER->xp >= 30 && attack == 2) {
        PLAYER->attack += 1;
        attack = 3;
    }
    if (PLAYER->xp >= 40 && attack == 3) {
        PLAYER->attack += 1;
        attack = 4;
    }
    if (PLAYER->xp >= 50 && attack == 4) {
        PLAYER->attack += 1;
        attack = 5;
    }
    return attack;
}

void augment_attack(all_t *all)
{
    static int attack = 0;

    if (PLAYER->xp >= 10 && attack == 0) {
        PLAYER->attack += 1;
        attack = 1;
    }
    if (PLAYER->xp >= 20 && attack == 1) {
        PLAYER->attack += 1;
        attack = 2;
    }
    attack = augment_attack_next(all, attack);
}

static
int attack(states_t *state, player_t *player)
{
    switch (state->direction) {
        case UP:
            player->rect.left = 16;
            break;
        case DOWN:
            player->rect.left = 0;
            break;
        case LEFT:
            player->rect.left = 32;
            break;
        case RIGHT:
            player->rect.left = 48;
            break;
    }
    return SUCCESS;
}

/**
* This function is used to handle the player attack
* @param all The struct containing the game
* @param x The x axis attack (1, -1)
* @param y The y axis attack (1, -1)
* @return SUCCESS
*/
int attack_player(all_t *all)
{
    PLAYER->anim_clock_sec =
        SF_SECONDS(sfClock_getElapsedTime(PLAYER->anim_clock));
    if (PLAYER->anim_clock_sec > 1.0 / ANIM_FPS) {
        attack(STATES, PLAYER);
        PLAYER->rect.top = 64;
        sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
        STATES->attacking = true;
        sfClock_restart(PLAYER->anim_clock);
    }
    return SUCCESS;
}
