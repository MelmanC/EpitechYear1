/*
** EPITECH PROJECT, 2023
** my_show_word_array
** File description:
** function my_show_word_array
*/

#include <string.h>
#include "../../include/my.h"

void my_show_word_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i += 1) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
