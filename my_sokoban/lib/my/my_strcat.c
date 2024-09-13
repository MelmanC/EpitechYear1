/*
** EPITECH PROJECT, 2023
** strcat
** File description:
** cat
*/

#include "include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int size_1 = my_strlen(dest);
    int size_2 = my_strlen(src);
    int j = 0;

    for (int i = size_1; i <= size_1 + size_2; i++) {
        dest[i] = src[j];
        j++;
    }
    return dest;
}
