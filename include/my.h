/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all prototypes of all the lib
*/

#ifndef MY_H_
#define MY_H_

#include "mylist.h"

char *concat_params(int argc, char **argv);

int my_compute_factorial_rec(int nb);

int my_strlen(char const *str);

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb);

int my_is_prime(int t);

int my_find_prime_sup(int nb);

int my_getnbr(char const *str);

int my_greatest(int a, int b);

int my_lowest(int a, int b);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

void my_putchar(char c);

int my_str_isnum(char const *str);

int my_str_isupper(char const *str);

int my_print_params(int argc, char **argv);

int my_put_nbr(int n);

void my_putstr(char const *str);

int my_rev_params(int argc, char **argv);

char *my_revstr(char *str);

int my_show_word_array(char * const *tab);

int my_showmem(char const *str, int size);

int my_showstr(char const *str);

void my_sort_int_array(int *tab, int size);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src);

char my_strlowcase(char *str);

char *my_strncat(char *dest, char const *src, int n);

int my_strncmp(char const *s1, char const *s2);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strstr(char *str, char const *to_find);

char *my_strupcase(char *str);

void my_swap(int *a, int *b);

void my_show_list(linked_list_t *list);

char *perform(char exp, char *op1, char *op2);

char *my_realloc_str(char *str, int size);

char *shorten_str_from_char(char *res, char c);

int my_putnbr_base(long nbr, char const *base);

int my_printf(char *str, ...);

char **my_str_to_word_array(char *str, char sep);

#endif