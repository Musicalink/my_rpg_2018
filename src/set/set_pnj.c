/*
** EPITECH PROJECT, 2019
** set_pnj.c
** File description:
** set pnj
*/

#include "rpg.h"
#include "struct.h"

void set_pnj(game_t *game)
{
    sfText_setFont(game->pnj_text, sfFont_createFromFile(ARIAL));
    sfText_setPosition(game->pnj_text, (sfVector2f){550, 250});
    sfSprite_setTexture(game->pnj->spr, game->pnj->txt, sfTrue);
    sfSprite_setPosition(game->pnj->spr, (sfVector2f){450, 200});
    sfSprite_setScale(game->pnj->spr, (sfVector2f){0.5, 0.5});
}

void game_map_helper(game_t *game, ebattle_t **enemies, player_t *player)
{
    game->enem = enemies;
    game->player = player;
    game->pnj = malloc(sizeof(pnj_t));
    if(game->pnj == NULL)
        return;
    game->pnj->spr = sfSprite_create();
    game->pnj->txt = sfTexture_createFromFile(MAGICIAN, NULL);
    game->pnj_increment = 0;
    game->pnj_text = sfText_create();
}
