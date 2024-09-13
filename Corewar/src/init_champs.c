/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** test.c
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
void get_magic_number(char *buff, header_t *info)
{
    info->magic += (buff[1] & 0x000000FF) << 16;
    info->magic += (buff[2] & 0x000000FF) << 8;
    info->magic += (buff[3] & 0x000000FF) << 0;
}

static
char *get_buff(char *path, char *buff)
{
    struct stat st = {0};
    FILE *file = NULL;

    stat(path, &st);
    buff = malloc(sizeof(char) * st.st_size + 1);
    file = fopen(path, "r");
    fread(buff, 1, st.st_size, file);
    buff[st.st_size] = '\0';
    fclose(file);
    return buff;
}

void get_champ_info(champions_t *champs, int nbr_champs)
{
    char *buff = NULL;

    for (int i = 0; i < nbr_champs; i++) {
        buff = get_buff(champs[i].path, buff);
        champs[i].header = malloc(sizeof(header_t));
        champs[i].instruction = malloc(sizeof(instruction_t));
        champs[i].nbr_ins = 0;
        get_magic_number(buff, champs[i].header);
        my_strncpy(champs[i].header->prog_name, START_NAME, PROG_NAME_LENGTH);
        my_strncpy(champs[i].header->comment, START_COMMENT, COMMENT_LENGTH);
        champs[i].header->prog_size = (int) PROG_SIZE;
        champs[i].instruction = get_instructions(&buff[START_INS],
            &champs[i].nbr_ins);
        get_params(champs[i].instruction, &buff[START_INS], champs[i].nbr_ins);
        free(buff);
    }
}
