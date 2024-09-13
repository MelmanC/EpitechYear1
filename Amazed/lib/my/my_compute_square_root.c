/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** sqrt
*/

#include "include/my.h"

int my_compute_square_root(int nb)
{
    int j = 1;
    int calcul = 0;

    while (calcul < nb) {
        calcul = j * j;
        if (calcul == nb) {
            return j;
        }
        j++;
    }
    return 0;
}
