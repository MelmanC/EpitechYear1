/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** zjmp.c
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

void zjmp(int index, corewar_t *corewar)
{
    int sign = 0;
    int result = 0;

    if (corewar->pc[index].carry == 0)
        return;
    if ((corewar->pc[index].args[0] & (1 << (16 - 1))) != 0)
        sign = -1;
    if (sign == -1)
        result = ((corewar->pc[index].args[0] - (1 << 16) + 1) - 1);
    else
        result = (corewar->pc[index].args[0]);
    corewar->pc[index].pc += ((result) % IDX_MOD) % MEM_SIZE;
    corewar->pc[index].cycle = op_tab[8].nbr_cycles;
}
