/*
** EPITECH PROJECT, 2019
** credits
** File description:
** credist
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include "include/my.h"
#include "include/structs.h"

extern const int NB_ASSETS;
extern const float VEC_Y_C;
extern const float VEC_X_C;

void display_credits(game_t *t)
{
    static bool firstpass = true;

    t->credits.scale = (sfVector2f){5, 5};
    if (firstpass)
        t->credits.pos = (sfVector2f){VEC_X_C, VEC_Y_C};
    t->credits.sprite = t->sprite[4];
    sfSprite_setScale(t->credits.sprite->sprite, t->credits.scale);
    if (firstpass)
        sfSprite_setPosition(t->credits.sprite->sprite, t->credits.pos);
    sfRenderWindow_drawSprite(t->window, t->sprite[4]->sprite, NULL);
    firstpass = false;
}

void credits(game_t *t)
{
    display_credits(t);
    sfSprite_move(t->credits.sprite->sprite, (sfVector2f){0, -0.2});
    t->credits.pos.y = sfSprite_getPosition(t->credits.sprite->sprite).y;
    if (t->credits.pos.y < -500) {
        t->scene = 3;
    }
}
