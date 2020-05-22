/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** menu.c
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Export.h>
#include <stdlib.h>
#include "my_runner.h"

void print_menu(sf_t *stc);

void destroy_all(sp_t **bg, sp_t *chara, sf_t *stc, sfMusic *theme);

int menu(sf_t *stc, sp_t **bg, sp_t *chara, sfMusic *theme)
{
    sfEvent ev = stc->event;

    while (sfRenderWindow_isOpen(stc->win)) {
        sfRenderWindow_clear(stc->win, sfBlack);
        print_menu(stc);
        while (sfRenderWindow_pollEvent(stc->win, &ev)) {
            if (ev.type == sfEvtClosed) {
                sfRenderWindow_close(stc->win);
                destroy_all(bg, chara, stc, theme);
                return (1);
            }
            if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyEscape) {
                sfRenderWindow_close(stc->win);
                destroy_all(bg, chara, stc, theme);
                return (1);
            }
            if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeySpace)
                return (0);
        }
    }
    return (0);
}