/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** game.c
*/

#include "SFML/Graphics/Sprite.h"
#include "SFML/Graphics/Types.h"
#include "functions.h"
#include <stdbool.h>

static
void tuto_text(sfText *text)
{
    sfText_setString(text, "Pour vous deplacer\nutilisez Z, Q, S, D\n\nPour "
        "attacker utilisez \nClique-Gauche\n");
}

tuto_t *init_tuto(void)
{
    tuto_t *tuto = malloc(sizeof(tuto_t));

    tuto->is_active = false;
    tuto->sprite = sfSprite_create();
    tuto->text = sfText_create();
    tuto->font = sfFont_createFromFile(FONT);
    tuto->texture = sfTexture_createFromFile(BOOK, NULL);
    if (!tuto->sprite || !tuto->text || !tuto->font || !tuto->texture)
        return NULL;
    tuto->pos = (sfVector2f) {0, 0};
    tuto->sprite_pos = (sfVector2f) {0, 0};
    sfSprite_setScale(tuto->sprite, (sfVector2f) {3, 3});
    sfSprite_setTexture(tuto->sprite, tuto->texture, sfTrue);
    sfText_setFont(tuto->text, tuto->font);
    sfText_setColor(tuto->text, sfBlack);
    sfText_setCharacterSize(tuto->text, 50);
    tuto_text(tuto->text);
    return tuto;
}

void display_tuto(all_t *all)
{
    if (TUTO->is_active == true) {
        sfRenderWindow_drawSprite(GAME->window, TUTO->sprite, NULL);
        sfRenderWindow_drawText(GAME->window, TUTO->text, NULL);
    }
}
