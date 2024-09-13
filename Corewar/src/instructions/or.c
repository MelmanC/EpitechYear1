/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** or.c
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

static
int get_value(pc_t *pc, int arg_nbr)
{
    int value = 0;
    int type = pc->type[arg_nbr];
    int arg = pc->args[arg_nbr];

    if (type == T_REG) {
        value = pc->registers[arg - 1];
    }
    if (type == T_DIR || type == T_IND) {
        value = arg;
    }
    return value;
}

void or_f(int index, corewar_t *corewar)
{
    int value1 = 0;
    int value2 = 0;
    int result = 0;

    value1 = get_value(&corewar->pc[index], 0);
    value2 = get_value(&corewar->pc[index], 1);
    result = value1 | value2;
    corewar->pc[index].registers[corewar->pc[index].args[2]] = result;
    corewar->pc[index].cycle = op_tab[6].nbr_cycles;
}
