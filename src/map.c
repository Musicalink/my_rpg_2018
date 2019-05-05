/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_rpg
*/

#include "rpg.h"

sfVector2f move_it(game_t *game, sfVector2f pos, sfColor color)
{
    game->y += (color.r > 200 && color.g > 200 && color.b < 50) ? 1 : 0;
    pos.y += (color.r > 200 && color.g > 200 && color.b < 50) ? 950 : 0;
    game->y -= (color.r < 50 && color.g > 200 && color.b < 50) ? 1 : 0;
    pos.y -= (color.r < 50 && color.g > 200 && color.b < 50) ? 950 : 0;
    game->x -= (color.r > 200 && color.g < 50 && color.b < 50) ? 1 : 0;
    pos.x += (color.r > 200 && color.g < 50 && color.b < 50) ? 1850 : 0;
    game->x += (color.r < 50 && color.g < 50 && color.b > 200) ? 1 : 0;
    pos.x -= (color.r < 50 && color.g < 50 && color.b > 200) ? 1850 : 0;
    printf("(%d, %d)\n", game->y, game->x);
    return (pos);
}

void make_move(game_t *game, map_t *map, int boolean, int minus)
{
    unsigned int y = (unsigned int)game->p_pos.y + 83;
    unsigned int x = (unsigned int)game->p_pos.x + 74;
    sfColor color;

    y = (boolean == 0) ? (minus == 1) ? y - 10 : y + 30 : y;
    x = (boolean == 1) ? (minus == 1) ? x - 10 : x + 30 : x;
    if (x <= 0 || x >= 1920 || y < 0 || y > 1130)
        return;
    color = sfImage_getPixel(map->hitbox, x, y);
    if (color.r > 100 || color.g > 100 || color.b > 100 || color.a < 120) {
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

void launch_fight(game_t *game, map_t ***maps)
{
    if (game->y >= 3 && game->y <= 5 && game->x >= 1 && game->x <= 3)
        printf("COMBAT FORESTIER\n");
}

void search_move(game_t *game, map_t ***maps)
{
    map_t *map = maps[game->y][game->x];

    if (sfKeyboard_isKeyPressed(sfKeyI))
        game->inventory->boolean = (game->inventory->boolean == 0) ? 1 : 0;
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
    if (sfKeyboard_isKeyPressed(sfKeyF))
        launch_fight(game, maps);
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
        else if (event.type == sfEvtKeyPressed) {
            game->moves_r.left += 150;
            game->moves_r.left =
                (game->moves_r.left > 1349) ? 0 : game->moves_r.left;
            search_move(game, maps);
        }
    }
}

void my_clock(map_t ***maps, sfRenderWindow *window, game_t *game)
{
    double seconds = 0;

    while (seconds < 0.005) {
        game->time = sfClock_getElapsedTime(game->clock);
        event_map(maps, window, game);
        seconds = game->time.microseconds / 1000000.0;
    }
    sfClock_restart(game->clock);
}
