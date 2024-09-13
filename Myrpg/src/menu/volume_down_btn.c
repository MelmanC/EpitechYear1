/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-nolann.dubos
** File description:
** volume_btn header
*/

#include "functions.h"

void init_volume_down_btn(volume_t *volume)
{
    volume->vol_down_pos.x = 723;
    volume->vol_down_pos.y = 188;
    volume->vol_down_scale.x = (float)5.5;
    volume->vol_down_scale.y = (float)5.5;
    volume->vol_down_t = sfTexture_createFromFile(VOLUME_DOWN_PNG, NULL);
    volume->vol_down_s = sfSprite_create();
    sfSprite_setTexture(volume->vol_down_s, volume->vol_down_t, sfTrue);
}

void draw_volume_down_btn(sfRenderWindow *window, volume_t *volume)
{
    sfSprite_setPosition(volume->vol_down_s, volume->vol_down_pos);
    sfSprite_setScale(volume->vol_down_s, volume->vol_down_scale);
    sfRenderWindow_drawSprite(window, volume->vol_down_s, NULL);
}

void check_volume_down_click(sfRenderWindow *window, volume_t *volume)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect vol_down_bounds =
        sfSprite_getGlobalBounds(volume->vol_down_s);
    sfColor gray = sfColor_fromRGBA(225, 225, 225, 225);
    sfTexture *click = sfTexture_createFromFile(VOL_DOWN_CLICK_PNG, NULL);

    if (sfFloatRect_contains(&vol_down_bounds, mouse_pos.x, mouse_pos.y))
        sfSprite_setColor(volume->vol_down_s, gray);
    else
        sfSprite_setColor(volume->vol_down_s, sfWhite);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&vol_down_bounds, mouse_pos.x, mouse_pos.y)) {
            sfRenderWindow_clear(window, sfBlack);
            sfSprite_setTexture(volume->vol_down_s, click, sfTrue);
            volume->volume -= volume->volume > 0 ? 5 : 0;
            sfMusic_setVolume(volume->music, (float)volume->volume);
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 0)
        sfSprite_setTexture(volume->vol_down_s, volume->vol_down_t, sfTrue);
}
