/*
** EPITECH PROJECT, 2023
** low
** File description:
** low
*/

#include "include/my.h"

static int len4(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strlowcase(char *str)
{
    int size = len4(str);

    for (int i = 0; i < size; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
        }
    }
    return str;
}
