/*
** EPITECH PROJECT, 2019
** drop
** File description:
** my_rpg
*/

#include "rpg.h"
#include "struct.h"

anim_t *choose_drop(battle_t *battle, anim_t ***drop)
{
    srand(time(NULL));
    int type = rand() % 3;
    int luck = rand() % 100;
    int rarety = -1;

    if (battle->enemy->type == 0) {
	rarety = (luck < 90) ? 0 : rarety;
	rarety = (luck >= 90 && luck < 97) ? 1 : rarety;
	rarety = (luck >= 97 && luck <= 99) ? 2 : rarety;
    } else if (battle->enemy->type == 1) {
	rarety = (luck < 70) ? 0 : rarety;
        rarety = (luck >= 70 && luck < 89) ? 1 : rarety;
        rarety = (luck >= 89 && luck <= 99) ? 2	: rarety;
    } else {
	rarety = (luck < 50) ? 0 : rarety;
        rarety = (luck >= 50 && luck < 79) ? 1 : rarety;
        rarety = (luck >= 79 && luck <= 99) ? 2 : rarety;
    }
    return (drop[type][rarety]);
}
