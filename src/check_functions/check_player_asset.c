/*
** EPITECH PROJECT, 2019
** check_player_asset
** File description:
** rpg
*/

#include <stddef.h>
#include "rpg.h"

int check_sprite_texture(sfSprite *sprite, sfTexture *texture)
{
    if (sprite == NULL || texture == NULL)
        return (1);
    else
        return (0);
}

int check_player_asset(player_t *player)
{
    if (player == NULL || player->stats == NULL || player->stuff == NULL)
        return (1);
    else if (player->inventory == NULL)
        return (1);
    else
        return (0);
}
