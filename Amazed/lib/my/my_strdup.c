/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** strdup
*/

#include <stdlib.h>
#include "include/my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest = NULL;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(dest, src);
    return dest;
}
