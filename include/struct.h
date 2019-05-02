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
    int hp_max;
    int atk;
    int def;
} stats_t;

typedef struct moving {
    sfSprite *s_right;
    sfTexture *t_right;
    sfSprite *s_left;
    sfTexture *t_left;
    sfSprite *s_up;
    sfTexture *t_up;
    sfSprite *s_down;
    sfTexture *t_down;
    sfIntRect rect;
} moving_t;

typedef struct stuff {
    int atk;
    int def;
    int hp;
} stuff_t;

typedef struct player {
    stats_t *stats;
    stuff_t **stuff;
    stuff_t **inventory;
    moving_t *move;
} player_t;

typedef struct bhud {
    sfRectangleShape *hp;
    sfRectangleShape *xp;
    sfRectangleShape *ene_hp;
    sfText *lvl;
    sfFont *font;
} bhud_t;

typedef struct ebattle {
    sfSprite *s_ene;
    sfTexture *t_ene;
    sfIntRect rect;
    sfVector2f size;
    int frame;
    int action;
    int wait;
    stats_t *stats;
    sfClock *clock;
} ebattle_t;

typedef struct pbattle {
    sfSprite *s_player;
    sfTexture *t_player;
    sfIntRect rect;
    int action;
    sfClock *clock;
} pbattle_t;

typedef struct battle {
    sfSprite *s_back;
    sfTexture *t_back;
    sfSprite *s_hud;
    sfTexture *t_hud;
    bhud_t *hud;
    pbattle_t *player;
    int turn;
} battle_t;

#endif /*MY_STRUCT_H*/
