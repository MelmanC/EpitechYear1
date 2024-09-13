/*
** EPITECH PROJECT, 2024
** workshop-csfml
** File description:
** parallax
*/

#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/View.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

void create_parallax_textures(parallax_t *parallax)
{
    const char *filenames[] = {
        "assets/parallax/image1.png",
        "assets/parallax/image2.png",
        "assets/parallax/image3.png",
        "assets/parallax/image4.png"
    };

    if (!parallax)
        return;
    for (int i = 0; i < NB_PARALLAX; i++) {
        parallax->textures[i] = sfTexture_createFromFile(filenames[i], NULL);
        if (!parallax->textures[i]) {
            printf("Failed to load texture from %s\n", filenames[i]);
            return;
        }
    }
}

static
void create_parallax(parallax_t *parallax, int i)
{
    sfVector2f pos = {0, 0};
    sfVector2f scale = {(float)3.3333, (float)3.3333};

    parallax->sprites[i] = sfSprite_create();
    sfSprite_setTexture(parallax->sprites[i], parallax->textures[i], sfTrue);
    sfSprite_setPosition(parallax->sprites[i], pos);
    sfSprite_setScale(parallax->sprites[i], scale);
}

void init_parallax(parallax_t *parallax)
{
    if (!parallax)
        return;
    create_parallax_textures(parallax);
    for (int i = 0; i < NB_PARALLAX; i++) {
        create_parallax(parallax, i);
    }
}

void draw_parallax(sfRenderWindow *window, parallax_t *parallax)
{
    for (int i = 0; i < NB_PARALLAX; i++) {
        sfRenderWindow_drawSprite(window, parallax->sprites[i], NULL);
    }
}

void move_parallax(parallax_t *parallax)
{
    sfVector2f pos = {0, 0};

    for (int i = 0; i < NB_PARALLAX; i++) {
        pos = sfSprite_getPosition(parallax->sprites[i]);
        pos.x -= (float)0.3 * (float)(i + 1);
        sfSprite_setPosition(parallax->sprites[i], pos);
        if (pos.x <= -1920)
            sfSprite_setPosition(parallax->sprites[i], (sfVector2f){0, 0});
    }
}

// void free_all(parallax_t *parralax)
// {
//     for (int i = 0; i < NB_PARALLAX; i++) {
//         sfTexture_destroy(parralax->textures[i]);
//         sfSprite_destroy(parralax->sprites[i]);
//     }
//     free(parralax->textures);
// }
