/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** functions_my_printf.h
*/

#ifndef FUNCTIONS_MY_PRINTF_H_
#define FUNCTIONS_MY_PRINTF_H_

#include <stdarg.h>
#include <errno.h>
#include <time.h>
#include "my.h"

void my_flag_p(va_list ap);

void my_flag_x(va_list ap);

void my_flag_bigx(va_list ap);

void my_flag_o(va_list ap);

void my_flag_b(va_list ap);

void my_flag_c(va_list ap);

void my_flag_mod(va_list ap);

void my_flag_m(va_list ap);

void my_flag_bigs(va_list ap);

void my_flag_u(va_list ap);

void my_flag_d_i(va_list ap);

void my_flag_s(va_list ap);

#endif