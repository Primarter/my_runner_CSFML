/*
** EPITECH PROJECT, 2019
** capitalize
** File description:
** capitalize
*/

char *my_strcapitalize(char *str)
{
    char *str2 = str;

    if (str[0] <= 'z' && str[0] >= 'a')
        str[0] += 32;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (*str >= 32 && *str >= 47 || *str == *str2)
        {
            if (*str != *str2) {
                str += 1;
            }
            if (*str >= 'a' && *str <= 'z') {
                *str += 32;
            }
        }
    }
    return (str);
}
