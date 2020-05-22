/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** is lower
*/

int my_str_islower(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < 97 || str[i] > 123)
            return (0);
    }
    return (1);
}
