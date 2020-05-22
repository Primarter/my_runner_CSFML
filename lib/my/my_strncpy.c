/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copy n characters from a string to another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int a = 0;

    while (src[a] != '\0') {
        a++;
    }
    if (n > a) {
        return (0);
    }
    for (int c = 0; c < n; c++) {
        dest[c] = src[c];
    }
    return (dest);
}
