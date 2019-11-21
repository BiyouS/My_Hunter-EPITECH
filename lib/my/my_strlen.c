/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** number of characters
*/

int my_strlen(char const *str)
{
    int number = 0;

    while (*str != '\0') {
        str++;
        number++;
    }
    return (number);
}
