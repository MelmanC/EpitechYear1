/*
** EPITECH PROJECT, 2024
** mysh
** File description:
** my_strrchr.c
*/

#include <stddef.h>

char *my_strrchr(char *str, int c)
{
    char *last_occurrence = NULL;

    for (; *str != '\0'; str += 1)
        if (*str == c)
            last_occurrence = str;
    return last_occurrence;
}
