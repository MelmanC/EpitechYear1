/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** right.c
*/

#include "../../include/printf.h"
#include "../../include/my.h"
#include "../../include/sokoban.h"
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>

static char **on_o(player_t *player, char **map)
{
    if (map[player->x - 1][player->y] == 'O') {
        map[player->x - 1][player->y] = 'P';
        map[player->x][player->y] = ' ';
        player->onO = 1;
    } else if (player->onO == 1) {
        map[player->x - 1][player->y] = 'P';
        map[player->x][player->y] = 'O';
        player->onO = 0;
    } else {
        map[player->x - 1][player->y] = 'P';
        map[player->x][player->y] = ' ';
    }
    return map;
}

char **go_up(player_t *player, char **map)
{
    if (map[player->x - 1][player->y] != '#') {
        if (map[player->x - 1][player->y] == 'X' &&
            map[player->x - 2][player->y] == 'X') {
            return 0;
        }
        if (map[player->x - 1][player->y] == 'X' &&
            map[player->x - 2][player->y] != '#') {
            map[player->x - 1][player->y] = 'P';
            map[player->x][player->y] = ' ';
            map[player->x - 2][player->y] = 'X';
        }
        if (map[player->x - 1][player->y] == 'X' &&
            map[player->x - 2][player->y] == '#') {
            return 0;
        }
        on_o(player, map);
    }
    return map;
}
