/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** struct for grahics program
*/

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <stdbool.h>
#include <SFML/Graphics/RenderWindow.h>

#define C_COL(b, t) (check_collision(b, t))
#define F_RECT(b, t, c) (sfFloatRect_contains(b, t, c))

typedef struct sprite {
    sfTexture *texture;
    sfSprite *sprite;
} sprite_t;

typedef struct anima {
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
}anima_t;

typedef struct duck {
    sfVector2f pos;
    sfVector2f scale;
    sfSprite *sprite;
}duck_t;

typedef struct credits {
    sfVector2f pos;
    sfVector2f scale;
    sprite_t *sprite;
    sfCursorType cursor;
}credits_t;

typedef struct button {
    sfVector2f pos;
    sfVector2f scale;
    sprite_t *sprite;
    sfFloatRect hitbox;
}button_t;

typedef struct tools {
    sfVideoMode mode;
    sfEvent event;
    sfMouseButtonEvent mouse_evt;
    sfRenderWindow *window;
    sprite_t **sprite;
    sfVector2f origin;
    int scene;
    int quit;
    button_t button[3];
    credits_t credits;
    duck_t duck;
    anima_t anima;
}game_t;

#endif /* _STRUCTS_H_ */
