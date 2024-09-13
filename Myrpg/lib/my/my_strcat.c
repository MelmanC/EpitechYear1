/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** function my_strcat
*/

#include <stddef.h>
#include <stdlib.h>
#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int j = 0;
    int len = my_strlen(dest);
    int len_src = my_strlen(src);
    char *res = malloc(sizeof(char) * (len + len_src + 1));

    for (int i = 0; dest[i] != '\0'; i += 1)
        res[i] = dest[i];
    for (; src[j] != '\0'; j += 1)
        res[j + len] = src[j];
    res[j + len] = '\0';
    return res;
}
