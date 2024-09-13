/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** st.c
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

void st_f(int index, corewar_t *corewar)
{
    int value1 = 0;
    int address = 0;

    value1 = get_value(&corewar->pc[index], 0);
    if (corewar->pc[index].type[1] == T_REG) {
        corewar->pc[index].registers[corewar->pc[index].args[1]] = value1;
    } else {
        address = corewar->pc[index].pc + corewar->pc[index].args[1] % IDX_MOD;
        put_value(value1, corewar, &address);
    }
    corewar->pc[index].cycle = op_tab[2].nbr_cycles;
}
