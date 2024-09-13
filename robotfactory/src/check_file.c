/*
** EPITECH PROJECT, 2024
** robot
** File description:
** check_file.c
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>

/* check if the name and comment are present and not too long */
static
int check_name_comment(header_t *header)
{
    if (my_strlen(header->prog_name) > PROG_NAME_LENGTH)
        return 84;
    if (my_strlen(header->comment) > COMMENT_LENGTH)
        return 84;
    return 0;
}

static
int check_param_type(char *param, int type)
{
    if (param[0] == 'r' && (type & T_REG))
        return 0;
    if (param[0] == '%' && (type & T_DIR))
        return 0;
    if ((param[0] == '%' || (param[0] >= '0' && param[0] <= '9'))
        && (type & T_IND))
        return 0;
    return 84;
}

static
int check_value(char **tmp, int i)
{
    for (int j = 1; tmp[j] != NULL; j++) {
        if (check_param_type(tmp[j], op_tab[i].type[j - 1]) == 84) {
            return 84;
        }
    }
    return 0;
}

static
int type_param(char **tmp)
{
    int value;

    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(op_tab[i].mnemonique, tmp[0]) == 0) {
            value = check_value(tmp, i);
        }
        if (value == 84)
            return 84;
    }
    return 0;
}

int check_type_param(char **file)
{
    char **tmp = NULL;
    int value = 0;

    for (int i = 2; file[i] != NULL; i++) {
        file[i] = remove_tabulation(file[i]);
        tmp = my_str_to_word_array(file[i], ' ');
        if (tmp[0][my_strlen(tmp[0]) - 1] == LABEL_CHAR) {
            value = type_param(tmp);
        } else {
            value = type_param(tmp);
        }
        if (value == 84)
            return 84;
    }
    return 0;
}

/* check all the error in the file */
int check_file(char **file, header_t *header)
{
    file = clean_str(file);
    file = remove_comment(file);
    if (check_name_comment(header) == 84) {
        my_printf("Error: name or comment is missing or too long\n");
        return 84;
    }
    if (check_if_label(file) == 84) {
        my_printf("Error: label is missing\n");
        return 84;
    }
    if (nbr_args(file) == 84) {
        my_printf("Error: instruction is missing\n");
        return 84;
    }
    if (check_type_param(file) == 84) {
        my_printf("Error: wrong type of parameter\n");
        return 84;
    }
    return 0;
}
