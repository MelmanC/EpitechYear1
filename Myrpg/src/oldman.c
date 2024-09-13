/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** event.c
*/

#include "SFML/Graphics/Rect.h"
#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/Sprite.h"
#include "SFML/System/Time.h"
#include "functions.h"
#include "macros.h"
#include "my.h"
#include "struct.h"
#include <stdio.h>

int check_dialog(all_t *all)
{
    sfFloatRect player_rect = sfSprite_getGlobalBounds(PLAYER->sprite);
    sfFloatRect npc_rect = sfSprite_getGlobalBounds(OLDMAN->sprite);
    static int enter = 0;

    if (sfFloatRect_intersects(&player_rect, &npc_rect, NULL) == sfTrue) {
        STATES->freezed = 1;
        if (enter == 0) {
            OLDMAN->is_dialog = 1;
            enter = 1;
            return 1;
        }
        if (enter == 1)
            OLDMAN->is_dialog = 2;
        return 1;
    }
    return 0;
}
