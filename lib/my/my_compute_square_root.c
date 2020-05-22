/*
** EPITECH PROJECT, 2019
** square root
** File description:
** my square root
*/

int my_compute_square_root(int nb)
{
    int b = 2;

    while (b < nb) {
        if (b * b == nb) {
            return (b);
        }
        b++;
    }
    return (0);
}
