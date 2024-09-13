/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** functions_length.c
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/printf.h"

void length_l(va_list list, char c)
{
    static void (*tab[])(va_list) = {long_dint, long_dint, long_octa,
    long_udint, long_hexa, long_hexa_maj};
    char *flags = "diouxX";

    for (int i = 0; i < my_strlen(flags); i++) {
        if (flags[i] == c)
            tab[i](list);
    }
}

void length_ll(va_list list, char c)
{
    static void (*tab[])() = {long_long_dint, long_long_dint, long_long_octa,
    long_long_udint, long_long_hexa, long_long_hexa_maj};
    char *flags = "diouxX";

    for (int i = 0; i < my_strlen(flags); i++) {
        if (flags[i] == c)
            tab[i](list);
    }
}

void length_h(va_list list, char c)
{
    static void (*tab[])() = {short_dint, short_dint, short_octa, short_udint,
    short_hexa, short_hexa_maj};
    char *flags = "diouxX";

    for (int i = 0; i < my_strlen(flags); i++) {
        if (flags[i] == c)
            tab[i](list);
    }
}

void length_hh(va_list list, char c)
{
    static void (*tab[])() = {char_dint, char_dint, char_octa, char_udint,
    char_hexa, char_hexa_maj};
    char *flags = "diouxX";

    for (int i = 0; i < my_strlen(flags); i++) {
        if (flags[i] == c)
            tab[i](list);
    }
}
