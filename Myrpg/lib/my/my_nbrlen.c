/*
** EPITECH PROJECT, 2023
** my_nbrlen
** File description:
** function to calculate the
** length of a number
*/

#include "../../include/my.h"
#include <stdio.h>

int my_nbrlen(int nb)
{
    int count = 0;

    if (nb < 0)
        count += 1;
    while (nb != 0) {
        nb /= 10;
        count += 1;
    }
    return count;
}
