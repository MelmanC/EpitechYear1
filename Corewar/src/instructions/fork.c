/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** fork.c
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

static
void sort_next(pc_t *pc, pc_t tmp, int j)
{
    if (pc[j].num_champs > pc[j + 1].num_champs) {
        tmp = pc[j];
        pc[j] = pc[j + 1];
        pc[j + 1] = tmp;
    }
}

static
void sort(pc_t *pc, int n)
{
    pc_t tmp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            sort_next(pc, tmp, j);
        }
    }
}

void fork_i(int index, corewar_t *corewar)
{
    pc_t *new_pc = realloc(corewar->pc, sizeof(pc_t) *
        (corewar->nbr_champs + 1));

    corewar->pc = new_pc;
    corewar->nbr_champs += 1;
    corewar->pc[index].cycle = op_tab[11].nbr_cycles;
    corewar->pc[corewar->nbr_champs - 1] = corewar->pc[index];
    corewar->pc[corewar->nbr_champs - 1].pc +=
        (corewar->pc[index].args[0] % IDX_MOD) % MEM_SIZE;
    sort(corewar->pc, corewar->nbr_champs);
}
