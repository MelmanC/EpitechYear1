/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** swap
*/

#include "include/my.h"

int my_swap(int *a, int *b)
{
    int c = 0;

    c = *a;
    *a = *b;
    *b = c;
    return 0;
}
