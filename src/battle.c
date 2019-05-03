/*
** EPITECH PROJECT, 2019
** menu
** File description:
** my_rpg
*/

#include "rpg.h"
#include "struct.h"

void display_battle(battle_t *battle, ebattle_t *enemy, player_t *player,
                    sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, battle->s_back, NULL);
    sfRenderWindow_drawSprite(window, battle->s_hud, NULL);
    sfRenderWindow_drawSprite(window, battle->player->s_player, NULL);
    if (enemy->action == 2) {
        flm_move(enemy, battle);
        sfRenderWindow_drawSprite(window, enemy->flm->spr, NULL);
    }
    sfRenderWindow_drawSprite(window, enemy->s_ene, NULL);
    atk(battle, window);
    enemy_atk(enemy, battle, player, window);
    sfRenderWindow_drawRectangleShape(window, battle->hud->hp, NULL);
    sfRenderWindow_drawRectangleShape(window, battle->hud->xp, NULL);
    sfRenderWindow_drawRectangleShape(window, battle->hud->ene_hp, NULL);
    sfRenderWindow_drawText(window, battle->hud->lvl, NULL);
}

int game_battle(sfRenderWindow *window, player_t *player, ebattle_t *enemy)
{
    battle_t *battle = init_battle(player);
    sfClock *clock = sfClock_create();
    
    while (sfRenderWindow_isOpen(window) && battle->end == 0) {
        display_battle(battle, enemy, player, window);
        sfRenderWindow_display(window);
        battle_action(window, battle, enemy, player);
        battle->end = battle_end(player, enemy);
    }
    game_loots(window, battle, enemy);
    return (0);
}
