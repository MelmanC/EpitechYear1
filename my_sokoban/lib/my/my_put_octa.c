/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** my_put_octa.c
*/

#include "include/my.h"
#include "include/printf.h"

long long my_put_octa(unsigned long long nb)
{
    long long res = nb / 8;

    if (res == 0) {
        my_putchar(nb % 8 + '0');
    }
    if (res > 0) {
        my_put_octa(res);
        my_putchar(nb % 8 + '0');
    }
    return (0);
}

long my_put_octas(unsigned short nb)
{
    long res = nb / 8;

    if (res == 0) {
        my_putchar(nb % 8 + '0');
    }
    if (res > 0) {
        my_put_octas(res);
        my_putchar(nb % 8 + '0');
    }
    return (0);
}

unsigned char my_put_octauc(unsigned char nb)
{
    unsigned char res = nb / 8;

    if (res == 0) {
        my_putchar(nb % 8 + '0');
    }
    if (res > 0) {
        my_put_octauc(res);
        my_putchar(nb % 8 + '0');
    }
    return (0);
}
