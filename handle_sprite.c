/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** handle_sprite.c
*/

#include "my_runner.h"
#include <SFML/Graphics.h>

float get_ground(sp_t *character, map_obj_t *map);

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left + offset >= max_value)
        rect->left = 0;
    else
        rect->left += offset;
}

void parallax_move(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left + offset >= max_value / 2)
        rect->left = 0;
    else
        rect->left += offset;
}

void jump_update(sp_t *chara, movement_t *mv, float ground)
{
    float gravity = 0.980665;

    if (mv->status == 0 && chara->pos.y + 95 == ground)
        return;
    mv->time = sfClock_getElapsedTime(mv->clock);
    if (sfTime_asSeconds(mv->time) > 0.013) {
        mv->velocity += gravity;
        chara->pos.y += mv->velocity;
        sfClock_restart(mv->clock);
    }
    if (chara->pos.y >= ground) {
        chara->pos.y = ground;
        mv->status = 0;
    }
    if (chara->pos.y >= 900) {
        chara->pos.y = 100;
        mv->status = 2;
        return;
    }
}