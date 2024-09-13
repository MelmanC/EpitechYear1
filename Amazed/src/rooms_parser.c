/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** main.c
*/

#include "../include/amazed.h"
#include "../include/printf.h"
#include "../include/my.h"
#include "../include/macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/*
Get the start and end room
*/
static
int get_room_start(all_t *all, int i, int j)
{
    if (all->map->map[i][j] == '#' && all->map->map[i][j + 1] == 's' &&
        NO_START_ROOM == 0) {
        all->maze->start = my_getnbr(all->map->map[i + 1]);
        NO_START_ROOM = 1;
        return 0;
    }
    if (all->map->map[i][j] == '#' && all->map->map[i][j + 1] == 's' &&
        NO_START_ROOM == 1)
        all->error = 1;
    if (all->map->map[i][j] == '#' && all->map->map[i][j + 1] == 'e' &&
        NO_END_ROOM == 0) {
        all->maze->end = my_getnbr(all->map->map[i + 1]);
        NO_END_ROOM = 1;
        return 0;
    }
    if (all->map->map[i][j] == '#' && all->map->map[i][j + 1] == 'e' &&
        NO_END_ROOM == 1)
        all->error = 1;
    return 0;
}

/*
Create the matrix and update it
*/
static
void matrix_start(all_t *all, int i, int j)
{
    static int pass = 0;

    if (TUNNEL == 1 && pass == 0) {
        all->matrix = create_matrix(NB_ROOMS);
        pass = 1;
    }
    if (TUNNEL == 1 && all->map->map[i][j] == '-') {
        update_matrix(all, my_getnbr(all->map->map[i]),
            my_getnbr(&all->map->map[i][j + 1]));
    }
}

/*
Check if the line is a tunnel
*/
static
int is_a_tunnel(char *str)
{
    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            return 1;
        }
    }
    return 0;
}

/*
Get error and number of rooms
*/
static
int parse_room(all_t *all, int i)
{
    int room = -1;
    int next_line = -1;

    if (my_strcmp(all->map->map[i], "##end") != 0 &&
        my_strcmp(all->map->map[i], "##start") != 0 && i != 0) {
        room = my_getnbr(all->map->map[i]);
        if (all->map->map[i + 1] != NULL && all->map->map[i + 1][0] != '#')
            next_line = my_getnbr(all->map->map[i + 1]);
    }
    if (room > -1 && is_a_tunnel(all->map->map[i]) == 0)
        NB_ROOMS++;
    if (next_line == -2)
        all->error = 1;
    return 0;
}

static
void pipe_next_line(all_t *all, int i, int j)
{
    int nbr_right = 0;
    int nbr_left = 0;

    if (TUNNEL == 1 && all->map->map[i + 1] != NULL &&
        all->map->map[i + 1][j] == '-') {
        if (all->map->map[i + 1] != NULL) {
            nbr_right = my_getnbr(all->map->map[i + 1]);
            nbr_left = my_getnbr(&all->map->map[i + 1][j + 1]);
        }
        if (nbr_right < 0 || nbr_left < 0 || nbr_right >= NB_ROOMS
            || nbr_left >= NB_ROOMS)
            all->error = 1;
    }
}

void get_rooms(all_t *all, int i)
{
    if (is_a_tunnel(all->map->map[i + 1]) == 1)
        TUNNEL = 1;
    my_printf("%s\n", all->map->map[i]);
    display_need(all);
    parse_room(all, i);
    for (int j = 0; all->map->map[i][j] != '\0'; j++) {
        matrix_start(all, i, j);
        get_room_start(all, i, j);
        pipe_next_line(all, i, j);
    }
}
