/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** function my_swap
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
