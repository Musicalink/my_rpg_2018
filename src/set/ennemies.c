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
    sfSprite_setPosition(enemy->s_ene, pos);
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
    enemies[2]->stats = set_enemy_stats(90, 16, 10, 20);
    enemies[3]->stats = set_enemy_stats(240, 50, 40, 20);
    set_enemy(enemies[0], (sfVector2f){1050, 350});
    set_enemy(enemies[1], (sfVector2f){1150, 400});
    set_enemy(enemies[2], (sfVector2f){1050, 200});
    set_enemy(enemies[3], (sfVector2f){1150, 550});
    enemies[4] = NULL;
    return (enemies);
}
