/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** navy.c
*/

#include "../include/navy.h"
#include "../include/printf.h"
#include "../include/my.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static int error_handle(int ac, game_t *game, char **av)
{
    if (open_map(game) == 84)
        return 84;
    if (ac == 3) {
        if (put_position(game, av[2]) == 84)
            return 84;
        game->distinction = 2;
    }
    if (ac == 2) {
        if (put_position(game, av[1]) == 84)
            return 84;
        game->distinction = 1;
    }
    return 0;
}

static void ini_game(game_t *game)
{
    game->hit = 0;
    game->hit2 = 0;
    game->player = 0;
    game->player = 0;
    game->alpha = 0;
    game->number = 0;
    game->usr2 = 0;
    game->res = 0;
    game->distinction = 0;
}

int main(int ac, char **av)
{
    pid_t pid = getpid();
    game_t *game = malloc(sizeof(game_t));

    if (ac > 3 || ac < 2)
        return 84;
    ini_game(game);
    if (error_handle(ac, game, av) == 84)
        return 84;
    my_printf("my_pid: %d\n\n", pid);
    game->player = which_player(game, ac, av);
    if (game->player == 84)
        return 84;
    game_while(game);
    return 0;
}
