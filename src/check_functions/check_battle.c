/*
** EPITECH PROJECT, 2019
** check_battle
** File description:
** rpg
*/

#include <stddef.h>
#include "rpg.h"

int check_menu(menu_t *menu)
{
    if (menu != NULL || menu->texture == NULL || menu->sprite == NULL)
        return (1);
    if (menu->play == NULL || menu->exit == NULL || menu->font == NULL)
        return (1);
    return (0);
}

int check_battle_hud(bhud_t *hud)
{
    if (hud == NULL || hud->hp == NULL || hud->xp == NULL)
        return (1);
    if (hud->ene_hp == NULL || hud->lvl == NULL || hud->font == NULL)
        return (1);
    return (0);
}

int check_player_battle(pbattle_t *battle)
{
    if (battle == NULL || battle->s_ene == NULL || battle->t_ene == NULL)
        return (1);
    if (battle->stats == NULL || battle->clock == NULL)
        return (1);
    return (0);
}

int check_battle(battle_t *battle)
{
    if (battle != NULL || battle->s_back == NULL || battle->t_back == NULL)
        return (1);
    if (battle->s_hud == NULL || battle->t_hud == NULL)
        return (1);
    return (0);
}

int check_all_battle(battle_t *battle)
{
    if (check_battle(battle) == 1 || check_player_battle(battle->player) == 1)
        return (1);
    if (check_battle_hud(battle->hud) == 1)
        return (1);
    return (0);
}
