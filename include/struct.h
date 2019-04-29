/*
** EPITECH PROJECT, 2018
** rpg.h
** File description:
** main include for rpg
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct menu {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfText *play;
    sfText *exit;
    sfFont *font;
    int launch_game;
} menu_t;

typedef struct stats {
    int level;
    int xp;
    int hp;
    int atk;
    int def;
} stats_t;

typedef struct stuff {
    int atk;
    int def;
    int hp;
} stuff_t;

typedef struct player {
    stats_t *stats;
    stuff **stuff;
} player_t;

#endif /*MY_STRUCT_H*/
