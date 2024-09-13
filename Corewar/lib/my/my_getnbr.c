/*
** EPITECH PROJECT, 2023
** my_get_nbr
** File description:
** getnbr
*/

#include "include/my.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int neg = 1;
    int i = 0;

    if (str[0] == '-') {
        neg = -1;
        i++;
    }
    for (; str[i] != '\0' && str[i] >= 48 && str[i] <= 57; i++) {
        nb = nb * 10 + (str[i] - '0');
    }
    return nb * neg;
}
