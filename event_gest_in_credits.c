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

static void close_window(game_t *t)
{
    sfRenderWindow_close(t->window);
}

int analyse_events_credits(game_t *t)
{
    sfMusic_stop(t->menu.music_2);
    if (t->event.type == sfEvtClosed)
        close_window(t);
    return 0;
}
