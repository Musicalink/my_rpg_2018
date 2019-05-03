/*
** EPITECH PROJECT, 2019
** free_player
** File description:
** rpg
*/

#include <stddef.h>
#include <stdlib.h>
#include "rpg.h"
#include "struct.h"

void free_player_stuff(stuff_t **stuff)
{
    for (int i = 0; i <= 3; i++) {
        if (stuff[i] != NULL)
            free(stuff[i]);
    }
    free(stuff);
}

void free_player_inventory(stuff_t **inventory)
{
    for (int i = 0; i <= 14; i++) {
        if (inventory[i] != NULL)
            free(inventory[i]);
    }
    free(inventory);
}

void free_player(player_t *player)
{
    if (player != NULL) {
        if (player->stats != NULL)
            free(player->stats);
        free_player_stuff(player->stuff);
        free_player_inventory(player->inventory);
        free(player);
    }
}
