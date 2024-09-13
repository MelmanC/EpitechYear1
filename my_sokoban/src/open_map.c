/*
** EPITECH PROJECT, 2023
** PSU-100
** File description:
** open_map.c
*/

#include "../include/printf.h"
#include "../include/my.h"
#include "../include/sokoban.h"
#include <curses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>

char **copy_map(int lines, char *buff, char **map)
{
    int a = 0;
    int end = 0;
    char *temp = NULL;

    temp = malloc(sizeof(char) * (my_strlen(buff) + 1));
    my_strcpy(temp, buff);
    for (int i = 0; i < lines; i++) {
        end = a;
        while (temp[end] != '\n')
            end++;
        temp[end] = '\0';
        map[i] = my_strdup(&temp[a]);
        a = end + 1;
    }
    return map;
}

static void display_next(char **map, int i, int k, player_t *player)
{
    mvprintw(i + player->start_y, k + player->start_x, "%c", map[i][k]);
    if (map[i][k] == 'P') {
        player->x = i;
        player->y = k;
    }
}

static char **display_map(player_t *player, char **map)
{
    clear();
    for (int i = 0; map[i] != NULL; i++) {
        for (int k = 0; map[i][k] != '\0'; k++) {
            display_next(map, i, k, player);
        }
    }
    return map;
}

static void pos_window(player_t *player, char **map)
{
    player->start_x = (COLS - width(map)) / 2;
    player->start_y = (LINES - player->line) / 2;
}

static int game_status(char **map, char **map_ini, player_t *player)
{
    if (is_win(map, map_ini, player) == 0) {
        usleep(1000000);
        endwin();
        return 3;
    }
    if (is_defeat(map, player) == 1) {
        endwin();
        return 1;
    }
    return 0;
}

static int while_next(char **map, char **map_ini, player_t *player, char *buff)
{
    int a = 0;

    pos_window(player, map);
    display_map(player, map);
    while (a != 23) {
        a = game_status(map, map_ini, player);
        if (a == 1)
            return 1;
        if (a == 3)
            return 0;
        is_on_o(map, map_ini);
        a = move_player(player, map, buff);
        pos_window(player, map);
        display_map(player, map);
        refresh();
    }
    return 0;
}

static void ini_player(player_t *player, char *buff)
{
    player->line = get_line(buff);
    player->x = 0;
    player->y = 0;
}

static void destroy(char **map, char **map_ini)
{
    endwin();
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
        free(map_ini[i]);
    }
    free(map);
    free(map_ini);
}

static int display(char *buff)
{
    player_t player;
    char **map = NULL;
    char **map_ini = NULL;

    ini_player(&player, buff);
    map = malloc(sizeof(char *) * (player.line + 1));
    map_ini = malloc(sizeof(char *) * (player.line + 1));
    map = copy_map(player.line, buff, map);
    map_ini = copy_map(player.line, buff, map_ini);
    player.compteur = count_o(map_ini);
    player.cmpx = count_x(map);
    if (is_valid(map, &player) == 84)
        return 84;
    initscr();
    curs_set(0);
    keypad(stdscr, true);
    if (while_next(map, map_ini, &player, buff) == 1)
        return 1;
    destroy(map, map_ini);
    return 0;
}

int open_map(char *av)
{
    int fd = 0;
    char *buff = NULL;
    struct stat st;
    int size = 0;
    int a = 0;

    stat(av, &st);
    size = st.st_size;
    fd = open(av, O_RDONLY);
    if (fd == -1)
        return 84;
    buff = malloc(sizeof(char) * (size + 1));
    read(fd , buff, size);
    a = display(buff);
    if (a == 1)
        return 1;
    if (a == 84)
        return 84;
    close(fd);
    return 0;
}
