/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** my_strdup function
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(const char *str)
{
    int len = my_strlen(str);
    char *new_str = malloc((len + 1) * sizeof(char));

    if (new_str == NULL) {
        return NULL;
    }
    for (int i = 0; i <= len; i++) {
        new_str[i] = str[i];
    }
    return new_str;
}
