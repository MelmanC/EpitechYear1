/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** function my_putstr
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        my_putchar(str[i]);
    }
    return 0;
}
