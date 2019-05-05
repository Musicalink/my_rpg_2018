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
    for (int i = 0; i < 11; i++)
        game->inventory->stuff[i] = NULL;
    game->inventory->spr = sfSprite_create();
    game->inventory->tex = sfTexture_createFromFile(INVENTORY, NULL);
    game->inventory->boolean = 0;
    sfSprite_setTexture(game->inventory->spr, game->inventory->tex, sfTrue);
    sfSprite_setPosition(game->inventory->spr, (sfVector2f){245, 902});
    game = init_move(game);
    game->clock = sfClock_create();
    game->y = 4;
    game->x = 4;
    game->pause = init_pause_menu(PAUSE);
    return (game);
}

void pnj_display(sfRenderWindow *window, map_t ***maps, game_t *game)
{
    if (game->pnj_increment == 0 && game->y == 5 && game->x == 2) {
        game->pnj_increment++;
    }
    sfText_setString(game->pnj_text, QUEST_STR[game->pnj_increment]);
    if (game->x == 4 && game->y == 4) {
        sfRenderWindow_drawSprite(window, game->pnj->spr, NULL);
        sfRenderWindow_drawText(window, game->pnj_text, NULL);
    }
}

void display_game(sfRenderWindow *window, map_t ***maps, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, maps[game->y][game->x]->sprite, NULL);
    pnj_display(window, maps, game);
    sfRenderWindow_drawSprite(window, game->moves, NULL);
    if (game->inventory->boolean == 1) {
        sfRenderWindow_drawSprite(window, game->inventory->spr, NULL);
        for (int i = 0; game->inventory->stuff[i] != NULL; i++)
            sfRenderWindow_drawSprite(window,
                game->inventory->stuff[i]->anim->spr, NULL);
    }
    sfRenderWindow_display(window);
}

void game_map(map_t ***maps, sfRenderWindow *window, ebattle_t **enemies,
    player_t *player
)
{
    game_t *game = init_game();

    game->enem = enemies;
    game->player = player;
    game->pnj = malloc(sizeof(pnj_t));
    game->pnj->spr = sfSprite_create();
    game->pnj->txt = sfTexture_createFromFile(MAGICIAN, NULL);
    game->pnj_increment = 0;
    game->pnj_text = sfText_create();
    sfText_setFont(game->pnj_text, sfFont_createFromFile(ARIAL));
    sfText_setPosition(game->pnj_text, (sfVector2f){550, 250});
    sfSprite_setTexture(game->pnj->spr, game->pnj->txt, sfTrue);
    sfSprite_setPosition(game->pnj->spr, (sfVector2f){450, 200});
    sfSprite_setScale(game->pnj->spr, (sfVector2f){0.5, 0.5});
    while (sfRenderWindow_isOpen(window)) {
        search_move(game, maps, window);
        my_clock(maps, window, game);
        display_game(window, maps, game);
    }
}
