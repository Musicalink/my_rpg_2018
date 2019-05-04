/*
** EPITECH PROJECT, 2019
** set_lootscreen.c
** File description:
** set loot screen
*/

#include "rpg.h"
#include "struct.h"

char *xp_char(battle_t *battle)
{
    char *xp = "XP : ";
    char *nb;

    if (battle->end == 1)
        nb = my_strdup("0");
    else
        nb = my_itoa(battle->enemy->stats->xp);
    if (nb == NULL)
        return (NULL);
    xp = mall_strcat(xp, nb);
    if (xp == NULL)
        return (NULL);
    return (xp);
}

void get_battle_status(battle_t *battle, loots_t *loot)
{
    if (battle->end == 1)
        sfText_setString(loot->status, "DEFEAT  !");
    else
        sfText_setString(loot->status, "VICTORY !");
}
