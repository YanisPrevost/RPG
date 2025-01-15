/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** menu.h
*/
#include "../my.h"
#include "../rpg.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>

#ifndef MENU_H
    #define MENU_H

typedef struct Help {
    sfSprite *hub;
    sfSprite *combat;
    sfSprite *key_h;
    sfSprite *key_c;
    sfRectangleShape *exit;
    sfFloatRect gb_exit;
    sfText *text_exit;
} Help_t;

typedef struct Menu {
    sfMusic* music;
    sfVector2u wsize;
    sfClock *save_auto_clk;
    sfSprite *map;
    sfSprite *lock;
    sfSprite *cursor;
    sfText *title;
    sfText *new_game;
    sfText *continuer;
    sfText *settings;
    sfText *exit;
    sfRectangleShape *button1;
    sfRectangleShape *button2;
    sfRectangleShape *button3;
    sfRectangleShape *button4;
    sfFloatRect gb_b1;
    sfFloatRect gb_b2;
    sfFloatRect gb_b3;
    sfFloatRect gb_b4;
    sfFloatRect text;
    sfText *save_txt;
} Menu_t;

typedef struct S {
    sfSprite *fond;
    sfText *title;
    sfSprite *p1;
    sfSprite *p2;
    sfSprite *p3;
    sfSprite *p4;
    sfSprite *p5;
    sfSprite *p1_w;
    sfSprite *p2_w;
    sfSprite *p3_w;
    sfSprite *p4_w;
    sfSprite *p5_w;
    sfSprite *p1_d;
    sfSprite *p2_d;
    sfSprite *p3_d;
    sfSprite *p4_d;
    sfSprite *p5_d;
    sfRectangleShape *button1;
    sfRectangleShape *button2;
    sfRectangleShape *button3;
    sfRectangleShape *button4;
    sfRectangleShape *button5;
    sfRectangleShape *play;
    sfRectangleShape *back;
    sfFloatRect gb_b1;
    sfFloatRect gb_b2;
    sfFloatRect gb_b3;
    sfFloatRect gb_b4;
    sfFloatRect gb_b5;
    sfFloatRect gb_play;
    sfFloatRect gb_back;
    sfText *play_txt;
    sfText *back_txt;
    sfText *select1;
    sfText *select2;
    sfText *select3;
    sfText *select4;
    sfText *select5;
    int p1_select;
    int p2_select;
    int p3_select;
    int p4_select;
    int p5_select;
} S_t;

typedef struct Option_hub {
    sfSprite *fond;
    sfRectangleShape *button1;
    sfRectangleShape *button2;
    sfRectangleShape *button3;
    sfRectangleShape *button4;
    sfRectangleShape *help;
    sfFloatRect gb_b1;
    sfFloatRect gb_b2;
    sfFloatRect gb_b3;
    sfFloatRect gb_b4;
    sfFloatRect gb_help;
    sfText *text1;
    sfText *text2;
    sfText *text2_1;
    sfText *text3;
    sfText *text4;
    sfText *text_help;
    int is_saved;
    int is_saved2;
    sfClock *txt_clock;
} Option_hub_t;

typedef struct Option_combat {
    sfSprite *fond;
    sfRectangleShape *button1;
    sfRectangleShape *button2;
    sfRectangleShape *button3;
    sfRectangleShape *button4;
    sfFloatRect gb_b1;
    sfFloatRect gb_b2;
    sfFloatRect gb_b3;
    sfFloatRect gb_b4;
    sfText *text1;
    sfText *text2;
    sfText *text3;
    sfText *text4;
} Option_combat_t;

typedef struct End {
    sfSprite *fond;
    sfRectangleShape *button1;
    sfRectangleShape *button2;
    sfFloatRect gb_b1;
    sfFloatRect gb_b2;
    sfText *text1;
    sfText *text2;
    sfText *win;
    sfText *loose;
} End_t;

#endif
