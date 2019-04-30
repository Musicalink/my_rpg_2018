/*
** EPITECH PROJECT, 2019
** check_player_asset
** File description:
** rpg
*/

#include <stddef.h>
#include "rpg.h"
#include "struct.h"

int check_sprite_texture(sfSprite *sprite, sfTexture *texture)
{
    if (sprite == NULL || texture == NULL)
        return (1);
    else
        return (0);
}

int check_player_move(moving_t *move)
{
    int res = 0;

    if (move == NULL)
        return (1);
    res += check_sprite_texture(move->s_right, move->t_right);
    res += check_sprite_texture(move->s_left, move->t_left);
    res += check_sprite_texture(move->s_up, move->t_up);
    res += check_sprite_texture(move->s_down, move->t_down);
    if (move->rect == NULL)
        return (1);
    return (res);
}

int check_player_asset(player_t *player)
{
    if (player == NULL || player->stats == NULL || player->stuff == NULL)
        return (1);
    else if (player->inventory == NULL || check_player_move(player->move) == 1)
        return (1);
    else
        return (0);
}
