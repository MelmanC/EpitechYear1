/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** connection.c
*/

#include "../include/navy.h"
#include "../include/printf.h"
#include "../include/my.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int player;

static void sig1(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1) {
        my_printf("enemy connected\n\n");
        player = info->si_pid;
    }
}

static int get_connection(game_t *game)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sig1;
    sigaction(SIGUSR1, &sa, NULL);
    my_printf("waiting for enemy connection...\n\n");
    pause();
    game->pid = player;
    return 0;
}

static int connection(game_t *game, char *av)
{
    pid_t pid1 = my_getnbr(av);

    if (kill(pid1, SIGUSR1) == -1)
        return 84;
    game->pid = pid1;
    my_printf("successfully connected\n\n");
    return 0;
}

int which_player(game_t *game, int ac, char **av)
{
    if (ac == 2) {
        get_connection(game);
        return 1;
    } else {
        if (connection(game, av[1]) == 84)
            return 84;
    }
    return 0;
}
