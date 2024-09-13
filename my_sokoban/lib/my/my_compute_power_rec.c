/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** my_compute
*/

#include "include/my.h"

static long long test1(int nb, int p, long long a)
{
    if (nb > 0 && a > 0){
        return a;
    }
    if (nb < 0 && p % 2 == 0 && a > 0) {
        return a;
    }
    if (nb < 0 && p % 2 != 0 && a < 0) {
        return a;
    }
    return 0;
}

long long my_compute_power_rec(int nb, int p)
{
    long long a = nb;

    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    a = a * my_compute_power_rec(nb, p - 1);
    a = test1(nb, p, a);
    return a;
}
