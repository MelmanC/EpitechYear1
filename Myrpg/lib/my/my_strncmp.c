/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** function my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (!s1 || !s2)
        return 84;
    while (i < n && (s1[i] && s2[i])) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
        i += 1;
    }
    return 0;
}
