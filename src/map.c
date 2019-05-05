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
                (minus == 1) ? game->p_pos.y - 5 : game->p_pos.y + 5;
        else if (boolean == 1)
            game->p_pos.x =
                (minus == 1) ? game->p_pos.x - 5 : game->p_pos.x + 5;
        if (color.r <= 200 || color.b <= 200 || color.g <= 200)
            game->p_pos = move_it(game, game->p_pos, color);
    }
}

void handle_key(game_t *game, map_t ***maps, sfRenderWindow *window)
{
    int res;

    if (sfKeyboard_isKeyPressed(sfKeyF))
        launch_fight(game, maps, window);
    else if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        res = pause_menu(game->pause, window);
        if (res == 3) {
            game->player->reset = 2;
            sfRenderWindow_close(window);
        } else if (res == 0) {
            game->player->reset = 1;
            sfRenderWindow_close(window);
        }
    }
    else {
        if (sfKeyboard_isKeyPressed(sfKeyI))
            game->inventory->boolean = (game->inventory->boolean == 0) ? 1 : 0;
    }
}

void event_map(map_t ***maps, sfRenderWindow *window, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtKeyPressed)
            handle_key(game, maps, window);
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
