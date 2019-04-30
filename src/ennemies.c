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
    ebattle_t **enemies = malloc(sizeof(ebattle_t *) * 5);

    enemies[0] = gen_bad_guy("ressources/sprites/caillou.png", 396, 480, 11);
    enemies[1] = gen_bad_guy("ressources/sprites/glace.png", 360, 480, 13);
    enemies[2] = gen_bad_guy("ressources/sprites/fighter.png", 211, 480, 18);
    enemies[3] = gen_bad_guy("ressources/sprites/orc.png", 480, 480, 18);
    enemies[4] = NULL;
    return (enemies);
}
