/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** create_matrix.c
*/

#include "../include/amazed.h"
#include "../include/my.h"
#include "../include/macro.h"
#include "../include/printf.h"
#include <stdlib.h>

/*
 @Purpose: Display the matrix
 @params: int **matrix
 The function will display the matrix
*/
void display_matrix(int **matrix)
{
    my_printf("  ");
    for (int i = 0; matrix[i] != NULL; i++)
        my_printf("%d ", i);
    my_printf("\n");
    for (int i = 0; matrix[i] != NULL; i++) {
        my_printf("%d ", i);
        for (int j = 0; matrix[i][j] != -1; j++)
            my_printf("%d ", matrix[i][j]);
        my_printf("\n");
    }
}

/*
 @Purpose: Initialize a matrix
 @params: int size
 The function will initialize an int** to 0 and
 put a -1 at the end of each int *
*/
int **create_matrix(int size)
{
    int **matrix = malloc(sizeof(int *) * size + 12);

    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(sizeof(int) * size + 12);
        for (int j = 0; j < size; j++)
            matrix[i][j] = 0;
        matrix[i][size] = -1;
    }
    matrix[size] = NULL;
    return matrix;
}

/*
 @Purpose: Update the matrix
 @params: all_t *all, int x, int y
 The function will update the matrix at the position x, y to 1
 to indicate that there is a path between x and y
*/
int update_matrix(all_t *all, int x, int y)
{
    if (x < 0 || y < 0 || x >= NB_ROOMS || y >= NB_ROOMS)
        return 84;
    all->matrix[x][y] = 1;
    all->matrix[y][x] = 1;
    return 0;
}
