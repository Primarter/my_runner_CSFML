/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** map_handling.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my_runner.h"
#include "my.h"

tile_t *tile_object(const char *path_spritesheet, sfVector2f pos, sfIntRect rect);

int sp_tab_size(map_obj_t *map)
{
    int size = 0;

    for (int i = 0; map->map[i]; i++)
        switch (map->map[i]) {
            case ('2'):
                size++;
                break;
            case ('6'):
                size++;
                break;
            case ('<'):
                size++;
                break;
            default:
                break;
            }
    return (size);
}

void set_sprite(map_obj_t *map, sfVector2f pos, int sp, sfIntRect rect)
{
    sfSprite_setPosition(map->sp_tab[sp]->sp, pos);
    sfSprite_setTextureRect(map->sp_tab[sp]->sp, rect);
    sfSprite_setTexture(map->sp_tab[sp]->sp, map->sp_tab[sp]->txtre, 0);
}

void setup_sprites(map_obj_t *map, int size_map)
{
    sfIntRect rect = {0, 0, 0, 0};
    sfVector2f pos = {0, 0};
    int x = 0;
    int y = 0;
    int top = 0;
    int sp = 0;

    for (int i = 0; i < size_map; i++)
        map->sp_tab[i] = tile_object("images/tileset.png", pos, rect);
    for (int i = 0; map->map[i] && sp < size_map; i++) {
        if (map->map[i] != '0' && map->map[i] != '\n') {
            top = ((map->map[i] - 49) / 4) * 64;
            rect = (sfIntRect) {((map->map[i] - 49) % 4) * 64, top, 64, 64};
            map->sp_tab[sp]->pos = (sfVector2f) {x, y};
            sfSprite_setPosition(map->sp_tab[sp]->sp, (sfVector2f) {x, y});
            sfSprite_setTextureRect(map->sp_tab[sp]->sp, rect);
            sfSprite_setTexture(map->sp_tab[sp]->sp, map->sp_tab[sp]->txtre, 0);
            sp++;
        }
        x = (map->map[i + 1] == '\n') ? 0 : x + 64;
        y = (map->map[i + 1] == '\n') ? y + 64 : y;
    }
}

map_obj_t *get_map(char *path)
{
    char *rd_buf = NULL;
    FILE *fd = fopen(path, "r");
    map_obj_t *map = malloc(sizeof(map_obj_t));
    size_t size_map = 0;

    if (!fd)
        return (NULL);
    map->map = NULL;
    while (getline(&rd_buf, &size_map, fd) > 0) {
        map->map = my_strcat(map->map, rd_buf);
        free(rd_buf);
        rd_buf = NULL;
    }
    fclose(fd);
    map->clock = sfClock_create();
    map->start_map = 0.0;
    map->sp_tab = malloc(sizeof(tile_t *) * (sp_tab_size(map) + 1));
    map->sp_tab[sp_tab_size(map)] = NULL;
    setup_sprites(map, sp_tab_size(map));
    return (map);
}

void disp_map(map_obj_t *map, sf_t *stc)
{
    map->time = sfClock_getElapsedTime(map->clock);
    if (sfTime_asSeconds(map->time) > 0.00225) {
        for (int i = 0; map->sp_tab[i]; i++)
            map->sp_tab[i]->pos.x -= 5;
        stc->score += 1;
        sfClock_restart(map->clock);
    }
    for (int i = 0; map->sp_tab[i]; i++) {
        sfSprite_setPosition(map->sp_tab[i]->sp, map->sp_tab[i]->pos);
        sfRenderWindow_drawSprite(stc->win, map->sp_tab[i]->sp, NULL);
    }
}
// x_tile : ((tile - 1) % 4) * 64
// y_tile : ((tile - 1) / 4) * 64