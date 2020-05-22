/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** print array
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    for (int n = 0; str[n] != '\0'; n += 1) {
        my_putchar(str[n]);
    }
}
