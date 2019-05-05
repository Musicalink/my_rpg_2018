/*
** EPITECH PROJECT, 2019
** set_lootscreen.c
** File description:
** set loot screen
*/

#include "rpg.h"

void set_loot(loots_t *loot, battle_t *battle)
{
    char *xp = xp_char(battle);

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

void set_drop_sprite(anim_t **drop, char *ress)
{
    int cnt;

    for (cnt = 0; cnt != 3; cnt++) {
        drop[cnt]->spr = sfSprite_create();
        drop[cnt]->txt = sfTexture_createFromFile(ress, NULL);
        drop[cnt]->rect = create_rect((cnt * 138), 0, 138, 138);
        sfSprite_setTexture(drop[cnt]->spr, drop[cnt]->txt, sfTrue);
        sfSprite_setTextureRect(drop[cnt]->spr, drop[cnt]->rect);
        sfSprite_setPosition(drop[cnt]->spr, (sfVector2f){770, 490});
    }
}

void init_drop_sprite(anim_t ***drop, int pos)
{
    int cnt;

    for (cnt = 0; cnt != 3; cnt++) {
        drop[pos][cnt] = malloc(sizeof(anim_t));
        if (drop[pos][cnt] == NULL)
            exit(84);
    }
    if (pos == 0)
        set_drop_sprite(drop[pos], ARMOR);
    else if (pos == 1)
        set_drop_sprite(drop[pos], BOOTS);
    else
        set_drop_sprite(drop[pos], HELMET);
}

anim_t ***set_drop(void)
{
    anim_t ***drop = malloc(sizeof(anim_t **) * 4);
    int cnt;

    if (drop == NULL)
        exit(84);
    drop[3] = NULL;
    for (cnt = 0; cnt != 3; cnt++) {
        drop[cnt] = malloc(sizeof(anim_t *) * 4);
        if (drop[cnt] == NULL)
            exit(84);
        drop[cnt][3] = NULL;
        init_drop_sprite(drop, cnt);
    }
    return (drop);
}

loots_t *init_loot(battle_t *battle, inventory_t *inv)
{
    loots_t *loot = malloc(sizeof(loots_t));
    anim_t ***drop = set_drop();

    loot->t_back = sfTexture_createFromFile(REWARD, NULL);
    loot->s_back = sfSprite_create();
    loot->font = sfFont_createFromFile(ARIAL);
    loot->loot = sfText_create();
    loot->xp = sfText_create();
    loot->status = sfText_create();
    loot->drop = choose_drop(battle, drop, inv);
    set_loot(loot, battle);
    return (loot);
}
