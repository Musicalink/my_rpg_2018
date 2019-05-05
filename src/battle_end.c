/*
** EPITECH PROJECT, 2019
** battle_end.c
** File description:
** check end of battle
*/

#include "rpg.h"
#include "struct.h"

void lvl_up_stats(player_t *player)
{
    player->stats->hp_max += 10 + 1 * (player->stats->level - 1);
    player->stats->atk += 2;
    player->stats->def += 1;
}

void update_xp(player_t *player, ebattle_t *enemy)
{
    int up = 20 + 20 + 5 * (player->stats->level - 1);
    
    player->stats->xp += enemy->stats->xp;
    while (player->stats->xp >= up) {
        lvl_up_stats(player);
        player->stats->level += 1;
        player->stats->xp -= up;
    }
}

int battle_end(player_t *player, ebattle_t *enemy)
{
    if (player->stats->hp <= 0) {
        enemy->stats->hp = enemy->stats->hp_max;
        player->stats->hp = player->stats->hp_max;
        return (1);
    } else if (enemy->stats->hp <= 0) {
        enemy->action = 0;
        update_xp(player, enemy);
        player->stats->hp = player->stats->hp_max;
        enemy->stats->hp = enemy->stats->hp_max;         
        return (2);
    }
    return (0);
}
