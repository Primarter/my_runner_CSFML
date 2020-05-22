/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** text_print.c
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Export.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

char *itos(long long nb);

void print_end(int end, sf_t *stc)
{
    if (end == 2) {
        sfRenderWindow_clear(stc->win, sfBlack);
        sfText_setString(stc->text, "DEFEAT");
        sfText_setFont(stc->text, stc->font);
        sfText_setCharacterSize(stc->text, 250);
        sfText_setColor(stc->text, sfRed);
        sfText_setFillColor(stc->text, sfRed);
        sfText_setPosition(stc->text, (sfVector2f) {360, 192});
        sfRenderWindow_drawText(stc->win, stc->text, NULL);
    } else if (end == 3) {
        sfRenderWindow_clear(stc->win, sfBlack);
        sfText_setString(stc->text, "VICTORY");
        sfText_setFont(stc->text, stc->font);
        sfText_setCharacterSize(stc->text, 250);
        sfText_setColor(stc->text, sfBlue);
        sfText_setFillColor(stc->text, sfBlue);
        sfText_setPosition(stc->text, (sfVector2f) {360, 192});
        sfRenderWindow_drawText(stc->win, stc->text, NULL);
    }
}

void print_score(sf_t *stc)
{
    sfText_setString(stc->text, itos(stc->score));
    sfText_setFont(stc->text, stc->font);
    sfText_setCharacterSize(stc->text, 50);
    sfText_setColor(stc->text, sfRed);
    sfText_setFillColor(stc->text, sfBlue);
    sfText_setPosition(stc->text, (sfVector2f) {50, 50});
    sfRenderWindow_drawText(stc->win, stc->text, NULL);
}

void print_menu(sf_t *stc)
{
    sfTexture *texture = sfTexture_createFromFile("images/logo.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfColor orange = {230, 165, 0, 255};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f) {250, 100});
    sfRenderWindow_drawSprite(stc->win, sprite, NULL);
    sfText_setString(stc->text, "Fierce Run\n\n\n\t   Press space to start");
    sfText_setFont(stc->text, stc->font);
    sfText_setCharacterSize(stc->text, 50);
    sfText_setColor(stc->text, orange);
    sfText_setFillColor(stc->text, orange);
    sfText_setPosition(stc->text, (sfVector2f) {350, 300});
    sfRenderWindow_drawText(stc->win, stc->text, NULL);
    sfRenderWindow_display(stc->win);
}