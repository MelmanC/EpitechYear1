/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** main.c
*/

#include "../include/amazed.h"
#include "../include/printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

static
char **remove_all_line(char **file)
{
    int lines = 0;
    char **file2 = NULL;
    int line = 0;

    while (file[lines] != NULL)
        lines++;
    file2 = malloc(sizeof(char *) * (lines + 1));
    for (int i = 0; i < lines; i++) {
        if (file[i][0] != '#' || (file[i][0] == '#' && file[i][1] == '#')) {
            file2[line] = file[i];
            line++;
        }
    }
    file2[line] = NULL;
    return file2;
}

static
char **remove_comment_next(char **file, int i, int j)
{
    if (file[i][0] == '#') {
        file = remove_all_line(file);
        return file;
    }
    if (file[i][j] == '#') {
        while (file[i][j] != '\0') {
            file[i][j] = '\0';
            j++;
        }
    }
    return file;
}

char **remove_comment(char **file)
{
    for (int i = 0; file[i] != NULL; i++) {
        for (int j = 0; file[i][j] != '\0'; j++) {
            file = remove_comment_next(file, i, j);
        }
    }
    return file;
}
