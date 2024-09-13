/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** functions_u.c
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/printf.h"

void udint(va_list list)
{
    my_put_unsigned(va_arg(list, unsigned int));
}

void long_udint(va_list list)
{
    my_put_unsigned(va_arg(list, unsigned long));
}

void long_long_udint(va_list list)
{
    my_put_unsigned(va_arg(list, unsigned long long));
}

void short_udint(va_list list)
{
    my_put_ushort(va_arg(list, unsigned int));
}

void char_udint(va_list list)
{
    my_put_uschar(va_arg(list, unsigned int));
}
