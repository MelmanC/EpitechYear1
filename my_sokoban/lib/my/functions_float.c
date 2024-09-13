/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** functions3.c
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/printf.h"

void tfloat(va_list list, int numbers)
{
    my_put_float(va_arg(list, double), numbers);
}

void scient(va_list list, int numbers)
{
    my_put_scient(va_arg(list, double), numbers);
}
