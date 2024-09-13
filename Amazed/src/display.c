/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** main.c
*/

#include "../include/amazed.h"
#include "../include/printf.h"
#include "../include/my.h"
#include "../include/macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

static
void display_rooms(all_t *all)
{
    static int write_start = 0;

    if (all->map->line_next > -1 && write_start == 0) {
        my_printf("#rooms\n");
        write_start = 1;
    }
    if (write_start == 0 && NO_START_ROOM == 1){
        my_printf("#rooms\n");
        write_start = 1;
    }
    if (write_start == 0 && NO_END_ROOM == 1) {
        my_printf("#rooms\n");
        write_start = 1;
    }
}

static
void display_tunnel(all_t *all)
{
    static int write_tunnel = 0;

    if (TUNNEL == 1 && write_tunnel == 0) {
        my_printf("#tunnels\n");
        write_tunnel = 1;
    }
}

/*
Display rooms and tunnels
*/
int display_need(all_t *all)
{
    display_rooms(all);
    display_tunnel(all);
    return 0;
}
