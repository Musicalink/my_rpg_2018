/*
** EPITECH PROJECT, 2019
** menu
** File description:
** my_rpg
*/

#include "rpg.h"

void display_battle(battle_t *battle, sfRenderWindow *window, inventory_t *inv)
{
    sfRenderWindow_clear(window, sfBlack);
    atk(battle, window);
    enemy_atk(battle, window, inv);
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

int game_battle(sfRenderWindow *window, player_t *player, ebattle_t *enemy,
    inventory_t *inv
)
{
    battle_t *battle = init_battle(player, enemy);
    sfClock *clock = sfClock_create();
    int atk;
    int def;
    int hp;

    while (sfRenderWindow_isOpen(window) && battle->end == 0) {
        display_battle(battle, window, inv);
        sfRenderWindow_display(window);
        battle_action(window, battle, inv);
        battle->end = battle_end(player, enemy, inv);
    }
    game_loots(window, battle, inv);
    atk = player->stats->atk;
    def = player->stats->def;
    hp = player->stats->hp;
    for (int i = 0; inv->stuff[i] != NULL; i++) {
        atk += inv->stuff[i]->atk;
        def += inv->stuff[i]->def;
        hp += inv->stuff[i]->hp;
    }
    sfText_setString(player->stats->atk_t, my_itoa(atk));
    sfText_setString(player->stats->def_t, my_itoa(def));
    sfText_setString(player->stats->hp_t, my_itoa(hp));
    return (battle->end);
}
