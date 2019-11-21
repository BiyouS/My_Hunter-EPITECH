/*
** EPITECH PROJECT, 2019
** put_nbr
** File description:
** put_nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int i = 1;
    int inter = 0;

    if (nb >= 0) {
        while ((nb / i) > 9) {
            i = i * 10;
        }
    }
    else {
        while ((nb / i) < -9) {
            i = i * 10;
        }
        my_putchar('-');
    }
    while (i != 0) {
        inter = nb /i % 10;
        (inter < 0) ? (inter *= -1) : (inter = inter);
        my_putchar('0'+ inter);
        i = i / 10;
    }
    return (0);
}
