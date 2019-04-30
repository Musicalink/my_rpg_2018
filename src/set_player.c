/*
** EPITECH PROJECT, 2019
** set_player
** File description:
** player
*/

#include <stdlib.h>
#include <stddef.h>
#include "rpg.h"
#include "struct.h"

stats_t *set_player_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t) * 1);

    if (stats == NULL)
        return (NULL);
    stats->level = 1;
    stats->xp = 20;
    stats->hp = 100;
    stats->atk = 20;
    stats->def = 10;
    return (stats);
}

stuff_t **set_player_stuff(void)
{
    stuff_t **stuff = malloc(sizeof(stuff_t *) * 4);

    if (stuff == NULL)
        return (NULL);
    for (int i = 0; i <= 3; i++) {
        stuff[i] = NULL;
    }
    return (stuff);
}

moving_t *set_player_move(void)
{
    moving_t *move = malloc(sizeof(moving_t) * 1);

    if (move == NULL)
        return (NULL);
    move->t_right = sfTexture_createFromFile("ressources/sprites/walk_right.png"
    , NULL);
    move->s_right = sfSprite_create();
    move->t_left = sfTexture_createFromFile("ressources/sprites/walk_left.png"
    , NULL);
    move->s_left = sfSprite_create();
    move->t_up = sfTexture_createFromFile("ressources/sprites/walk_up.png"
    , NULL);
    move->s_up = sfSprite_create();
    move->t_down = sfTexture_createFromFile("ressources/sprites/walk_down.png"
    , NULL);
    move->s_down = sfSprite_create();
    move->rect = create_rect(0, 0, 240, 299);
    return (move);
}

stuff_t **set_player_inventory(void)
{
    stuff_t **inventory = malloc(sizeof(stuff_t *) * 15);

    if (inventory == NULL)
        return (NULL);
    for (int i = 0; i <= 14; i++) {
        inventory[i] = NULL;
    }
    return (inventory);
}

player_t *set_player(void)
{
    player_t *player = malloc(sizeof(player_t) * 1);

    if (player == NULL)
        return (NULL);
    player->stats = set_player_stats();
    player->stuff = set_player_stuff();
    player->move = set_player_move();
    player->inventory = set_player_inventory();
    return (player);
}
