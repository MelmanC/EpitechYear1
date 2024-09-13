/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** tmp.c
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
int set_ratio(all_t *all, int index, int last_path)
{
    int len_1 = all->paths[last_path]->len;
    int len_2 = all->paths[index]->len;

    return (len_1 - len_2) + 1;
}

static
void next_2(all_t *all, int index, int tmp, int nb_paths)
{
    for (int i = index; tmp > 0; i++) {
        all->paths[i]->nb_robots += 1;
        tmp -= 1;
        if (i == (index + nb_paths - 1))
            i = index - 1;
    }
}

static
int next(all_t *all, int *index, int tmp)
{
    int nb_paths = 1;
    int nb = 0;

    for (int i = *index + 1; all->paths[i] != NULL &&
        (all->paths[*index]->ratio == all->paths[i]->ratio); i++)
        nb_paths += 1;
    nb = all->paths[*index]->ratio * nb_paths;
    if (tmp >= nb) {
        for (int i = *index; i < *index + nb_paths; i++)
            all->paths[i]->nb_robots += all->paths[i]->ratio;
        tmp -= nb;
        *index += nb_paths - 1;
    } else {
        next_2(all, *index, tmp, nb_paths);
        tmp = 0;
    }
    return tmp;
}

static
void init_path(all_t *all)
{
    int tmp = all->map->nb_robot;
    int index = 0;

    while (1) {
        for (; tmp > 0 && all->paths[index] != NULL; index++)
            tmp = next(all, &index, tmp);
        if (tmp <= 0)
            return;
        index = 0;
    }
}

int set_inf_path(all_t *all)
{
    int last_path = nb_path(all) - 1;

    all->paths[last_path]->ratio = 1;
    for (int i = last_path - 1; i >= 0; i--)
        all->paths[i]->ratio = set_ratio(all, i, last_path);
    init_path(all);
    for (int i = last_path - 1; i >= 0; i--) {
        if (all->paths[i]->nb_robots == 0) {
            free(all->paths[i]);
            all->paths[i] = NULL;
        }
    }
    return SUCCESS;
}
