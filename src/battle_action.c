/*
** EPITECH PROJECT, 2019
** battle_action.c
** File description:
** battle_action
*/

#include "rpg.h"
#include "struct.h"

int get_action(sfRenderWindow *window, battle_t *battle)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (battle->turn == 1 || battle->player->action != 0)
        return (0);
    if (mouse.y > 1000 && mouse.y < 1071) {
        if (mouse.x >= 565 && mouse.x <= 636) {
            battle->player->action = 1;
        } else if (mouse.x >= 645 && mouse.x < 716)
            battle->player->action = 2;
    }
}

int battle_action(sfRenderWindow *window, battle_t *battle)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonReleased) {
            get_action(window, battle);
        }
    }   
}
