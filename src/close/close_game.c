/*
** EPITECH PROJECT, 2019
** close_game.c
** File description:
** close_game
*/

#include "rpg.h"
#include "struct.h"

void close_inventory(inventory_t *inventory)
{
    sfSprite_destroy(inventory->spr);
    sfTexture_destroy(inventory->tex);
    free(inventory);
}

void close_pnj(game_t *game)
{
    sfSprite_destroy(game->pnj->spr);
    sfTexture_destroy(game->pnj->txt);
    sfText_destroy(game->pnj_text);
    free(game->pnj);
}

void close_move(game_t *game)
{
    sfSprite_destroy(game->moves);
    sfTexture_destroy(game->moves_t[0]);
    sfTexture_destroy(game->moves_t[1]);
    sfTexture_destroy(game->moves_t[2]);
    sfTexture_destroy(game->moves_t[3]);
}

void close_game(game_t *game)
{
    close_inventory(game->inventory);
    close_pnj(game);
    close_move(game);
    sfClock_destroy(game->clock);
    free(game);
}
