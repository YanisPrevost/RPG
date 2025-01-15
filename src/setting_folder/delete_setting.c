/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <SFML/Graphics.h>

void destroy_all2(Global_t *m)
{
    sfText_destroy(m->setting.test);
    sfText_destroy(m->setting.txtcredit);
    sfText_destroy(m->setting.volumeb);
    sfText_destroy(m->setting.volumeh);
    sfText_destroy(m->setting.cvolume);
    sfText_destroy(m->setting.creditpara);
    sfRectangleShape_destroy(m->setting.creditrect);
    sfText_destroy(m->setting.synopsypara);
    sfRectangleShape_destroy(m->setting.buttonsynop);
    sfRectangleShape_destroy(m->setting.buttoncred);
    sfRectangleShape_destroy(m->setting.buttonvolum);
    sfRectangleShape_destroy(m->setting.buttonretour);
    sfRectangleShape_destroy(m->setting.buttonwindow);
    sfRectangleShape_destroy(m->setting.coversynop);
    sfRectangleShape_destroy(m->setting.covercredit);
}

void destroy_all(Global_t *m)
{
    sfSprite_destroy(m->setting.background_s);
    sfText_destroy(m->setting.titre);
    sfText_destroy(m->setting.credit);
    sfText_destroy(m->setting.synopsis);
    sfText_destroy(m->setting.volumetxt);
    sfText_destroy(m->setting.volumehaut);
    sfText_destroy(m->setting.volumebas);
    sfText_destroy(m->setting.volumecoupe);
    sfText_destroy(m->setting.retour);
    sfText_destroy(m->setting.sizewindows);
    sfText_destroy(m->setting.littlez);
    sfText_destroy(m->setting.mediumz);
    sfText_destroy(m->setting.bigz);
    destroy_all2(m);
}
