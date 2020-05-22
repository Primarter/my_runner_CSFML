/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** movement.c
*/

#include "my_runner.h"
#include <stdlib.h>

movement_t *init_movement(void)
{
    movement_t *move = NULL;

    move = malloc(sizeof(movement_t));
    move->status = 0;
    move->velocity = 50;
    move->clock = sfClock_create();
    return (move);
}