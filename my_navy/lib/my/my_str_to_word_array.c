/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** str to word array
*/

#include <stddef.h>
#include <stdlib.h>

static int is_separator(char c, char separator)
{
    return c == separator;
}

static char *my_next(char *string, char separator)
{
    for (int i = 0; string[i] != '\0'; i += 1) {
        if (is_separator(string[i], separator) == 0) {
            return &string[i];
        }
    }
    return NULL;
}

static int my_length(char *string, char separator)
{
    int i = 0;

    while (string[i] != '\0' && is_separator(string[i], separator) == 0)
        i += 1;
    return i;
}

static int word_count(char const *str, char separator)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (is_separator(str[i], separator) == 0 && (str[i + 1] == '\0'
            || is_separator(str[i + 1], separator) == 1)) {
            count += 1;
        }
    }
    return count;
}

char **my_str_to_word_array(char const *str, char sepatatr)
{
    char **tab;
    int x = 0;

    tab = malloc(sizeof(char *) * (word_count(str, sepatatr) + 1));
    while (*str != '\0') {
        str = my_next((char *)str, sepatatr);
        if (str == NULL) {
            tab[x] = NULL;
            return tab;
        }
        tab[x] = malloc(sizeof(char) * (my_length((char *)str, sepatatr) + 1));
        for (int i = 0; i < my_length((char *)str, sepatatr); i += 1) {
            tab[x][i] = str[i];
        }
        tab[x][my_length((char *)str, sepatatr)] = '\0';
        x += 1;
        str += my_length((char *)str, sepatatr);
    }
    tab[x] = NULL;
    return tab;
}
