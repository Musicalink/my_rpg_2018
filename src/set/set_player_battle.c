/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "rpg.h"
#include "struct.h"

void set_player_battle(pbattle_t *play)
{
    sfSprite_setPosition(play->s_player, (sfVector2f){0, 550});
    sfSprite_setScale(play->s_player, (sfVector2f){0.8, 0.8});
    sfSprite_setTexture(play->s_player, play->t_player, sfTrue);
    sfSprite_setTextureRect(play->s_player, play->rect);
}

pbattle_t *init_player_battle(char *resources)
{
    pbattle_t *tmp = malloc(sizeof(pbattle_t));

    if (tmp == NULL)
        return (NULL);
    tmp->rect = create_rect(0, 0, 512, 537);
    tmp->t_player = sfTexture_createFromFile(resources, NULL);
    tmp->s_player = sfSprite_create();
    tmp->clock = sfClock_create();
    tmp->p_atk = &atk;
    set_player_battle(tmp);
    return (tmp);
}
