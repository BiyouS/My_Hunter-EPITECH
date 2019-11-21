/*
** EPITECH PROJECT, 2019
** header
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_

#define IS_NUM(c) (c >= '0' && c <= '9')
#define IS_OPE(C) ((C >= '(' && C <= '+') || C == '-' || C == '/')
#define POS_X (event.x >= 330 && event.x <= 660)
#define POS_Y (event.y >= 200 && event.y <= 260)


#include "structs.h"

void credits(game_t *t);
void duck(game_t *t);
void game(game_t *t);
sprite_t **create_sprite_array(void);
int analyse_events_menu(game_t *t);
void destroy(sfRenderWindow *wi, sfTexture *tex, sfSprite *spt, sfSprite *spt2);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);

#endif /* MY_H_  */