/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** count.c
*/

#include "../include/printf.h"
#include "../include/my.h"
#include "../include/sokoban.h"
#include <unistd.h>

static int cout_x_next(char **map, int i, int k, int compteur)
{
    if (map[i][k] == 'X') {
        compteur++;
    }
    return compteur;
}

int count_x(char **map)
{
    int compteur = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int k = 0; map[i][k] != '\0'; k++) {
            compteur = cout_x_next(map, i, k, compteur);
        }
    }
    return compteur;
}

static int cout_o_next(char **map, int i, int k, int compteur)
{
    if (map[i][k] == 'O') {
        compteur++;
    }
    return compteur;
}

int count_o(char **map)
{
    int compteur = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int k = 0; map[i][k] != '\0'; k++) {
            compteur = cout_o_next(map, i, k, compteur);
        }
    }
    return compteur;
}
