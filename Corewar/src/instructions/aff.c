/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** aff.c
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

void aff(int index, corewar_t *corewar)
{
    char value = 0;

    value = corewar->pc[index].registers[corewar->pc[index].args[0] - 1];
    value %= 256;
    my_printf("%c\n", value);
    corewar->pc[index].cycle = op_tab[15].nbr_cycles;
}
