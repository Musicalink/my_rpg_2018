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
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, battle->s_back, NULL);
    sfRenderWindow_drawSprite(window, battle->s_hud, NULL);
    sfRenderWindow_drawSprite(window, battle->player->s_player, NULL);
    battle->player->p_atk(battle->player, window);
    sfRenderWindow_drawRectangleShape(window, battle->hud->hp, NULL);
    sfRenderWindow_drawRectangleShape(window, battle->hud->xp, NULL);
    sfRenderWindow_drawRectangleShape(window, battle->hud->ene_hp, NULL);
    sfRenderWindow_drawText(window, battle->hud->lvl, NULL);
}

void atk(pbattle_t *player, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime(player->clock);
    double seconds = time.microseconds / 1000000.0;

    if (seconds > 0.06) {
        if (player->rect.left == 4608)
            player->rect.left = 0;
        else
            player->rect.left += 512;
        sfSprite_setTextureRect(player->s_player, player->rect);
        sfClock_restart(player->clock);
    }
}

int game_battle(sfRenderWindow *window, player_t *player)
{
    battle_t *battle = init_battle(player);
    int turn = 0;
    
    while (sfRenderWindow_isOpen(window) /*&& battle_end(player, enemy) != 0*/) {     
        display_battle(battle, window);
        sfRenderWindow_display(window);
    }
    return (0);
}
