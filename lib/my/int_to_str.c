/*
** EPITECH PROJECT, 2019
** strtoint
** File description:
** int
*/

#include "../../include/my.h"
#include <stdlib.h>

char *int_to_str(char *str, int nb)
{
    int len = my_digitlen(nb);
    int len2 = my_strlen(str);
    char *str2 = malloc(sizeof(char) * (len2 + len) + 1);
    int div = 1;

    for (int i = 1; i < len; i++)
        div *= 10;
    for (int i = 0; i <= len2 + len - 1; i++) {
        if (i < len2)
            str2[i] = str[i];
        else {
            str2[i] = (nb / div) % 10 + '0';
            div /= 10;
        }
    }
    str2[len2 + len] = '\0';
    return (str2);
}
