/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** get_type.c
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* add size for global_size */
int add_types_size(args_type_t *types)
{
    int size = 0;

    for (int i = 0; types[i] != 0; i++) {
        if (types[i] == INDEX)
            size += IND_SIZE;
        if (types[i] == T_DIR)
            size += DIR_SIZE;
        if (types[i] == T_IND)
            size += IND_SIZE;
        if (types[i] == T_REG)
            size += 1;
    }
    return size;
}

/* verif if an instruction can take index */
void verif_index(args_type_t *types, char *instruction)
{
    if (my_strcmp(instruction, "sti") == 0) {
        if (types[1] == T_DIR)
            types[1] = INDEX;
        if (types[2] == T_DIR)
            types[2] = INDEX;
    }
    if (my_strcmp(instruction, "ldi") == 0
        || my_strcmp(instruction, "lldi") == 0) {
        if (types[0] == T_DIR)
            types[0] = INDEX;
        if (types[1] == T_DIR)
            types[1] = INDEX;
    }
    if (my_strcmp(instruction, "zjmp") == 0)
        types[0] = INDEX;
    if (my_strcmp(instruction, "fork") == 0
        || my_strcmp(instruction, "lfork") == 0)
        types[0] = INDEX;
}

static
void params_next(char **tokens, args_type_t *types, int i)
{
    if (tokens[i][0] == 'r') {
        types[i] = T_REG;
        return;
    }
    if (tokens[i][0] == DIRECT_CHAR) {
        types[i] = T_DIR;
        return;
    }
    types[i] = T_IND;
}

/* give the type of the args */
args_type_t *parse_params(char *params)
{
    args_type_t *types = malloc(sizeof(args_type_t) * MAX_ARGS_NUMBER);
    char **token = my_str_to_word_array(params, SEPARATOR_CHAR);

    for (int i = 0; token[i] != NULL; i++)
        params_next(token, types, i);
    return types;
}
