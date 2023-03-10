/*
** EPITECH PROJECT, 2019
** set_battle.c
** File description:
** set battle mode
*/

#include "rpg.h"

bhud_t *init_hud(player_t *player)
{
    bhud_t *hud = malloc(sizeof(bhud_t));

    if (hud == NULL)
        return (NULL);
    hud->hp = sfRectangleShape_create();
    hud->xp = sfRectangleShape_create();
    hud->ene_hp = sfRectangleShape_create();
    hud->lvl = sfText_create();
    hud->font = sfFont_createFromFile(ARIAL);
    set_hud(hud, player);
    return (hud);
}

void set_battle(battle_t *battle)
{
    sfSprite_setTexture(battle->s_back, battle->t_back, sfTrue);
    sfSprite_setTexture(battle->s_hud, battle->t_hud, sfTrue);
    sfSprite_setPosition(battle->s_back, (sfVector2f){0, 0});
    sfSprite_setPosition(battle->s_hud, (sfVector2f){555, 922});
}

battle_t *init_battle(player_t *player, ebattle_t *enemy)
{
    battle_t *tmp = malloc(sizeof(battle_t));

    if (tmp == NULL)
        return (NULL);
    tmp->t_back = sfTexture_createFromFile(BATTLE, NULL);
    tmp->t_hud = sfTexture_createFromFile(HUD, NULL);
    tmp->s_back = sfSprite_create();
    tmp->s_hud = sfSprite_create();
    tmp->hud = init_hud(player);
    tmp->player = init_player_battle(ATK, player);
    tmp->enemy = enemy;
    tmp->turn = 0;
    tmp->end = 0;
    set_battle(tmp);
    return (tmp);
}
