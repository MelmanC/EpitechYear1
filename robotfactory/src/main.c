/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** main.c
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>

static
char *remove_slash(char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        if (src[i] == '/') {
            return &src[i + 1];
        }
        i++;
    }
    return src;
}

/* change the extension of the file */
static
char *change_extensions(char **av)
{
    int i = 0;
    char *name = NULL;

    i = my_strlen(av[1]);
    name = malloc(sizeof(char) * i);
    while (i != 0) {
        if (av[1][i] == '.')
            break;
        i--;
    }
    name = my_strncpy(name, av[1], i);
    name = remove_slash(name);
    name = my_strcat(name, ".cor");
    return name;
}

/* ini structure value */
static
void init_struct(header_t *header, body_t *body)
{
    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = 0;
    body->instructions = NULL;
    body->labels = NULL;
    body->params = NULL;
    body->binary = NULL;
    body->address = NULL;
}

/* check params and return 84 or 0 */
static
int check_params(int ac, char **av)
{
    if (ac == 1)
        return 84;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usage_info();
        return 0;
    }
    return 0;
}

/* main function, load the program */
int main(int ac, char **av)
{
    header_t *header = malloc(sizeof(header_t));
    body_t *body = malloc(sizeof(body_t));
    FILE *fp = NULL;
    char *name = NULL;

    if (check_params(ac, av) == 84)
        return 84;
    init_struct(header, body);
    if (read_file(av, header, body) == 84)
        return 84;
    name = change_extensions(av);
    header->prog_size = body->global_size;
    fp = fopen(name, "w");
    if (fp == NULL)
        return 84;
    write_in_file(header, body, fp);
    fclose(fp);
    return 0;
}
