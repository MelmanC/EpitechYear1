/*
** EPITECH PROJECT, 2024
** robot
** File description:
** utils.c
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"
#include <stdlib.h>

/* strlen of a char ** */
int tab_len(char **tab)
{
    int cmpt = 0;

    for (int i = 0; tab[i] != NULL; i++)
        cmpt++;
    return cmpt;
}

/* clean space in the file for parse it */
char **clean_str(char **str)
{
    int j = 0;

    for (int i = 0; str[i] != NULL; i++) {
        j = 0;
        while (str[i][j] == ' ' || str[i][j] == '\t') {
            j++;
        }
        if (j > 0) {
            my_strcpy(str[i], str[i] + j);
        }
    }
    return str;
}

char *remove_tabulation(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    return str;
}

/* add params to the string */
char *define_params(char **tmp)
{
    char *str = tmp[0];

    for (int i = 1; tmp[i] != NULL; i++) {
        str = my_strcat(str, tmp[i]);
    }
    str[my_strlen(str)] = '\0';
    return str;
}

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
        if (file[i][0] != COMMENT_CHAR) {
            file2[line] = my_strdup(file[i]);
            line++;
        }
    }
    file2[line] = NULL;
    return file2;
}

static
char **remove_comment_next(char **file, int i, int j)
{
    if (file[i][0] == COMMENT_CHAR) {
        file = remove_all_line(file);
        return file;
    }
    if (file[i][j] == COMMENT_CHAR) {
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
