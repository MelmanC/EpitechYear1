/*
** EPITECH PROJECT, 2024
** template
** File description:
** main
*/

#include "functions.h"
#include "init_menu.h"

/**
* This function is used to display the help message
*/
int main(const int argc, char const *const argv[])
{
    menu_t *menu = malloc(sizeof(menu_t));
    all_t *all = malloc(sizeof(all_t));

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        help_message();
        return SUCCESS;
    }
    malloc_function(menu);
    if (init_resources(menu, all) == ERROR)
        return ERROR;
    return game_loop(menu, all);
}
