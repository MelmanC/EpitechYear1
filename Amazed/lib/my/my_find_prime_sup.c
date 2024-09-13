/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** prime
*/

#include "include/my.h"

static int prime(int nb)
{
    if (nb == 1 || nb == 0 || nb < 0) {
        return 0;
    }
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}

int my_find_prime_sup(int nb)
{
    int take = 0;

    if (nb <= 0) {
        return 2;
    }
    for (int i = nb; i > 0; i++) {
        take = prime(i);
        if (take == 1) {
            return i;
        }
    }
    return 0;
}
