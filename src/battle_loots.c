/*
** EPITECH PROJECT, 2019
** battle_loots.c
** File description:
** loots for battle
*/

#include "rpg.h"

void display_loots(sfRenderWindow *window, loots_t *loot)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, loot->s_back, NULL);
    sfRenderWindow_drawText(window, loot->xp, NULL);
    sfRenderWindow_drawText(window, loot->loot, NULL);
    sfRenderWindow_drawText(window, loot->status, NULL);
    if (loot->drop != NULL)
        sfRenderWindow_drawSprite(window, loot->drop->spr, NULL);
}

int game_loots(sfRenderWindow *window, battle_t *battle, inventory_t *inv)
{
    loots_t *loot = init_loot(battle, inv);
    sfClock *clock = sfClock_create();
    sfTime time;
    double seconds = 0;

    while (sfRenderWindow_isOpen(window) && seconds < 1.25) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        display_loots(window, loot);
        sfRenderWindow_display(window);
    }
    sfClock_destroy(clock);
    close_loots(loot);
    return (0);
}
