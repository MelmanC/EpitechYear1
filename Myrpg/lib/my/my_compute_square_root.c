/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** function my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int square_root = 1;
    int nbr = nb;

    for (int i = 1; i * i < nb; i += 1) {
        if (i * i != nb)
            square_root += 1;
        else
            return 0;
    }
    if (square_root > 46340 || square_root < -46340)
        return 0;
    if (nb == 0)
        return 0;
    if (nb == 1)
        return 1;
    if (nb < 0)
        return 0;
    else
    return square_root;
}
