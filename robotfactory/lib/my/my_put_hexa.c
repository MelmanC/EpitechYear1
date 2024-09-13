/*
** EPITECH PROJECT, 2023
** my_put_hexa
** File description:
** a
*/

#include <stdio.h>
#include "include/my.h"
#include "include/printf.h"

static void lettre(int nb)
{
    int index = nb - 10;
    char *str = "abcdef";

    my_putchar(str[index]);
}

long long my_put_hexa(unsigned long long nb)
{
    long long res = nb / 16;

    if (res == 0) {
        if ((nb % 16) > 9) {
            lettre(nb % 16);
        } else {
            my_putchar(nb % 16 + '0');
        }
    }
    if (res > 0) {
        my_put_hexa(res);
        if ((nb % 16) > 9) {
            lettre(nb % 16);
        } else {
            my_putchar(nb % 16 + '0');
        }
    }
    return (0);
}

long my_put_hexas(unsigned short nb)
{
    short res = nb / 16;

    if (res == 0) {
        if ((nb % 16) > 9) {
            lettre(nb % 16);
        } else {
            my_putchar(nb % 16 + '0');
        }
    }
    if (res > 0) {
        my_put_hexas(res);
        if ((nb % 16) > 9) {
            lettre(nb % 16);
        } else {
            my_putchar(nb % 16 + '0');
        }
    }
    return (0);
}

unsigned char my_put_hexaus(unsigned char nb)
{
    unsigned char res = nb / 16;

    if (res == 0) {
        if ((nb % 16) > 9) {
            lettre(nb % 16);
        } else {
            my_putchar(nb % 16 + '0');
        }
    }
    if (res > 0) {
        my_put_hexaus(res);
        if ((nb % 16) > 9) {
            lettre(nb % 16);
        } else {
            my_putchar(nb % 16 + '0');
        }
    }
    return (0);
}
