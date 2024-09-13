/*
** EPITECH PROJECT, 2023
** robot
** File description:
** utils_2.c
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"
#include <stdlib.h>

unsigned long to_big_endian_index(unsigned long x)
{
    unsigned long value = 0;

    value += (x & 0x000000FF) << 8;
    value += (x & 0x0000FF00) >> 8;
    return value;
}

/* change the endianness of a number */
unsigned long to_big_endian(unsigned long x)
{
    unsigned long value = 0;

    value += (x & 0x000000FF) << 24;
    value += (x & 0xFF000000) >> 24;
    value += (x & 0x0000FF00) << 8;
    value += (x & 0x00FF0000) >> 8;
    return value;
}
