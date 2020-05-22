/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swap two values
*/

#include <unistd.h>

void my_swap(int *a, int *b)
{
    int s = *a;

    *a = *b;
    *b = s;
}
