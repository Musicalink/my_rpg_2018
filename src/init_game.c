/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_rpg
*/

#include "rpg.h"

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return (NULL);
    game->inventory = malloc(sizeof(inventory_t));
    if (game->inventory == NULL)
        return (NULL);
    game->inventory->spr = sfSprite_create();
    game->inventory->tex = sfTexture_createFromFile(INVENTORY, NULL);
    game->inventory->boolean = 0;

    sfSprite_setTexture(game->inventory->spr, game->inventory->tex, sfTrue);
    sfSprite_setPosition(game->inventory->spr, (sfVector2f){245, 902});
    game = init_move(game);
    game->clock = sfClock_create();
    game->y = 1;
    game->x = 0;
    return (game);
}

void display_game(sfRenderWindow *window, map_t ***maps, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, maps[game->y][game->x]->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->moves, NULL);
    if (game->inventory->boolean == 1)
        sfRenderWindow_drawSprite(window, game->inventory->spr, NULL);
    sfRenderWindow_display(window);
}

void game_map(map_t ***maps, sfRenderWindow *window)
{
    game_t *game = init_game();

    while (sfRenderWindow_isOpen(window)) {
        my_clock(maps, window, game);
        display_game(window, maps, game);
    }
}