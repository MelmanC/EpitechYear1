/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** create_map.c
*/

#include "../include/navy.h"
#include "../include/printf.h"
#include "../include/my.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

static int transform_map(game_t *game, char *buff)
{
    game->map = NULL;
    game->map2 = NULL;
    game->line = get_line(buff);
    game->map = my_str_to_word_array(buff, '\n');
    game->map2 = my_str_to_word_array(buff, '\n');
    return 0;
}

int open_map(game_t *game)
{
    int fd = 0;
    char *buff = NULL;
    int size = 0;

    fd = open("res/map", O_RDONLY);
    if (fd == -1)
        return 84;
    size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    buff[size] = '\0';
    transform_map(game, buff);
    close(fd);
    return 0;
}
