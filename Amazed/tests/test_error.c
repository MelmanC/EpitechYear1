/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** test_error.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/amazed.h"
#include "../include/my.h"
#include "../include/printf.h"

Test(amazed, no_room_error, .init = cr_redirect_stdout)
{
    freopen("ressources/no_room", "r", stdin);
    amazed();
    cr_assert_stdout_eq_str("#number_of_robots\n34\n", "The output of amazed did not match the expected output");
}

Test(amazed, no_tunnels_error, .init = cr_redirect_stdout)
{
    freopen("ressources/no_tunnels", "r", stdin);
    amazed();
    cr_assert_stdout_eq_str("#number_of_robots\n3\n#rooms\n0 27 55\n1 30 106\n##end\n", "The output of amazed did not match the expected output");
}

Test(amazed, bad_robots_number_error, .init = cr_redirect_stdout)
{
    freopen("ressources/bad_robots_number", "r", stdin);
    amazed();
    cr_assert_stdout_eq_str("#number_of_robots\n", "The output of amazed did not match the expected output");
}

Test(amazed, no_start_room, .init = cr_redirect_stdout)
{
    freopen("ressources/no_start_room", "r", stdin);
    amazed();
    cr_assert_stdout_eq_str("#number_of_robots\n3\n#rooms\n0 27 55\n1 30 106\n##end\n2 114 55\n#tunnels\n0-1\n1-2\n#moves\n", "The output of amazed did not match the expected output");
}

Test(amazed, no_end_room, .init = cr_redirect_stdout)
{
    freopen("ressources/no_end_room", "r", stdin);
    amazed();
    cr_assert_stdout_eq_str("#number_of_robots\n3\n#rooms\n0 27 55\n1 30 106\n##start\n2 114 55\n#tunnels\n0-1\n1-2\n#moves\n", "The output of amazed did not match the expected output");
}

Test(amazed, pipe_room_not_exist, .init = cr_redirect_stdout)
{
    freopen("ressources/pipe_room_not_exist", "r", stdin);
    amazed();
    cr_assert_stdout_eq_str("#number_of_robots\n3\n#rooms\n0 27 55\n##start\n1 30 106\n##end\n2 114 55\n#tunnels\n0-1\n1-2\n", "The output of amazed did not match the expected output");
}
