/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_hunter
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Text.h>
#include "../include/my.h"
#include "../include/structs.h"

int main(void)
{
    game_t tools;

    tools.score.point = 00;
    tools.quit = 0;
    tools.scene = 3;
    tools.anima.rect = (sfIntRect){0, 0, 110, 110};
    tools.anima_title.rect = (sfIntRect){0, 0, 330, 330};
    tools.menu.music_1 = sfMusic_createFromFile("Assets/song/Bipbip.wav");
    tools.menu.music_2 = sfMusic_createFromFile("Assets/song/hunter.ogg");
    tools.music_3 = sfMusic_createFromFile("Assets/song/hunter-game.ogg");
    tools.score.music = sfMusic_createFromFile("Assets/song/ShotGun.wav");
    sfMusic_play(tools.menu.music_2);
    sfMusic_setLoop(tools.menu.music_2, sfTrue);
    game(&tools);
    sfMusic_destroy(tools.menu.music_1);
    sfMusic_destroy(tools.menu.music_2);
    sfMusic_destroy(tools.score.music);
    sfMusic_destroy(tools.music_3);
    return (0);
}
