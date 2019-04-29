/*
** EPITECH PROJECT, 2019
** menu
** File description:
** my_rpg
*/

#include <stdlib.h>
#include <unistd.h>
#include "rpg.h"

sfIntRect create_rect(int left, int top, int width, int height)
{
    sfIntRect rect;

    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return (rect);
}

menu_t *init_menu(char *resources)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfVector2f pos;

    pos.x = 0;
    pos.y = 0;
    menu->rect = create_rect(0, 0, 1920, 1080);
    menu->texture = sfTexture_createFromFile(resources, NULL);
    menu->sprite = sfSprite_create();
    sfSprite_setPosition(menu->sprite, pos);
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    return (menu);
}

void check_mouse_pos(sfRenderWindow *window, menu_t *menu)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x < 1245 && mouse.x > 778) {
        if (mouse.y > 372 && mouse.y < 529) {
            menu->launch_game = 1;
        } else if (mouse.y > 651 && mouse.y < 807)
            sfRenderWindow_close(window);
    }
}

int display_menu(menu_t *menu, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtMouseButtonPressed) {
            check_mouse_pos(window, menu);
        }
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->sprite, NULL);
}

int game_menu(menu_t *menu, sfRenderWindow *window)
{
    menu->launch_game = 0;
    while (sfRenderWindow_isOpen(window) && menu->launch_game == 0) {
        display_menu(menu, window);
        sfRenderWindow_display(window);
    }
    if (menu->launch_game == 1)
        game_start(window);
}
