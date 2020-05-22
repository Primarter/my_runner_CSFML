/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_realloc_str.c
*/

#include <stdlib.h>

char *my_realloc_str(char *str, int size)
{
    char *tmp = malloc(sizeof(char) * (size + 1));

    if (!str[0] || !str) {
        free(tmp);
        str = malloc(sizeof(char) * size);
        return str;
    }
    for (int i = 0; i < size; i += 1) {
        tmp[i] = str[i];
        tmp[i + 1] = '\0';
    }
    return tmp;
}