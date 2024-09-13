/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** event.c
*/

#include "SFML/Graphics/Color.h"
#include "SFML/Graphics/Sprite.h"
#include "SFML/Graphics/Text.h"
#include "SFML/System/Vector2.h"
#include "functions.h"
#include "struct.h"

quest_follow_t *init_quest_follow(void)
{
    quest_follow_t *quest_follow = malloc(sizeof(quest_follow_t));

    quest_follow->is_active = 0;
    quest_follow->sprite = sfSprite_create();
    quest_follow->texture = sfTexture_createFromFile(QUESTF, NULL);
    quest_follow->font = sfFont_createFromFile(FONT);
    if (!quest_follow->font || !quest_follow->texture)
        return NULL;
    quest_follow->text = sfText_create();
    quest_follow->pos = (sfVector2f){1100, -50};
    sfText_setFont(quest_follow->text, quest_follow->font);
    sfText_setColor(quest_follow->text, sfBlack);
    sfText_setCharacterSize(quest_follow->text, 20);
    sfText_setString(quest_follow->text, "Quete : \n\nBat les 2 monstres: \n -"
        " Raton laveur\n - Grenouille\n");
    sfSprite_setScale(quest_follow->sprite, (sfVector2f){1.5, 2.7});
    sfSprite_setTexture(quest_follow->sprite, quest_follow->texture, sfTrue);
    sfSprite_setPosition(quest_follow->sprite, quest_follow->pos);
    return quest_follow;
}
