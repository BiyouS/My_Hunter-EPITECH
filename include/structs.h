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
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

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

typedef struct score {
    int point;
    int bonus;
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfVector2f scale;
    sfMusic *music;
}score_t;

typedef struct duck {
    sfVector2f pos;
    sfVector2f scale;
    sprite_t sprite;
    sfFloatRect hitbox;
}duck_t;

typedef struct title {
    sfVector2f pos;
    sfVector2f scale;
    sprite_t sprite;
}title_t;

typedef struct menu {
    sfVector2f pos;
    sfVector2f scale;
    sprite_t *sprite;
    sfMusic *music_1;
    sfMusic *music_2;
}menu_t;

typedef struct credits {
    sfVector2f pos;
    sfVector2f scale;
    sprite_t *sprite;
}credits_t;

typedef struct button {
    sfVector2f pos;
    sfVector2f scale;
    sprite_t *sprite;
    sfFloatRect hitbox;
}button_t;

typedef struct tools {
    sfCursorType cursor;
    sfVideoMode mode;
    sfEvent event;
    sfMouseButtonEvent mouse_evt;
    sfRenderWindow *window;
    sprite_t **sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f origin;
    int scene;
    int quit;
    button_t button[3];
    credits_t credits;
    duck_t duck[5];
    menu_t menu;
    anima_t anima;
    anima_t anima_title;
    title_t title;
    score_t score;
    sfMusic *music_3;
}game_t;

#endif /* _STRUCTS_H_ */
