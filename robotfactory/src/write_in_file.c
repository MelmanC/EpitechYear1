/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** write_header.c
*/

#include "printf.h"
#include "asm.h"
#include "op.h"
#include "my.h"
#include <printf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

/* write the header in the file */
static
int write_header(header_t *header, FILE *fp)
{
    header->magic = to_big_endian(header->magic);
    header->prog_size = to_big_endian(header->prog_size);
    fwrite(header, sizeof(header_t), 1, fp);
    return 0;
}

static
void write_label_next(LN)
{
    int nb = 0;

    if (my_strcmp(&tmp[j][2], body->labels[k].label) == 0) {
        nb = body->labels[k].pos - body->line_size[i];
        nb = to_big_endian_index(nb);
        fwrite(&nb, sizeof(unsigned char), IND_SIZE, fp);
    }
}

static
void write_label(ALL)
{
    if (tmp[j][0] == DIRECT_CHAR && tmp[j][1] == LABEL_CHAR) {
        for (int k = 0; k < body->nb_labels; k++) {
            write_label_next(tmp, i, body, fp, j, k);
        }
    }
}

static
void write_direct(ALL)
{
    int nb = 0;

    nb = my_getnbr(&tmp[j][1]);
    if (body->types[i][j] == T_DIR) {
        nb = to_big_endian(nb);
        fwrite(&nb, sizeof(unsigned char), DIR_SIZE, fp);
    } else if (body->types[i][j] == INDEX) {
        nb = to_big_endian_index(nb);
        fwrite(&nb, sizeof(unsigned char), IND_SIZE, fp);
    }
}

static
void write_all(char **tmp, int i, body_t *body, FILE *fp)
{
    int nb = 0;

    for (int j = 0; tmp[j] != NULL; j++) {
        if (body->types[i][j] == T_REG) {
            nb = my_getnbr(&tmp[j][1]);
            fwrite(&nb, sizeof(unsigned char), 1, fp);
        }
        if (tmp[j][0] == DIRECT_CHAR && tmp[j][1] != LABEL_CHAR) {
            write_direct(tmp, i, body, fp, j);
        }
        write_label(tmp, i, body, fp, j);
        if (body->types[i][j] == T_IND) {
            nb = my_getnbr(tmp[j]);
            nb = to_big_endian_index(nb);
            fwrite(&nb, sizeof(unsigned char), IND_SIZE, fp);
        }
    }
}

static
int write_body(body_t *body, FILE *fp)
{
    char **tmp = NULL;

    for (int i = 0; i < body->nb_instructions; i++) {
        if (body->opcode[i] != 0)
            fwrite(&body->opcode[i], sizeof(unsigned char), 1, fp);
        if (body->binary[i] != 0)
            fwrite(&body->binary[i], sizeof(unsigned char), 1, fp);
        if (body->params[i] != NULL) {
            tmp = my_str_to_word_array(body->params[i], SEPARATOR_CHAR);
            write_all(tmp, i, body, fp);
        }
    }
    return 0;
}

/* write in the file */
int write_in_file(header_t *header, body_t *body, FILE *fp)
{
    write_header(header, fp);
    write_body(body, fp);
    return 0;
}
