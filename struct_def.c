/*
** EPITECH PROJECT, 2019
** Graphic
** File description:
** struct_def.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "my_runner.h"

map_obj_t *get_map(char *path);

sp_t *game_object(const char *path_spritesheet, sfVector2f pos, sfIntRect rect);

tile_t *tile_object(const char *path_spritesheet, sfVector2f pos, sfIntRect rect);

sfVideoMode set_videomode(sfVideoMode mode, int width, int height, int bpp)
{
    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = bpp;
    return mode;
}

int get_end(map_obj_t *map)
{
    int end = 0;

    for (int i = 0; map->map[i]; i++) {
        if (map->map[i] == '<')
            break;
        end += 64;
    }
    return (end / 5);
}

sf_t *struct_def(int width, int height, char *path_to_map)
{
    sf_t *st = malloc(sizeof(sf_t));

    st->mode = set_videomode(st->mode, width, height, 32);
    st->win = sfRenderWindow_create(st->mode, "win", sfResize | sfClose, NULL);
    st->jump = sfSoundBuffer_createFromFile("./audio/Jump.wav");
    st->jump_sound = sfSound_create();
    sfSound_setBuffer(st->jump_sound, st->jump);
    st->map = get_map(path_to_map);
    if (!(st->map)) {
        sfRenderWindow_destroy(st->win);
        sfSoundBuffer_destroy(st->jump);
        return (NULL);
    }
    st->font = sfFont_createFromFile("fonts/dimis.ttf");
    st->text = sfText_create();
    st->score = 0;
    st->end = get_end(st->map);
    return (st);
}

sp_t **init_background(void)
{
    sp_t **game_obj = NULL;
    sfVector2f angle = {0, 0};
    sfIntRect rect = {0, 0, 512, 256};
    sfIntRect rect2 = {0, 0, 417, 256};

    game_obj = malloc(sizeof(sp_t *) * 6);
    game_obj[5] = NULL;
    game_obj[0] = game_object("images/Hills_layer_1.png", angle, rect2);
    game_obj[1] = game_object("images/Hills_layer_2.png", angle, rect);
    game_obj[2] = game_object("images/Hills_layer_3.png", angle, rect);
    game_obj[3] = game_object("images/Hills_layer_4.png", angle, rect);
    game_obj[4] = game_object("images/Hills_layer_6.png", angle, rect);
    game_obj[0]->en = BACK;
    game_obj[1]->en = MIDDLE;
    game_obj[2]->en = FRONT;
    game_obj[3]->en = FORE;
    game_obj[4]->en = DOWN;
    sfSprite_setScale(game_obj[0]->sp, (sfVector2f) {3.683453, 3.683453});
    for (int i = 1; i < 5; i += 1)
        sfSprite_setScale(game_obj[i]->sp, (sfVector2f) {3, 3});
    return (game_obj);
}

sp_t *init_chara(void)
{
    sp_t *chara = NULL;
    sfVector2f pos = {50, 0};
    sfIntRect rect = {0, 0, 75, 55};

    chara = malloc(sizeof(sp_t));
    chara = game_object("images/running.png", pos, rect);
    sfSprite_setScale(chara->sp, (sfVector2f) {2, 2});
    return (chara);
}