/*
** EPITECH PROJECT, 2019
** PSU_my_printf_bootstrap_2019
** File description:
** disp_stdarg.c
*/

#include <stdarg.h>

void my_putchar(char c);

void my_putstr(char const *str);

int my_put_nbr(int n);

int my_strlen(char *str);

int disp_stdarg(char *s, ... )
{
    va_list ap;
    va_start(ap, s);
    for (int i; i < my_strlen(s); i += 1) {
        if (s[i] == 'c') {
            my_putchar(va_arg(ap, int));
        }
        if (s[i] == 's') {
            my_putstr(va_arg(ap, char *));
        }
        if (s[i] == 'i') {
            my_put_nbr(va_arg(ap, int));
        }
        my_putchar('\n');
    }
    va_end(ap);
    return 0;
}