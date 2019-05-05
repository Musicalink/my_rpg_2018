/*
** EPITECH PROJECT, 2019
** menu
** File description:
** my_rpg
*/

#include "rpg.h"
#include "struct.h"

void display_battle(battle_t *battle, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    atk(battle, window);
    enemy_atk(battle, window);
    sfRenderWindow_drawSprite(window, battle->s_back, NULL);
    sfRenderWindow_drawSprite(window, battle->s_hud, NULL);
    sfRenderWindow_drawSprite(window, battle->player->s_player, NULL);
    if (battle->enemy->action == 2) {
        flm_move(battle->enemy->flm);
        sfRenderWindow_drawSprite(window, battle->enemy->flm->spr, NULL);
    }
    sfRenderWindow_drawSprite(window, battle->enemy->s_ene, NULL);
    sfRenderWindow_drawRectangleShape(window, battle->hud->hp, NULL);
    sfRenderWindow_drawRectangleShape(window, battle->hud->xp, NULL);
    sfRenderWindow_drawRectangleShape(window, battle->hud->ene_hp, NULL);
    sfRenderWindow_drawText(window, battle->hud->lvl, NULL);
}

int game_battle(sfRenderWindow *window, player_t *player, ebattle_t *enemy, inventory_t *inv)
{
    battle_t *battle = init_battle(player, enemy);
    sfClock *clock = sfClock_create();
    
    while (sfRenderWindow_isOpen(window) && battle->end == 0) {
        display_battle(battle, window);
        sfRenderWindow_display(window);
        battle_action(window, battle);
        battle->end = battle_end(player, enemy);
    }
    game_loots(window, battle, inv);
    return (0);
}
