/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** a
*/

#include <stdarg.h>
#include <stdio.h>
#include "include/my.h"
#include "include/printf.h"

static void (*tab3[])() = {dint, dint, udint, hexa,
    hexa_maj, octa, ptr, string, charac, purcent};

static void (*tab2[])(va_list, int) = {tfloat, scient};

static void (*tab[])(va_list, char) = {length_l, length_ll, length_h,
    length_hh};

static int check_flags(char c, va_list list, int numbers, char letter)
{
    char *flags = "diuxXopsc%";
    char *flags_pre = "feKKKKKKKK";
    char *flags_length = "lLhHKKKKKK";

    for (int i = 0; i < my_strlen(flags); i++) {
        if (flags_length[i] == letter) {
            tab[i](list, c);
            return 0;
        }
        if (flags_pre[i] == c && letter == '\0') {
            tab2[i](list, numbers);
            return 0;
        }
        if (flags[i] == c && letter == '\0') {
            tab3[i](list);
            return 0;
        }
    }
    return (84);
}

char check_length(const char *format, int *i, char letter)
{
    if (format[*i + 1] == 'l') {
        letter = format[*i + 1];
        *i += 1;
        if (format[*i + 1] == 'l') {
            letter = 'L';
            *i += 1;
        }
    }
    if (format[*i + 1] == 'h') {
        letter = format[*i + 1];
        *i += 1;
        if (format[*i + 1] == 'h') {
            letter = 'H';
            *i += 1;
        }
    }
    return letter;
}

int check_pre(const char *format, int *i, int numbers)
{
    int res = 0;

    numbers = 6;
    if (format[*i + 1] == '.') {
        if (my_getnbr(&format[*i + 2]) == 0) {
            numbers = -1;
            *i += 1;
        } else {
            numbers = my_getnbr(&format[*i + 2]);
            *i += 2;
        }
        if ((format[*i + 1] == '0') && (format[*i] == '.'))
            *i += 1;
    }
    res = numbers;
    while (res >= 10) {
        res /= 10;
        *i += 1;
    }
    return numbers;
}

int my_printf(const char *format, ...)
{
    va_list list;
    int numbers = 0;
    char letter = '\0';

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            numbers = check_pre(format, &i, numbers);
            letter = check_length(format, &i, letter);
            check_flags(format[i + 1], list, numbers, letter);
            i += 1;
        } else
            my_putchar(format[i]);
    }
    va_end(list);
    return (0);
}
