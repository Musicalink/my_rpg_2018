/*
** EPITECH PROJECT, 2019
** menu
** File description:
** my_rpg
*/

#include "rpg.h"

void menu_btn_act(sfRenderWindow *window, menu_t *menu)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x < 1800 && mouse.x > 1500) {
        if (mouse.y >= 400 && mouse.y < 500) {
            menu->launch_game = 1;
        } else if (mouse.y >= 550 && mouse.y < 650)
            sfRenderWindow_close(window);
    }
}

void menu_btn_over(sfRenderWindow *window, menu_t *menu)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x < 1800 && mouse.x > 1500) {
        if (mouse.y >= 400 && mouse.y < 500)
            sfText_setColor(menu->play, (sfColor){255, 255, 255, 200});
        else
            sfText_setColor(menu->play, (sfColor){0, 0, 0, 200});
        if (mouse.y >= 550 && mouse.y < 650)
            sfText_setColor(menu->exit, (sfColor){255, 255, 255, 200});
        else
            sfText_setColor(menu->exit, (sfColor){0, 0, 0, 200});
    } else {
        sfText_setColor(menu->play, (sfColor){0, 0, 0, 200});
        sfText_setColor(menu->exit, (sfColor){0, 0, 0, 200});
    }
}

int display_menu(menu_t *menu, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtMouseButtonPressed) {
            menu_btn_act(window, menu);
        }
    }
    menu_btn_over(window, menu);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->sprite, NULL);
    sfRenderWindow_drawText(window, menu->play, NULL);
    sfRenderWindow_drawText(window, menu->exit, NULL);
}

int game_menu(menu_t *menu, sfRenderWindow *window)
{
    menu->launch_game = 0;
    while (sfRenderWindow_isOpen(window) && menu->launch_game == 0) {
        display_menu(menu, window);
        sfRenderWindow_display(window);
    }
    return (0);
}
