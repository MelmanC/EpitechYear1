/*
** EPITECH PROJECT, 2023
** mystrncmp
** File description:
** cmp
*/

#include "include/my.h"

static int len1(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (len1(s1) < n || len1(s2) < n)
        return (84);
    while (i < n) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return 0;
}
