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

    for (i = 0; i < 8; i++)
        maps[i] = malloc_list_maps(maps[i]);
    maps[i] = NULL;
    while ((dent = readdir(dir)) != NULL)
        if (dent->d_name[1] == ',') {
            y = dent->d_name[0] - '0';
            x = dent->d_name[2] - '0';
            maps[y][x] = take_map(maps[y][x], dent->d_name);
        }
    return (maps);
}

map_t ***init_maps()
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

void move_it(game_t *game, sfVector2i pos)
{
    if (pos.y < 200) {
        game->y++;
    } else if (pos.y > 880) {
        game->y--;
    } else if (pos.x < 200) {
        game->x--;
    } else if (pos.x > 1720) {
        game->x++;
    }
    printf("(%d, %d)\n", game->y, game->x);
}

void event_map(map_t ***maps, sfRenderWindow *window, game_t *game)
{
    sfEvent event;
    sfVector2i pos;
    sfColor color;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed) {
            pos = sfMouse_getPositionRenderWindow(window);
            color = sfImage_getPixel(maps[game->y][game->x]->hitbox,
                (unsigned int)pos.x, (unsigned int)pos.y);
            (color.r == 128) ? move_it(game, pos) : game;
        }
    }
}

void game_map(map_t ***maps, sfRenderWindow *window)
{
    game_t *game = malloc(sizeof(game_t));

    game->y = 1;
    game->x = 0;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        event_map(maps, window, game);
        sfRenderWindow_drawSprite(window, maps[game->y][game->x]->sprite, NULL);
        sfRenderWindow_display(window);
    }
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
    game_menu(menu, window);
    maps = init_maps();
    game_map(maps, window);   /*   for (int i = 0; i != 3; i++)
          game_battle(window, player, enemies[2]);*/
    return (0);
}
