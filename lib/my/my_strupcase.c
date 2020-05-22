/*
** EPITECH PROJECT, 2019
** strupcase
** File description:
** going from lowercase to uppercase
*/

#include <stdlib.h>

char *my_strupcase(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if ('a' <= str[a] && str[a] <= 'z') {
            str[a] = str[a] - 32;
        }
    }
    return (str);
}
