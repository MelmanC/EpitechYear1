/*
** EPITECH PROJECT, 2024
** robot
** File description:
** to_binary.c
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

unsigned char calculate_coding_byte(args_type_t *types)
{
    unsigned char coding_byte = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        coding_byte = coding_byte << 2;
        if (types[i] == T_IND)
            coding_byte += 3;
        else
            coding_byte += types[i];
    }
    return coding_byte;
}
