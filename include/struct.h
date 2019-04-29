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
    sfText *text;
    int launch_game;
} menu_t;

#endif /*MY_STRUCT_H*/
