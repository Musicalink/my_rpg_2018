/*
** EPITECH PROJECT, 2019
** mall_strcat
** File description:
** same as strcat fct with auto alloc mem
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char *mall_strcat(char *s1, char *s2)
{
    char *new = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    int i = 0;

	if (new == NULL)
		return (NULL);
    for (int j = 0; s1[j] != '\0'; j++) {
        new[i] = s1[j];
        i++;
    }
    for (int k = 0; s2[k] != '\0'; k++) {
        new[i] = s2[k];
        i++;
    }
    new[i] = '\0';
    return (new);
}
