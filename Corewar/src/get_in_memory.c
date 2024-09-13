/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** get_in_memory.c
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

static
void get_dir(pc_t *pc, uint8_t *memory, int j, int *index)
{
    pc->args[j] += (memory[(*index) % MEM_SIZE] & 0x000000FF) << 24;
    pc->args[j] += (memory[(*index + 1) % MEM_SIZE] & 0x000000FF) << 16;
    pc->args[j] += (memory[(*index + 2) % MEM_SIZE] & 0x000000FF) << 8;
    pc->args[j] += (memory[(*index + 3) % MEM_SIZE] & 0x000000FF) << 0;
    *index += 4 % MEM_SIZE;
}

void get_args(pc_t *pc, uint8_t *memory, int nb_args, int *index)
{
    for (int j = 0; j < nb_args; j++) {
        if (pc->type[j] == T_REG) {
            pc->args[j] = memory[*index];
            *index += 1 % MEM_SIZE;
        }
        if (pc->type[j] == T_DIR) {
            get_dir(pc, memory, j, index);
        }
        if (pc->type[j] == T_IND) {
            pc->args[j] += (memory[(*index) % MEM_SIZE] & 0x000000FF) << 8;
            pc->args[j] += (memory[(*index + 1) % MEM_SIZE] & 0x000000FF) << 0;
            *index += 2 % MEM_SIZE;
        }
    }
}

void get_params_in_memory(pc_t *pc, int nb, corewar_t *c, int *i)
{
    if (my_strcmp(pc->instruction, "live") == 0 ||
        my_strcmp(pc->instruction, "zjmp") == 0 ||
        my_strcmp(pc->instruction, "fork") == 0 ||
        my_strcmp(pc->instruction, "lfork") == 0) {
        *i += 1;
    } else
        *i += 2;
    get_args(pc, c->memory, nb, i);
}
