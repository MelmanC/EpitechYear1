/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** sti.c
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
    if (type == T_IND) {
        value = arg;
    }
    return value;
}

void sti(int index, corewar_t *corewar)
{
    int value1 = 0;
    int value2 = 0;
    int value3 = 0;
    int adresse = 0;

    value1 = get_value(&corewar->pc[index], 0);
    value2 = get_value(&corewar->pc[index], 1);
    value3 = get_value(&corewar->pc[index], 2);
    adresse = corewar->pc[index].pc + ((value2 + value3) % IDX_MOD) % MEM_SIZE;
    put_value(value1, corewar, &adresse);
    corewar->pc[index].cycle = op_tab[10].nbr_cycles;
}
