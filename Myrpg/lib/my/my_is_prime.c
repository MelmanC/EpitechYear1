/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** function my_is_prime
*/

int my_is_prime(int nb)
{
    if (nb <= 1) {
        return 0;
    }
    for (int i = 2; i < nb; i += 1) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
