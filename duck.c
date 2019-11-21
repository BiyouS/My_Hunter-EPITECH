/*
** EPITECH PROJECT, 2019
** credits
** File description:
** credist
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include "../include/my.h"
#include "../include/structs.h"

extern const int NB_ASSETS_D;
extern const float VEC_Y_D;
extern const float VEC_X_D;
extern const float FRAME_BY_S;

void move_rect(game_t *t)
{
    int offset = 110;
    int max_value = 330;

    t->anima.rect.left += offset;
    if (t->anima.rect.left == max_value) {
        t->anima.rect.left = 0;
    }
    return;
}

void clock(game_t *t)
{
    static bool firstpass = true;

    if (firstpass)
        t->anima.clock = sfClock_create();
    t->anima.time = sfClock_getElapsedTime(t->anima.clock);
    t->anima.seconds = t->anima.time.microseconds / 1000000.0;
    if (t->anima.seconds > FRAME_BY_S) {
        move_rect(t);
        sfClock_restart(t->anima.clock);
        sfSprite_move(t->duck.sprite, (sfVector2f){10, 0});
    }
    sfSprite_setTextureRect(t->duck.sprite, t->anima.rect);
    firstpass = false;
}

void display_duck(game_t *t)
{
    t->duck.scale = (sfVector2f){1, 1};
    t->duck.pos = (sfVector2f){50, 50};
    t->duck.sprite = t->sprite[5]->sprite;
    sfSprite_setScale(t->duck.sprite, t->duck.scale);
    sfSprite_setPosition(t->duck.sprite, t->duck.pos);
    sfRenderWindow_drawSprite(t->window, t->sprite[5]->sprite, NULL);
}

void duck(game_t *t)
{
    display_duck(t);
    clock(t);
}
