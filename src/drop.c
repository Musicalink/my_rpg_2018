/*
** EPITECH PROJECT, 2019
** drop
** File description:
** my_rpg
*/

#include "rpg.h"
#include "struct.h"

void add_to_inventory(int rare, anim_t *item, inventory_t *inv, int type)
{
    int i = 0;
    int atk = 5 * (rare + 1) + rand() % 10;
    int def = 3 * (rare + 1) + rand() % 10;
    int hp = 15 * (rare + 1) + rand() % 30;

    for (i = 0; inv->stuff[i] != NULL; i++)
        if (inv->stuff[i]->type == type)
            break;
    if (i >= 9)
        return;
    if (inv->stuff[i] != NULL) {
        if ((atk + def + hp) <
            inv->stuff[i]->atk + inv->stuff[i]->def + inv->stuff[i]->hp)
            return;
    } else
        inv->stuff[i] = malloc(sizeof(stuff_t));
    inv->stuff[i]->type = type;
    inv->stuff[i]->atk = atk;
    inv->stuff[i]->def = def;
    inv->stuff[i]->hp = hp;
    inv->stuff[i]->anim = item;
}

anim_t *choose_drop(battle_t *battle, anim_t ***drop, inventory_t *inv)
{
    int type = rand() % 3;
    int luck = rand() % 100;
    int rarety = -1;

    if (battle->end == 1)
        return (NULL);
    if (battle->enemy->type == 0) {
        rarety = (luck < 90) ? 0 : rarety;
        rarety = (luck >= 90 && luck < 97) ? 1 : rarety;
        rarety = (luck >= 97 && luck <= 99) ? 2 : rarety;
    } else if (battle->enemy->type == 1) {
        rarety = (luck < 70) ? 0 : rarety;
        rarety = (luck >= 70 && luck < 89) ? 1 : rarety;
        rarety = (luck >= 89 && luck <= 99) ? 2 : rarety;
    } else {
        rarety = (luck < 50) ? 0 : rarety;
        rarety = (luck >= 50 && luck < 79) ? 1 : rarety;
        rarety = (luck >= 79 && luck <= 99) ? 2 : rarety;
    }
    add_to_inventory(rarety, drop[type][rarety], inv, type);
    return (drop[type][rarety]);
}
