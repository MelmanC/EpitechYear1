/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** amazed.c
*/

#include "../include/amazed.h"
#include "../include/printf.h"
#include "../include/my.h"
#include "../include/macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static
void free_all(all_t *all)
{
    for (int i = 0; all->map->map[i] != NULL; i++) {
        free(all->map->map[i]);
    }
    free(all->map->map);
    free(all->map);
    free(all->maze);
    if (all->matrix != NULL) {
        for (int i = 0; all->matrix[i] != NULL; i++)
            free(all->matrix[i]);
        free(all->matrix);
    }
    free(all);
}

/*
Initialize any struct
*/
static
void ini_struct(all_t *all)
{
    all->map = malloc(sizeof(map_t));
    all->maze = malloc(sizeof(maze_t));
    all->algo = malloc(sizeof(algo_t));
    all->paths = NULL;
    all->error = 0;
    all->map->line_next = -1;
    all->map->nb_robot = 0;
    all->maze->pass_start = 0;
    all->maze->start = -1;
    all->maze->end = -1;
    all->maze->pass_end = 0;
    all->maze->nb_rooms = 0;
    all->maze->is_tunnel = 0;
    all->matrix = NULL;
    all->arr_idx = 0;
}

/*
Amazed main function
*/
int amazed(void)
{
    all_t *all = malloc(sizeof(all_t));

    ini_struct(all);
    if (open_file(all) == ERROR)
        return ERROR;
    if (begin_parser(all))
        return ERROR;
    if (find_all_paths(all) == ERROR)
        return ERROR;
    if (bubble_sort_arr(all) == ERROR)
        return ERROR;
    clear_path(all);
    set_inf_path(all);
    display_moove(all);
    free_all(all);
    return 0;
}
