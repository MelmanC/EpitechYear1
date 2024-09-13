/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** weapon.c
*/

#include "SFML/Graphics/BlendMode.h"
#include "SFML/Graphics/Color.h"
#include "SFML/Graphics/Rect.h"
#include "SFML/Graphics/RenderStates.h"
#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/Shader.h"
#include "SFML/Graphics/Sprite.h"
#include "SFML/Graphics/Transform.h"
#include "SFML/Graphics/Types.h"
#include "SFML/System/Vector2.h"
#include "functions.h"
#include <stdbool.h>

static
void sprite(pause_t *pause)
{
    pause->background = sfSprite_create();
    pause->save = sfSprite_create();
    pause->load = sfSprite_create();
    pause->settings = sfSprite_create();
    pause->chest = sfSprite_create();
    pause->weapon = sfSprite_create();
    pause->character = sfSprite_create();
    pause->text_level = sfText_create();
    pause->text_attack = sfText_create();
    pause->augment = sfSprite_create();
}

static
void set_texture(pause_t *pause)
{
    sfSprite_setTexture(pause->background, pause->background_t, sfTrue);
    sfSprite_setTexture(pause->save, pause->save_t, sfTrue);
    sfSprite_setTexture(pause->load, pause->load_t, sfTrue);
    sfSprite_setTexture(pause->settings, pause->settings_t, sfTrue);
    sfSprite_setTexture(pause->chest, pause->chest_t, sfTrue);
    sfSprite_setTexture(pause->weapon, pause->weapon_t, sfTrue);
    sfSprite_setTexture(pause->character, pause->character_t, sfTrue);
    sfText_setFont(pause->text_level, pause->font);
    sfText_setFont(pause->text_attack, pause->font);
    sfSprite_setTexture(pause->augment, pause->augment_t, sfTrue);
}

static
void set_scale(pause_t *pause)
{
    sfSprite_setScale(pause->background, (sfVector2f){7, 9});
    sfSprite_setScale(pause->save, (sfVector2f){6, 6});
    sfSprite_setScale(pause->load, (sfVector2f){6, 6});
    sfSprite_setScale(pause->settings, (sfVector2f){6, 6});
    sfSprite_setScale(pause->chest, (sfVector2f){6, 6});
    sfSprite_setScale(pause->weapon, (sfVector2f){5, 5});
    sfSprite_setScale(pause->character, (sfVector2f){5, 5});
    sfSprite_setScale(pause->augment, (sfVector2f){4, 4});
    sfText_setCharacterSize(pause->text_level, 30);
    sfText_setCharacterSize(pause->text_attack, 30);
    sfText_setColor(pause->text_level, sfBlue);
    sfText_setColor(pause->text_attack, sfBlue);
}

static
int create_sprite_texture(pause_t *pause)
{
    sprite(pause);
    pause->background_t = sfTexture_createFromFile(MENUBUTTON, NULL);
    pause->save_t = sfTexture_createFromFile(SAVE, NULL);
    pause->load_t = sfTexture_createFromFile(LOAD, NULL);
    pause->settings_t = sfTexture_createFromFile(OPTIONSS, NULL);
    pause->chest_t = sfTexture_createFromFile(CHEST, NULL);
    pause->weapon_t = sfTexture_createFromFile(WEAPONINVENTORY, NULL);
    pause->character_t = sfTexture_createFromFile(SPRITESHEET, NULL);
    pause->font = sfFont_createFromFile(FONT);
    pause->augment_t = sfTexture_createFromFile(AUGMENT, NULL);
    if (!pause->background_t || !pause->save_t || !pause->load_t ||
        !pause->settings_t || !pause->chest_t || !pause->weapon_t ||
        !pause->character_t || !pause->font || !pause->augment_t)
        return ERROR;
    set_texture(pause);
    set_scale(pause);
    return 0;
}

static
void ini_pos(pause_t *pause)
{
    pause->background_pos = (sfVector2f){0, 0};
    pause->save_pos = (sfVector2f){0, 0};
    pause->load_pos = (sfVector2f){0, 0};
    pause->settings_pos = (sfVector2f){0, 0};
    pause->chest_pos = (sfVector2f){0, 0};
    pause->weapon_pos = (sfVector2f){0, 0};
    pause->character_pos = (sfVector2f){0, 0};
    pause->text_attack_pos = (sfVector2f){0, 0};
    pause->text_level_pos = (sfVector2f){0, 0};
    pause->augment_pos = (sfVector2f){0, 0};
}

pause_t *init_pause_menu(void)
{
    pause_t *pause = malloc(sizeof(pause_t));
    sfIntRect rect = {0, 0, 16, 16};

    pause->is_paused = false;
    pause->is_option = false;
    if (create_sprite_texture(pause) == ERROR)
        return NULL;
    ini_pos(pause);
    sfSprite_setTextureRect(pause->character, rect);
    return pause;
}

static
void draw_sprite(all_t *all, sfRenderStates states)
{
    sfRenderWindow_drawSprite(GAME->window, PLAYER->sprite, &states);
    sfRenderWindow_drawSprite(GAME->window, PAUSE->background, NULL);
    sfRenderWindow_drawSprite(GAME->window, PAUSE->save, NULL);
    sfRenderWindow_drawSprite(GAME->window, PAUSE->load, NULL);
    sfRenderWindow_drawSprite(GAME->window, PAUSE->settings, NULL);
    if (PAUSE->is_option == false) {
        sfRenderWindow_drawSprite(GAME->window, PAUSE->chest, NULL);
        sfRenderWindow_drawSprite(GAME->window, PAUSE->character, NULL);
        sfRenderWindow_drawText(GAME->window, PAUSE->text_level, NULL);
        sfRenderWindow_drawText(GAME->window, PAUSE->text_attack, NULL);
        sfRenderWindow_drawSprite(GAME->window, PAUSE->augment, NULL);
        if (OLDMAN->player_dialog == 1)
            sfRenderWindow_drawSprite(GAME->window, PAUSE->weapon, NULL);
    }
}

void blur(all_t *all, sfShader *shader, sfRenderStates states)
{
    sfShader_setTextureUniform(shader, "src",
        sfSprite_getTexture(MAP->sprite));
    sfShader_setVec2Uniform(shader, "offset", (sfVector2f){1.f / 4000.f,
        0.f});
    sfRenderWindow_drawSprite(GAME->window, MAP->sprite, &states);
    sfShader_setTextureUniform(shader, "src",
        sfSprite_getTexture(PLAYER->sprite));
    sfShader_setVec2Uniform(shader, "offset", (sfVector2f){0.f,
        1.f / 300.f});
}

void display_pause_menu(all_t *all)
{
    sfShader *shader;
    sfRenderStates states = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};

    if (PAUSE->is_paused == true) {
        shader = sfShader_createFromFile(NULL, NULL, "src/blur");
        states = (sfRenderStates){sfBlendAlpha, sfTransform_Identity, NULL,
            shader};
        if (!shader)
            return;
        blur(all, shader, states);
        draw_sprite(all, states);
    }
}
