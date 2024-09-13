/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** make_instruction.c
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

static void (*tab[16])(int, corewar_t *) = {
    live,
    ld_f,
    st_f,
    add,
    sub,
    and_f,
    or_f,
    xor_f,
    zjmp,
    ldi,
    sti,
    fork_i,
    lld,
    lldi,
    lfork,
    aff
};

static
int verif_instruction(pc_t *pc)
{
    if (my_strcmp(pc->instruction, "live") == 0) {
        pc->type[0] = T_DIR;
        return 1;
    }
    if (my_strcmp(pc->instruction, "zjmp") == 0 ||
        my_strcmp(pc->instruction, "fork") == 0 ||
        my_strcmp(pc->instruction, "lfork") == 0) {
        pc->type[0] = T_IND;
        return 1;
    }
    return 0;
}

static
int on_instruction(pc_t *pc, corewar_t *corewar)
{
    if (corewar->memory[pc->pc] < 1 || corewar->memory[pc->pc] > 16) {
        pc->pc += 1;
        return 0;
    }
    return 1;
}

static
void init_type_and_args(pc_t *pc)
{
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        pc->args[i] = 0;
        pc->type[i] = 0;
    }
}

static
void verif_zjump(corewar_t *corewar, int i, int index)
{
    if (my_strcmp(corewar->pc[i].instruction, "zjmp") != 0 ||
        corewar->pc[i].carry == 0)
        corewar->pc[i].pc = index;
}

static
int verif_cycle(corewar_t *corewar, int i)
{
    if (corewar->pc[i].cycle != 0) {
        corewar->pc[i].cycle -= 1;
        return 0;
    }
    return 1;
}

static
void game(corewar_t *corewar, int i)
{
    int instrcution = 0;
    int index = corewar->pc[i].pc;

    if (verif_cycle(corewar, i) == 0 || corewar->pc[i].is_alive == 0 ||
        on_instruction(&corewar->pc[i], corewar) == 0)
        return;
    instrcution = corewar->memory[index] - 1;
    corewar->pc[i].instruction = op_tab[instrcution].mnemonique;
    init_type_and_args(&corewar->pc[i]);
    corewar->pc[i].opcode = corewar->memory[index + 1];
    if (verif_instruction(&corewar->pc[i]) == 0)
        define_type(corewar->pc[i].type, corewar->pc[i].opcode,
            corewar->pc[i].instruction);
    get_params_in_memory(&corewar->pc[i], op_tab[instrcution].nbr_args,
        corewar, &index);
    tab[instrcution](i, corewar);
    verif_zjump(corewar, i, index);
    if ((corewar->count_live % NBR_LIVE) == 0)
        corewar->cycle_to_die -= CYCLE_DELTA;
}

static
void verif_alive(corewar_t *corewar)
{
    for (int i = 0; i < corewar->nbr_champs; i++) {
        if (corewar->pc[i].live != 1) {
            corewar->pc[i].is_alive = 0;
            corewar->nbr_alive -= 1;
        }
        corewar->pc[i].live = 0;
    }
}

void make_instruction(corewar_t *corewar)
{
    while (corewar->nbr_alive > 1 && corewar->cycle != corewar->dump) {
        for (int i = 0; i < corewar->nbr_champs; i++)
            game(corewar, i);
        corewar->cycle += 1;
        if (corewar->cycle % corewar->cycle_to_die == 0
            || corewar->cycle_to_die <= 0)
            verif_alive(corewar);
    }
    if (corewar->winner == NULL)
        my_printf("Every body won.\n");
    else
        my_printf("The player %d(%s) has won.\n",
            corewar->last_live, corewar->winner);
    if (corewar->dump != -1)
        print_memory(corewar->memory, MEM_SIZE);
}
