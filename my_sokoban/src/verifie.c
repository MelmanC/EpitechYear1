/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** verifie.c
*/

#include "../include/sokoban.h"
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <ncurses.h>

char **is_next(char **map, char **map_ini, int i)
{
    for (int k = 0; map_ini[i][k] != '\0'; k++) {
        if (map_ini[i][k] == 'O' && map[i][k] == ' ') {
            map[i][k] = 'O';
        }
    }
    return map;
}

char **is_on_o(char **map, char **map_ini)
{
    for (int i = 0; map_ini[i] != NULL; i++) {
        is_next(map, map_ini, i);
    }
    return map;
}
