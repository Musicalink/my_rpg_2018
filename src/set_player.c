/*
** EPITECH PROJECT, 2019
** set_player
** File description:
** player
*/

#include <stdlib.h>
#include <stddef.h>
#include "struct.h"

stats_t *set_player_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t) * 1);

    if (stats == NULL)
        return (NULL);
    stats->level = 1;
    stats->xp = 0;
    stats->hp = 100;
    stats->atk = 20;
    stats->def = 0;
    return (stats);
}

stuff_t **set_stuff(void)
{
    stuff_t **stuff = malloc(sizeof(stuff_t *) * 6);

    if (stuff == NULL)
        return (NULL);
    stuff[0] = NULL;
    stuff[1] = NULL;
    stuff[2] = NULL;
    stuff[3] = NULL;
    stuff[4] = NULL;
    stuff[5] = NULL;
    return (stuff);
}

moving_t *set_player_move(void)
{
    moving_t *move = malloc(sizeof(moving_t) * 1);

    if (moving == NULL)
        return (NULL);
    move->t_right = sfTexture_createFromFile("walk_right.png", NULL);
    move->s_right = sfSprite_create();
    move->t_left = sfTexture_createFromFile("walk_left.png", NULL);
    move->s_left = sfSprite_create();
    move->t_up = sfTexture_createFromFile("walk_up.png", NULL);
    move->s_up = sfSprite_create();
    move->t_down = sfTexture_createFromFile("walk_down.png", NULL);
    move->s_down = sfSprite_create();
    return (move);
}

player_t *set_player(void)
{
    player_t *player = malloc(sizeof(player_t) * 1);

    if (player == NULL)
        return (NULL);
    player->stats = set_player_stats();
    player->stuff = set_player_stuff();
    player->move = set_player_move();
    return (player);
}
