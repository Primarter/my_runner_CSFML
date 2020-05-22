/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** objects.c
*/

#include "my_runner.h"
#include <stdlib.h>

sp_t *game_object(const char *path_spritesheet, sfVector2f pos, sfIntRect rect)
{
    sp_t *sp = malloc(sizeof(sp_t));

    sp->txtre = sfTexture_createFromFile(path_spritesheet, NULL);
    sp->sp = sfSprite_create();
    sfSprite_setPosition(sp->sp, pos);
    sfSprite_setTexture(sp->sp, sp->txtre, sfTrue);
    sp->rect = rect;
    sp->pos = pos;
    sp->clock = sfClock_create();
    sp->status = 0;
    sp->velocity = 20;
    return (sp);
}

tile_t *tile_object(const char *path_spritesheet, sfVector2f pos, sfIntRect rect)
{
    tile_t *sp = malloc(sizeof(tile_t));

    sp->txtre = sfTexture_createFromFile(path_spritesheet, NULL);
    sp->sp = sfSprite_create();
    sfSprite_setPosition(sp->sp, pos);
    sfSprite_setTexture(sp->sp, sp->txtre, sfTrue);
    sp->rect = rect;
    sp->pos = pos;
    return (sp);
}