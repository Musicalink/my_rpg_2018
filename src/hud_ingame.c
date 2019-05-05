/*
** EPITECH PROJECT, 2019
** xp.c
** File description:
** file linked to experience in game
*/

#include "rpg.h"

sfVector2f bar_xp(player_t *player)
{
    int up;
    float percent;
    sfVector2f bar;

    up = 20 + 20 + 5 * (player->stats->level - 1);
    percent = (float)(player->stats->xp) / (float)(up);
    bar = (sfVector2f){790 * percent, 20};
    return (bar);
}

void upd_hp_player(pbattle_t *player, bhud_t *hud)
{
    float percent = (float)(player->stats->hp) / (float)(player->stats->hp_max);
    sfVector2f bar = (sfVector2f){317 * percent, 26};

    sfRectangleShape_setSize(hud->hp, bar);
}

void upd_hp_enemy(ebattle_t *enemy, bhud_t *hud)
{
    float percent = (float)(enemy->stats->hp) / (float)(enemy->stats->hp_max);
    sfVector2f bar = (sfVector2f){317 * percent, 26};

    sfRectangleShape_setSize(hud->ene_hp, bar);
}

char *display_lvl(player_t *player)
{
    char *str = my_strdup("Lvl : ");
    char *lvl = my_itoa(player->stats->level);
    char *res;

    if (str == NULL || lvl == NULL)
        return (NULL);
    res = mall_strcat(str, lvl);
    free(str);
    free(lvl);
    return (res);
}

void set_hud(bhud_t *hud, player_t *player)
{
    char *lvl = display_lvl(player);

    if (lvl != NULL)
        sfText_setString(hud->lvl, lvl);
    sfText_setFont(hud->lvl, hud->font);
    sfText_setPosition(hud->lvl, (sfVector2f){910, 925});
    sfRectangleShape_setPosition(hud->hp, (sfVector2f){565, 932});
    sfRectangleShape_setPosition(hud->ene_hp, (sfVector2f){1038, 932});
    sfRectangleShape_setPosition(hud->xp, (sfVector2f){565, 970});
    sfRectangleShape_setSize(hud->hp, (sfVector2f){317, 26});
    sfRectangleShape_setSize(hud->ene_hp, (sfVector2f){317, 26});
    sfRectangleShape_setSize(hud->xp, bar_xp(player));
    sfRectangleShape_setFillColor(hud->hp, sfRed);
    sfRectangleShape_setFillColor(hud->ene_hp, sfBlue);
    sfRectangleShape_setFillColor(hud->xp, sfGreen);
}
