/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** dialog.c
*/

#include "SFML/Graphics/RenderWindow.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"
#include <stdbool.h>

static
void dialog_old(all_t *all, int nbr)
{
    FILE *file = fopen("config/dialog", "r");
    char *text = NULL;
    int count = 0;
    int px = sfSprite_getPosition(PLAYER->sprite).x;
    int py = sfSprite_getPosition(PLAYER->sprite).y;

    text = malloc(sizeof(char) * 210);
    while (count < nbr) {
        fscanf(file, "%[^@]", text);
        fgetc(file);
        count++;
    }
    sfSprite_setPosition(DIALOG->sprite, (sfVector2f) {px - 500, py + 300});
    sfText_setPosition(DIALOG->text, (sfVector2f) {px - 450, py + 350});
    sfText_setString(DIALOG->text, text);
    sfRenderWindow_drawSprite(GAME->window, DIALOG->sprite, NULL);
    sfRenderWindow_drawText(GAME->window, DIALOG->text, NULL);
    fclose(file);
    free(text);
}

void check_finish_dialog(all_t *all)
{
    if (RACOON->is_alive == false && FROG->is_alive == false) {
        OLDMAN->player_dialog = 2;
        sfText_setString(QUEST_FOLLOW->text, "Quete : \n\nRetourne voir le"
            " vieil homme");
    }
}

int display_quest_follow(all_t *all)
{
    if (QUEST_FOLLOW->is_active == 1) {
        sfRenderWindow_drawSprite(GAME->window, QUEST_FOLLOW->sprite, NULL);
        sfRenderWindow_drawText(GAME->window, QUEST_FOLLOW->text, NULL);
    }
    return 0;
}

int display_dialog(all_t *all)
{
    if (OLDMAN->is_dialog == 1) {
        STATES->freezed = 1;
        dialog_old(all, 1);
    }
    if (OLDMAN->is_dialog == 2) {
        STATES->freezed = 1;
        dialog_old(all, 2);
    }
    return 0;
}
