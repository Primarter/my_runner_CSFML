/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** get_ground.c
*/

#include "my_runner.h"

float get_ground(sp_t *character, map_obj_t *map)
{
    for (int i = 0; map->sp_tab[i]; i++) {
        if (character->pos.x + 37.5 >= map->sp_tab[i]->pos.x && \
        character->pos.x + 37.5 <= map->sp_tab[i]->pos.x + 64 && \
        character->pos.y <= map->sp_tab[i]->pos.y) {
            return (map->sp_tab[i]->pos.y - 95);
        }
    }
    return (900.0);
}