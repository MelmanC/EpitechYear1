/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** main.c
*/

#include "../include/amazed.h"
#include "../include/printf.h"
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdbool.h>

static
int get_line(char *buff)
{
    int lines = 0;

    if (buff == NULL)
        return 84;
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            lines++;
        }
    }
    return lines;
}

/*
open the labyrinth file and return 84 if it fails
*/
int open_file(all_t *all)
{
    char *buffer = NULL;
    size_t content = 0;
    ssize_t read_size;
    char *params[2] = {"\n", NULL};

    buffer = malloc(sizeof(char) * 4096 + 1);
    while (true) {
        read_size = read(STDIN_FILENO, buffer + content, 4096 - content);
        if (read_size == 0) {
            break;
        }
        content += read_size;
    }
    buffer[content] = '\0';
    all->map->map = malloc(sizeof(char *) * (get_line(buffer) + 1));
    all->map->map = my_str_to_word_array(buffer, params);
    all->map->map = remove_comment(all->map->map);
    free(buffer);
    return 0;
}
