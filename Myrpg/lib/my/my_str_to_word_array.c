/*
** EPITECH PROJECT, 2024
** lib
** File description:
** my_str_to_word_array.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int is_separator(char c, char *separators)
{
    for (int i = 0; separators[i] != '\0'; i++) {
        if (c == separators[i]) {
            return 1;
        }
    }
    return 0;
}

static char *my_next(char *str, char *separators)
{
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i += 1) {
        if (!is_separator(str[i], separators)) {
            return &str[i];
        }
    }
    return NULL;
}

static int len(char *str, char *separators)
{
    int i = 0;

    while (str[i] != '\0' && !is_separator(str[i], separators)
        && str[i] != '\n')
        i += 1;
    return i;
}

static int word_count(char const *str, char *separators)
{
    int count = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i += 1) {
        if (!is_separator(str[i], separators) && (str[i + 1] == '\0'
            || is_separator(str[i + 1], separators))) {
            count += 1;
        }
    }
    return count;
}

char **my_str_to_word_array(char const *str, char *separators)
{
    char **tab;
    int x = 0;

    tab = malloc(sizeof(char *) * (word_count(str, separators) + 1));
    while (*str != '\0' && *str != '\n') {
        str = my_next((char *)str, separators);
        if (str == NULL) {
            tab[x] = NULL;
            return tab;
        }
        tab[x] = malloc(sizeof(char) * (len((char *)str, separators) + 1));
        for (int i = 0; i < len((char *)str, separators); i += 1) {
            tab[x][i] = str[i];
        }
        tab[x][len((char *)str, separators)] = '\0';
        x += 1;
        str += len((char *)str, separators);
    }
    tab[x] = NULL;
    return tab;
}
