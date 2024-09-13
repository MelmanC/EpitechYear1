/*
** EPITECH PROJECT, 2023
** my_put_scient
** File description:
** a
*/

#include "include/my.h"
#include "include/printf.h"
#include <stdio.h>

static void display(double nb, int numbers, char signe, int compteur)
{
    my_put_float(nb, numbers);
    my_putchar('e');
    my_putchar(signe);
    if (compteur < 10)
        my_putchar('0');
    my_put_nbr(compteur);
}

void my_put_scient(double nb, int numbers)
{
    int compteur = 0;
    char signe = '+';

    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    while (nb >= 10) {
        nb = (float) nb / 10;
        compteur += 1;
        signe = '+';
    }
    while (nb < 1) {
        nb *= 10;
        compteur += 1;
        signe = '-';
    }
    display(nb, numbers, signe, compteur);
}
