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
<<<<<<< HEAD
    game->y = 4;
    game->x = 4;
    return (game);
}

void pnj_display(sfRenderWindow *window, map_t ***maps, game_t *game)
{
    if (game->x == 4 && game->y == 4)
        sfRenderWindow_drawSprite(window, game->pnj->spr, NULL);
}

=======
    game->y = 1;
    game->x = 0;
    return (game);
}

>>>>>>> 511da8c09836077848d8a3839fe84c444374e4ed
void display_game(sfRenderWindow *window, map_t ***maps, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, maps[game->y][game->x]->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->moves, NULL);
<<<<<<< HEAD
    pnj_display(window, maps, game);
=======
>>>>>>> 511da8c09836077848d8a3839fe84c444374e4ed
    if (game->inventory->boolean == 1)
        sfRenderWindow_drawSprite(window, game->inventory->spr, NULL);
    sfRenderWindow_display(window);
}

void game_map(map_t ***maps, sfRenderWindow *window)
{
    game_t *game = init_game();

<<<<<<< HEAD
    game->pnj = malloc(sizeof(anim_t));
    game->pnj->spr = sfSprite_create();
    game->pnj->txt = sfTexture_createFromFile(MAGICIAN, NULL);
    sfSprite_setScale(game->pnj->spr, (sfVector2f){0.5, 0.5});
    sfSprite_setTexture(game->pnj->spr, game->pnj->txt, sfTrue);
    sfSprite_setPosition(game->pnj->spr, (sfVector2f){400, 200});
=======
>>>>>>> 511da8c09836077848d8a3839fe84c444374e4ed
    while (sfRenderWindow_isOpen(window)) {
        my_clock(maps, window, game);
        display_game(window, maps, game);
    }
}