/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** hit.c
*/

#include "../include/navy.h"
#include "../include/printf.h"
#include "../include/my.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void trigger(game_t *game, char *pos)
{
    for (int i = 0; i < pos[0] - 'A'; i++) {
        kill(game->pid, SIGUSR1);
        usleep(4000);
    }
    kill(game->pid, SIGUSR2);
    usleep(4000);
    for (int i = 0; i < pos[1] - '0'; i++) {
        kill(game->pid, SIGUSR1);
        usleep(4000);
    }
    kill(game->pid, SIGUSR2);
}

int attack(game_t *game)
{
    char *pos = NULL;
    size_t len = 0;

    my_printf("attack: ");
    getline(&pos, &len, stdin);
    if (pos[0] < 'A' || pos[0] > 'H' ||
        pos[1] < '1' || pos[1] > '8') {
        my_printf("\nwrong position\n\n");
        my_printf("attack: ");
        getline(&pos, &len, stdin);
    }
    my_printf("\n");
    trigger(game, pos);
    map_attack(game, pos);
    free(pos);
    return 0;
}
