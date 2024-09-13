/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** asm.h
*/

#include "op.h"
#include <stdio.h>

#ifndef ROBOT_ASM_H
    #define ROBOT_ASM_H
    #define TAB_LABELS (tab_len(body->labels) + 3)
    #define LENCOMM my_strlen(COMMENT_CMD_STRING)
    #define LN char **tmp, int i, body_t *body, FILE *fp, int j, int k
    #define ALL char **tmp, int i, body_t *body, FILE *fp, int j

typedef struct label_s {
    char *label;
    int pos;
} label_t;

typedef struct body_s {
    char **instructions;
    label_t *labels;
    char **params;
    unsigned char *binary;
    int **address;
    int *opcode;
    int nb_instructions;
    int *line_size;
    int global_size;
    int nb_labels;
    args_type_t **types;
} body_t;

void usage_info(void);
int read_file(char **av, header_t *header, body_t *body);
int store_header(char *buff, header_t *header);
char **clean_str(char **str);
char *remove_tabulation(char *str);
int write_in_file(header_t *header, body_t *body, FILE *fp);
unsigned char calculate_coding_byte(args_type_t *types);
int tab_len(char **tab);
int check_file(char **file, header_t *header);
char *define_params(char **tmp);
int check_if_label(char **file);
void verif_index(args_type_t *types, char *instruction);
int add_types_size(args_type_t *types);
args_type_t *parse_params(char *params);
char **remove_comment(char **file);
unsigned long to_big_endian(unsigned long x);
unsigned long to_big_endian_index(unsigned long x);
int nbr_args(char **file);
int last_check(char **line, body_t *body);

#endif //ROBOT_ASM_H
