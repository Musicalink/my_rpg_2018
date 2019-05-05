/*
** EPITECH PROJECT, 2019
** pause menu
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

void set_pause_menu(menu_t *menu)
{
    sfSprite_setPosition(menu->sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfText_setFont(menu->play, menu->font);
    sfText_setFont(menu->exit, menu->font);
    sfText_setFont(menu->main, menu->font);
    sfText_setString(menu->play, "Resume Game");
    sfText_setString(menu->exit, "Exit Game");
    sfText_setString(menu->main, "Main menu");
    sfText_setCharacterSize(menu->play, 70);
    sfText_setCharacterSize(menu->exit, 70);
    sfText_setCharacterSize(menu->main, 70);
    sfText_setColor(menu->play, (sfColor){0, 0, 0, 200});
    sfText_setColor(menu->exit, (sfColor){0, 0, 0, 200});
    sfText_setColor(menu->exit, (sfColor){0, 0, 0, 200});
    sfText_setPosition(menu->main, (sfVector2f){1000, 500});
    sfText_setPosition(menu->play, (sfVector2f){1000, 650});
    sfText_setPosition(menu->exit, (sfVector2f){1000, 800});
}

menu_t *init_pause_menu(char *resources)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (menu == NULL)
        return (NULL);
    menu->launch_game = 0;
    menu->texture = sfTexture_createFromFile(resources, NULL);
    menu->sprite = sfSprite_create();
    menu->font = sfFont_createFromFile("ressources/font/GAD.ttf");
    menu->play = sfText_create();
    menu->exit = sfText_create();
    menu->main = sfText_create();
    set_pause_menu(menu);
    return (menu);
}
