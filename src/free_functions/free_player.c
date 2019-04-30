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

void destroy_sprite_texture(sfSprite *sprite, sfTexture *texture)
{
    if (sprite != NULL)
        sfSprite_destroy(move->s_right);
    if (texture != NULL)
        sfTexture_destroy(texture);
}

void free_player_move(moving_t *move)
{
    destroy_sprite_texture(move->s_right, move->t_right);
    destroy_sprite_texture(move->s_left, move->t_left);
    destroy_sprite_texture(move->s_up, move->t_up);
    destroy_sprite_texture(move->s_down, move->t_down);
    free(move);
}

void free_player(player_t *player)
{
    if (player != NULL) {
        if (player->stats != NULL)
            free(player->stats);
        free_player_stuff(player->stuff);
        free_player_inventory(player->inventory);
        if (player->move != NULL)
            free_player_move(player->move);
        free(player);
    }
}
