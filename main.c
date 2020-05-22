/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main.c
*/

#include "my.h"
#include <unistd.h>

int game(char **av);

void print_help(void)
{
    write(1, "Finite runner done in CSFML.\n\nUSAGE\n\t./my_runner ", 49);
    write(1, "map.txt\n\nMAPS\n\tMaps are created thanks to a formatting", 54);
    write(1, " inspired by an app called Tiled: each character ", 49);
    write(1, "corresponds to a specific tile.\n\tYou can create a map ", 54);
    write(1, "using ASCII characters ranging from the 48 ASCII value ", 55);
    write(1, "to the 68th, 48 meaning nothing and 60 meaning an end tile", 58);
    write(1, ".\n\tThe end tile also specifies when the game ends : if ", 55);
    write(1, "the player goes past one, the game is a victory.", 48);
    write(1, "\n\nKEYS\n\tSpace: jump, you need only to jump over holes", 53);
    write(1, " in the map, the character will automatically climb walls.", 58);
    write(1, "\n\tYour hitbox is right at the middle of your character ", 55);
    write(1, "on the ground, if it reaches a tile, Roy will climb on it.", 53);
    write(1, "\n\tEscape: you quit the game, you can also click on the ", 55);
    write(1, "cross.\n\n", 8);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        write(2, "Wrong arguments, -h for help\n", 29);
        return (84);
    }
    if (my_strcmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    }
    return (game(av));
}