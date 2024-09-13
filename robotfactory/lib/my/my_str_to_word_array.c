/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** str to word array
*/

#include <stddef.h>
#include <stdlib.h>
#include "include/my.h"

int count_words(const char *str, char separ)
{
    int words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != separ && (i == 0 || str[i - 1] == separ))
            words++;
    }
    return words;
}

char **my_str_to_word_array(char *str, char separ)
{
    int words = count_words(str, separ);
    char **array = malloc(sizeof(char *) * words + 1);
    int length = 0;

    for (int i = 0; i < words; i++) {
        length = 0;
        while (*str == separ) {
            str++;
        }
        while (str[length] != '\0' && str[length] != separ)
            length++;
        array[i] = malloc(sizeof(char) * length + 1);
        my_strncpy(array[i], str, length);
        array[i][length] = '\0';
        str += length;
    }
    array[words] = NULL;
    return array;
}
