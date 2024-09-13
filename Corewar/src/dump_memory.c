/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** main.c
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>

void print_memory(uint8_t *memory, int size)
{
    int line = 0;

    for (int i = 0; i < size; i++) {
        if (memory[i] > 15)
            my_printf("%x ", memory[i]);
        else
            my_printf("0%x ", memory[i]);
        line++;
        if (line % 32 == 0) {
            my_printf("\n");
        }
    }
}
