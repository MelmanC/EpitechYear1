/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-nolann.dubos
** File description:
** keybinds header
*/

#include "functions.h"

void init_arrow_keybinds(keybinds_t *keybinds)
{
    keybinds->up_arrow_pos = (sfVector2f){900, 400};
    keybinds->up_arrow_scale = (sfVector2f){(float)5.5, (float)5.5};
    keybinds->u_arrow_t = sfTexture_createFromFile(UP_ARROW, NULL);
    keybinds->u_arrow_s = sfSprite_create();
    sfSprite_setTexture(keybinds->u_arrow_s, keybinds->u_arrow_t, sfTrue);
    keybinds->down_arrow_pos = (sfVector2f){900, 500};
    keybinds->down_arrow_scale = (sfVector2f){(float)5.5, (float)5.5};
    keybinds->d_arrow_t = sfTexture_createFromFile(DOWN_ARROW, NULL);
    keybinds->d_arrow_s = sfSprite_create();
    sfSprite_setTexture(keybinds->d_arrow_s, keybinds->d_arrow_t, sfTrue);
    keybinds->left_arrow_pos = (sfVector2f){800, 500};
    keybinds->left_arrow_scale = (sfVector2f){(float)5.5, (float)5.5};
    keybinds->l_arrow_t = sfTexture_createFromFile(LEFT_ARROW, NULL);
    keybinds->l_arrow_s = sfSprite_create();
    sfSprite_setTexture(keybinds->l_arrow_s, keybinds->l_arrow_t, sfTrue);
    keybinds->right_arrow_pos = (sfVector2f){1000, 500};
    keybinds->right_arrow_scale = (sfVector2f){(float)5.5, (float)5.5};
    keybinds->r_arrow_t = sfTexture_createFromFile(RIGHT_ARROW, NULL);
    keybinds->r_arrow_s = sfSprite_create();
    sfSprite_setTexture(keybinds->r_arrow_s, keybinds->r_arrow_t, sfTrue);
}

void draw_arrow_keybinds(sfRenderWindow *window, keybinds_t *keybinds)
{
    sfSprite_setPosition(keybinds->u_arrow_s, keybinds->up_arrow_pos);
    sfSprite_setScale(keybinds->u_arrow_s, keybinds->up_arrow_scale);
    sfRenderWindow_drawSprite(window, keybinds->u_arrow_s, NULL);
    sfSprite_setPosition(keybinds->d_arrow_s, keybinds->down_arrow_pos);
    sfSprite_setScale(keybinds->d_arrow_s, keybinds->down_arrow_scale);
    sfRenderWindow_drawSprite(window, keybinds->d_arrow_s, NULL);
    sfSprite_setPosition(keybinds->l_arrow_s, keybinds->left_arrow_pos);
    sfSprite_setScale(keybinds->l_arrow_s, keybinds->left_arrow_scale);
    sfRenderWindow_drawSprite(window, keybinds->l_arrow_s, NULL);
    sfSprite_setPosition(keybinds->r_arrow_s, keybinds->right_arrow_pos);
    sfSprite_setScale(keybinds->r_arrow_s, keybinds->right_arrow_scale);
    sfRenderWindow_drawSprite(window, keybinds->r_arrow_s, NULL);
}
