/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include "my.h"

char *my_strndup(char const *src, int start, int end)
{
    int length_src = end - start + 1;
    char *dest = malloc(sizeof(char) * length_src + 1);
    int i = 0;

    if (start >= end || dest == NULL)
        return (NULL);
    for (; i + start < end; i++)
        dest[i] = src[i + start];
    dest[i] = '\0';
    return (dest);
}