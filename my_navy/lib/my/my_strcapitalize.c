/*
** EPITECH PROJECT, 2023
** cap
** File description:
** cap
*/

#include "include/my.h"

static int len5(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

static void suite2(char *str, int i)
{
    if (str[i] >= 49 && str[i] <= 57) {
        if (str[i + 1] >= 49 && str[i + 1] <= 57) {
            str[i + 1] = str[i + 1];
        } else {
            str[i + 1] = str[i + 1] + 32;
        }
    }
}

static void suite(char *str, int i)
{
    if (str[i] >= 97 && str[i] <= 122) {
        if (str[i + 1] >= 65 && str[i + 1] <= 90) {
            str[i + 1] = str[i + 1] + 32;
        }
    }
    if (str[i] == ' ') {
        if (str[i + 1] >= 49 && str[i + 1] <= 57) {
            str[i + 1] = str[i + 1];
        } else {
            str[i + 1] = str[i + 1] - 32;
        }
    }
}

char *my_strcapitalize(char *str)
{
    int size = len5(str);

    for (int i = 0; i < size; i++) {
        if (str[0] >= 97 && str[0] <= 122) {
            str[0] = str[0] - 32;
        }
        if (str[i] == 43 || str[i] == 45) {
            str[i + 1] = str[i + 1] - 32;
        }
        suite(str, i);
        suite2(str, i);
    }
    return str;
}
