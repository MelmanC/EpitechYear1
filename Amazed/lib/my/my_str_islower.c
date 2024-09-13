/*
** EPITECH PROJECT, 2023
** islower
** File description:
** lower
*/

#include "include/my.h"

int my_str_islower(char const *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 97 && str[i] <= 122) {
        } else {
            return 0;
        }
    }
    return 1;
}
