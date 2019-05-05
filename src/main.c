/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_rpg
*/

#include "rpg.h"

int main(int ac, char **av)
{
    menu_t *menu = init_menu("ressources/sprites/menu.jpg");
    player_t *player = set_player();
    ebattle_t **enemies = gen_enemies();
    sfVideoMode mode = {1920, 1080, 60};
    sfRenderWindow *window;
    map_t ***map;

    window = sfRenderWindow_create(mode, "rpg",
        sfClose | sfResize/* | sfFullscreen*/, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    srand((unsigned int)time(NULL));
    //   game_menu(menu, window);
    map = init_maps();
    game_map(map, window, enemies, player);
    return (0);
}
