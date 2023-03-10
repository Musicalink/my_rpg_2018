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
    if (game->pnj_increment == 0 && game->y == 5 && game->x == 2)
        game->pnj_increment++;
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
        sfRenderWindow_drawSprite(window, game->stat_spr->spr, NULL);
        for (int i = 0; game->inventory->stuff[i] != NULL; i++) {
            sfSprite_setPosition(game->inventory->stuff[i]->anim->spr,
                INV_POS[i]);
            sfRenderWindow_drawSprite(window,
                game->inventory->stuff[i]->anim->spr, NULL);
        }
        sfRenderWindow_drawText(window, game->player->stats->hp_t, NULL);
        sfRenderWindow_drawText(window, game->player->stats->def_t, NULL);
        sfRenderWindow_drawText(window, game->player->stats->atk_t, NULL);
    }
    sfRenderWindow_display(window);
}

int set_stat_spr(game_t *game)
{
    game->stat_spr = malloc(sizeof(anim_t));
    if (game->stat_spr == NULL)
        return (84);
    game->stat_spr->spr = sfSprite_create();
    game->stat_spr->txt = sfTexture_createFromFile(STAT, NULL);
    sfSprite_setTexture(game->stat_spr->spr, game->stat_spr->txt, sfTrue);
    sfSprite_setPosition(game->stat_spr->spr, (sfVector2f){800, 705});
    return (0);
}

void game_map(map_t ***maps, sfRenderWindow *w, ebattle_t **enem, player_t *p)
{
    game_t *game = init_game();
    sfMusic *music = sfMusic_createFromFile("ressources/theme.ogg");

    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    game_map_helper(game, enem, p);
    set_pnj(game);
    if (set_stat_spr(game) == 84)
        return;
    while (sfRenderWindow_isOpen(w)) {
        search_move(game, maps, w);
        my_clock(maps, w, game);
        display_game(w, maps, game);
    }
    sfMusic_destroy(music);
}
