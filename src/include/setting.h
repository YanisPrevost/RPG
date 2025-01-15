/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** setting.h
*/
#include "../my.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>

#ifndef SETTING_H
    #define SETTING_H

typedef struct setting {
    sfFont *font;
    sfFont *special_font;
    sfVector2u window_size;
    sfSprite *background_s;
    sfText *titre;
    sfText *credit;
    sfText *synopsis;

    sfText *volumetxt;
    sfText *volumehaut;
    sfText *volumebas;
    sfText *volumecoupe;

    sfText *retour;

    sfText *sizewindows;
    sfText *littlez;
    sfText *mediumz;
    sfText *bigz;
    sfText *test;
    sfText *txtcredit;

    sfText *volumeb;
    sfText *volumeh;
    sfText *cvolume;

    sfText *creditpara;
    sfRectangleShape *creditrect;
    sfText *synopsypara;

    sfRectangleShape *buttonsynop;
    sfRectangleShape *buttoncred;
    sfRectangleShape *buttonvolum;
    sfRectangleShape *buttonretour;
    sfRectangleShape *buttonwindow;

    sfRectangleShape *coversynop;
    sfRectangleShape *covercredit;

    bool displaySizeOptions;
    bool volumeclicked;
    bool creditbool;
    bool back;
    bool synopbool;

    sfFloatRect se_1;
    sfFloatRect se_2;
    sfFloatRect se_3;
    sfFloatRect se_4;
    sfFloatRect se_5;
    sfFloatRect se_6;
    sfFloatRect se_7;
    sfFloatRect se_8;
    sfFloatRect se_9;
    sfFloatRect se_10;
    sfFloatRect se_11;

    sfVector2i mouse;
    sfFloatRect creditBounds;

    sfFont* fontdi;
    sfMusic *music;
} Setting_t;

#endif
