/*
** EPITECH PROJECT, 2019
** rand
** File description:
** rand
*/

#include <stdlib.h>

int get_rnd_nbr(unsigned int min, unsigned int max)
{
    return (min + rand() % (max - min));
}
