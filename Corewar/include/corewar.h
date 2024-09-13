/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** asm.h
*/

#include "op.h"
#include <stdint.h>
#include <stdio.h>

#ifndef ROBOT_ASM_H
    #define ROBOT_ASM_H

    #include <stdbool.h>
    #define START_NAME &buff[4]
    #define START_COMMENT &buff[12 + PROG_NAME_LENGTH]
    #define PROG_SIZE buff[11 + PROG_NAME_LENGTH]
    #define START_INS 16 + PROG_NAME_LENGTH + COMMENT_LENGTH


typedef struct instruction_s {
    char *name;
    unsigned char instruction;
    unsigned char op_code;
    int *type;
    int *args;
    int nbr_args;
} instruction_t;

typedef struct champions_s {
    char *path;
    header_t *header;
    instruction_t *instruction;
    int nbr_ins;
    uint8_t *memory;
    int num;
    int address;
} champions_t;

typedef struct pc_s {
    int pc;
    char *name;
    char *instruction;
    int carry;
    int cycle;
    int live;
    int is_alive;
    int opcode;
    int registers[REG_NUMBER];
    int type[MAX_ARGS_NUMBER];
    int args[MAX_ARGS_NUMBER];
    int num_champs;
} pc_t;

typedef struct corewar_s {
    pc_t *pc;
    uint8_t *memory;
    int cycle;
    int cycle_to_die;
    int nbr_champs;
    int count_live;
    int nbr_alive;
    int dump;
    int last_live;
    char *winner;
} corewar_t;

int corewar(int ac, char **av);
void get_champ_info(champions_t *champs, int nbr_champs);
instruction_t *get_instructions(char *buff, int *nb_ins);
void get_params(instruction_t *ins, char *buff, int nb_ins);
int ini_memory(corewar_t *corewar);
void load_champions(champions_t *champs, corewar_t *corewar, int nbr_champs);
void print_memory(uint8_t *memory, int size);
void make_instruction(corewar_t *corewar);
void init_corewar(corewar_t *corewar, int nbr_champions, champions_t *champs);
void get_args(pc_t *pc, uint8_t *memory, int nb_args, int *index);
void define_type(int *types, int op_code, char *name);
void get_params_in_memory(pc_t *pc, int nb, corewar_t *c, int *i);
char *convert_int_to_hexa(int number);
int my_char_isnum(char c);
void put_value(int value1, corewar_t *c, int *index);
void check_len(char *str, int len, int type);

// INSTRUCTIONS
void live(int index, corewar_t *corewar);
void ld_f(int index, corewar_t *corewar);
void st_f(int index, corewar_t *corewar);
void add(int index, corewar_t *corewar);
void sub(int index, corewar_t *corewar);
void and_f(int index, corewar_t *corewar);
void or_f(int index, corewar_t *corewar);
void xor_f(int index, corewar_t *corewar);
void zjmp(int index, corewar_t *corewar);
void ldi(int index, corewar_t *corewar);
void sti(int index, corewar_t *corewar);
void fork_i(int index, corewar_t *corewar);
void lld(int index, corewar_t *corewar);
void lldi(int index, corewar_t *corewar);
void lfork(int index, corewar_t *corewar);
void aff(int index, corewar_t *corewar);
void print_memory(uint8_t *memory, int size);

#endif //ROBOT_ASM_H
