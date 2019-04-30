/*
** EPITECH PROJECT, 2019
** enemies
** File description:
** my_rpg
*/

#include "rpg.h"
#include "struct.h"

ebattle_t *gen_bad_guy(char *path, int height, int width, int nb)
{
    ebattle_t *enemy = malloc(sizeof(ebattle_t));

    enemy->s_ene = sfSprite_create();
    enemy->t_ene = sfTexture_createFromFile(path, NULL);
    enemy->rect = create_rect(0, 0, width, height);
    enemy->frame = nb;
    return (enemy);
}

ebattle_t **gen_enemies()
{
    int cnt;
    ebattle_t **enemies = malloc(sizeof(ebattle_t *) * 5);

    enemies[4] = NULL;
    enemies[0] = gen_bad_guy();
}
