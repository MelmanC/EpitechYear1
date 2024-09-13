/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** main.c
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>

static
void free_all(champions_t *champs, corewar_t *corewar, int nbr_champs)
{
    for (int i = 0; i < nbr_champs; i++) {
        free(champs[i].header);
        for (int j = 0; j < champs[i].nbr_ins; j++) {
            free(champs[i].instruction[j].args);
            free(champs[i].instruction[j].type);
        }
        free(champs[i].instruction);
    }
    free(champs);
    free(corewar->pc);
    free(corewar->memory);
    free(corewar);
}

static
void fill_champ_struct(champions_t *champs, int nbr_champs)
{
    champs[nbr_champs].num = 0;
    champs[nbr_champs].address = 0;
    champs[nbr_champs].path = NULL;
}

static
void define_num(champions_t *champ, champions_t *all_champs, int nbr_champs)
{
    int num = 1;

    for (int i = 0; i < nbr_champs; i++) {
        if (all_champs[i].num == num) {
            num += 1;
            i = -1;
        }
    }
    champ->num = num;
}

static
int get_dump(char **av, corewar_t *corewar)
{
    int index = 1;

    corewar->dump = -1;
    if (my_strcmp(av[1], "-dump") == 0) {
        corewar->dump = my_getnbr(av[2]);
        index += 2;
    }
    return index;
}

static
champions_t *parseur(int ac, char **av, int *nbr_champs, corewar_t *corewar)
{
    champions_t *champs = malloc(sizeof(champions_t));
    int index = get_dump(av, corewar);

    for (; index < ac; index++) {
        champs = realloc(champs, sizeof(champions_t) * (*nbr_champs + 1));
        fill_champ_struct(champs, *nbr_champs);
        if (my_strcmp(av[index], "-n") == 0) {
            champs[*nbr_champs].num = my_getnbr(av[index + 1]);
            index += 2;
        } else
            define_num(&champs[*nbr_champs], champs, *nbr_champs);
        if (my_strcmp(av[index], "-a") == 0) {
            champs[*nbr_champs].address = my_getnbr(av[index + 1]) % MEM_SIZE;
            index += 2;
        } else
            champs[*nbr_champs].address = -1;
        champs[*nbr_champs].path = av[index];
        *nbr_champs += 1;
    }
    return champs;
}

static
void sort_next(champions_t *champs, champions_t tmp, int j)
{
    if (champs[j].num > champs[j + 1].num) {
        tmp = champs[j];
        champs[j] = champs[j + 1];
        champs[j + 1] = tmp;
    }
}

static
void sort(champions_t *champs, int n)
{
    champions_t tmp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            sort_next(champs, tmp, j);
        }
    }
}

int corewar(int ac, char **av)
{
    champions_t *champs = NULL;
    corewar_t *corewar = malloc(sizeof(corewar_t));
    int nbr_champs = 0;

    if (ac < 2)
        return 84;
    champs = parseur(ac, av, &nbr_champs, corewar);
    if (champs == NULL)
        return 84;
    if (nbr_champs < 2 || nbr_champs > 4)
        return 84;
    get_champ_info(champs, nbr_champs);
    sort(champs, nbr_champs);
    init_corewar(corewar, nbr_champs, champs);
    ini_memory(corewar);
    load_champions(champs, corewar, nbr_champs);
    make_instruction(corewar);
    free_all(champs, corewar, nbr_champs);
    return 0;
}
