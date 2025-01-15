/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <SFML/Graphics.h>

void text_setting(Global_t *m)
{
    sfRenderWindow_drawText(m->window, m->setting.titre, NULL);
    sfRenderWindow_drawText(m->window, m->setting.synopsis, NULL);
    sfRenderWindow_drawText(m->window, m->setting.volumetxt, NULL);
    sfRenderWindow_drawText(m->window, m->setting.credit, NULL);
    sfRenderWindow_drawText(m->window, m->setting.volumetxt, NULL);
    sfRenderWindow_drawText(m->window, m->setting.retour, NULL);
    sfRenderWindow_drawText(m->window, m->setting.sizewindows, NULL);
}

void draw_setting(Global_t *m)
{
    if (m->current == 13) {
        check_the_hover2(m);
        sfRenderWindow_drawSprite(m->window,
        m->setting.background_s, NULL);
        sfRenderWindow_drawRectangleShape(m->window,
        m->setting.buttonsynop, NULL);
        sfRenderWindow_drawRectangleShape(m->window,
        m->setting.buttoncred, NULL);
        sfRenderWindow_drawRectangleShape(m->window,
        m->setting.buttonvolum, NULL);
        sfRenderWindow_drawRectangleShape(m->window,
        m->setting.buttonretour, NULL);
        sfRenderWindow_drawRectangleShape(m->window,
        m->setting.buttonwindow, NULL);
        text_setting(m);
        verif_thing(m);
    }
}
