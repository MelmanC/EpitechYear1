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
Get the number of robots
*/
static
int get_number_of_robots(all_t *all)
{
    if (all->map->map[0] == NULL)
        return 84;
    all->map->nb_robot = my_getnbr(all->map->map[0]);
    if (all->map->nb_robot < 1)
        return 84;
    if (all->map->map[1] == NULL) {
        all->error = 1;
        return 0;
    }
    if (all->map->map[1][0] != '#')
        all->map->line_next = my_getnbr(all->map->map[1]);
    if (all->map->line_next == -2)
        all->error = 1;
    return 0;
}

/*
Get number of robots
*/
int get_robots(all_t *all)
{
    my_printf("#number_of_robots\n");
    if (get_number_of_robots(all) == ERROR)
        return ERROR;
    return 0;
}
