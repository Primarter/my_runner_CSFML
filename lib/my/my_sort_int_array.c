/*
** EPITECH PROJECT, 2019
** sort array
** File description:
** sort array
*/

#include <stdlib.h>

void my_sort_int_array(int *array, int size)
{
    int tmp;

    for (int i = 0; i != size; i += 1) {
        for (int j = 0; j != size - i - 1; j += 1) {
            if (array[j] > array [j + 1]) {
                tmp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}