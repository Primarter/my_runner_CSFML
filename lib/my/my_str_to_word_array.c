/*
** EPITECH PROJECT, 2019
** my str to word array
** File description:
** try 2
*/

#include <stdlib.h>

typedef struct letters_s {
    int first_l;
    int letter;
    int size_word;
    int j;
} letter_t;

int my_strlen(char const *str);

int greatest(int a, int b);

int subs(char *str, char sep)
{
    int c_substr = 0;

    for (int i = 0; str[i]; i += 1) {
        if (str[i + 1] == sep) {
            c_substr += 1;
        }
    }
    if (str[my_strlen(str) - 1] != '\n')
        c_substr += 1;
    return (c_substr);
}

char **my_str_to_word_array(char *str, char sep)
{
    letter_t lett = {0, 0, 0, 0};
    char **array = malloc(sizeof(char *) * (subs(str, sep) + 1));

    for (int i = 0; str[i]; i += 1) {
        for (; str[i] != sep; i += 1) {
            lett.first_l = i - lett.size_word;
            lett.size_word += 1;
        }
        array[lett.j] = malloc(sizeof(char) * (lett.size_word + 1));
        for (; lett.first_l < i; lett.first_l += 1) {
            array[lett.j][lett.letter++] = str[lett.first_l];
        }
        array[lett.j][lett.letter] = '\0';
        lett.letter = 0;
        lett.j += 1;
        lett.size_word = 0;
    }
    array[lett.j] = NULL;
    return (array);
}