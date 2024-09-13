/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** strncpy
*/

#include "include/my.h"

static int len8(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int size = len8(src);
    int i = 0;

    for (i; i < n; i++) {
        dest[i] = src[i];
    }
    if (n > size) {
        dest[i] = '\0';
    }
    return (dest);
}
