/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** ld.c
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

char *convert_int_to_hexa(int number)
{
    char *hexa = malloc(sizeof(char) * 10);
    int i = 0;
    int letter = 0;

    while (number != 0) {
        letter = number % 16;
        if (letter < 10) {
            hexa[i] = letter + '0';
        } else {
            hexa[i] = letter + 'a' - 10;
        }
        number /= 16;
        i++;
    }
    hexa[i] = '\0';
    hexa = my_revstr(hexa);
    return hexa;
}

int my_char_isnum(char c)
{
    if (c < '0' || c > '9')
        return 0;
    return 1;
}

static
void loop_on_str(corewar_t *corewar, char *str, int *index)
{
    uint8_t tmp = 0;

    for (int l = 0; str[l] != '\0'; l++) {
        if (my_char_isnum(str[l]) == 1)
            tmp = (str[l] - '0') << 4;
        else
            tmp = (str[l] - 'a' + 10) << 4;
        l += 1;
        if (my_char_isnum(str[l]) == 1)
            tmp += str[l] - '0';
        else
            tmp += str[l] - 'a' + 10;
        corewar->memory[*index] = tmp;
        *index += 1;
    }
}

void put_value(int value1, corewar_t *c, int *index)
{
    char *str = NULL;
    int len = 0;

    str = convert_int_to_hexa(value1);
    len = my_strlen(str);
    check_len(str, len, T_DIR);
    loop_on_str(c, str, index);
    free(str);
}
