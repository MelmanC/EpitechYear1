/*
** EPITECH PROJECT, 2023
** my_get_nbr
** File description:
** getnbr
*/

#include "include/my.h"

static
int my_getnbr_next(char const *str, int i, int nb)
{
    if (str[i] < 48 || str[i] > 57) {
        if (i == 0)
            return -2;
        return nb;
    }
    return -1;
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int neg = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_getnbr_next(str, i, nb) != -1)
            return my_getnbr_next(str, i, nb);
        if (str[i] >= 48 && str[i] <= 57) {
            nb *= 10;
            nb += str[i] - '0';
        }
        if (str[i] >= 97 && str[i - 1] >= 48 && str[i - 1] <= 57) {
            nb *= neg;
            return nb;
        }
    }
    nb *= neg;
    return nb;
}
