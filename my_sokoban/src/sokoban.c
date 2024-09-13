/*
** EPITECH PROJECT, 2023
** PSU-100
** File description:
** sokoban.c
*/

#include "../include/printf.h"
#include "../include/my.h"
#include "../include/sokoban.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>

void usage(void)
{
    int fd = 0;
    char *buff = NULL;
    struct stat st;
    int size = 0;

    stat("./src/usage", &st);
    size = st.st_size;
    fd = open("./src/usage", O_RDONLY);
    buff = malloc(sizeof(char) * (size + 1));
    read(fd , buff, size);
    close(fd);
    write(1, buff, size);
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    int err = 0;

    if (ac == 1)
        return 84;
    if (my_strcmp(av[1], "-h") == 0) {
        usage();
        return 0;
    }
    err = open_map(av[1]);
    if (err == 1)
        return 1;
    if (err == 84)
        return 84;
    return 0;
}
