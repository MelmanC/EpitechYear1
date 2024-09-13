/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** function my_strlen
*/

int my_strlen(char const *str)
{
    int number = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        number += 1;
    }
    return number;
}
