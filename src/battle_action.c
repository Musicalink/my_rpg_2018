/*
** EPITECH PROJECT, 2019
** battle_action.c
** File description:
** battle_action
*/

#include "rpg.h"
#include "struct.h"

int get_action(sfRenderWindow *window, battle_t *battle, ebattle_t *enemy,
               player_t *player)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (battle->turn == 1 || battle->player->action != 0)
        return (0);
    if (mouse.y > 1000 && mouse.y < 1071) {
        if (mouse.x >= 565 && mouse.x <= 636) {
            battle->player->action = 1;
            enemy->stats->hp -= player->stats->atk - enemy->stats->def;
            upd_hp_enemy(enemy, battle->hud);
        } else if (mouse.x >= 645 && mouse.x < 716)
            battle->player->action = 2;
    }
}

int enemy_action(battle_t *battle, ebattle_t *enemy, player_t *player)
{
    if (battle->turn == 1 && enemy->action == 0) {
        player->stats->hp -= enemy->stats->atk - player->stats->def;
        enemy->action = 1;
        upd_hp_player(player, battle->hud);
    }
    return (0);
}

int battle_action(sfRenderWindow *window, battle_t *battle, ebattle_t *enemy,
                  player_t *player)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonReleased) {
            get_action(window, battle, enemy, player);
        }
    }
    enemy_action(battle, enemy, player);
}
