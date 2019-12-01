/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** number of characters
*/

int my_digitlen(int digit)
{
    int number = 1;
    int i = 1;

    while (digit / i > 9) {
        i *= 10;
        number++;
    }
    return (number);
}
