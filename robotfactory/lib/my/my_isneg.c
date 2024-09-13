/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** Display positive or negative
*/

#include "include/my.h"

int my_isneg(int n)
{
    int negative = 'N';
    int positive = 'P';

    if (n < 0) {
        my_putchar(negative);
    } else if (n == 0){
        my_putchar(positive);
    } else {
        my_putchar(positive);
    }
}
