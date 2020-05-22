/*
** EPITECH PROJECT, 2019
** PSU_my_printf_bootstrap_2019
** File description:
** sum_stdarg.c
*/

#include <stdarg.h>

int my_strlen(char const *str);

int sum_stdarg(int i, int nb, ...)
{
    va_list ap;
    va_list ap2;
    int res = 0;

    if (i == 0) {
        va_start(ap, nb);
        for (int i = 0; i < nb; i += 1)
            res = res + va_arg(ap, int);
        va_end(ap);
        return res;
    } else if (i == 1) {
        va_start(ap, nb);
        for (int i; i < nb; i += 1)
            res = my_strlen(va_arg(ap, char *));
        for (int i; i < nb; i += 1)
            res = res + my_strlen(va_arg(ap, char *));
        va_end(ap);
        return res;
    }
    return 84;
}