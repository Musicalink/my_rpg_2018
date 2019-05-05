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
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    sfText_setFont(menu->play, menu->font);
    sfText_setFont(menu->exit, menu->font);
    sfText_setString(menu->play, "Resume Game");
    sfText_setString(menu->exit, "Exit Game");
    sfText_setCharacterSize(menu->play, 70);
    sfText_setCharacterSize(menu->exit, 70);
    sfText_setColor(menu->play, (sfColor){0, 0, 0, 200});
    sfText_setColor(menu->exit, (sfColor){0, 0, 0, 200});
    sfText_setPosition(menu->play, (sfVector2f){1500, 400});
    sfText_setPosition(menu->exit, (sfVector2f){1500, 550});
}

menu_t *init_pause_menu(char *resources)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->texture = sfTexture_createFromFile(resources, NULL);
    menu->sprite = sfSprite_create();
    menu->font = sfFont_createFromFile("ressources/font/GAD.ttf");
    menu->play = sfText_create();
    menu->exit = sfText_create();
    set_pause_menu(menu);
    return (menu);
}