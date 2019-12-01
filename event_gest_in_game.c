/*
** EPITECH PROJECT, 2019
** eventgest
** File description:
** gestion events
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Text.h>
#include <stdbool.h>
#include "include/my.h"
#include "include/structs.h"

static bool check_collision(duck_t *d, game_t *t, int i)
{
    int random = get_rnd_nbr(1, 500);

    t->duck[i].sprite.sprite = t->sprite[i + 7]->sprite;
    d->hitbox = sfSprite_getGlobalBounds(t->duck[i].sprite.sprite);
    if (F_RECT(&d->hitbox, t->mouse_evt.x, t->mouse_evt.y) == sfTrue) {
        sfSprite_setPosition(t->duck[0].sprite.sprite, (sfVector2f){0, random});
        sfMusic_play(t->score.music);
        return (true);
    }
    sfMusic_play(t->score.music);
    return (false);
}

static void manage_events(game_t *t)
{
    t->mouse_evt = t->event.mouseButton;
    for (int i = 0; i < 4; i++) {
        t->score.point += (check_collision(&t->duck[i], t, i) == true) ? 10 : 0;
    }
    if (t->score.point >= 200) {
        t->scene = 3;
        t->score.point = 0;
    }
}

int analyse_events_game(game_t *t)
{
    sfMusic_stop(t->menu.music_2);
    if (t->event.type == sfEvtMouseButtonPressed)
        manage_events(t);
    if (t->event.type == sfEvtClosed)
        sfRenderWindow_close(t->window);
    return 0;
}
