/*
** EPITECH PROJECT, 2023
** strncat
** File description:
** ncat
*/

#include "include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int size_1 = my_strlen(dest);
    int size_2 = my_strlen(src);
    int j = 0;

    for (int i = size_1; i < size_2 + nb - 1; i++) {
        dest[i] = src[j];
        j++;
    }
    return dest;
}
