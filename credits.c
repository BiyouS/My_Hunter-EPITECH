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
extern const unsigned int WIN_W;
extern const unsigned int WIN_H;

void display_credits(game_t *t)
{
    static bool firstpass = true;
    sfVector2u vec_origin;

    t->credits.scale = (sfVector2f){5, 5};
    t->credits.sprite = t->sprite[4];
    vec_origin = sfTexture_getSize(t->credits.sprite->texture);
    if (firstpass) {
        t->origin = (sfVector2f){vec_origin.x / 2, vec_origin.y / 2};
        sfSprite_setOrigin(t->credits.sprite->sprite, t->origin);
        t->credits.pos = (sfVector2f){WIN_W / 2, WIN_H * ((1 + 1.0f) / 4.0f)};
    }
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
    if (t->credits.pos.y < -400) {
        t->scene = 3;
        t->credits.pos = (sfVector2f){WIN_W / 2, WIN_H * ((1 + 1.0f) / 4.0f)};
        sfSprite_setPosition(t->credits.sprite->sprite, t->credits.pos);
    }
}
