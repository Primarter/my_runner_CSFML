/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** if neg N if pos P
*/

void my_putchar(char);

int my_isneg(int n)
{
    if (n<0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}
