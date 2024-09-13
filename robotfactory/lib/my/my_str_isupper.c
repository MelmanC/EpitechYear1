/*
** EPITECH PROJECT, 2023
** isupper
** File description:
** upper
*/

#include "include/my.h"

int my_str_isupper(char const *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 65 && str[i] <= 90) {
        } else {
            return 0;
        }
    }
    return 1;
}
