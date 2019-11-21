/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_hunter
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include "include/my.h"
#include "include/structs.h"

int main(void)
{
    game_t tools;

    tools.quit = 0;
    tools.scene = 3;
    tools.anima.rect.top = 0;
    tools.anima.rect.left = 0;
    tools.anima.rect.width = 110;
    tools.anima.rect.height = 110;
    game(&tools);
    return (0);
}
