/*
** EPITECH PROJECT, 2023
** my_navy [WSL: fedora]
** File description:
** get.c
*/

#include "../include/navy.h"
#include "../include/printf.h"
#include "../include/my.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int get_line(char *buff)
{
    int lines = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            lines++;
        }
    }
    return lines;
}
