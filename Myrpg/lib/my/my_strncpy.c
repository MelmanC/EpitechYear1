/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** function my_strncpy
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len = my_strlen(src);

    for (i = 0; i < n; i += 1)
        dest[i] = src[i];
    if (n > len)
        dest[i] = '\0';
    return dest;
}
