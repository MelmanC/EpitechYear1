/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** functions.c
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/printf.h"

void string(va_list list)
{
    my_putstr(va_arg(list, char *));
}

void charac(va_list list)
{
    my_putchar(va_arg(list, int));
}

void purcent(void)
{
    my_putchar('%');
}

void ptr(va_list list)
{
    my_putstr("0x");
    my_put_ptr(va_arg(list, unsigned long));
}
