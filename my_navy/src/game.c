/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** game.c
*/

#include "../include/navy.h"
#include "../include/printf.h"
#include "../include/my.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

game_t *glob;

static void change_state(game_t *game)
{
    game->alpha = 0;
    game->number = 0;
    game->player = 1;
}

static void def_handler(int signum)
{
    game_t *game = glob;

    if (signum == SIGUSR2)
        game->usr2 = 1;
}

static void receive(game_t *game)
{
    struct sigaction *sa = malloc(sizeof(struct sigaction));

    sa->sa_handler = def_handler;
    sigaction(SIGUSR1, sa, NULL);
    sigaction(SIGUSR2, sa, NULL);
    game->usr2 = 0;
    while (game->usr2 != 1) {
        pause();
        game->alpha++;
    }
    game->usr2 = 0;
    while (game->usr2 != 1) {
        pause();
        game->number++;
    }
    game->alpha--;
    game->number--;
    map_modify(game);
}

static void player_in_wait(game_t *game, int i)
{
    if (i != 0 && game->distinction == 2)
        display(game);
    my_printf("waiting for enemy's attack...\n\n");
    usleep(4000);
    receive(game);
    usleep(4000);
    change_state(game);
}

static void player_in_attack(game_t *game, int i)
{
    if (i != 0 && game->distinction == 1)
        display(game);
    attack(game);
    usleep(4000);
    game->player = 0;
    game->alpha = 0;
    game->number = 0;
}

int game_while(game_t *game)
{
    int i = 0;

    glob = game;
    display(game);
    while (game->hit != 14 && game->hit2 != 14) {
        if (game->player == 1) {
            player_in_attack(game, i);
        } else {
            player_in_wait(game, i);
        }
        i++;
    }
    display(game);
    if (game->hit == 14)
        my_printf("I won\n");
    else if (game->hit2 == 14)
        my_printf("Enemy won\n");
    return 0;
}
