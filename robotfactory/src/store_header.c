/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** store_header.c
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
#include <string.h>

/* store name inside header->prog_name */
static
int store_name(char *str, header_t *header)
{
    int i = 0;
    int j = 0;

    while (str[i] != '"') {
        i++;
    }
    i++;
    while (str[i] != '"') {
        header->prog_name[j] = str[i];
        i++;
        j++;
    }
    return 0;
}

/* store comment inside header->comment */
static
int store_comment(char *str, header_t *header)
{
    int i = 0;
    int j = 0;

    while (str[i] != '"') {
        i++;
    }
    i++;
    while (str[i] != '"') {
        header->comment[j] = str[i];
        i++;
        j++;
    }
    return 0;
}

/* choose if it's a .name or .comment and go to the appropriate function */
static
int choose_store(char **tab, header_t *header, int i)
{
    int cmpt = 0;

    if (my_strncmp(tab[i], NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0) {
        store_name(tab[i], header);
        cmpt++;
    }
    if (my_strncmp(tab[i], COMMENT_CMD_STRING, LENCOMM) == 0) {
        store_comment(tab[i], header);
        cmpt++;
    }
    return cmpt;
}

static
int check_quotes(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == '"')
            count++;
        i++;
    }
    if (count != 2)
        return 84;
    return 0;
}

/* store the header inside a structure by calling
 * choose_store() to decide if is name or comment */
int store_header(char *buff, header_t *header)
{
    char **file = my_str_to_word_array(buff, '\n');
    int cmpt = 0;

    file = clean_str(file);
    file = remove_comment(file);
    for (int i = 0; file[i] != NULL; i++) {
        if (i < 2 && check_quotes(file[i]) == 84)
            return 84;
        cmpt += choose_store(file, header, i);
    }
    if (cmpt != 2) {
        my_printf("Error: .name or .comment missing\n");
        return 84;
    }
    return 0;
}
