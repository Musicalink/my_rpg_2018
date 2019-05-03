/*
** EPITECH PROJECT, 2019
** battle_loots.c
** File description:
** loots for battle
*/

#include "rpg.h"
#include "struct.h"

void display_loots(sfRenderWindow *window, loots_t *loot)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, loot->s_back, NULL);
    sfRenderWindow_drawText(window, loot->xp, NULL);
    sfRenderWindow_drawText(window, loot->loot, NULL);
    sfRenderWindow_drawText(window, loot->status, NULL);
}

int game_loots(sfRenderWindow *window, battle_t *battle, ebattle_t *enemy)
{
    loots_t *loot = init_loot(battle, enemy);
    sfClock *clock = sfClock_create();
    sfTime time;
    double seconds;

    while (sfRenderWindow_isOpen(window) && seconds < 30) {
        time = sfClock_getElapsedTime(enemy->flm->clock);
        seconds = time.microseconds / 1000000.0;
        display_loots(window, loot);
        sfRenderWindow_display(window);
    }
    return (0);
}
