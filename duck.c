/*
** EPITECH PROJECT, 2019
** credits
** File description:
** credist
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/structs.h"

extern const int NB_ASSETS_D;
extern const float VEC_Y_D;
extern const float VEC_X_D;
extern const float FRAME_BY_S;
extern const float SECONDS;

void collision_spawn(game_t *t)
{
    float random = get_rnd_nbr(1, 500);

    t->duck[0].pos = sfSprite_getPosition(t->duck[0].sprite.sprite);
//    sfSprite_setColor(t->duck[0].sprite.sprite, COLOR_ALEA));
    if (t->duck[0].pos.x >= 1000 || t->duck[0].pos.y < -150) {
        sfSprite_setPosition(t->duck[0].sprite.sprite, (sfVector2f){0, random});
    }
}

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

    if (firstpass) {
        t->anima.clock = sfClock_create();
    }
    t->anima.time = sfClock_getElapsedTime(t->anima.clock);
    t->anima.seconds = t->anima.time.microseconds / 1000000.0;
    if (t->anima.seconds > FRAME_BY_S) {
        move_rect(t);
        sfClock_restart(t->anima.clock);
    }
    sfSprite_setTextureRect(t->duck[0].sprite.sprite, t->anima.rect);
    firstpass = false;
}

void display_duck(game_t *t)
{
    static bool firstpass = true;

    t->duck[0].sprite.sprite = t->sprite[7]->sprite;
    t->duck[0].pos = (sfVector2f){0, 50};
    t->duck[0].scale = (sfVector2f){1, 1};
    sfSprite_setScale(t->duck[0].sprite.sprite, t->duck[0].scale);
    if (firstpass) {
        sfSprite_setPosition(t->duck[0].sprite.sprite, t->duck[0].pos);
    }
    sfRenderWindow_drawSprite(t->window, t->sprite[0]->sprite, NULL);
    sfRenderWindow_drawSprite(t->window, t->sprite[7]->sprite, NULL);
    sfSprite_move(t->sprite[7]->sprite, (sfVector2f){0.7, -0.2});
    clock(t);
    collision_spawn(t);
    firstpass = false;
}

void duck(game_t *t)
{
    display_duck(t);
    display_score(&t->score, t);
}
