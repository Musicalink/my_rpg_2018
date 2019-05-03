/*
** EPITECH PROJECT, 2019
** set_player
** File description:
** player
*/

#include "rpg.h"

stats_t *set_player_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t) * 1);

    if (stats == NULL)
        return (NULL);
    stats->level = 1;
    stats->xp = 0;
    stats->hp = 100;
    stats->hp_max = 100;
    stats->atk = 1000;
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

game_t *init_move(game_t *game)
{
    game->moves = sfSprite_create();
    game->moves_t[0] = sfTexture_createFromFile(WALK_RIGHT, NULL);
    game->moves_t[1] = sfTexture_createFromFile(WALK_LEFT, NULL);
    game->moves_t[2] = sfTexture_createFromFile(WALK_UP, NULL);
    game->moves_t[3] = sfTexture_createFromFile(WALK_DOWN, NULL);
    game->moves_r = create_rect(0, 0, 240, 299);
    sfSprite_setTexture(game->moves, game->moves_t[0], sfTrue);
    sfSprite_setTextureRect(game->moves, game->moves_r);
    game->p_pos.x = 500;
    game->p_pos.y = 500;
    sfSprite_setPosition(game->moves, game->p_pos);
    return (game);
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
    player->inventory = set_player_inventory();
    return (player);
}
