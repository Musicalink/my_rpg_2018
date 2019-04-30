/*
** EPITECH PROJECT, 2019
** set_battle.c
** File description:
** set battle mode
*/

#include "rpg.h"
#include "struct.h"

bhud_t *init_hud(player_t *player)
{
    bhud_t * hud = malloc(sizeof(bhud_t));
    
    if (hud == NULL)
        return (NULL);
    hud->hp = sfRectangleShape_create();
    hud->xp = sfRectangleShape_create();
    sfRectangleShape_setPosition(hud->hp, (sfVector2f){565, 932});
    sfRectangleShape_setPosition(hud->xp, (sfVector2f){565, 970});
    sfRectangleShape_setSize(hud->hp, (sfVector2f){317, 26});
    sfRectangleShape_setSize(hud->xp, bar_xp(player));
    sfRectangleShape_setFillColor(hud->hp, sfRed);
    sfRectangleShape_setFillColor(hud->xp, sfGreen);
    return (hud);
}

void set_battle(battle_t *battle)
{    
    sfSprite_setTexture(battle->s_back, battle->t_back, sfTrue);
    sfSprite_setTexture(battle->s_hud, battle->t_hud, sfTrue);
    sfSprite_setPosition(battle->s_back, (sfVector2f){0, 0});
    sfSprite_setPosition(battle->s_hud, (sfVector2f){555, 922});
}

battle_t *init_battle(player_t *player)
{
    battle_t *tmp = malloc(sizeof(battle_t));

    if (tmp == NULL)
        return (NULL);
    tmp->t_back = sfTexture_createFromFile("ressources/sprites/battle.png", NULL);
    tmp->t_hud = sfTexture_createFromFile("ressources/sprites/hud.png", NULL);
    tmp->s_back = sfSprite_create();
    tmp->s_hud = sfSprite_create();
    tmp->hud = init_hud(player);
    tmp->player = init_player_battle("ressources/sprites/atk.png", NULL);
    set_battle(tmp);
    return (tmp);
}
