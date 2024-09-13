/*
** EPITECH PROJECT, 2024
** Workshop-MYRPG-Parallax
** File description:
** sound
*/

#include <SFML/Audio.h>
#include "SFML/Graphics/RenderWindow.h"
#include "SFML/Graphics/View.h"
#include "functions.h"
#include "macros.h"
#include "struct.h"

sfMusic *play_sound(const char *filepath)
{
    sfMusic* music = sfMusic_createFromFile(filepath);

    if (!music) {
        printf("Failed to load sound\n");
        return NULL;
    }
    sfMusic_setVolume(music, 50);
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    return music;
}
