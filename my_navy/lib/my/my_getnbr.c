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

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57) {
            return nb;
        }
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
