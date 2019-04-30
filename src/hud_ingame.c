/*
** EPITECH PROJECT, 2019
** xp.c
** File description:
** file linked to experience in game
*/

#include "rpg.h"
#include "struct.h"

sfVector2f bar_xp(player_t *player)
{
    int up;
    float percent;
    sfVector2f bar;

    up = 20 + 20 + 5 * (player->stats->level - 1);
    percent = (float)(player->stats->xp) / (float)(up);
    bar = (sfVector2f){790 * percent, 20};
    return (bar);
}
