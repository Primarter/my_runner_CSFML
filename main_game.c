/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main.c
*/

#include "header.h"

void event_management(sf_t *st, sfEvent ev, sfRenderWindow *win, movement_t *m)
{
    while (sfRenderWindow_pollEvent(win, &ev)) {
        if (ev.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyEscape)
            sfRenderWindow_close(win);
        if (sfKeyboard_isKeyPressed(sfKeySpace) ==  sfTrue && m->status == 0) {
            sfSound_play(st->jump_sound);
            m->velocity = -20;
            m->status = 1;
        }
    }
}

void disp(sf_t *stc, sp_t *chara, sp_t **bg)
{
    sfRenderWindow_clear(stc->win, sfBlack);
    for (int i = 0; i <= 4; i += 1) {
        sfSprite_setTextureRect(bg[i]->sp, bg[i]->rect);
        sfRenderWindow_drawSprite(stc->win, bg[i]->sp, NULL);
    }
    sfSprite_setPosition(chara->sp, chara->pos);
    sfSprite_setTextureRect(chara->sp, chara->rect);
    sfRenderWindow_drawSprite(stc->win, chara->sp, NULL);
    print_score(stc);
}

void handle_clock(sp_t **bg, sp_t *chara)
{
    chara->time = sfClock_getElapsedTime(chara->clock);
    if (sfTime_asSeconds(chara->time) > 0.055) {
        move_rect(&chara->rect, 75, 600);
        sfClock_restart(chara->clock);
    }
    bg[0]->time = sfClock_getElapsedTime(bg[0]->clock);
    if (sfTime_asSeconds(bg[0]->time) > 0.05) {
        parallax_move(&bg[0]->rect, 1, 834);
        sfClock_restart(bg[0]->clock);
    }
    for (int i = 1; bg[i]; i++) {
        bg[i]->time = sfClock_getElapsedTime(bg[i]->clock);
        if (sfTime_asSeconds(bg[i]->time)> 0.05 / i) {
            parallax_move(&bg[i]->rect, 1, 1024);
            sfClock_restart(bg[i]->clock);
        }
    }
}

void game_loop(sf_t *stc, sp_t **bg, sp_t *chara, movement_t *mv)
{
    event_management(stc, stc->event, stc->win, mv);
    print_score(stc);
    if (stc->score >= stc->end)
        mv->status = 3;
    if (mv->status > 1) {
        print_end(mv->status, stc);
        sfRenderWindow_display(stc->win);
        return;
    }
    sfRenderWindow_clear(stc->win, sfBlack);
    jump_update(chara, mv, get_ground(chara, stc->map));
    handle_clock(bg, chara);
    disp(stc, chara, bg);
    disp_map(stc->map, stc);
    sfRenderWindow_display(stc->win);
}

int game(char **av)
{
    sf_t *stc = struct_def(1536, 768, av[1]);
    sp_t **bg = init_background();
    sp_t *chara = init_chara();
    movement_t *mv = init_movement();
    sfMusic *theme = sfMusic_createFromFile("./audio/Fire_Emblem_Theme.ogg");

    if (!stc || !stc->win) {
        sfMusic_destroy(theme);
        return (84);
    }
    sfMusic_play(theme);
    sfMusic_setLoop(theme, sfTrue);
    sfMusic_setVolume(theme, 10);
    sfRenderWindow_setFramerateLimit(stc->win, 60);
    if (menu(stc, bg, chara, theme))
        return (0);
    while (sfRenderWindow_isOpen(stc->win))
        game_loop(stc, bg, chara, mv);
    destroy_all(bg, chara, stc, theme);
    return (0);
}