/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** is num
*/

int my_str_isnum(char const *str)
{
    if (str[0] == '\0')
        return (0);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}
