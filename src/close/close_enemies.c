/*
** EPITECH PROJECT, 2019
** close_enemies.c
** File description:
** close enemies
*/

#include "rpg.h"
#include "struct.h"

void close_anim(anim_t *anim)
{
    sfSprite_destroy(anim->spr);
    sfTexture_destroy(anim->txt);
    sfClock_destroy(anim->clock);
    free(anim);
}

void close_enemy(ebattle_t *enemy)
{
    sfSprite_destroy(enemy->s_ene);
    sfTexture_destroy(enemy->t_ene);
    close_anim(enemy->flm);
    sfClock_destroy(enemy->clock);
    free(enemy);
}

void close_enemies(ebattle_t **enemies)
{
    for (int i = 0; i != 3; i++) {
        free(enemies[i]->stats);
        close_enemy(enemies[i]);    
    }
    free(enemies[3]);
    free(enemies);
}
