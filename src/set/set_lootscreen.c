/*
** EPITECH PROJECT, 2019
** set_lootscreen.c
** File description:
** set loot screen
*/

#include "rpg.h"
#include "struct.h"

void set_loot(loots_t *loot, battle_t *battle, ebattle_t *enemy)
{
    char *xp = xp_char(battle, enemy);
    
    sfSprite_setPosition(loot->s_back, (sfVector2f){480, 270});
    sfSprite_setTexture(loot->s_back, loot->t_back, sfTrue);
    sfText_setFont(loot->xp, loot->font);
    sfText_setFont(loot->loot, loot->font);
    sfText_setFont(loot->status, loot->font);
    if (xp != NULL)
        sfText_setString(loot->xp, xp);
    get_battle_status(battle, loot);
    sfText_setString(loot->loot, "LOOTS : ");
    sfText_setCharacterSize(loot->xp, 50);
    sfText_setCharacterSize(loot->loot, 50);
    sfText_setCharacterSize(loot->status, 50);
    sfText_setColor(loot->xp, (sfColor){255, 255, 255, 255});
    sfText_setColor(loot->loot, (sfColor){255, 255, 255, 255});
    sfText_setColor(loot->status, (sfColor){255, 255, 255, 255});
    sfText_setPosition(loot->xp, (sfVector2f){550, 450});
    sfText_setPosition(loot->loot, (sfVector2f){550, 550});
    sfText_setPosition(loot->status, (sfVector2f){860, 300});
}

loots_t *init_loot(battle_t *battle, ebattle_t *enemy)
{
    loots_t *loot = malloc(sizeof(loots_t));

    loot->t_back = sfTexture_createFromFile(REWARD, NULL);
    loot->s_back = sfSprite_create();
    loot->font = sfFont_createFromFile(ARIAL);
    loot->loot = sfText_create();
    loot->xp = sfText_create();
    loot->status = sfText_create();
    set_loot(loot, battle, enemy);
    return (loot);
}
