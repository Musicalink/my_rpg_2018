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
    menu_t *menu = init_menu("ressources/sprites/battle.png");
    sfVideoMode mode = {1920, 1080, 60};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "rpg", sfClose | sfResize, NULL);
    //game_menu(menu, window);
    game_battle(window);
    return (0);
}
