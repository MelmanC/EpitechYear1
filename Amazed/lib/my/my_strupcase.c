/*
** EPITECH PROJECT, 2023
** upcase
** File description:
** up
*/

#include "include/my.h"

static int len3(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strupcase(char *str)
{
    int size = len3(str);

    for (int i = 0; i < size; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
