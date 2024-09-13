/*
** EPITECH PROJECT, 2024
** EPITECH | WORKSHOP | CSFML
** File description:
** mon_rpg.c
*/

#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/Sprite.h"
#include "SFML/Graphics/View.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

static
int inventory_next(inventory_t *inventory, int i)
{
    inventory[i].weapon = sfSprite_create();
    inventory[i].weapont = sfTexture_createFromFile(WEAPONINVENTORY, NULL);
    if (!inventory[i].weapont)
        return ERROR;
    sfSprite_setTexture(inventory[i].weapon, inventory[i].weapont, sfTrue);
    sfSprite_setScale(inventory[i].weapon, (sfVector2f){4, 4});
    inventory[i].weapon_pos = (sfVector2f){inventory[i].pos.x + 55,
        inventory[i].pos.y + 25};
    sfSprite_setPosition(inventory[i].weapon, inventory[i].weapon_pos);
    return SUCCESS;
}

inventory_t *init_inventory(all_t *all)
{
    inventory_t *inventory = malloc(sizeof(inventory_t) * 3);

    for (int i = 0; i < 3; i++) {
        inventory[i].sprite = sfSprite_create();
        inventory[i].texture = sfTexture_createFromFile(INVENTORYSHEET, NULL);
        if (!inventory[i].texture)
            return NULL;
        sfSprite_setTexture(inventory[i].sprite, inventory[i].texture, sfTrue);
        sfSprite_setScale(inventory[i].sprite, (sfVector2f){3, 3});
        inventory[i].pos = (sfVector2f){PLAYER->pos.x + i * 200 - 250,
            PLAYER->pos.y + 500};
        sfSprite_setPosition(inventory[i].sprite, inventory[i].pos);
        if (inventory_next(inventory, i) == ERROR)
            return NULL;
        if (inventory_next(inventory, i) == ERROR)
            return NULL;
    }
    return inventory;
}

void draw_inventory(all_t *all)
{
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawSprite(GAME->window, INVENTORY[i].sprite, NULL);
        if (i == 0 && QUEST_FOLLOW->is_active == 1)
            sfRenderWindow_drawSprite(GAME->window, INVENTORY[i].weapon, NULL);
    }
}
