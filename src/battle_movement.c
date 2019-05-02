/*
** EPITECH PROJECT, 2019
** battle_movement.c
** File description:
** 
*/

#include "rpg.h"
#include "struct.h"

void atk(battle_t *bat, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime(bat->player->clock);
    double seconds = time.microseconds / 1000000.0;

    if (seconds > 0.06 && bat->player->action == 1) {
        if (bat->player->rect.left == 4608) {
            bat->player->rect.left = 0;
            bat->player->action = 0;
            bat->turn = 1;
        } else
            bat->player->rect.left += 512;
        sfSprite_setTextureRect(bat->player->s_player, bat->player->rect);
        sfClock_restart(bat->player->clock);
    }
}

void enemy_atk(ebattle_t *enemy, battle_t *bat, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime(enemy->clock);
    double seconds = time.microseconds / 1000000.0;

    if (seconds > 0.06 && enemy->action == 1) {
        if (enemy->rect.left == enemy->size.x * enemy->frame) {
            enemy->rect.left = 0;
            bat->turn = 0;
        } else
            enemy->rect.left += enemy->size.x;
        sfSprite_setTextureRect(enemy->s_ene, enemy->rect);
        sfClock_restart(enemy->clock);
    }
}
