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

sfVector2f move_it(game_t *game, sfVector2f pos, sfColor color)
{
    if (color.r > 120 && color.g > 120 && color.b < 120) {
        game->y++;
        pos.y += 800;
    } else if (color.r < 120 && color.g > 120 && color.b < 120) {
        game->y--;
        pos.y -= 800;
    } else if (color.r > 120 && color.g < 120 && color.b < 120) {
        game->x--;
        pos.x += 1700;
    } else if (color.r < 120 && color.g < 120 && color.b > 120) {
        game->x++;
        pos.x -= 1700;
    }
    return (pos);
    printf("(%d, %d)\n", game->y, game->x);
}

void make_move(game_t *game, map_t *map, int boolean, int minus)
{
    unsigned int y = (unsigned int)game->p_pos.y + 83;
    unsigned int x = (unsigned int)game->p_pos.x + 74;
    sfColor color;

    y = (boolean == 0) ? (minus == 1) ? y - 10 : y + 30 : y;
    x = (boolean == 1) ? (minus == 1) ? x - 10 : x + 30 : x;
    if (y <= 0 || y >= 1920)
        return;
    printf("Boolean: %d\nMinus:%d\n\n", boolean, minus);
    color = sfImage_getPixel(map->hitbox, x, y);
    printf("%d\n", color.r);
    if (color.r > 100 || color.g > 100 || color.b > 100) {
        if (boolean == 0)
            game->p_pos.y =
                (minus == 1) ? game->p_pos.y - 10 : game->p_pos.y + 10;
        else if (boolean == 1)
            game->p_pos.x =
                (minus == 1) ? game->p_pos.x - 10 : game->p_pos.x + 10;
        if (color.r <= 200 || color.b <= 200 || color.g <= 200)
            game->p_pos = move_it(game, game->p_pos, color);
    }
}

void search_move(game_t *game, map_t ***maps)
{
    map_t *map = maps[game->y][game->x];
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        make_move(game, map, 1, 1);
        sfSprite_setTexture(game->moves, game->moves_t[1], sfTrue);
        sfSprite_setTextureRect(game->moves, game->moves_r);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        make_move(game, map, 1, 0);
        sfSprite_setTexture(game->moves, game->moves_t[0], sfTrue);
        sfSprite_setTextureRect(game->moves, game->moves_r);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        make_move(game, map, 0, 1);
        sfSprite_setTexture(game->moves, game->moves_t[2], sfTrue);
        sfSprite_setTextureRect(game->moves, game->moves_r);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        make_move(game, map, 0, 0);
        sfSprite_setTexture(game->moves, game->moves_t[3], sfTrue);
        sfSprite_setTextureRect(game->moves, game->moves_r);
    }
    sfSprite_setPosition(game->moves, game->p_pos);
}

void event_map(map_t ***maps, sfRenderWindow *window, game_t *game)
{
    sfEvent event;
    sfVector2i pos;
    sfColor color;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        /*      if (event.type == sfEvtMouseButtonPressed) {
                  pos = sfMouse_getPositionRenderWindow(window);
                  color = sfImage_getPixel(maps[game->y][game->x]->hitbox,
                      (unsigned int)pos.x, (unsigned int)pos.y);
                  (color.r == 128) ? move_it(game, pos) : game;
              }*/
        if (event.type == sfEvtKeyPressed) {
            game->moves_r.left += 150;
            if (game->moves_r.left > 1349)
                game->moves_r.left = 0;
            search_move(game, maps);
        }
    }
}

void game_map(map_t ***maps, sfRenderWindow *window)
{
    game_t *game = malloc(sizeof(game_t));

    game = init_move(game);
    game->y = 1;
    game->x = 0;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        event_map(maps, window, game);
        sfRenderWindow_drawSprite(window, maps[game->y][game->x]->sprite, NULL);
        sfRenderWindow_drawSprite(window, game->moves, NULL);
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
        sfClose | sfResize | sfFullscreen, NULL);
    //game_menu(menu, window);
    //maps = init_maps();
    // game_map(maps, window);
    for (int i = 0; i != 100; i++)
	game_battle(window, player, enemies[0]);
    return (0);
}
