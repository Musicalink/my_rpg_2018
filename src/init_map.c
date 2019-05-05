/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_rpg
*/

#include "rpg.h"

map_t *take_map(map_t *map, char *name)
{
    char *name_of_file = my_strcat("maps/", name);
    char *hitbox_name = my_strcat("maps/hitbox/", name);

    map->y = name[0] - '0';
    map->x = name[2] - '0';
    map->sprite = sfSprite_create();
    map->texture = sfTexture_createFromFile(name_of_file, NULL);
    map->hitbox = sfImage_createFromFile(hitbox_name);
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    free(name_of_file);
    free(hitbox_name);
    return (map);
}

map_t **malloc_list_maps(map_t **maps)
{
    int j = 0;

    for (j = 0; j < 7; j++) {
        maps[j] = malloc(sizeof(map_t));
        if (maps[j] == NULL)
            return (NULL);
    }
    maps[j] = NULL;
    return (maps);
}

map_t ***fill_maps(map_t ***maps, DIR *dir)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    struct dirent *dent;

    for (i = 0; i < 8; i++) {
        maps[i] = malloc_list_maps(maps[i]);
        if (maps[i] == NULL)
            return (NULL);
    }
    maps[i] = NULL;
    while ((dent = readdir(dir)) != NULL)
        if (dent->d_name[1] == ',') {
            y = dent->d_name[0] - '0';
            x = dent->d_name[2] - '0';
            maps[y][x] = take_map(maps[y][x], dent->d_name);
        }
    return (maps);
}

map_t ***init_maps(void)
{
    map_t ***maps = malloc(sizeof(map_t **) * 9);
    struct dirent *dent;
    DIR *dir = opendir("./maps");
    char *s = "-";

    if (maps == NULL || dir == NULL)
        return (NULL);
    for (int i = 0; i < 8; i++) {
        maps[i] = malloc(sizeof(map_t *) * 8);
        if (maps[i] == NULL)
            return (NULL);
    }
    maps = fill_maps(maps, dir);
    closedir(dir);
    return (maps);
}