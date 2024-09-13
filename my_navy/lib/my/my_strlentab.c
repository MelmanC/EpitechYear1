/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my_strlentab.c
*/

#include "include/my.h"
#include <stdio.h>

int my_strlentab(char **dir)
{
    int compteur = 0;

    for (int i = 0; dir[i] != NULL; i++) {
        compteur++;
    }
    return compteur;
}
