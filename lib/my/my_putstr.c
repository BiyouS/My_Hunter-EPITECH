/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** str
*/

int my_putchar(char c);

int my_putstr(char const *str)
{
    char letter;

    while (*str != '\0') {
        letter = *str;
        my_putchar(letter);
        str++;
    }
    return (0);
}
