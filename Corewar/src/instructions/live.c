/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** live.c
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

void live(int index, corewar_t *corewar)
{
    corewar->count_live++;
    for (int i = 0; i < corewar->nbr_champs; i++) {
        if (corewar->pc[index].args[0] == corewar->pc[i].num_champs) {
            corewar->last_live = corewar->pc[i].num_champs;
            corewar->winner = corewar->pc[i].name;
            corewar->pc[i].live = 1;
            my_printf("The player %d(%s) is alive.\n",
                corewar->pc[i].num_champs, corewar->pc[i].name);
        }
    }
}
