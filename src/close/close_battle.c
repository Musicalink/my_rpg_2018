/*
** EPITECH PROJECT, 2019
** close_battle.c
** File description:
** close battle
*/

#include "rpg.h"
#include "struct.h"

void close_player_battle(pbattle_t *player)
{
    sfSprite_destroy(player->s_player);
    sfTexture_destroy(player->t_player);
    sfClock_destroy(player->clock);
    free(player);
}

void close_hud(bhud_t *hud)
{
    sfRectangleShape_destroy(hud->xp);
    sfRectangleShape_destroy(hud->hp);
    sfRectangleShape_destroy(hud->ene_hp);
    sfText_destroy(hud->lvl);
    sfFont_destroy(hud->font);
    free(hud);
}

void close_battle(battle_t *battle)
{
    sfSprite_destroy(battle->s_back);
    sfSprite_destroy(battle->s_hud);
    sfTexture_destroy(battle->t_back);
    sfTexture_destroy(battle->t_hud);
    close_hud(battle->hud);
    close_player_battle(battle->player);
    free(battle);
}
