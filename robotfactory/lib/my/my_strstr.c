/*
** EPITECH PROJECT, 2023
** str
** File description:
** str
*/

#include "include/my.h"
#include <string.h>

static int len2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

static int cmp(char const *s1, char const *s2, int max)
{
    for (int i = 0; i < max; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    int min = len2(str);
    int max = len2(to_find);
    int j = 0;

    if (max == 0) {
        return str;
    }
    for (int i = 0; i < min; i++) {
        if (str[i] == to_find[0]) {
            j = cmp(&str[i], to_find, max);
        }
        if (j == 1) {
            return &str[i];
        }
    }
    return NULL;
}
