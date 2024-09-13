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
Return error after parsing line per line
*/
static
int error_on_parser(all_t *all)
{
    if (NO_START_AFTER == -2 || NO_END_AFTER == -2)
        return ERROR;
    if (all->error == 1)
        return ERROR;
    return 0;
}

/*
Check error at the end of the file
*/
static
int error_end_file(all_t *all)
{
    if (NO_TUNNEL == 0)
        return ERROR;
    if (NO_START_ROOM == 0 || NO_END_ROOM == 0)
        return ERROR;
    return 0;
}

/*
Beginning of the parser, and write some comments
*/
int begin_parser(all_t *all)
{
    if (get_robots(all) == ERROR)
        return ERROR;
    for (int i = 0; all->map->map[i] != NULL; i++) {
        get_rooms(all, i);
        if (error_on_parser(all) == ERROR)
            return ERROR;
    }
    my_printf("#moves\n");
    if (error_end_file(all) == ERROR)
        return ERROR;
    return 0;
}
