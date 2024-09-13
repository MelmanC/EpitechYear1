/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** utils.c
*/

#include "functions.h"

void free_mem(all_t *all)
{
    free(all);
}

void help_message(void)
{
    my_putstr(BLD "HELP\n\n" RESET);
    my_putstr("To run the game, do \"./my_rpg\".\n");
}
