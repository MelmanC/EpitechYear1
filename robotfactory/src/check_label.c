/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** check_label.c
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>

static
int check_if_instructions(char *tmp)
{
    if (tmp == NULL)
        return 0;
    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(op_tab[i].mnemonique, tmp) == 0) {
            return 0;
        }
    }
    return 84;
}

static
int check_if_double_label(char **tmp)
{
    if (tmp[1] == NULL)
        return 0;
    if (tmp[1][my_strlen(tmp[1]) - 1] == LABEL_CHAR)
        return 84;
    return 0;
}

static
int check_label_next(char **tmp)
{
    int err = 0;
    int value = 0;

    if (tmp[0][my_strlen(tmp[0]) - 1] != LABEL_CHAR) {
        value = check_if_instructions(tmp[0]);
    } else if (tmp[0][my_strlen(tmp[0]) - 1] == LABEL_CHAR) {
        err = check_if_double_label(tmp);
        value = check_if_instructions(tmp[1]);
    }
    if (value == 84 || err == 84) {
        return 84;
    }
    return 0;
}

/* check if a label_char is at the end */
int check_if_label(char **file)
{
    char **tmp = NULL;
    int value = 0;

    for (int i = 2; file[i] != NULL; i++) {
        file[i] = remove_tabulation(file[i]);
        tmp = my_str_to_word_array(file[i], ' ');
        value = check_label_next(tmp);
        if (value == 84) {
            return 84;
        }
    }
    return 0;
}
