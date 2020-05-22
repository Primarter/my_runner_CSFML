/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** is alpha
*/

int my_str_isalpha(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((str[i] < 97 || str[i] > 123) && (str[i] < 'A' || str[i] > 'Z'))
            return (0);
    }
    return (1);
}
