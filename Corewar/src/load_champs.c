/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** main.c
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int ini_memory(corewar_t *corewar)
{
    corewar->memory = malloc(sizeof(uint8_t) * MEM_SIZE);
    if (!corewar->memory)
        return 84;
    for (int i = 0; i < MEM_SIZE; i++)
        corewar->memory[i] = 0;
    return 0;
}

void add_zero(char *str, int len, int size)
{
    char *tmp = malloc(sizeof(char) * size + 1);
    int i = 0;
    int j = 0;

    for (; i < size - len; i++)
        tmp[i] = '0';
    for (; i < size; i++) {
        tmp[i] = str[j];
        j++;
    }
    tmp[size] = '\0';
    str = my_strcpy(str, tmp);
    free(tmp);
}

void check_len(char *str, int len, int type)
{
    if (type == T_REG && len < 2)
        add_zero(str, len, 2);
    if (type == T_IND && len < 4)
        add_zero(str, len, 4);
    if (type == T_DIR && len < 8)
        add_zero(str, len, 8);
}

static
void verif_instruction_name(champions_t *ch, corewar_t *c, int j, int *index)
{
    if (my_strcmp(ch->instruction[j].name, "live") != 0 &&
        my_strcmp(ch->instruction[j].name, "zjmp") != 0 &&
        my_strcmp(ch->instruction[j].name, "fork") != 0 &&
        my_strcmp(ch->instruction[j].name, "lfork") != 0) {
        if (ch->instruction[j].op_code < 10) {
            c->memory[*index] = ch->instruction[j].op_code
                                + '0';
            *index += 1;
        }
        c->memory[*index] = ch->instruction[j].op_code;
        *index += 1;
    }
}

static
void loop_on_str(corewar_t *corewar, char *str, int *index)
{
    uint8_t tmp = 0;

    for (int l = 0; str[l] != '\0'; l += 2) {
        if (my_char_isnum(str[l]) == 1)
            tmp = (str[l] - '0') << 4;
        else
            tmp = (str[l] - 'a' + 10) << 4;
        if (my_char_isnum(str[l + 1]) == 1)
            tmp += str[l + 1] - '0';
        else
            tmp += str[l + 1] - 'a' + 10;
        corewar->memory[*index] = tmp;
        *index += 1;
    }
}

static
void loop_on_nbr_args(champions_t *ch, corewar_t *c, int j, int *index)
{
    char *str = NULL;
    int len = 0;

    for (int k = 0; k < ch->instruction[j].nbr_args; k++) {
        if (*index < MEM_SIZE) {
            str = convert_int_to_hexa(ch->instruction[j].args[k]);
            len = my_strlen(str);
            check_len(str, len, ch->instruction[j].type[k]);
            loop_on_str(c, str, index);
        }
        free(str);
    }
}

void load_champions(champions_t *champs, corewar_t *corewar, int nbr_champs)
{
    int index = 0;
    int mem_offset = MEM_SIZE / nbr_champs;

    for (int i = 0; i < nbr_champs; i++) {
        if (i == 0)
            index = 0;
        else
            index = i * mem_offset + champs[i].header->prog_size;
        if (champs[i].address != -1)
            index = champs[i].address;
        if (index % 2 != 0)
            index += 1;
        corewar->pc[i].pc = index;
        for (int j = 0; j < champs[i].nbr_ins; j++) {
            corewar->memory[index] = champs[i].instruction[j].instruction;
            index += 1;
            verif_instruction_name(&champs[i], corewar, j, &index);
            loop_on_nbr_args(&champs[i], corewar, j, &index);
        }
    }
}
