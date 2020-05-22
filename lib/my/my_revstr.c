/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse str
*/

char *my_revstr(char *str)
{
    int a = 0;
    int b = 0;
    int c = 0;
    unsigned char swap;

    while (str[c + 1]) {
        c += 1;
    }
    b = c;
    while (a <= c/2) {
        swap = str[a];
        str[a] = str[b];
        str[b] = swap;
        a += 1;
        b -= 1;
    }
    return (str);
}
