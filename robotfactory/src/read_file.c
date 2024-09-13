/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** read_file.c
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

/* find the opcode of the instruction */
static
int opcode(char *instructions)
{
    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(instructions, op_tab[i].mnemonique) == 0)
            return op_tab[i].code;
    }
    return 0;
}

static
void find_label_next(body_t *body, char **tmp, int i)
{
    body->instructions[i] = my_strdup(tmp[1]);
    body->opcode[i] = opcode(body->instructions[i]);
    body->global_size += 1;
    body->params[i] = define_params(&tmp[2]);
    body->types[i] = parse_params(body->params[i]);
}

/* store all instructions inside the body structure (here if it's a label) */
static
int find_label(body_t *body, char **tmp, int i)
{
    body->nb_labels += 1;
    body->labels = realloc(body->labels, sizeof(label_t) * body->nb_labels);
    body->labels[body->nb_labels - 1].label = my_strdup(tmp[0]);
    body->labels[body->nb_labels - 1].label[my_strlen(tmp[0]) - 1] = '\0';
    body->labels[body->nb_labels - 1].pos = body->global_size;
    if (tmp[1] == NULL)
        return 0;
    find_label_next(body, tmp, i);
    if (my_strcmp(tmp[1], "live") == 0 || my_strcmp(tmp[1], "zjmp") == 0
    || my_strcmp(tmp[1], "fork") == 0 || my_strcmp(tmp[1], "lfork") == 0) {
        verif_index(body->types[i], body->instructions[i]);
        body->global_size += add_types_size(body->types[i]);
        return 0;
    }
    body->binary[i] = calculate_coding_byte(body->types[i]);
    body->global_size += 1;
    verif_index(body->types[i], body->instructions[i]);
    body->global_size += add_types_size(body->types[i]);
    return 0;
}

/* store all instructions inside the body structure
 * (here if it's not a label) */
static
int not_find_label(body_t *body, char **tmp, int i)
{
    body->instructions[i] = my_strdup(tmp[0]);
    body->params[i] = define_params(&tmp[1]);
    body->opcode[i] = opcode(body->instructions[i]);
    body->global_size += 1;
    body->types[i] = parse_params(body->params[i]);
    if (my_strcmp(tmp[0], "live") == 0 || my_strcmp(tmp[0], "zjmp") == 0
    || my_strcmp(tmp[0], "fork") == 0 || my_strcmp(tmp[0], "lfork") == 0) {
        verif_index(body->types[i], body->instructions[i]);
        body->global_size += add_types_size(body->types[i]);
        return 0;
    }
    body->binary[i] = calculate_coding_byte(body->types[i]);
    body->global_size += 1;
    verif_index(body->types[i], body->instructions[i]);
    body->global_size += add_types_size(body->types[i]);
    return 0;
}

/* store args inside their respective string */
static
int which_store(char **line, body_t *body)
{
    char **tmp = NULL;

    for (int i = 0; line[i] != NULL; i++) {
        body->line_size[i] = body->global_size;
        line[i] = remove_tabulation(line[i]);
        tmp = my_str_to_word_array(line[i], ' ');
        if (tmp[0][my_strlen(tmp[0]) - 1] == LABEL_CHAR) {
            find_label(body, tmp, i);
        } else {
            not_find_label(body, tmp, i);
        }
        body->nb_instructions++;
    }
    return 0;
}

/* malloc all */
static
int store_args(char **line, body_t *body)
{
    line = &line[2];
    line = clean_str(line);
    line = remove_comment(line);
    body->params = malloc(sizeof(char *) * tab_len(line) + 1);
    body->labels = malloc(sizeof(label_t));
    body->instructions = malloc(sizeof(char *) * tab_len(line) + 1);
    body->binary = malloc(sizeof(unsigned char) * tab_len(line) + 2);
    body->address = malloc(sizeof(int *) * tab_len(line) + 1);
    body->opcode = malloc(sizeof(int *) * tab_len(line) + 1);
    body->line_size = malloc(sizeof(int *) * tab_len(line) + 1);
    body->types = malloc(sizeof(args_type_t *) * tab_len(line) + 1);
    body->global_size = 0;
    body->nb_labels = 0;
    which_store(line, body);
    return 0;
}

static
int read_file_next(char *buff, header_t *header, body_t *body)
{
    char **line = NULL;

    line = my_str_to_word_array(buff, '\n');
    if (store_header(buff, header) == 84)
        return 84;
    if (check_file(line, header) == 84)
        return 84;
    store_args(line, body);
    if (last_check(line, body) == 84)
        return 84;
    return 0;
}

/* read the '.s', store header inside the header_t structure
 * and store all the body into structures */
int read_file(char **av, header_t *header, body_t *body)
{
    struct stat st;
    FILE *file = fopen(av[1], "r");
    char *buff = NULL;

    if (file == NULL)
        return 84;
    stat(av[1], &st);
    buff = malloc(sizeof(char) * st.st_size);
    if (buff == NULL)
        return 84;
    fread(buff, 1, st.st_size, file);
    fclose(file);
    if (read_file_next(buff, header, body) == 84)
        return 84;
    return 0;
}
