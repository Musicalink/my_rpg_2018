/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_rpg
*/

#include "rpg.h"

void launch_fight_h(game_t *game, map_t ***maps, sfRenderWindow *win, int test)
{
    if (game->y >= 1 && game->y <= 2 && game->x >= 1 && game->x <= 2) {
        test = game_battle(win, game->player, game->enem[2], game->inventory);
        if (test == 2 && game->pnj_increment > 10 && game->pnj_increment < 16)
            game->pnj_increment++;
    } else if (game->y == 5 && game->x == 0 && game->pnj_increment == 16) {
        test = game_battle(win, game->player, game->enem[3], game->inventory);
        if (test == 2 && game->pnj_increment == 16)
            game->pnj_increment++;
    }
}

void launch_fight(game_t *game, map_t ***maps, sfRenderWindow *window)
{
    int test;

    if (game->y >= 3 && game->y <= 5 && game->x >= 1 && game->x <= 3) {
        test = game_battle(window, game->player, game->enem[0],
            game->inventory);
        if (test == 2 && game->pnj_increment > 0 && game->pnj_increment < 6)
            game->pnj_increment++;
    } else if (game->y == 3 && game->x >= 4 && game->x <= 5) {
        test = game_battle(window, game->player, game->enem[1],
            game->inventory);
        if (test == 2 && game->pnj_increment > 5 && game->pnj_increment < 11)
            game->pnj_increment++;
    } else
        launch_fight_h(game, maps, window, test);
}