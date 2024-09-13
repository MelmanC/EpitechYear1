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
    int min_size = len1(s1);
    int max_size = len1(s2);

    if (min_size < max_size) {
        return -1;
    }
    if (min_size > max_size) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return 0;
}
