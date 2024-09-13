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
int room(int room, int *path_2)
{
    for (int l = 1; path_2[l + 1] != -1; l++) {
        if (room == path_2[l])
            return 1;
    }
    return 0;
}

static
int path(int *path_1, int *path_2)
{
    for (int k = 1; path_1[k + 1] != -1; k++) {
        if (room(path_1[k], path_2) == 1)
            return 1;
    }
    return 0;
}

static
void colision(all_t *all, int j)
{
    for (int k = j; all->paths[k] != NULL; k++)
        all->paths[k] = all->paths[k + 1];
}

static
int verif_colision(all_t *all, int i)
{
    for (int j = i + 1; all->paths[j] != NULL; j++) {
        if (path(all->paths[i]->path, all->paths[j]->path) == 1) {
            free(all->paths[j]);
            colision(all, j);
            j--;
        }
    }
    return 0;
}

int clear_path(all_t *all)
{
    for (int i = 0; all->paths[i] != NULL; i++)
        verif_colision(all, i);
    return 0;
}
