/*
** EPITECH PROJECT, 2019
** menu
** File description:
** my_rpg
*/

#include "rpg.h"
#include "struct.h"

void display_battle(battle_t *battle, ebattle_t *enemy ,sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, battle->s_back, NULL);
    sfRenderWindow_drawSprite(window, battle->s_hud, NULL);
    sfRenderWindow_drawSprite(window, battle->player->s_player, NULL);
    sfRenderWindow_drawSprite(window, enemy->s_ene, NULL);
    atk(battle, window);
    enemy_atk(enemy, window);
    sfRenderWindow_drawRectangleShape(window, battle->hud->hp, NULL);
    sfRenderWindow_drawRectangleShape(window, battle->hud->xp, NULL);
    sfRenderWindow_drawRectangleShape(window, battle->hud->ene_hp, NULL);
    sfRenderWindow_drawText(window, battle->hud->lvl, NULL);
}

int game_battle(sfRenderWindow *window, player_t *player, ebattle_t *enemy)
{
    battle_t *battle = init_battle(player);
    int turn = 0;
    sfClock *clock = sfClock_create();
    
    while (sfRenderWindow_isOpen(window) /*&& battle_end(player, enemy) != 0*/) {     
        display_battle(battle, enemy, window);
        sfRenderWindow_display(window);
        battle_action(window, battle, enemy, player);
    }
    return (0);
}
