/*
** EPITECH PROJECT, 2019
** menu
** File description:
** my_rpg
*/

#include "rpg.h"
#include "struct.h"

int pause_menu_btn_act(sfRenderWindow *window, menu_t *menu)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x < 1300 && mouse.x > 1000) {
        if (mouse.y >= 650 && mouse.y < 750) {
            return (0);
        } else if (mouse.y >= 800 && mouse.y < 900)
            return (1);
    }
    return (2);
}

void pause_menu_btn_over(sfRenderWindow *window, menu_t *menu)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x < 1500 && mouse.x > 1000) {
        if (mouse.y >= 650 && mouse.y < 750)
            sfText_setColor(menu->play, (sfColor){255, 255, 255, 200});
        else
            sfText_setColor(menu->play, (sfColor){0, 0, 0, 200});
        if (mouse.y >= 800 && mouse.y < 900)
            sfText_setColor(menu->exit, (sfColor){255, 255, 255, 200});
        else
            sfText_setColor(menu->exit, (sfColor){0, 0, 0, 200});
    } else {
        sfText_setColor(menu->play, (sfColor){0, 0, 0, 200});
        sfText_setColor(menu->exit, (sfColor){0, 0, 0, 200});
    }
}

int display_pause_menu(menu_t *menu, sfRenderWindow *window)
{
    sfEvent event;
    int res;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            return (1);
        else if (event.type == sfEvtMouseButtonPressed) {
            res = pause_menu_btn_act(window, menu);
            if (res == 1 || res == 0)
                return (res);
        }
    }
    pause_menu_btn_over(window, menu);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->sprite, NULL);
    sfRenderWindow_drawText(window, menu->play, NULL);
    sfRenderWindow_drawText(window, menu->exit, NULL);
    return (2);
}

int pause_menu(menu_t *menu, sfRenderWindow *window)
{
    int res;

    while (sfRenderWindow_isOpen(window)) {
        res = display_pause_menu(menu, window);
        sfRenderWindow_display(window);
        if (res == 0 || res == 1)
            return (res);
    }
    return (1);
}
