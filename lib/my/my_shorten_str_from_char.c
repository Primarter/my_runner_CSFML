/*
** EPITECH PROJECT, 2019
** lib
** File description:
** shorten_str_from_char.c
*/

#include <stdlib.h>

char *shorten_str_from_char(char *res, char c)
{
    int i = 0;
    char *tmp;

    while (res[i] != c)
        i += 1;
    tmp = malloc(sizeof(char) * i);
    for (int j = 0; i > j; j += 1)
        tmp[j] = res[j];
    free(res);
    return tmp;
}