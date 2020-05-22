/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner.h
*/

#ifndef MY_RUNNER_H_
    #define MY_RUNNER_H_

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Audio.h>

    typedef enum en_sprite_s{
        BACK,
        MIDDLE,
        FRONT,
        FORE,
        DOWN
    } en_sprite_t;

    typedef struct movement_s {
        int status;
        float velocity;
        sfClock *clock;
        sfTime time;
    } movement_t;

    typedef struct sp_s
    {
        sfTexture *txtre;
        sfSprite *sp;
        sfVector2f pos;
        sfIntRect rect;
        en_sprite_t en;
        sfClock *clock;
        sfTime time;
        int status;
        float velocity;
    } sp_t;

    typedef struct tile_s
    {
        sfTexture *txtre;
        sfSprite *sp;
        sfVector2f pos;
        sfIntRect rect;
    } tile_t;

    typedef struct map_obj_s {
        char *map;
        float start_map;
        tile_t **sp_tab;
        sfClock *clock;
        sfTime time;
    } map_obj_t;

    typedef struct sf_s {
        sfVideoMode mode;
        sfRenderWindow *win;
        sfEvent event;
        sfSoundBuffer *jump;
        sfSound *jump_sound;
        map_obj_t *map;
        sfFont *font;
        sfText *text;
        int score;
        int end;
    } sf_t;

#endif /* MY_RUNNER_H_*/