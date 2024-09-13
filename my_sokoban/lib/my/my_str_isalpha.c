/*
** EPITECH PROJECT, 2023
** isalpha
** File description:
** alpha
*/

#include "include/my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122) {
        } else {
            return 0;
        }
    }
    return 1;
}
