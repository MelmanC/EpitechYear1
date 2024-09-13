/*
** EPITECH PROJECT, 2023
** PSU-100
** File description:
** play.c
*/

#include "../include/printf.h"
#include "../include/my.h"
#include "../include/sokoban.h"
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>

int move_player(player_t *player, char **map, char *buff)
{
    int c = 0;

    c = getch();
    if (c == KEY_UP) {
        go_up(player, map);
    }
    if (c == KEY_DOWN) {
        down(player, map);
    }
    if (c == KEY_LEFT) {
        left(player, map);
    }
    if (c == KEY_RIGHT) {
        right(player, map);
    }
    if (c == ' ')
        map = copy_map(player->line, buff, map);
    if (c == 'q')
        return 23;
    return 0;
}
