/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** function my_compute_square_root
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    char temp;

    for (int j = 0; j < i; j += 1) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        i -= 1;
    }
    return str;
}
