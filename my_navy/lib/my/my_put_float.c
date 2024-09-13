/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** my_put_float.c
*/

#include <stdio.h>
#include "include/my.h"
#include "include/printf.h"

static void my_put_zero(double nb, int numbers)
{
    int a = nb;

    for (int i = 0; i < numbers; i++) {
        nb *= 10;
        a *= 10;
        if ((nb < a + 1) && (i < numbers - 1) && ((int)nb % 10 != 1)) {
            my_putchar('0');
        }
    }
}

void my_put_float(double nb, int numbers)
{
    long long tmp = nb * my_compute_power_rec(10, 8);

    if (numbers > 0)
        tmp = nb * my_compute_power_rec(10, numbers + 2);
    if (numbers == -1) {
        my_put_nbr(nb);
        return;
    }
    my_put_nbr(nb);
    my_putstr(".");
    if (nb < 0) {
        tmp *= -1;
        nb *= -1;
    }
    my_put_zero(nb, numbers);
    tmp = tmp % my_compute_power_rec(10, numbers + 2);
    if ((tmp % 100) > 50)
        tmp += 100;
    tmp = tmp / 100;
    my_put_nbr(tmp);
}
