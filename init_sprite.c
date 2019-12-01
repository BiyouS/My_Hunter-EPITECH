/*
** EPITECH PROJECT, 2019
** init
** File description:
** init
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include "include/my.h"
#include "include/structs.h"

void init_sprite(game_t *t)
{
    t->button[0].sprite = t->sprite[1];
    t->button[1].sprite = t->sprite[2];
    t->button[2].sprite = t->sprite[3];
}
