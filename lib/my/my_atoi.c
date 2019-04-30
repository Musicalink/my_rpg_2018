/*
** EPITECH PROJECT, 2018
** Project By Maxence Carpentier
** File description:
** A Epitech Project
*/

#include "my.h"

int my_atoi(char *array)
{
    int nb = 0;
    int tempo = 0;

    while (*array == '-' || *array == '+') {
        if (*array == '-')
            tempo++;
        (array)++;
    }
    while (*array >= '0' && *array <= '9') {
        nb = nb * 10 + (*array - '0');
        (array)++;
    }
    if (tempo % 2 != 0)
        nb *= -1;
    return (nb);
}

int my_natoi(char *array, int n)
{
    int nb = 0;
    int tempo = 0;

    for (int i = 0; i < n; i++)
        (array)++;
    while (*array == '-' || *array == '+') {
        if (*array == '-')
            tempo++;
        (array)++;
    }
    while (*array >= '0' && *array <= '9') {
        nb = nb * 10 + (*array - '0');
        (array)++;
    }
    if (tempo % 2 != 0)
        nb *= -1;
    return (nb);
}

char *my_itoa(int nb)
{
    char *str;
    int incrementer = 0;
    int buffer = nb;

    if (nb < 0) {
        str = malloc(sizeof(char) * my_intlen(nb) + 2);
        nb *= -1;
    } else
        str = malloc(sizeof(char) * my_intlen(nb) + 1);
    for (int i = 0; nb != 0; i++) {
        str[incrementer] = (char)(nb % 10 + '0');
        nb /= 10;
        incrementer++;
    }
    if (buffer < 0) {
        str[incrementer] = '-';
        incrementer++;
    }
    str[incrementer] = '\0';
    return (my_revstr(str));
}
