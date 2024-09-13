/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** function my_putchar
*/

#include <unistd.h>

int my_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return 84;
    return 0;
}
