/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** ld.c
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

void ld_f(int index, corewar_t *corewar)
{
    int value = 0;
    int j = 0;

    value = corewar->pc[index].args[0];
    j = corewar->pc[index].pc + value % IDX_MOD;
    for (int i = 0; i < REG_SIZE; i++) {
        value += corewar->memory[j];
        j += 1 % MEM_SIZE;
    }
    corewar->pc[index].registers[corewar->pc[index].args[1]] = value;
    corewar->pc[index].carry = 1;
    corewar->pc[index].cycle = op_tab[1].nbr_cycles;
}
