/*
** EPITECH PROJECT, 2023
** macros.h
** File description:
** macros file
*/

#ifndef MACROS_H
    #define MACROS_H

    // SETTINGS
    #define FPS 60
    #define ANIM_FPS 15
    #define PLAYER_SPEED 80
    #define SPRITE_SHEET_WIDTH 64
    #define SPRITE_WIDTH 16
    #define SPRITE_MIDDLE 8
    #define NB_OF_SPRITES SPRITE_SHEET_WIDTH / SPRITE_WIDTH

    // STRUCTURES
    #define CLOCK all->clock
    #define GAME all->game
    #define PLAYER all->player
    #define STATES all->states
    #define OLDMAN all->old
    #define DIALOG all->dialog
    #define CAMERA all->camera
    #define ENEMY all->enemy
    #define QUEST_FOLLOW all->quest_follow
    #define MAP all->map
    #define MAPCOL all->map_col
    #define INVENTORY all->inventory
    #define RACOON all->racoon
    #define FROG all->frog
    #define DEATH all->death
    #define PAUSE all->pause
    #define M_MAP all->mini_map
    #define TUTO all->tuto
    #define KEY menu->option->keybinds
    #define TUTO all->tuto

    // MACROS
    #define QUESTSHEET "assets/HUD/quest.png"
    #define FROGATTACK "assets/enemy/frog/attack.png"
    #define FROGCHARGE "assets/enemy/frog/charge.png"
    #define FROGSHEET "assets/enemy/frog/frog.png"
    #define RACOONATTACK "assets/enemy/racoon/racoon_attack.png"
    #define RACOONSHEET "assets/enemy/racoon/racoon.png"
    #define DEADSHEET "assets/enemy/death.png"
    #define SPRITESHEET "assets/character/SpriteSheet.png"
    #define OLDSHEET "assets/OldMan/SpriteSheet.png"
    #define ENEMYSHEET "assets/enemy/monsters/bamboo/SpriteSheet.png"
    #define ENEMYLIFE "assets/HUD/life_bar/LifeBarMiniProgress.png"
    #define ENEMYDEAD "assets/HUD/life_bar/LifeBarMiniUnder.png"
    #define SF_SECONDS sfTime_asSeconds
    #define WEAPON "assets/items/weapons/lance/SpriteInHand.png"
    #define WEAPONINVENTORY "assets/items/weapons/lance/Sprite.png"
    #define LIFE "assets/HUD/Heart.png"
    #define DIALOGBOX "assets/Dialogue/box/DialogBox.png"
    #define FONT "assets/Dialogue/font/font.ttf"
    #define QUESTF "assets/Dialogue/follow/DialogueBoxSimple.png"
    #define MAPPNG "assets/Map/Map.png"
    #define MAPCOLLISION "assets/Map/whitemap.png"
    #define MAPLAYER "assets/Map/layer.png"
    #define BEAR "assets/animal/Bear_Walk.png"
    #define PARTICLE1 "assets/particle/particle1.png"
    #define PARTICLE2 "assets/particle/particle2.png"
    #define PARTICLE3 "assets/particle/particle3.png"
    #define PARTICLE4 "assets/particle/particle4.png"
    #define PARTICLE5 "assets/particle/particle5.png"
    #define PARTICLE6 "assets/particle/particle6.png"
    #define PARTICLE7 "assets/particle/particle7.png"
    #define PARTICLE8 "assets/particle/particle8.png"
    #define PARTICLE9 "assets/particle/particle9.png"
    #define PARTICLE10 "assets/particle/particle10.png"
    #define PARTICLE11 "assets/particle/particle11.png"
    #define PARTICLE12 "assets/particle/particle12.png"
    #define PARTICLE13 "assets/particle/particle13.png"
    #define PARTICLE14 "assets/particle/particle14.png"
    #define PARTICLE15 "assets/particle/particle15.png"
    #define PARTICLE16 "assets/particle/particle16.png"
    #define PARTICLE17 "assets/particle/particle17.png"
    #define PARTICLE18 "assets/particle/particle18.png"
    #define PARTICLE19 "assets/particle/particle19.png"
    #define GAMEBOY "assets/gameboy/gameboy.png"
    #define PLAY_BUTTON "assets/buttons/play_game_btn.png"
    #define SETTINGS mode, "Wildland", sfResize | sfClose, NULL
    #define SETTINGS_HANDLE sfRenderWindow *window, menu_t *menu
    #define INVENTORYSHEET "assets/Inventory/FacesetBox.png"
    #define MENUBUTTON "assets/buttons/buttons_bg.png"
    #define CHEST "assets/HUD/chest/chest.png"
    #define AUGMENT "assets/buttons/augment.png"
    #define OPTIONSS "assets/buttons/options.png"
    #define SAVE "assets/buttons/save.png"
    #define LOAD "assets/buttons/load.png"
    #define BOOK "assets/HUD/tuto/Book.png"

#endif //MACROS_H
