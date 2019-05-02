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
            if (player->stats->atk - enemy->stats->def > 0)
                enemy->stats->hp -= player->stats->atk - enemy->stats->def;
            upd_hp_enemy(enemy, battle->hud);
        } else if (mouse.x >= 645 && mouse.x < 716)
            battle->player->action = 2;
    }
}

int rm_hp_player(battle_t *battle, ebattle_t *enemy, player_t *player)
{
    if (enemy->action == 2) {
        if ((enemy->stats->atk * 2) - player->stats->def > 0)
            player->stats->hp -= (enemy->stats->atk * 2) - player->stats->def;
        enemy->action = 0;
        return (0);
    }
    if (enemy->stats->atk - player->stats->def > 0) 
        player->stats->hp -= enemy->stats->atk - player->stats->def;
    enemy->action++;
    return (0);
}

int enemy_action(battle_t *battle, ebattle_t *enemy, player_t *player)
{
    if (battle->turn == 1 && enemy->wait == 0) {
        rm_hp_player(battle, enemy, player);
        upd_hp_player(player, battle->hud);
        enemy->wait = 1;
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
