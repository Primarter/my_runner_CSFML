/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** yay
*/
#include <stdio.h>

void my_putstr(char const *str);

void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL; i += 1) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
