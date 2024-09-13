/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** cmp
*/

#include "include/my.h"

static int len(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int min_size = len(s1);
    int max_size = len(s2);

    for (int i = 0; i < max_size + 1; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return 0;
}
