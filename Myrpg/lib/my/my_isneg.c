/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** function my_isneg
*/

#include "../../include/my.h"

void my_isneg(int nb)
{
    if (nb < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
}
