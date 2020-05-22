/*
** EPITECH PROJECT, 2019
** power rec
** File description:
** power rec
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return (1);
    } else if (p < 0) {
        return (0);
    } else {
        nb = nb * my_compute_power_rec(nb, p);
        return (nb);
    }
}
