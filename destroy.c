/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** destroy.c
*/

#include "my_runner.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/System.h>

void destroy_game_object(sp_t *obj)
{
    sfClock_destroy(obj->clock);
    sfSprite_destroy(obj->sp);
    sfTexture_destroy(obj->txtre);
    free(obj);
}

void destroy_all(sp_t **bg, sp_t *chara, sf_t *stc, sfMusic *theme)
{
    for (int i = 0; bg[i]; i++)
        destroy_game_object(bg[i]);
    free(bg);
    destroy_game_object(chara);
    sfMusic_destroy(theme);
    sfSound_destroy(stc->jump_sound);
    sfSoundBuffer_destroy(stc->jump);
    sfRenderWindow_destroy(stc->win);
    free(stc);
}