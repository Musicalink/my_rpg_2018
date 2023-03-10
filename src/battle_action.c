/*
** EPITECH PROJECT, 2019
** battle_action.c
** File description:
** battle_action
*/

#include "rpg.h"

void rm_hp_enemy(ebattle_t *enemy, pbattle_t *player, inventory_t *inventory)
{
    int atk = player->stats->atk;
    int def = enemy->stats->def;

    for (int i = 0; inventory->stuff[i] != NULL; i++)
        atk += inventory->stuff[i]->atk;
    if (atk - def > 0)
        enemy->stats->hp -= atk - def;
    enemy->stats->hp = (enemy->stats->hp < 0) ? 0 : enemy->stats->hp;
}

void rm_hp_player(ebattle_t *enemy, pbattle_t *player, inventory_t *inventory)
{
    int atk = enemy->stats->atk;
    int def = player->stats->def;

    for (int i = 0; inventory->stuff[i] != NULL; i++)
        def += inventory->stuff[i]->def;
    if (player->action == 2)
        def *= 2.5;
    if (enemy->action == 2) {
        atk = atk * 2;
        enemy->action = 0;
    } else
        enemy->action++;
    player->stats->hp -= (atk - def > 0) ? atk - def : 0;
    player->stats->hp = (player->stats->hp < 0) ? 0 : player->stats->hp;
}

int enemy_action(battle_t *battle, inventory_t *inventory)
{
    if (battle->turn == 1 && battle->enemy->wait == 0) {
        rm_hp_player(battle->enemy, battle->player, inventory);
        upd_hp_player(battle->player, battle->hud);
        battle->enemy->wait = 1;
    }
    return (0);
}

void get_action(sfRenderWindow *window, battle_t *battle, inventory_t *inv)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (battle->turn == 1 || battle->player->action != 0)
        return;
    if (mouse.y > 1000 && mouse.y < 1071) {
        if (mouse.x >= 565 && mouse.x <= 636) {
            battle->player->action = 1;
            rm_hp_enemy(battle->enemy, battle->player, inv);
            upd_hp_enemy(battle->enemy, battle->hud);
        } else if (mouse.x >= 645 && mouse.x < 716) {
            battle->player->action = 2;
            battle->turn = 1;
        }
    }
}

int battle_action(sfRenderWindow *window, battle_t *battle, inventory_t *inv)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtMouseButtonReleased)
            get_action(window, battle, inv);
}
