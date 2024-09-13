/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** functions_x.c
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/printf.h"

void hexa(va_list list)
{
    my_put_hexa(va_arg(list, unsigned int));
}

void long_hexa(va_list list)
{
    my_put_hexa(va_arg(list, unsigned long));
}

void long_long_hexa(va_list list)
{
    my_put_hexa(va_arg(list, unsigned long long));
}

void short_hexa(va_list list)
{
    my_put_hexas(va_arg(list, unsigned int));
}

void char_hexa(va_list list)
{
    my_put_hexaus(va_arg(list, unsigned int));
}
