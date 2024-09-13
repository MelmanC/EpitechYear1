/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** my_put_nbrus.c
*/

#include "include/my.h"

unsigned long long my_put_unsigned(unsigned long long nb)
{
    unsigned long long len = 0;

    if (nb >= 10) {
        len += my_put_unsigned(nb / 10);
        my_putchar(nb % 10 + '0');
        len += 1;
    } else {
        my_putchar(nb + '0');
        len += 1;
    }
    return len;
}

unsigned short my_put_ushort(unsigned short nb)
{
    unsigned short len = 0;

    if (nb >= 10) {
        len += my_put_ushort(nb / 10);
        my_putchar(nb % 10 + '0');
        len += 1;
    } else {
        my_putchar(nb + '0');
        len += 1;
    }
    return len;
}

unsigned char my_put_uschar(unsigned char nb)
{
    unsigned char len = 0;

    if (nb >= 10) {
        len += my_put_schar(nb / 10);
        my_putchar(nb % 10 + '0');
        len += 1;
    } else {
        my_putchar(nb + '0');
        len += 1;
    }
    return len;
}
