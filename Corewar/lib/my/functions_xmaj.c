/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** functions_X.c
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/printf.h"

void hexa_maj(va_list list)
{
    my_put_hexa_maj(va_arg(list, unsigned int));
}

void long_hexa_maj(va_list list)
{
    my_put_hexa_maj(va_arg(list, unsigned long));
}

void long_long_hexa_maj(va_list list)
{
    my_put_hexa_maj(va_arg(list, unsigned long long));
}

void short_hexa_maj(va_list list)
{
    my_put_hexa_majs(va_arg(list, unsigned int));
}

void char_hexa_maj(va_list list)
{
    my_put_hexamajus(va_arg(list, unsigned int));
}
