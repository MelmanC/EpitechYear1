/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** modify_map.c
*/

#include "../include/navy.h"
#include "../include/printf.h"
#include "../include/my.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

game_t *global_game;

static void att_handler(int signum)
{
    game_t *game = global_game;

    if (signum == SIGUSR1) {
        game->res = 1;
    }
    if (signum == SIGUSR2) {
        game->res = 2;
    }
}

static void kill_usr2(game_t *game)
{
    usleep(4000);
    kill(game->pid, SIGUSR2);
}

int map_modify(game_t *game)
{
    game->number += 1;
    game->alpha += 1;
    if (game->map[game->number][game->alpha * 2] == '.' ||
        game->map[game->number][game->alpha * 2] == 'o') {
        game->map[game->number][game->alpha * 2] = 'o';
        kill_usr2(game);
        my_printf(MISS, game->alpha + 'A' - 1, game->number + '0' - 1);
    } else if (game->map[game->number][game->alpha * 2] == 'x') {
        game->map[game->number][game->alpha * 2] = 'x';
        kill_usr2(game);
        my_printf(MISS, game->alpha + 'A' - 1, game->number + '0' - 1);
    } else {
        game->map[game->number][game->alpha * 2] = 'x';
        usleep(4000);
        kill(game->pid, SIGUSR1);
        my_printf(HIT, game->alpha + 'A' - 1, game->number + '0' - 1);
        game->hit2++;
    }
    return 0;
}

static void change_map(game_t *game)
{
    my_printf(MISS, game->alpha + 'A' - 1, game->number + '0' - 1);
    if (game->map2[game->number][game->alpha * 2] == '.')
        game->map2[game->number][game->alpha * 2] = 'o';
    else if (game->map2[game->number][game->alpha * 2] == 'x')
        game->map2[game->number][game->alpha * 2] = 'x';
}

int map_attack(game_t *game, char *pos)
{
    struct sigaction *atck = malloc(sizeof(struct sigaction));

    global_game = game;
    atck->sa_handler = att_handler;
    sigaction(SIGUSR1, atck, NULL);
    sigaction(SIGUSR2, atck, NULL);
    pause();
    game->alpha = pos[0] - 'A' + 1;
    game->number = pos[1] - '0' + 1;
    if (game->res == 1) {
        my_printf(HIT, game->alpha + 'A' - 1, game->number + '0' - 1);
        game->map2[game->number][game->alpha * 2] = 'x';
        game->hit++;
    } else if (game->res == 2) {
        change_map(game);
    }
    return 0;
}
