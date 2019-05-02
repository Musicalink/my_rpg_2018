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

void gen_stat_bad_guys(ebattle_t *enemy, int hp_max, int atk, int def)
{
    enemy->stats->hp_max = hp_max;
    enemy->stats->atk = atk;
    enemy->stats->def = def;
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

void set_enemy(ebattle_t *enemy)
{
    sfSprite_setTexture(enemy->s_ene, enemy->t_ene, sfTrue);
    sfSprite_setPosition(enemy->s_ene, (sfVector2f){1000, 350});
    sfSprite_setTextureRect(enemy->s_ene, enemy->rect);
    sfSprite_setScale(enemy->s_ene, (sfVector2f){2, 2});
}

ebattle_t **gen_enemies(void)
{
    ebattle_t **enemies = malloc(sizeof(ebattle_t *) * 5);

    enemies[0] = gen_bad_guy("ressources/sprites/caillou.png", 396, 480, 11);
    enemies[1] = gen_bad_guy("ressources/sprites/glace.png", 360, 480, 13);
    enemies[2] = gen_bad_guy("ressources/sprites/orc.png", 480, 480, 18);
    enemies[3] = gen_bad_guy("ressources/sprites/fighter.png", 211, 480, 18);
    enemies[0]->stats = set_enemy_stats(110, 30, 15, 20);
    enemies[1]->stats = set_enemy_stats(160, 30, 40, 20);
    enemies[2]->stats = set_enemy_stats(90, 15, 8, 20);
    enemies[3]->stats = set_enemy_stats(240, 50, 40, 20);
    for (int i = 0; i != 4; i++)
        set_enemy(enemies[i]);
    enemies[4] = NULL;
    return (enemies);
}
