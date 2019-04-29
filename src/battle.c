/*
** EPITECH PROJECT, 2019
** menu
** File description:
** my_rpg
*/

#include "rpg.h"
#include "struct.h"

int display_battle(battle_t *battle, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, battle->s_back, NULL);
    sfRenderWindow_drawSprite(window, battle->s_hud, NULL);
}

int game_battle(sfRenderWindow *window)
{
    battle_t *battle = init_battle("ressources/sprites/battle.png");
    
    while (sfRenderWindow_isOpen(window)) {
        display_battle(battle, window);
        sfRenderWindow_display(window);
    }
    return (0);
}
