/*
** EPITECH PROJECT, 2019
** dislay.anima.title
** File description:
** title.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include "../include/my.h"
#include "../include/structs.h"

extern const unsigned int WIN_W;
extern const unsigned int WIN_H;
extern const int NB_ASSETS_D;
extern const float VEC_Y_D;
extern const float VEC_X_D;
extern const float FRAME_BY_S;

static void move_rect(game_t *t)
{
    float offset = 320.0;
    float max_value = 4160.0;

    t->anima_title.rect.left += offset;
    if (t->anima_title.rect.left >= max_value) {
        t->anima_title.rect.left = 0;
    }
    return;
}

static void clock(game_t *t)
{
    static bool firstpass = true;

    if (firstpass)
        t->anima_title.clock = sfClock_create();
    t->anima_title.time = sfClock_getElapsedTime(t->anima_title.clock);
    t->anima_title.seconds = t->anima_title.time.microseconds / 1000000.0;
    if (t->anima_title.seconds > FRAME_BY_S) {
        move_rect(t);
        sfClock_restart(t->anima_title.clock);
    }
    sfSprite_setTextureRect(t->sprite[5]->sprite, t->anima_title.rect);
    firstpass = false;
}

static void display_title(game_t *t)
{
    static bool firstpass = true;

    t->title.sprite.sprite = t->sprite[5]->sprite;
    t->title.scale = (sfVector2f){3, 3};
    if (firstpass)
        t->title.pos = (sfVector2f){50, 0};
    sfSprite_setScale(t->title.sprite.sprite, t->title.scale);
    if (firstpass)
        sfSprite_setPosition(t->title.sprite.sprite, t->title.pos);
    sfRenderWindow_drawSprite(t->window, t->title.sprite.sprite, NULL);
    clock(t);
    firstpass = false;
}

void display_anima_title(game_t *t)
{
    display_title(t);
}
