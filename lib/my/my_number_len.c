/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** number of characters
*/

int my_number_len(int const *nb)
{
    int number = 0;

    for (int i = 0; nb[i] != '\0'; i++)
        number++;
    return (number);
}
