/*
** EPITECH PROJECT, 2019
** factorial
** File description:
** factorial of parameter
*/

int my_compute_factorial_rec(int nb)
{
    if (nb > 12) {
        return (0);
    }
    if (nb == 0) {
        return (0);
    } else {
    nb = my_compute_factorial_rec(nb-1)*nb;
    return (nb);
    }
}
