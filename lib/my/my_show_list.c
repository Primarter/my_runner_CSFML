/*
** EPITECH PROJECT, 2019
** my_show_list function
** File description:
** prints out the list given as argument
*/

#include "../../include/my.h"
#include <stdlib.h>

void my_putstr(char const *str);

void my_show_list(linked_list_t *list)
{
    linked_list_t  *tmp;

    tmp = list;
    while (tmp != NULL) {
        my_putstr(tmp -> data);
        if (tmp -> next != NULL) {
            my_putstr(", ");
        }
        tmp = tmp -> next;
    }
    my_putchar('\n');
}
