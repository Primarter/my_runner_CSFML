/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** compare one string's length to another up to n
*/

#include <stdlib.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int a = 0;
    int u = 0;
    int v = 0;

    while (s1[a] != '\0') {
        a++;
    }
    if (n > a) {
        return (0);
    }
    for (int b = 0; s1[b] != '\0'; b += 1) {
        u = u + s1[a];
    }
    for (int c = 0; s2[a] != '\0'; c += 1) {
        v = v + s2[a];
    }
    u = u - v;
    return (u);
}
