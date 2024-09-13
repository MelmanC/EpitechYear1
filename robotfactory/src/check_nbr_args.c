/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** check_nbr_args.c
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>

static
int good_number(char **tmp)
{
    int count = 0;
    int i = 0;

    if (tmp[0][my_strlen(tmp[i]) - 1] == LABEL_CHAR)
        i += 2;
    else
        i++;
    while (tmp[i] != NULL) {
        count++;
        i++;
    }
    return count;
}

static
int get_nbr_args(char *tmp)
{
    int nbr = 0;

    for (int j = 0; op_tab[j].mnemonique != 0; j++) {
        if (my_strcmp(tmp, op_tab[j].mnemonique) == 0) {
            nbr = op_tab[j].nbr_args;
            return nbr;
        }
    }
    return 0;
}

static
int on_label_nbr(char **tmp)
{
    int nbr = 0;
    int args = 0;

    if (tmp[1] == NULL)
        return 0;
    nbr = get_nbr_args(tmp[1]);
    args = good_number(tmp);
    if (args != nbr) {
        return 84;
    }
    return 0;
}

static
int not_on_label_nbr(char **tmp)
{
    int nbr = 0;
    int args = 0;

    nbr = get_nbr_args(tmp[0]);
    args = good_number(tmp);
    if (args != nbr) {
        return 84;
    }
    return 0;
}

int nbr_args(char **file)
{
    char **tmp = NULL;
    int value = 0;

    for (int i = 2; file[i] != NULL; i++) {
        file[i] = remove_tabulation(file[i]);
        tmp = my_str_to_word_array(file[i], ' ');
        if (tmp[0][my_strlen(tmp[0]) - 1] == LABEL_CHAR) {
            value = on_label_nbr(tmp);
        } else {
            value = not_on_label_nbr(tmp);
        }
        if (value == 84)
            return 84;
    }
    return 0;
}
