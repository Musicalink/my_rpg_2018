/*
** EPITECH PROJECT, 2019
** enemies
** File description:
** my_rpg
*/

#include "rpg.h"

anim_t *gen_anim(char *path, int height, int width, int nb)
{
    anim_t *anim = malloc(sizeof(anim_t));

    if (anim == NULL)
        return (NULL);
    anim->spr = sfSprite_create();
    anim->txt = sfTexture_createFromFile(path, NULL);
    anim->rect = create_rect(0, 0, width, height);
    anim->frame = nb;
    anim->size = (sfVector2f){width, height};
    anim->clock = sfClock_create();
    return (anim);
}

ebattle_t *gen_bad_guy(char *path, int height, int width, int nb)
{
    ebattle_t *enemy = malloc(sizeof(ebattle_t));

    if (enemy == NULL)
        return (NULL);
    enemy->s_ene = sfSprite_create();
    enemy->t_ene = sfTexture_createFromFile(path, NULL);
    enemy->rect = create_rect(0, 0, width, height);
    enemy->frame = nb;
    enemy->flm = gen_anim("ressources/sprites/flms.png", 300, 256, 33);
    enemy->action = 0;
    enemy->wait = 0;
    enemy->size = (sfVector2f){width, height};
    enemy->clock = sfClock_create();
    return (enemy);
}

stats_t *set_enemy_stats(int hp, int atk, int def, int xp)
{
    stats_t *stats = malloc(sizeof(stats_t) * 1);

    if (stats == NULL)
        return (NULL);
    stats->level = 1;
    stats->xp = xp;
    stats->hp = hp;
    stats->hp_max = hp;
    stats->atk = atk;
    stats->def = def;
    return (stats);
}

void set_enemy(ebattle_t *enemy, sfVector2f pos)
{
    sfSprite_setTexture(enemy->s_ene, enemy->t_ene, sfTrue);
    sfSprite_setTexture(enemy->flm->spr, enemy->flm->txt, sfTrue);
    sfSprite_setPosition(enemy->s_ene, pos);
    sfSprite_setPosition(enemy->flm->spr, (sfVector2f){1400, 380});
    sfSprite_setTextureRect(enemy->s_ene, enemy->rect);
    sfSprite_setTextureRect(enemy->flm->spr, enemy->flm->rect);
    sfSprite_setScale(enemy->s_ene, (sfVector2f){2, 2});
    sfSprite_setScale(enemy->flm->spr, (sfVector2f){2, 2});
}

ebattle_t **gen_enemies(void)
{
    ebattle_t **enemies = malloc(sizeof(ebattle_t *) * 5);

    if (enemies == NULL)
        return (NULL);
    enemies[0] = gen_bad_guy("ressources/sprites/orc.png", 480, 480, 18);
    enemies[1] = gen_bad_guy("ressources/sprites/caillou.png", 396, 480, 11);
    enemies[2] = gen_bad_guy("ressources/sprites/glace.png", 360, 480, 13);
    enemies[3] = gen_bad_guy("ressources/sprites/fighter.png", 211, 480, 18);
    enemies[0]->stats = set_enemy_stats(80, 20, 8, 20);
    enemies[1]->stats = set_enemy_stats(300, 60, 50, 40);
    enemies[2]->stats = set_enemy_stats(600, 120, 90, 60);
    enemies[3]->stats = set_enemy_stats(1000, 250, 190, 200);
    for (int i = 0; i < 4; i++)
        enemies[i]->type = i;
    set_enemy(enemies[0], (sfVector2f){1050, 200});
    set_enemy(enemies[1], (sfVector2f){1050, 350});
    set_enemy(enemies[2], (sfVector2f){1150, 400});
    set_enemy(enemies[3], (sfVector2f){1150, 550});
    enemies[4] = NULL;
    return (enemies);
}
