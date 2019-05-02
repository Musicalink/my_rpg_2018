/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_rpg
*/

#include "rpg.h"
#include "struct.h"

int main(int ac, char **av)
{
    menu_t *menu = init_menu("ressources/sprites/menu.jpg");
    player_t *player = set_player();
    ebattle_t **enemies = gen_enemies();
    sfVideoMode mode = {1920, 1080, 60};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "rpg", sfClose | sfResize | sfFullscreen, NULL);
    //game_menu(menu, window);
    game_battle(window, player, enemies[3]);
    return (0);
}
