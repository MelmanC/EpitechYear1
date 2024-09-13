/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** function my_strcmp
*/

#include "../../include/my.h"

int cmp_char(char const *s1, char const *s2, int len_s1, int len_s2)
{
    for (int i = 0; i < len_s1; i += 1) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);

    if (len_s1 == len_s2) {
        return (cmp_char(s1, s2, len_s1, len_s2));
    }
    if (len_s1 != len_s2) {
        return (len_s1 - len_s2);
    }
    return 0;
}
