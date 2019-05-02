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
    //  printf("Name of file: %s\ty: %d\tx: %d\n", name, map->y, map->x);
    map->sprite = sfSprite_create();
    map->texture = sfTexture_createFromFile(name_of_file, NULL);
    map->hitbox = sfImage_createFromFile(hitbox_name);
}

map_t ***init_maps()
{
    map_t ***maps = malloc(sizeof(map_t **) * 8);
    struct dirent *dent;
    DIR *dir = opendir("./maps");
    char *s = "-";
    int y = 0;
    int x = 0;

    if (maps == NULL || dir == NULL)
        return (NULL);
    for (int i = 0; i < 8; i++) {
        maps[i] = malloc(sizeof(map_t *) * 7);
        if (maps[i] == NULL)
            return (NULL);
    }
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 7; x++) {
            maps[y][x] = malloc(sizeof(map_t));
        }
        maps[y] = NULL;
    }
    maps = NULL;
    while ((dent = readdir(dir)) != NULL)
        if (dent->d_name[1] == ',') {
            y = dent->d_name[0] - '0';
            x = dent->d_name[2] - '0';
            maps[y][x] = take_map(maps[y][x], dent->d_name);
        }
    return (maps);
}

int main(int ac, char **av)
{
    menu_t *menu = init_menu("ressources/sprites/menu.jpg");
    player_t *player = set_player();
    ebattle_t **enemies = gen_enemies();
    sfVideoMode mode = {1920, 1080, 60};
    sfRenderWindow *window;
    map_t ***maps;

    window = sfRenderWindow_create(mode, "rpg",
        sfClose | sfResize /*| sfFullscreen*/, NULL);
    maps = init_maps();
    /* game_menu(menu, window);
     for (int i = 0; i != 3; i++)
         game_battle(window, player, enemies[2]);*/
    return (0);
}
