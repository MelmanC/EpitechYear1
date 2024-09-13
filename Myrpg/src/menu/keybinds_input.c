/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-nolann.dubos
** File description:
** keybinds_input header
*/

#include "functions.h"

void check_up_arrow_keybinds_click(sfRenderWindow *window,
    keybinds_t *keybinds)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect u_arrow_bounds = sfSprite_getGlobalBounds(keybinds->u_arrow_s);
    sfColor gray = sfColor_fromRGBA(225, 225, 225, 225);
    sfTexture *up_click = sfTexture_createFromFile(UP_ARROW_CLICK, NULL);

    if (sfFloatRect_contains(&u_arrow_bounds, mouse_pos.x, mouse_pos.y))
        sfSprite_setColor(keybinds->u_arrow_s, gray);
    else
        sfSprite_setColor(keybinds->u_arrow_s, sfWhite);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&u_arrow_bounds, mouse_pos.x, mouse_pos.y)) {
            sfRenderWindow_clear(window, sfBlack);
            sfSprite_setTexture(keybinds->u_arrow_s, up_click, sfTrue);
            keybinds->is_up_binded = false;
            keybinds->waiting_for_keybind_up = true;
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 0) {
        sfSprite_setTexture(keybinds->u_arrow_s, keybinds->u_arrow_t, sfTrue);
    }
}

void check_down_arrow_keybinds_click(sfRenderWindow *window,
    keybinds_t *keybinds)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect d_arrow_bounds = sfSprite_getGlobalBounds(keybinds->d_arrow_s);
    sfColor gray = sfColor_fromRGBA(225, 225, 225, 225);
    sfTexture *down_click = sfTexture_createFromFile(DOWN_ARROW_CLICK, NULL);

    if (sfFloatRect_contains(&d_arrow_bounds, mouse_pos.x, mouse_pos.y))
        sfSprite_setColor(keybinds->d_arrow_s, gray);
    else
        sfSprite_setColor(keybinds->d_arrow_s, sfWhite);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&d_arrow_bounds, mouse_pos.x, mouse_pos.y)) {
            sfRenderWindow_clear(window, sfBlack);
            sfSprite_setTexture(keybinds->d_arrow_s, down_click, sfTrue);
            keybinds->is_down_binded = false;
            keybinds->waiting_for_keybind_down = true;
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 0) {
        sfSprite_setTexture(keybinds->d_arrow_s, keybinds->d_arrow_t, sfTrue);
    }
}

void check_left_arrow_keybinds_click(sfRenderWindow *window,
    keybinds_t *keybinds)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect l_arrow_bounds = sfSprite_getGlobalBounds(keybinds->l_arrow_s);
    sfColor gray = sfColor_fromRGBA(225, 225, 225, 225);
    sfTexture *left_click = sfTexture_createFromFile(LEFT_ARROW_CLICK, NULL);

    if (sfFloatRect_contains(&l_arrow_bounds, mouse_pos.x, mouse_pos.y))
        sfSprite_setColor(keybinds->l_arrow_s, gray);
    else
        sfSprite_setColor(keybinds->l_arrow_s, sfWhite);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&l_arrow_bounds, mouse_pos.x, mouse_pos.y)) {
            sfRenderWindow_clear(window, sfBlack);
            sfSprite_setTexture(keybinds->l_arrow_s, left_click, sfTrue);
            keybinds->is_left_binded = false;
            keybinds->waiting_for_keybind_left = true;
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 0) {
        sfSprite_setTexture(keybinds->l_arrow_s, keybinds->l_arrow_t, sfTrue);
    }
}

void check_right_arrow_keybinds_click(sfRenderWindow *window,
    keybinds_t *keybinds)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect r_arrow_bounds = sfSprite_getGlobalBounds(keybinds->r_arrow_s);
    sfColor gray = sfColor_fromRGBA(225, 225, 225, 225);
    sfTexture *right_click = sfTexture_createFromFile(RIGHT_ARROW_CLICK, NULL);

    if (sfFloatRect_contains(&r_arrow_bounds, mouse_pos.x, mouse_pos.y))
        sfSprite_setColor(keybinds->r_arrow_s, gray);
    else
        sfSprite_setColor(keybinds->r_arrow_s, sfWhite);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&r_arrow_bounds, mouse_pos.x, mouse_pos.y)) {
            sfRenderWindow_clear(window, sfBlack);
            sfSprite_setTexture(keybinds->r_arrow_s, right_click, sfTrue);
            keybinds->is_right_binded = false;
            keybinds->waiting_for_keybind_right = true;
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 0) {
        sfSprite_setTexture(keybinds->r_arrow_s, keybinds->r_arrow_t, sfTrue);
    }
}
