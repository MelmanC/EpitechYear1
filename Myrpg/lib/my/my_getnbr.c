/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** function my_getnbr
*/

#include <stdio.h>
#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int number = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= '0' && str[i] <= '9') {
            number *= 10;
            number += str[i] - '0';
        } else
            return 84;
    }
    return number;
}
