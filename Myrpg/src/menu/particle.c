/*
** EPITECH PROJECT, 2023
** Workshop-MYRPG-Parallax
** File description:
** particle.c
*/
#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/View.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

static
void create_particle_textures(particle_t *particle)
{
    particle->textures[0] = sfTexture_createFromFile(PARTICLE1, NULL);
    particle->textures[1] = sfTexture_createFromFile(PARTICLE2, NULL);
    particle->textures[2] = sfTexture_createFromFile(PARTICLE3, NULL);
    particle->textures[3] = sfTexture_createFromFile(PARTICLE4, NULL);
    particle->textures[4] = sfTexture_createFromFile(PARTICLE5, NULL);
    particle->textures[5] = sfTexture_createFromFile(PARTICLE6, NULL);
    particle->textures[6] = sfTexture_createFromFile(PARTICLE7, NULL);
    particle->textures[7] = sfTexture_createFromFile(PARTICLE8, NULL);
    particle->textures[8] = sfTexture_createFromFile(PARTICLE9, NULL);
    particle->textures[9] = sfTexture_createFromFile(PARTICLE10, NULL);
    particle->textures[10] = sfTexture_createFromFile(PARTICLE11, NULL);
    particle->textures[11] = sfTexture_createFromFile(PARTICLE12, NULL);
    particle->textures[12] = sfTexture_createFromFile(PARTICLE13, NULL);
    particle->textures[13] = sfTexture_createFromFile(PARTICLE14, NULL);
    particle->textures[14] = sfTexture_createFromFile(PARTICLE15, NULL);
    particle->textures[15] = sfTexture_createFromFile(PARTICLE16, NULL);
    particle->textures[16] = sfTexture_createFromFile(PARTICLE17, NULL);
    particle->textures[17] = sfTexture_createFromFile(PARTICLE18, NULL);
    particle->textures[18] = sfTexture_createFromFile(PARTICLE19, NULL);
}

void create_particle(particle_t *particle, int i)
{
    sfVector2f pos = {1920, rand() % 1080};
    sfVector2f scale = {3.333, 3.333};

    particle->sprites[i] = sfSprite_create();
    sfSprite_setTexture(particle->sprites[i], particle->textures[i], sfTrue);
    sfSprite_setPosition(particle->sprites[i], pos);
    sfSprite_setScale(particle->sprites[i], scale);
}

void init_particle(particle_t *particle)
{
    create_particle_textures(particle);
    for (int i = 0; i < NB_PARTICLES; i++) {
        create_particle(particle, i);
    }
}

void draw_particle(sfRenderWindow *window, particle_t *particle)
{
    for (int i = 0; i < NB_PARTICLES; i++) {
        sfRenderWindow_drawSprite(window, particle->sprites[i], NULL);
    }
}

void move_particle(particle_t *particle)
{
    sfVector2f pos = {0, 0};
    int momo = 0;

    for (int i = 0; i < NB_PARTICLES; i++) {
        pos = sfSprite_getPosition(particle->sprites[i]);
        pos.x -= 0.5 * (i + 1);
        sfSprite_setPosition(particle->sprites[i], pos);
        if (pos.x <= -1920) {
            momo = (int)(500.0f * (sin(i) + 1.0f));
            sfSprite_setPosition(particle->sprites[i]
            , (sfVector2f){1920, momo});
        }
    }
}

void delete_particle(particle_t *particle)
{
    for (int i = 0; i < NB_PARTICLES; i++) {
        sfSprite_destroy(particle->sprites[i]);
        sfTexture_destroy(particle->textures[i]);
    }
}
