/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** lldi.c
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

static
void put_pc(int index, corewar_t *corewar, int value3)
{
    corewar->pc[index].registers[corewar->pc[index].args[2 - 1]] = value3;
    corewar->pc[index].cycle = op_tab[12].nbr_cycles;
    corewar->pc[index].carry = (value3 == 0) ? 1 : 0;
}

void lldi(int index, corewar_t *corewar)
{
    int value1 = get_value(&corewar->pc[index], 0);
    int value2 = get_value(&corewar->pc[index], 1);
    int value3 = 0;
    int adresse = corewar->pc[index].pc + value1;
    int sum = 0;

    for (int i = 0; i < IND_SIZE; i++) {
        sum += corewar->memory[adresse];
        adresse += 1 % MEM_SIZE;
    }
    sum += value2;
    adresse = corewar->pc[index].pc + sum;
    for (int i = 0; i < REG_SIZE; i++) {
        value3 += corewar->memory[adresse];
        adresse += 1 % MEM_SIZE;
    }
    put_pc(index, corewar, value3);
}
