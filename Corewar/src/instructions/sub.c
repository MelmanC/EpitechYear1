/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** sub.cpp
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

void sub(int index, corewar_t *corewar)
{
    int sum = 0;
    int value1 = 0;
    int value2 = 0;

    value1 = corewar->pc[index].registers[corewar->pc[index].args[0]];
    value2 = corewar->pc[index].registers[corewar->pc[index].args[1]];
    sum = value1 - value2;
    corewar->pc[index].registers[corewar->pc[index].args[2]] = sum;
    corewar->pc[index].cycle = op_tab[4].nbr_cycles;
}
