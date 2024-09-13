/*
** EPITECH PROJECT, 2023
** my_put_long
** File description:
** a
*/

#include <stdio.h>
#include "include/my.h"
#include "include/printf.h"

static void lettre(unsigned long nb)
{
    int index = nb - 10;
    char *str = "abcdef";

    my_putchar(str[index]);
}

int my_put_ptr(unsigned long nb)
{
    unsigned long res = nb / 16;

    if (res == 0) {
        if ((nb % 16) > 9) {
            lettre(nb % 16);
        } else {
            my_putchar(nb % 16 + '0');
        }
    }
    if (res > 0) {
        my_put_ptr(res);
        if ((nb % 16) > 9) {
            lettre(nb % 16);
        } else {
            my_putchar(nb % 16 + '0');
        }
    }
    return (0);
}
