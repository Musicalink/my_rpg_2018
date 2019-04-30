/*
** EPITECH PROJECT, 2019
** check_enemies
** File description:
** rpg
*/

#include <stddef.h>
#include "rpg.h"
#include "struct.h"

int check_enemies_struct(ebattle_t *nmy)
{
    if (nmy == NULL || nmy->s_ene == NULL || nmy->t_ene == NULL)
        return (1);
    if (nmy->stats == NULL || nmy->clcok == NULL)
        return (1);
    return (0);
}

int check_enemies(ebattle_t **enemies)
{
    if (enemies == NULL)
        return (1);
    for (int i = 0; enemies[i] != NULL; i++) {
        if (check_enemies_struct(enemies[i]) == 1)
            return (1);
    }
    return (0);
}
