/*
** EPITECH PROJECT, 2023
** isprintable
** File description:
** printable
*/

#include "include/my.h"

int my_str_isprintable(char const *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122 ||
            str[i] >= 48 && str[i] <= 57) {
        } else {
            return 0;
        }
    }
    return 1;
}
