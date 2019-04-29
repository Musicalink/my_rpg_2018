/*
** EPITECH PROJECT, 2018
** rpg.h
** File description:
** main include for rpg
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/InputStream.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/SoundStatus.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "my.h"

//menu.c
int game_menu(menu_t *, sfRenderWindow *);

//set_player
player_t *set_player(void);

//set_menu.c
menu_t *init_menu(char *);

#endif /*MY_RPG_H*/
