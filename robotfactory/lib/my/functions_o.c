/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** functions_o.c
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/printf.h"

void octa(va_list list)
{
    my_put_octa(va_arg(list, unsigned int));
}

void long_octa(va_list list)
{
    my_put_octa(va_arg(list, unsigned long));
}

void long_long_octa(va_list list)
{
    my_put_octa(va_arg(list, unsigned long long));
}

void short_octa(va_list list)
{
    my_put_octas(va_arg(list, unsigned int));
}

void char_octa(va_list list)
{
    my_put_octauc(va_arg(list, unsigned int));
}
