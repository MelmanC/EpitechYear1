/*
** EPITECH PROJECT, 2024
** my_puts
** File description:
** my_putstr but with specified fd
*/

#include <unistd.h>
#include "../../include/my.h"

int my_puts(int fd, char const *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        write(fd, &str[i], 1);
    }
    return 0;
}
