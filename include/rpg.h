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

//free_player
void free_player(player_t *);

//set_menu.c
sfIntRect create_rect(int, int, int, int);
menu_t *init_menu(char *);

//battle.c
void atk(battle_t *, sfRenderWindow *);
int game_battle(sfRenderWindow *, player_t *, ebattle_t *);

//battle_action.c
int battle_action(sfRenderWindow *, battle_t *, ebattle_t *, player_t *);

//set_battle.c
battle_t *init_battle(player_t *);

//set_player_battle.c
pbattle_t *init_player_battle(char *);

//hud_ingame.c
void set_hud(bhud_t *, player_t *);

//xp.c
sfVector2f bar_xp(player_t *);

//enemies.c
ebattle_t **gen_enemies(void);

#endif /*MY_RPG_H*/
