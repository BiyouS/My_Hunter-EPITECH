/*
** EPITECH PROJECT, 2019
** game
** File description:
** game.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include "include/my.h"
#include "include/structs.h"

extern const unsigned int WIN_W;
extern const unsigned int WIN_H;
extern const int NB_ASSETS;

void position_button(game_t *t, int i)
{
    sfVector2u vec_origin = sfTexture_getSize(t->button[i].sprite->texture);

    t->origin = (sfVector2f){vec_origin.x / 2, vec_origin.y / 2};
    t->button[i].pos = (sfVector2f){WIN_W / 2, WIN_H * ((i + 2.5f) / 5.5f)};
    t->button[i].scale = (sfVector2f){4, 4};
    sfSprite_setOrigin(t->button[i].sprite->sprite, t->origin);
    sfSprite_setScale(t->button[i].sprite->sprite, t->button[i].scale);
    sfSprite_setPosition(t->button[i].sprite->sprite, t->button[i].pos);
}

void display_sprite(game_t *t)
{
    t->menu.sprite = t->sprite[0];
    for (int i = 0; i < 3; i++) {
        position_button(t, i);
        sfRenderWindow_drawSprite(t->window, t->menu.sprite->sprite, NULL);
    }
    for (int i = 0; i < 3; i++) {
        t->button[i].scale = (sfVector2f){0.5, 0.5};
        t->button[i].sprite = t->sprite[1 + i];
    }
    for (int i = 1; i < 4; i++)
        sfRenderWindow_drawSprite(t->window, t->sprite[i]->sprite, NULL);
}

void scene(game_t *t)
{
    if (t->scene == 0)
        duck(t);
    if (t->scene == 1)
        credits(t);
    if (t->scene == 2)
        t->quit = 1;
    if (t->scene == 3) {
        display_sprite(t);
        display_anima_title(t);
    }
}

void event(game_t *t)
{
    while (sfRenderWindow_pollEvent(t->window, &t->event)) {
        if (t->scene == 3)
            analyse_events_menu(t);
        if (t->scene == 0)
            analyse_events_game(t);
        if (t->scene == 1)
            analyse_events_credits(t);
    }
}

void game(game_t *t)
{
    char *stl = "My_Hunter";

    t->mode = (sfVideoMode){WIN_W, WIN_H, 32};
    t->window = sfRenderWindow_create(t->mode, stl, sfDefaultStyle, NULL);
    t->sprite = create_sprite_array();
    init_sprite(t);
    while (sfRenderWindow_isOpen(t->window)) {
        sfRenderWindow_clear(t->window, sfBlack);
        event(t);
        scene(t);
        sfRenderWindow_display(t->window);
        if (t->quit == 1) {
            sfRenderWindow_destroy(t->window);
            return;
        }
    }
    sfRenderWindow_destroy(t->window);
}
