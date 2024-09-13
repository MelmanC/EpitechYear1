/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** test_display.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/amazed.h"
#include "../include/my.h"
#include "../include/printf.h"

Test(amazed, should_print_expected_output, .init = cr_redirect_stdout)
{
    freopen("ressources/laby", "r", stdin);
    amazed();
    cr_assert_stdout_eq_str("#number_of_robots\n3\n##start\n1 23 3\n#rooms\n2 16 7\n3 16 3\n4 16 5\n5 9 3\n6 1 0\n7 4 8\n##end\n0 9 5\n#tunnels\n0-4\n0-6\n1-3\n4-3\n5-2\n3-5\n4-2\n2-1\n7-6\n7-2\n7-4\n6-5\n#moves\nP1-2 P2-3\nP1-4 P3-2 P2-5\nP1-0 P3-4 P2-6\nP2-0 P3-0\n", "The output of amazed did not match the expected output");
}

Test(amazed, should_print_expected_output2, .init = cr_redirect_stdout)
{
    freopen("ressources/laby2", "r", stdin);
    amazed();
    cr_assert_stdout_eq_str("#number_of_robots\n3\n#rooms\n0 27 55\n1 30 106\n##end\n2 114 55\n##start\n3 31 103\n4 13 51\n5 114 89\n6 3 0\n7 96 118\n8 4 24\n9 21 58\n10 5 66\n11 8 59\n12 28 56\n#tunnels\n0-3\n1-12\n2-0\n2-3\n2-12\n3-4\n4-6\n4-10\n5-2\n5-4\n5-8\n6-4\n6-7\n6-8\n7-3\n7-8\n8-8\n9-1\n9-5\n9-6\n9-9\n10-7\n10-11\n11-0\n11-2\n11-4\n11-10\n12-2\n12-5\n12-11\n#moves\nP1-2\nP2-2\nP3-2\n", "The output of amazed (laby2) did not match the expected output");
}
