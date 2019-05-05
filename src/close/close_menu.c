/*
** EPITECH PROJECT, 2019
** close_menu.c
** File description:
** close menu
*/

#include "rpg.h"
#include "struct.h"

void close_menu(menu_t *menu)
{
    sfTexture_destroy(menu->texture);
    sfSprite_destroy(menu->sprite);
    sfFont_destroy(menu->font);
    sfText_destroy(menu->play);
    sfText_destroy(menu->exit);
    free(menu);
}
