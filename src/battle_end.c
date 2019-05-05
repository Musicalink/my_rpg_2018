/*
** EPITECH PROJECT, 2019
** battle_end.c
** File description:
** check end of battle
*/

#include "rpg.h"

void lvl_up_stats(player_t *player, inventory_t *inventory)
{
    player->stats->hp_max += 10 + 1 * (player->stats->level - 1);
    player->stats->atk += 2;
    player->stats->def += 1;
}

void update_xp(player_t *player, ebattle_t *enemy, inventory_t *inventory)
{
    int up = 20 + 20 + 5 * (player->stats->level - 1);

    player->stats->xp += enemy->stats->xp;
    while (player->stats->xp >= up) {
        lvl_up_stats(player, inventory);
        player->stats->level += 1;
        player->stats->xp -= up;
    }
}

int battle_end(player_t *player, ebattle_t *enemy, inventory_t *inventory)
{
    if (player->stats->hp <= 0) {
        enemy->stats->hp = enemy->stats->hp_max;
        player->stats->hp = player->stats->hp_max;
        return (1);
    } else if (enemy->stats->hp <= 0) {
        enemy->action = 0;
        update_xp(player, enemy, inventory);
        player->stats->hp = player->stats->hp_max;
        enemy->stats->hp = enemy->stats->hp_max;
        return (2);
    }
    return (0);
}
