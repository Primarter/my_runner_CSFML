/*
** EPITECH PROJECT, 2019
** print params
** File description:
** jdo
*/

int my_put_nbr(int n);

void my_putstr(char const *str);

void my_putchar(char c);

int my_rev_params(int argc, char **argv)
{
    int a = argc - 1;

    my_put_nbr(argc);
    while (a >= 0) {
        my_putstr(argv[a]);
        a--;
        my_putchar('\n');
    }
    return (0);
}
