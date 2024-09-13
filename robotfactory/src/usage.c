/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** usage.c
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/* display -h info */
void usage_info(void)
{
    int fd = 0;
    char *buff = NULL;
    struct stat st;
    int size = 0;

    stat("./src/usage", &st);
    size = st.st_size;
    fd = open("./src/usage", O_RDONLY);
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    close(fd);
    write(1, buff, size);
    write(1, "\n", 1);
}
