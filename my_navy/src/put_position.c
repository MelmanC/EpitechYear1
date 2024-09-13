/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** put_position.c
*/

#include "../include/navy.h"
#include "../include/printf.h"
#include "../include/my.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

static void ini_pos(position_t *position)
{
    position->number = 0;
    position->len = 0;
    position->x = 0;
    position->y = 0;
    position->end_x = 0;
    position->end_y = 0;
}

static void horiz_boat(game_t *game, position_t *position, int i, char **pos)
{
    for (int j = position->y; j <= position->end_y; j++)
        game->map[j][position->x * 2] = pos[i][0];
}

static void vert_boat(game_t *game, position_t *position, int i, char **pos)
{
    for (int j = position->x; j <= position->end_x; j++) {
        if (game->map[position->y][j * 2] == '.')
            game->map[position->y][j * 2] = pos[i][0];
        else
            position->end_x++;
    }
}

static int err_pos_next(position_t *position)
{
    if (position->len > 5 || position->len < 2)
        return 84;
    if (position->x > 8 || position->x < 1)
        return 84;
    if (position->y > 8 || position->y < 1)
        return 84;
    if (position->end_x > 9 || position->end_x < 1)
        return 84;
    if (position->end_y > 9 || position->end_y < 1)
        return 84;
    if (position->number > 4)
        return 84;
    return 0;
}

static int error_pos(position_t *position)
{
    int actual_len = 0;

    if (position->x == position->end_x)
        actual_len = position->end_y - position->y + 1;
    else if (position->y == position->end_y)
        actual_len = position->end_x - position->x + 1;
    else
        return 84;
    if (position->len != actual_len)
        return 84;
    if (position->len != position->end_x - position->x + 1 &&
        position->len != position->end_y - position->y + 1)
        return 84;
    if (err_pos_next(position) == 84)
        return 84;
    return 0;
}

static int index_boat(position_t *position, char **pos, int i, int *boats)
{
    position->number += 1;
    position->len = my_getnbr(&pos[i][0]);
    position->x = pos[i][2] - 'A' + 1;
    position->y = pos[i][3] - '0' + 1;
    position->end_x = pos[i][5] - 'A' + 1;
    position->end_y = pos[i][6] - '0' + 1;
    if (boats[position->len - 2] == 1)
        return 84;
    boats[position->len - 2] = 1;
    if (error_pos(position) == 84)
        return 84;
    return 0;
}

static int get_pos(game_t *game, char *buff)
{
    position_t *position = malloc(sizeof(position_t));
    char **pos = my_str_to_word_array(buff, '\n');
    int boats[5] = {0, 0, 0, 0, 0};

    ini_pos(position);
    for (int i = 0; pos[i] != NULL; i++) {
        if (index_boat(position, pos, i, boats) == 84) {
            free(position);
            return 84;
        }
        if (position->x == position->end_x)
            horiz_boat(game, position, i, pos);
        else
            vert_boat(game, position, i, pos);
    }
    free(position);
    return 0;
}

int put_position(game_t *game, char *av)
{
    int fd = 0;
    char *buff = NULL;
    int size = 0;

    fd = open(av, O_RDONLY);
    if (fd == -1)
        return 84;
    size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    buff[size] = '\0';
    if (get_pos(game, buff) == 84)
        return 84;
    close(fd);
    return 0;
}
