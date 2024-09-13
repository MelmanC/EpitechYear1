/*
** EPITECH PROJECT, 2023
** isnum
** File description:
** num
*/

#include "include/my.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 48 && str[i] <= 57) {
        } else {
            return 0;
        }
    }
    return 1;
}
