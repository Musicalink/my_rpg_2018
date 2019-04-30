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
    printf("up : %d\n", player->stats->xp);
    percent = player->stats->xp / up;
    printf("perc : %f\n", percent);
    bar = (sfVector2f){790 * percent, 20};
    return (bar);
}
