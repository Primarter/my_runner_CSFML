/*
** EPITECH PROJECT, 2019
** task07
** File description:
** who is prime
*/

int my_is_prime2(int test)
{
    int a = 1;

    if (test <= 1)
        return (1);

    for (int c = 0; c < test; c += 1) {
        if (test % c == 0) {
            return (0);
        }
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    int count = nb;

    while (my_is_prime2(count) != 1) {
        count += 1;
    }
    return (count);
}