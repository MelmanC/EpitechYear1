/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** get_params.c
*/

#include "printf.h"
#include "my.h"
#include "op.h"
#include "corewar.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

static
void get_arguments(instruction_t *ins, int i, char *buff, int *index)
{
    for (int j = 0; j < ins[i].nbr_args; j++) {
        if (ins[i].type[j] == T_REG) {
            ins[i].args[j] = buff[*index];
            *index += 1;
        }
        if (ins[i].type[j] == T_DIR) {
            ins[i].args[j] += (buff[*index] & 0x000000FF) << 24;
            ins[i].args[j] += (buff[*index + 1] & 0x000000FF) << 16;
            ins[i].args[j] += (buff[*index + 2] & 0x000000FF) << 8;
            ins[i].args[j] += (buff[*index + 3] & 0x000000FF) << 0;
            *index += 4;
        }
        if (ins[i].type[j] == T_IND) {
            ins[i].args[j] += (buff[*index] & 0x000000FF) << 8;
            ins[i].args[j] += (buff[*index + 1] & 0x000000FF) << 0;
            *index += 2;
        }
    }
}

void get_params(instruction_t *ins, char *buff, int nb_ins)
{
    int index = 0;

    for (int i = 0; i < nb_ins; i++) {
        if (my_strcmp(ins[i].name, "live") == 0 ||
            my_strcmp(ins[i].name, "zjmp") == 0 ||
            my_strcmp(ins[i].name, "fork") == 0 ||
            my_strcmp(ins[i].name, "lfork") == 0) {
            index++;
        } else
            index += 2;
        get_arguments(ins, i, buff, &index);
    }
}
