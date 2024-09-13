/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** putnbr
*/

#include "include/my.h"

long long my_put_nbr(long long nb)
{
    long long len = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        len += 1;
    }
    if (nb >= 10) {
        len += my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
        len += 1;
    } else {
        my_putchar(nb + '0');
        len += 1;
    }
    return len;
}

short my_put_short(short nb)
{
    short len = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        len += 1;
    }
    if (nb >= 10) {
        len += my_put_short(nb / 10);
        my_putchar(nb % 10 + '0');
        len += 1;
    } else {
        my_putchar(nb + '0');
        len += 1;
    }
    return len;
}

signed char my_put_schar(signed char nb)
{
    signed char len = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        len += 1;
    }
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
