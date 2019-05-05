/*
** EPITECH PROJECT, 2019
** close_loots.c
** File description:
** close loots
*/

#include "rpg.h"
#include "struct.h"

void close_loots(loots_t *loots)
{
    sfSprite_destroy(loots->s_back);
    sfTexture_destroy(loots->t_back);
    sfFont_destroy(loots->font);
    sfText_destroy(loots->loot);
    sfText_destroy(loots->xp);
    sfText_destroy(loots->status);
    free(loots);
}
