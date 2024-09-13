/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** get_instructions.c
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
void verif_index(int *types, char *instruction)
{
    if (my_strcmp(instruction, "sti") == 0) {
        if (types[1] == T_DIR)
            types[1] = T_IND;
        if (types[2] == T_DIR)
            types[2] = T_IND;
    }
    if (my_strcmp(instruction, "ldi") == 0
        || my_strcmp(instruction, "lldi") == 0) {
        if (types[0] == T_DIR)
            types[0] = T_IND;
        if (types[1] == T_DIR)
            types[1] = T_IND;
    }
}

static
char *int_to_bin(int number)
{
    int i = 0;
    char *bin = malloc(sizeof(char) * 8 + 1);

    if (!bin)
        return NULL;
    for (i = 0; i < 8; i++)
        bin[i] = '0';
    i = 7;
    while (number > 0) {
        bin[i] = (number % 2) + '0';
        number /= 2;
        i--;
    }
    bin[8] = '\0';
    return bin;
}

static
void check_type(char *bin, int *type)
{
    int index = 0;

    for (int i = 0; i < 8; i += 2) {
        if (bin[i] == '0' && bin[i + 1] == '1') {
            type[index] = T_REG;
            index++;
            continue;
        }
        if (bin[i] == '1' && bin[i + 1] == '0') {
            type[index] = T_DIR;
            index++;
            continue;
        }
        if (bin[i] == '1' && bin[i + 1] == '1') {
            type[index] = T_IND;
            index++;
            continue;
        }
    }
}

static
void augmente_index(int *index, instruction_t *instructions, int nb_ins)
{
    for (int j = 0; j < instructions[nb_ins].nbr_args; j++) {
        if (instructions[nb_ins].type[j] == T_REG)
            *index += 1;
        if (instructions[nb_ins].type[j] == T_DIR)
            *index += DIR_SIZE;
        if (instructions[nb_ins].type[j] == T_IND)
            *index += IND_SIZE;
    }
}

static
int verif_instruction(instruction_t *instructions, int nb_ins, int *index)
{
    if (my_strcmp(instructions[nb_ins].name, "live") == 0) {
        instructions[nb_ins].type[0] = T_DIR;
        *index += DIR_SIZE + 1;
        return 1;
    }
    if (my_strcmp(instructions[nb_ins].name, "zjmp") == 0 ||
        my_strcmp(instructions[nb_ins].name, "fork") == 0 ||
        my_strcmp(instructions[nb_ins].name, "lfork") == 0) {
        instructions[nb_ins].type[0] = T_IND;
        *index += IND_SIZE + 1;
        return 1;
    }
    return 0;
}

void define_type(int *types, int op_code, char *name)
{
    char *bin = int_to_bin(op_code);

    check_type(bin, types);
    verif_index(types, name);
    free(bin);
}

static
void fill_instruction(instruction_t *ins, int nb_ins)
{
    ins[nb_ins].name = NULL;
    ins[nb_ins].instruction = 0;
    ins[nb_ins].op_code = 0;
    ins[nb_ins].nbr_args = 0;
}

static
void fill_args_and_type(int *args, int *type, int nbr_args)
{
    for (int i = 0; i < nbr_args; i++) {
        args[i] = 0;
        type[i] = 0;
    }
}

static
void get_info(instruction_t *ins, int nb_ins, char *buff, int i)
{
    ins[nb_ins].name = op_tab[(int) buff[i] - 1].mnemonique;
    ins[nb_ins].instruction = buff[i];
    ins[nb_ins].nbr_args = (int) op_tab[(int) buff[i] - 1].nbr_args;
    ins[nb_ins].type = malloc(sizeof(int) * ins[nb_ins].nbr_args);
    ins[nb_ins].args = malloc(sizeof(int) * ins[nb_ins].nbr_args);
    fill_args_and_type(ins[nb_ins].args, ins[nb_ins].type,
        ins[nb_ins].nbr_args);
}

instruction_t *get_instructions(char *buff, int *nb_ins)
{
    instruction_t *ins = malloc(sizeof(instruction_t));

    for (int i = 0; buff[i] != '\0';) {
        ins = realloc(ins, sizeof(instruction_t) * (*nb_ins + 1));
        fill_instruction(ins, *nb_ins);
        get_info(ins, *nb_ins, buff, i);
        if (verif_instruction(ins, *nb_ins, &i) == 1) {
            *nb_ins += 1;
            continue;
        }
        ins[*nb_ins].op_code = buff[i + 1];
        define_type(ins[*nb_ins].type, ins[*nb_ins].op_code,
            ins[*nb_ins].name);
        augmente_index(&i, ins, *nb_ins);
        *nb_ins += 1;
        i += 2;
    }
    return ins;
}
