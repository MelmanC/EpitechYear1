/*
** EPITECH PROJECT, 2024
** src
** File description:
** algorithm_dfs
*/

#include "amazed.h"
#include "printf.h"
#include "macro.h"
#include <stdlib.h>
#include <unistd.h>

static
void fill_array(paths_t **new, all_t *all)
{
    if (all->paths != NULL)
        for (int i = 0; all->paths[i] != NULL; i ++) {
            new[i]->path = all->paths[i]->path;
            new[i]->len = all->paths[i]->len;
            new[i]->ratio = all->paths[i]->ratio;
            new[i]->nb_robots = all->paths[i]->nb_robots;
        }
}

static
void init_last_node(paths_t **new, all_t *all)
{
    new[all->arr_idx]->len = all->algo->path_idx;
    new[all->arr_idx]->ratio = 0;
    new[all->arr_idx]->nb_robots = 0;
    new[all->arr_idx]->path[all->algo->path_idx] = -1;
}

static
paths_t **init_paths(all_t *all)
{
    paths_t **new = NULL;

    new = malloc(sizeof(paths_t *) * (all->arr_idx + 2));
    for (int i = 0; i < all->arr_idx; i ++) {
        new[i] = malloc(sizeof(paths_t));
        new[i]->path = NULL;
        new[i]->len = 0;
        new[i]->ratio = 0;
        new[i]->nb_robots = 0;
    }
    new[all->arr_idx + 1] = NULL;
    return new;
}

static
int add_in_array(all_t *all)
{
    paths_t **new = NULL;

    new = init_paths(all);
    if (!new)
        return ERROR;
    fill_array(new, all);
    new[all->arr_idx] = malloc(sizeof(paths_t) * (all->algo->path_idx + 1));
    if (!new[all->arr_idx])
        return ERROR;
    new[all->arr_idx]->path = malloc(sizeof(int) * (all->algo->path_idx + 2));
    for (int i = 0; i < all->algo->path_idx; i ++)
        new[all->arr_idx]->path[i] = all->algo->path[i];
    init_last_node(new, all);
    new[all->arr_idx + 1] = NULL;
    all->arr_idx += 1;
    if (all->paths)
        free(all->paths);
    all->paths = new;
    return SUCCESS;
}

static
int do_recursion(all_t *all, int node)
{
    for (int i = 0; i < NB_ROOMS; i++) {
        if (all->matrix[node][i] == 1 && all->algo->visited[i] == 0) {
            dfs(all, i);
        }
    }
    return SUCCESS;
}

int dfs(all_t *all, int node)
{
    all->algo->visited[node] = 1;
    all->algo->path[all->algo->path_idx] = node;
    all->algo->path_idx++;
    if (node == all->maze->end) {
        if (add_in_array(all) == ERROR)
            return ERROR;
    } else {
        do_recursion(all, node);
    }
    all->algo->path_idx--;
    all->algo->visited[node] = 0;
    return SUCCESS;
}

int find_all_paths(all_t *all)
{
    if (!all)
        return ERROR;
    all->algo->visited = malloc(sizeof(int) * (NB_ROOMS + 1));
    all->algo->path = malloc(sizeof(int) * (NB_ROOMS + 1));
    all->algo->path_idx = 0;
    for (int i = 0; i < NB_ROOMS; i++) {
        all->algo->visited[i] = 0;
    }
    if (dfs(all, all->maze->start) == ERROR) {
        free(all->algo->visited);
        free(all->algo->path);
        return ERROR;
    }
    free(all->algo->visited);
    free(all->algo->path);
    return SUCCESS;
}

static
void check_sort(all_t *all, int i)
{
    paths_t *tmp = NULL;

    for (int j = i + 1; all->paths[j] != NULL; j ++) {
        if (all->paths[i]->len > all->paths[j]->len) {
            tmp = all->paths[i];
            all->paths[i] = all->paths[j];
            all->paths[j] = tmp;
        }
    }
}

int bubble_sort_arr(all_t *all)
{
    if (!all || !all->paths || !all->paths[0])
        return ERROR;
    for (int i = 0; all->paths[i] != NULL; i ++) {
        check_sort(all, i);
    }
    return SUCCESS;
}
