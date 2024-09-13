/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** init_corewar.c
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>

static
void init_pc(pc_t *pc, int nbr_champions, champions_t *champions)

{
    for (int i = 0; i < nbr_champions; i++) {
        pc[i].pc = 0;
        pc[i].carry = 0;
        pc[i].name = champions[i].header->prog_name;
        pc[i].num_champs = champions[i].num;
        pc[i].cycle = 0;
        pc[i].live = 0;
        pc[i].is_alive = 1;
        pc[i].registers[0] = champions[i].num;
        for (int j = 1; j < REG_NUMBER; j++)
            pc[i].registers[j] = 0;
    }
}

void init_corewar(corewar_t *corewar, int nbr_champions, champions_t *c)
{
    corewar->pc = malloc(sizeof(pc_t) * nbr_champions);
    init_pc(corewar->pc, nbr_champions, c);
    corewar->cycle = 0;
    corewar->cycle_to_die = CYCLE_TO_DIE;
    corewar->nbr_champs = nbr_champions;
    corewar->nbr_alive = nbr_champions;
    corewar->count_live = 0;
    corewar->last_live = 0;
    corewar->winner = NULL;
}
