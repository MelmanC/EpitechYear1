/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** display_moove.c
*/

#include "amazed.h"
#include "printf.h"
#include "my.h"
#include "macro.h"
#include <stdio.h>
#include <stdlib.h>

static
int nb_path(all_t *all)
{
    int nb = 0;

    for (int i = 0; all->paths[i] != NULL; i++)
        nb += 1;
    return nb;
}

static
void case_1_1(all_t *all, int *values, int *sep, int *tmp)
{
    for (int j = LOOP; j > 0; j--) {
        my_printf("P%d-%d", NUM_ROBOTS, all->paths[INDEX]->path[j]);
        if (((j - 1) > 0) || all->paths[INDEX + 1] != NULL)
            my_printf(" ");
        NUM_ROBOTS += *sep;
        if (all->paths[INDEX]->path[j] == all->maze->end) {
            all->paths[INDEX]->arrived += 1;
            *tmp += 1;
        }
        if (all->paths[INDEX]->arrived == all->paths[INDEX]->nb_robots)
            *sep -= 1;
    }
}

static
void case_1_2(all_t *all, int *values, int *sep, int *tmp)
{
    for (int j = LOOP; j > LOOP - all->paths[INDEX]->nb_robots; j--) {
        my_printf("P%d-%d", NUM_ROBOTS, all->paths[INDEX]->path[j]);
        if ((j - 1) > LOOP - all->paths[INDEX]->nb_robots ||
            all->paths[INDEX + 1] != NULL)
            my_printf(" ");
        NUM_ROBOTS += *sep;
        if (all->paths[INDEX]->path[j] == all->maze->end) {
            all->paths[INDEX]->arrived += 1;
            *tmp += 1;
        }
        if (all->paths[INDEX]->arrived == all->paths[INDEX]->nb_robots)
            *sep -= 1;
    }
}

static
void case_1(all_t *all, int *values, int *sep, int *tmp)
{
    if (LOOP - all->paths[INDEX]->nb_robots < 0) {
        case_1_1(all, values, sep, tmp);
    } else {
        case_1_2(all, values, sep, tmp);
    }
}

static
void case_2_1(all_t *all, int *values, int *sep, int *tmp)
{
    for (int j = all->paths[INDEX]->len - 1; j > 0; j--) {
        my_printf("P%d-%d", NUM_ROBOTS, all->paths[INDEX]->path[j]);
        NUM_ROBOTS += *sep;
        if (((j - 1) > 0) || (all->paths[INDEX + 1] != NULL))
            my_printf(" ");
        if (all->paths[INDEX]->path[j] == all->maze->end) {
            all->paths[INDEX]->arrived += 1;
            *tmp += 1;
        }
        if (all->paths[INDEX]->arrived == all->paths[INDEX]->nb_robots)
            *sep -= 1;
    }
}

static
void case_2_2(all_t *all, int *values, int *sep, int *tmp)
{
    for (int j = all->paths[INDEX]->len - 1;
    j > LOOP - all->paths[INDEX]->nb_robots; j--) {
        my_printf("P%d-%d", NUM_ROBOTS, all->paths[INDEX]->path[j]);
        if (((j - 1) > LOOP - all->paths[INDEX]->nb_robots) ||
            all->paths[INDEX + 1] != NULL)
            my_printf(" ");
        NUM_ROBOTS += *sep;
        if (all->paths[INDEX]->path[j] == all->maze->end) {
            all->paths[INDEX]->arrived += 1;
            *tmp += 1;
        }
        if (all->paths[INDEX]->arrived == all->paths[INDEX]->nb_robots)
            *sep -= 1;
    }
}

static
void case_2(all_t *all, int *values, int *sep, int *tmp)
{
    if (LOOP - all->paths[INDEX]->nb_robots < 0) {
        case_2_1(all, values, sep, tmp);
    } else {
        case_2_2(all, values, sep, tmp);
    }
}

static
void first_step(all_t *all, int loop, int *sep, int *tmp)
{
    int num_robots = *tmp + 1;
    int values[3] = {loop, 0, 0};

    for (int i = 0; all->paths[i] != NULL; i++) {
        INDEX = i;
        NUM_ROBOTS = num_robots + INDEX;
        if (all->paths[i]->arrived == all->paths[i]->nb_robots) {
            free(all->paths[i]);
            all->paths[i] = NULL;
            continue;
        }
        if (loop < all->paths[i]->len) {
            case_1(all, values, sep, tmp);
        } else {
            case_2(all, values, sep, tmp);
        }
    }
}

int display_moove(all_t *all)
{
    int loop = 1;
    int tmp = 0;
    int sep = nb_path(all);

    for (int i = 0; all->paths[i] != NULL; i++)
        all->paths[i]->arrived = 0;
    while (tmp < all->map->nb_robot) {
        first_step(all, loop, &sep, &tmp);
        my_printf("\n");
        loop += 1;
    }
    return 0;
}
