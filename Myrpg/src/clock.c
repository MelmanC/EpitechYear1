/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-nolann.dubos
** File description:
** clock.c
*/

#include "functions.h"

wclock_t *init_clock(void)
{
    wclock_t *clock = malloc(sizeof(wclock_t));

    if (!clock)
        return NULL;
    clock->window = sfClock_create();
    return clock;
}

void set_clock_var(wclock_t *clock)
{
    clock->window_sec = SF_SECONDS(sfClock_getElapsedTime(clock->window));
}
