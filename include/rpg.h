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
#include <stddef.h>
#include <dirent.h>
#include <time.h>
#include "struct.h"
#include "my.h"

//menu.c
int game_menu(menu_t *, sfRenderWindow *);

//set_player
player_t *set_player(void);

game_t *init_move(game_t *);

//free_player
void free_player(player_t *);

//set_pause_menu.c
menu_t *init_pause_menu(char *);

//pause_menu.c
int pause_menu(menu_t *, sfRenderWindow *);

//set_menu.c
sfIntRect create_rect(int, int, int, int);

menu_t *init_menu(char *);

//battle.c
int game_battle(sfRenderWindow *, player_t *, ebattle_t *, inventory_t *);

//battle_movement.c
void enemy_atk(battle_t *, sfRenderWindow *);
void flm_move(anim_t *);
void atk(battle_t *, sfRenderWindow *);

//battle_action.c
int battle_action(sfRenderWindow *, battle_t *);
int enemy_action(battle_t *);

//battle_end.c
int battle_end(player_t *, ebattle_t *);

//battle_loots.c
int game_loots(sfRenderWindow *, battle_t *, inventory_t *);

//set_battle.c
battle_t *init_battle(player_t *, ebattle_t *);

//set_player_battle.c
pbattle_t *init_player_battle(char *, player_t *);

//set_lootscreen.c
loots_t *init_loot(battle_t *, inventory_t *);

//set_textloot.c
void get_battle_status(battle_t *, loots_t *);
char *xp_char(battle_t *);

//hud_ingame.c
void set_hud(bhud_t *, player_t *);
void upd_hp_player(pbattle_t *, bhud_t *);
void upd_hp_enemy(ebattle_t *, bhud_t *);

//xp.c
sfVector2f bar_xp(player_t *);

//enemies.c
ebattle_t **gen_enemies(void);
anim_t *gen_anim(char *, int, int, int);

//init_game.c
game_t *init_game(void);

void display_game(sfRenderWindow *window, map_t ***maps, game_t *game);

void game_map(map_t ***maps, sfRenderWindow *window, ebattle_t **enemies, player_t *player);

//map.c

sfVector2f move_it(game_t *game, sfVector2f pos, sfColor color);

void make_move(game_t *game, map_t *map, int boolean, int minus);

void search_move(game_t *game, map_t ***maps, sfRenderWindow *window);

void event_map(map_t ***maps, sfRenderWindow *window, game_t *game);

void my_clock(map_t ***maps, sfRenderWindow *window, game_t *game);

//init_map.c

map_t *take_map(map_t *map, char *name);

map_t **malloc_list_maps(map_t **maps);

map_t ***fill_maps(map_t ***maps, DIR *dir);

map_t ***init_maps();

//drop.c

anim_t *choose_drop(battle_t *, anim_t ***, inventory_t *);

#define WALK_RIGHT "ressources/sprites/walk_right.png"
#define WALK_LEFT "ressources/sprites/walk_left.png"
#define WALK_UP "ressources/sprites/walk_up.png"
#define WALK_DOWN "ressources/sprites/walk_down.png"
#define BATTLE "ressources/sprites/battle.png"
#define HUD "ressources/sprites/hud.png"
#define ATK "ressources/sprites/atk.png"
#define ARIAL "ressources/font/arial.ttf"
#define REWARD "ressources/sprites/reward.png"
#define ARMOR "ressources/sprites/armor_set.png"
#define BOOTS "ressources/sprites/boots_set.png"
#define HELMET "ressources/sprites/helmet_set.png"
#define INVENTORY "ressources/sprites/inventory.png"
#define MAGICIAN "ressources/sprites/pnj.png"
#define PAUSE "ressources/sprites/pause_menu.jpg"

#endif /*MY_RPG_H*/
