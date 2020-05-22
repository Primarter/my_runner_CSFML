/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** header.h
*/

#ifndef HEADER_H_
#define HEADER_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Export.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

int menu(sf_t *stc, sp_t **bg, sp_t *chara, sfMusic *theme);

void disp_map(map_obj_t *map, sf_t *stc);

sf_t *struct_def(int width, int height, char *path_to_map);

sp_t *game_object(const char *path_spritesheet, sfVector2f pos, sfIntRect rect);

sp_t **init_background(void);

sp_t *init_chara(void);

movement_t *init_movement(void);

void move_rect(sfIntRect *rect, int offset, int max_value);

void destroy_all(sp_t **bg, sp_t *chara, sf_t *stc, sfMusic *theme);

void parallax_move(sfIntRect *rect, int offset, int max_value);

void jump_update(sp_t *chara, movement_t *mv, float ground);

void print_end(int end, sf_t *stc);

float get_ground(sp_t *character, map_obj_t *map);

void print_score(sf_t *stc);

#endif /* HEADER_H_ */