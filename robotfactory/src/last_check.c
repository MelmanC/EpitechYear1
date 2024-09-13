/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** last_check.c
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>

static
int check_label_dnext(body_t *body, int i)
{
    for (int j = i + 1; body->labels[j].label != NULL; j++) {
        if (my_strcmp(body->labels[i].label, body->labels[j].label) == 0) {
            return 84;
        }
    }
    return 0;
}

static
int check_label_double(body_t *body)
{
    for (int i = 0; body->labels[i].label != NULL; i++) {
        if (check_label_dnext(body, i) == 84) {
            return 84;
        }
    }
    return 0;
}

int last_check(char **line, body_t *body)
{
    if (check_label_double(body) == 84)
        return 84;
    return 0;
}
