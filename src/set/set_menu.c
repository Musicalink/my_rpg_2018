/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "rpg.h"
#include "struct.h"

sfIntRect create_rect(int left, int top, int width, int height)
{
    sfIntRect rect;

    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return (rect);
}

void set_menu(menu_t *menu)
{
    sfSprite_setPosition(menu->sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    sfText_setFont(menu->play, menu->font);
    sfText_setFont(menu->exit, menu->font);
    sfText_setString(menu->play, "Play Game");
    sfText_setString(menu->exit, "Exit Game");
    sfText_setCharacterSize(menu->play, 70);
    sfText_setCharacterSize(menu->exit, 70);
    sfText_setColor(menu->play, (sfColor){0, 0, 0, 200});
    sfText_setColor(menu->exit, (sfColor){0, 0, 0, 200});
    sfText_setPosition(menu->play, (sfVector2f){1500, 400});
    sfText_setPosition(menu->exit, (sfVector2f){1500, 550});
}

menu_t *init_menu(char *resources)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->rect = create_rect(0, 0, 1920, 1080);
    menu->texture = sfTexture_createFromFile(resources, NULL);
    menu->sprite = sfSprite_create();
    menu->font = sfFont_createFromFile("ressources/font/GAD.ttf");
    menu->play = sfText_create();
    menu->exit = sfText_create();
    set_menu(menu);
    return (menu);
}
