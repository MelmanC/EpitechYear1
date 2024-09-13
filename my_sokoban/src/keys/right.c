/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** right.c
*/

#include "../../include/my.h"
#include "../../include/printf.h"
#include "../../include/sokoban.h"
#include <curses.h>
#include <fcntl.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

static char **on_o(player_t *player, char **map)
{
    if (map[player->x][player->y + 1] == 'O') {
        map[player->x][player->y + 1] = 'P';
        map[player->x][player->y] = ' ';
        player->onO = 1;
    } else if (player->onO == 1) {
        map[player->x][player->y + 1] = 'P';
        map[player->x][player->y] = 'O';
        player->onO = 0;
    } else {
        map[player->x][player->y + 1] = 'P';
        map[player->x][player->y] = ' ';
    }
    return map;
}

char **right(player_t *player, char **map)
{
    if (map[player->x][player->y + 1] != '#') {
        if (map[player->x][player->y + 1] == 'X' &&
            map[player->x][player->y + 2] == 'X') {
            return 0;
        }
        if (map[player->x][player->y + 1] == 'X' &&
            map[player->x][player->y + 2] != '#') {
            map[player->x][player->y + 1] = 'P';
            map[player->x][player->y] = ' ';
            map[player->x][player->y + 2] = 'X';
        }
        if (map[player->x][player->y + 1] == 'X' &&
            map[player->x][player->y + 2] == '#') {
            return 0;
        }
        on_o(player, map);
    }
    return map;
}
