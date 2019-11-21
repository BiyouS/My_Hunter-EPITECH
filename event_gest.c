/*
** EPITECH PROJECT, 2019
** eventgest
** File description:
** gestion events
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include "include/my.h"
#include "include/structs.h"

void close_window(game_t *t)
{
    sfRenderWindow_close(t->window);
}

bool check_collision(button_t *b, game_t *t)
{
    b->hitbox = sfSprite_getGlobalBounds(b->sprite->sprite);
    if (F_RECT(&b->hitbox, t->mouse_evt.x, t->mouse_evt.y) == sfTrue)
        return (true);
    return (false);
}

int analyse_events_menu(game_t *t)
{
    if (t->event.type == sfEvtKeyReleased)
        my_putstr("CLAVIER");
    for (int i = 0; i < 3; i++) {
        if (t->event.type == sfEvtMouseButtonReleased) {
            t->mouse_evt = t->event.mouseButton;
            t->scene = (C_COL(&t->button[i], t)) ? i : (t->scene);
        }
    }
    if (t->event.type == sfEvtClosed)
        close_window(t);
    return 0;
}
