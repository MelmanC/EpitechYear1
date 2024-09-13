/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** display_map.c
*/

#include "../include/navy.h"
#include "../include/printf.h"
#include "../include/my.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static int display_enemy(game_t *game)
{
    my_printf("enemy navy:\n");
    for (int i = 0; game->map2[i] != NULL; i++) {
        for (int j = 0; game->map2[i][j] != '\0'; j++) {
            my_printf("%c", game->map2[i][j]);
        }
        my_printf("\n");
    }
    my_printf("\n");
    return 0;
}

static int display_player(game_t *game)
{
    my_printf("my navy:\n");
    for (int i = 0; game->map[i] != NULL; i++) {
        for (int j = 0; game->map[i][j] != '\0'; j++) {
            my_printf("%c", game->map[i][j]);
        }
        my_printf("\n");
    }
    my_printf("\n");
    return 0;
}

int display(game_t *game)
{
    display_player(game);
    display_enemy(game);
    return 0;
}
