/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** functions_d.c
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/printf.h"

void dint(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

void long_dint(va_list list)
{
    my_put_nbr(va_arg(list, long));
}

void long_long_dint(va_list list)
{
    my_put_nbr(va_arg(list, long long));
}

void short_dint(va_list list)
{
    my_put_short(va_arg(list, int));
}

void char_dint(va_list list)
{
    my_put_schar(va_arg(list, int));
}
