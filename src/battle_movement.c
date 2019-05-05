/*
** EPITECH PROJECT, 2019
** battle_movement.c
** File description:
** 
*/

#include "rpg.h"

void atk(battle_t *bat, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime(bat->player->clock);
    double seconds = time.microseconds / 1000000.0;

    if (bat->turn == 1)
        return;
    if (seconds > 0.06 && bat->player->action == 1) {
        if (bat->player->rect.left == 4608) {
            bat->player->rect.left = 0;
            bat->turn = 1;
        } else
            bat->player->rect.left += 512;
        sfSprite_setTextureRect(bat->player->s_player, bat->player->rect);
        sfClock_restart(bat->player->clock);
    }
}

void enemy_atk(battle_t *bat, sfRenderWindow *window, inventory_t *inventory)
{
    sfTime time = sfClock_getElapsedTime(bat->enemy->clock);
    double seconds = time.microseconds / 1000000.0;
    ebattle_t *enemy = bat->enemy;

    if (seconds > 0.06 && bat->turn == 1) {
        if (enemy->rect.left >= enemy->size.x * (enemy->frame - 1)) {
            enemy_action(bat, inventory);
            enemy->rect.left = 0;
            bat->turn = 0;
            bat->player->action = 0;
            enemy->wait = 0;
        } else
            enemy->rect.left += enemy->size.x;
        sfSprite_setTextureRect(enemy->s_ene, enemy->rect);
        sfClock_restart(enemy->clock);
    }
}

void flm_move(anim_t *flm)
{
    sfTime time = sfClock_getElapsedTime(flm->clock);
    double seconds = time.microseconds / 1000000.0;

    if (seconds > 0.06) {
        if (flm->rect.left >= flm->size.x * (flm->frame - 1)) {
            flm->rect.left = 0;
        } else
            flm->rect.left += flm->size.x;
        sfSprite_setTextureRect(flm->spr, flm->rect);
        sfClock_restart(flm->clock);
    }
}
