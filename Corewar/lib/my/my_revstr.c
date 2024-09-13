/*
** EPITECH PROJECT, 2023
** revstr
** File description:
** rev
*/

#include "include/my.h"

static int lenght(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int j = lenght(str) - 1;
    char temp;

    for (int i = 0; i < j; i++) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    return (str);
}
