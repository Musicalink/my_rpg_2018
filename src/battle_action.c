/*
** EPITECH PROJECT, 2019
** battle_action.c
** File description:
** battle_action
*/

#include "rpg.h"
#include "struct.h"

void rm_hp_enemy(player_t *player, ebattle_t *enemy)
{
    int atk = player->stats->atk;
    int def = enemy->stats->def;

    if (atk - def > 0)
        enemy->stats->hp -= atk - def;
    enemy->stats->hp = (enemy->stats->hp < 0) ? 0 : enemy->stats->hp;
}

int get_action(sfRenderWindow *window, battle_t *battle, ebattle_t *enemy,
               player_t *player)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (battle->turn == 1 || battle->player->action != 0)
        return (0);
    if (mouse.y > 1000 && mouse.y < 1071) {
        if (mouse.x >= 565 && mouse.x <= 636) {
            battle->player->action = 1;
            rm_hp_enemy(player, enemy);
            upd_hp_enemy(enemy, battle->hud);
        } else if (mouse.x >= 645 && mouse.x < 716) {
            battle->player->action = 2;
            battle->turn = 1;
        }        
    }
}

void rm_hp_player(battle_t *battle, ebattle_t *enemy, player_t *player)
{
    int atk = enemy->stats->atk;
    int def = player->stats->def;

    if (battle->player->action == 2)
        def *= 1.7;
    if (enemy->action == 2) {
        atk = atk * 2;
        enemy->action = 0;
    } else
        enemy->action++;
    player->stats->hp -= (atk - def > 0) ? atk - def : 0;
    player->stats->hp = (player->stats->hp < 0) ? 0 : player->stats->hp;
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
}
