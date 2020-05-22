/*
** EPITECH PROJECT, 2019
** task06
** File description:
** is it prime?
*/

int my_is_prime(int nb)
{
    int c = 0;
    int a = 1;

    while (c < nb) {
        if (nb % c == 0) {
            a = 0;
            c += 1;
        }
    }
    return (a);
}
