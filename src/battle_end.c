/*
** EPITECH PROJECT, 2019
** battle_end.c
** File description:
** check end of battle
*/

#include "rpg.h"
#include "struct.h"

void update_xp(player_t *player, ebattle_t *enemy)
{
    int up = 20 + 20 + 5 * (player->stats->level - 1);
    
    player->stats->xp += enemy->stats->xp;
    if (player->stats->xp >= up) {
        player->stats->level += 1;
        player->stats->xp -= up;
    }
}

void reset_enemy()
{
    
}

int battle_end(player_t *player, ebattle_t *enemy)
{
    if (player->stats->hp <= 0) {
        enemy->stats->hp = enemy->stats->hp_max;
        player->stats->hp = player->stats->hp_max;
        return (1);
    } else if (enemy->stats->hp <= 0) {
        enemy->stats->hp = enemy->stats->hp_max;
        player->stats->hp = player->stats->hp_max;
        update_xp(player, enemy); 
        return (2);
    }
    return (0);
}
