/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** get.c
*/

#include "../include/printf.h"
#include "../include/my.h"
#include "../include/sokoban.h"
#include <unistd.h>

int get_line(char *buff)
{
    int lines = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            lines++;
        }
    }
    return lines;
}

static int is_win_next(char **map, char **map_ini, int i, player_t *player)
{
    for (int k = 0; map[i][k] != '\0'; k++) {
        if (map[i][k] == 'X' && map_ini[i][k] == 'O') {
            player->cmpo++;
        }
        if (player->cmpo == player->compteur) {
            return 1;
        }
    }
    return 0;
}

int is_win(char **map, char **map_ini, player_t *player)
{
    player->cmpo = 0;
    for (int i = 0; map[i] != NULL; i++) {
        if (is_win_next(map, map_ini, i, player) == 1)
            return 0;
    }
    return 1;
}

static int is_def_next(char **map, int i, player_t *player)
{
    for (int k = 0; map[i][k] != '\0'; k++) {
        if (map[i][k] == 'X' && ((map[i][k + 1] == '#'
        && map[i + 1][k] == '#')
        || (map[i][k + 1] == '#' && map[i - 1][k] == '#')
        || (map[i][k - 1] == '#' && map[i + 1][k] == '#')
        || (map[i][k - 1] == '#' && map[i - 1][k] == '#'))) {
            player->cmptd++;
        }
    }
    return 0;
}

int is_defeat(char **map, player_t *player)
{
    player->cmptd = 0;
    for (int i = 0; map[i] != NULL; i++) {
        is_def_next(map, i, player);
    }
    if (player->cmptd == player->cmpx)
        return 1;
    return 0;
}

static int valid_next(char **map, int i)
{
    for (int k = 0; map[i][k] != '\0'; k++) {
        if (map[i][k] != 'P' && map[i][k] != 'O'
            && map[i][k] != '#' && map[i][k] != ' ' && map[i][k] != 'X')
            return 84;
    }
    return 0;
}

int is_valid(char **map, player_t *player)
{
    if (player->cmpx != player->compteur)
        return 84;
    for (int i = 0; map[i] != NULL; i++) {
        if (valid_next(map, i) == 84)
            return 84;
    }
    return 0;
}

int width(char **map)
{
    int max_width = 0;
    int width = 0;

    for (int i = 0; map[i] != NULL; i++) {
        width = 0;
        for (int j = 0; map[i][j] != '\0'; j++)
            width++;
        if (width > max_width)
            max_width = width;
    }
    return max_width;
}
