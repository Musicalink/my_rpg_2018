/*
** EPITECH PROJECT, 2019
** set_battle.c
** File description:
** set battle mode
*/

#include "rpg.h"
#include "struct.h"

void set_battle(battle_t *battle)
{    
    sfSprite_setTexture(battle->s_back, battle->t_back, sfTrue);
    sfSprite_setTexture(battle->s_hud, battle->t_hud, sfTrue);
    sfSprite_setPosition(battle->s_back, (sfVector2f){0, 0});
    sfSprite_setPosition(battle->s_hud, (sfVector2f){555, 922});
}

battle_t *init_battle(char *resources)
{
    battle_t *tmp = malloc(sizeof(battle_t));
 
    tmp->t_back = sfTexture_createFromFile(resources, NULL);
    tmp->t_hud = sfTexture_createFromFile("ressources/sprites/hud.png", NULL);
    tmp->s_back = sfSprite_create();
    tmp->s_hud = sfSprite_create();
    set_battle(tmp);
    return (tmp);
}
