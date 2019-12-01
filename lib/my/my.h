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
#define RAND (get_rnd_nbr)
#define COLOR_ALEA (sfColor_fromRGB(RAND(0, 255), RAND(0, 255), RAND(0, 255))
#define AS_1 "Assets/img/Menu.png", "Assets/img/Button_Jouer.png"
#define AS_2 "Assets/img/Button_Credits.png", "Assets/img/Button_Exit.png"
#define AS_3 "Assets/img/Credits.png", "Assets/img/Title.png"
#define AS_4 "Assets/img/Kwak/Kwak.png", "Assets/img/Kwak/Kwak_1.png"
#define AS_5 "Assets/img/Kwak/Kwak_2.png", "Assets/img/Kwak/Kwak_3.png"
#define AS_6 "Assets/img/Kwak/Kwak_4.png", NULL


#include "structs.h"


void init_sprite(game_t *t);
int my_digitlen(int digit);
char *int_to_str(char *str, int nb);
int my_number_len(int nb);
int get_rnd_nbr(unsigned int min, unsigned int max);
void display_score(score_t *s, game_t *t);
void display_anima_title(game_t *t);
void credits(game_t *t);
void duck(game_t *t);
void game(game_t *t);
sprite_t **create_sprite_array(void);
int analyse_events_menu(game_t *t);
int analyse_events_credits(game_t *t);
int analyse_events_game(game_t *t);
void destroy(sfRenderWindow *wi, sfTexture *tex, sfSprite *spt, sfSprite *spt2);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);

#endif /* MY_H_  */
