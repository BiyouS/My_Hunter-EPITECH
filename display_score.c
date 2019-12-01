/*
** EPITECH PROJECT, 2019
** score
** File description:
** score.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/structs.h"

void display_score(score_t *s, game_t *t)
{
    static bool firstpass = true;
    char *score_text = int_to_str("score : ", t->score.point);

    if (firstpass)
        s->text = sfText_create();
    sfText_setString(t->score.text, score_text);
    t->score.pos = (sfVector2f){10, 700};
    if (firstpass)
        sfText_setPosition(t->score.text, t->score.pos);
    t->score.font = sfFont_createFromFile("Assets/font/game_over.ttf");
    sfText_setFont(t->score.text, t->score.font);
    sfText_setCharacterSize(t->score.text, 90);
    sfText_setFillColor(t->score.text, sfBlack);
    sfText_setStyle(t->score.text, sfTextRegular);
    sfRenderWindow_drawText(t->window, t->score.text, NULL);
    firstpass = false;
}
