/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** function my_compute_power_rec
*/

int my_compute_power_rec(int nb, int power)
{
    int result = 1;
    int nbr = nb;

    if (nbr < 0)
        nbr *= -1;
    if (power == 0)
        return 1;
    if (power < 0 || power > 31)
        return 0;
    if (result > 2147483647 / nbr)
        return 0;
    if (result < -2147483648 / nbr)
        return 0;
    else
        result = my_compute_power_rec(nb, power - 1) * nbr;
    if (nb < 0) {
        result *= -1;
        return result;
    } else
        return result;
}
