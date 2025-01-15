/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** perso.c
*/
#include "../rpg.h"
#include "../include/menu.h"

static void roy_select(Global_t *m)
{
    sfColor color = sfColor_fromRGB(153, 112, 29);

    if (sfFloatRect_contains(&m->s.gb_b1, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->s.p1_select = 1;
            sfRectangleShape_setFillColor(m->s.button1, color);
            m->perso->current_perso = ROY;
            m->perso->first_current_perso = ROY;
        }
    }
    if (m->s.p1_select == 1) {
        sfRenderWindow_drawSprite(m->window, m->s.p1_w, NULL);
        sfRenderWindow_drawSprite(m->window, m->s.p1_d, NULL);
        m->s.p2_select = 0;
        m->s.p3_select = 0;
        m->s.p4_select = 0;
        m->s.p5_select = 0;
    }
}

static void xmarano_select(Global_t *m)
{
    sfColor color = sfColor_fromRGB(153, 112, 29);

    if (sfFloatRect_contains(&m->s.gb_b2, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->s.p2_select = 1;
            sfRectangleShape_setFillColor(m->s.button2, color);
            m->perso->current_perso = XMARANO;
            m->perso->first_current_perso = XMARANO;
        }
    }
    if (m->s.p2_select == 1) {
        sfRenderWindow_drawSprite(m->window, m->s.p2_w, NULL);
        sfRenderWindow_drawSprite(m->window, m->s.p2_d, NULL);
        m->s.p1_select = 0;
        m->s.p3_select = 0;
        m->s.p4_select = 0;
        m->s.p5_select = 0;
    }
}

static void patecarbo_select(Global_t *m)
{
    sfColor color = sfColor_fromRGB(153, 112, 29);

    if (sfFloatRect_contains(&m->s.gb_b3, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->s.p3_select = 1;
            sfRectangleShape_setFillColor(m->s.button3, color);
            m->perso->current_perso = PATECARBO;
            m->perso->first_current_perso = PATECARBO;
        }
    }
    if (m->s.p3_select == 1) {
        sfRenderWindow_drawSprite(m->window, m->s.p3_w, NULL);
        sfRenderWindow_drawSprite(m->window, m->s.p3_d, NULL);
        m->s.p1_select = 0;
        m->s.p2_select = 0;
        m->s.p4_select = 0;
        m->s.p5_select = 0;
    }
}

static void infenium_select(Global_t *m)
{
    sfColor color = sfColor_fromRGB(153, 112, 29);

    if (sfFloatRect_contains(&m->s.gb_b4, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->s.p4_select = 1;
            sfRectangleShape_setFillColor(m->s.button4, color);
            m->perso->current_perso = INFENIUM;
            m->perso->first_current_perso = INFENIUM;
        }
    }
    if (m->s.p4_select == 1) {
        sfRenderWindow_drawSprite(m->window, m->s.p4_w, NULL);
        sfRenderWindow_drawSprite(m->window, m->s.p4_d, NULL);
        m->s.p1_select = 0;
        m->s.p2_select = 0;
        m->s.p3_select = 0;
        m->s.p5_select = 0;
    }
}

static void racaillou_select(Global_t *m)
{
    sfColor color = sfColor_fromRGB(153, 112, 29);

    if (sfFloatRect_contains(&m->s.gb_b5, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->s.p5_select = 1;
            sfRectangleShape_setFillColor(m->s.button5, color);
            m->perso->current_perso = RACAILLOU;
            m->perso->first_current_perso = RACAILLOU;
        }
    }
    if (m->s.p5_select == 1) {
        sfRenderWindow_drawSprite(m->window, m->s.p5_w, NULL);
        sfRenderWindow_drawSprite(m->window, m->s.p5_d, NULL);
        m->s.p1_select = 0;
        m->s.p2_select = 0;
        m->s.p3_select = 0;
        m->s.p4_select = 0;
    }
}

static void all_deselect(Global_t *m)
{
    m->s.p1_select = 0;
    m->s.p2_select = 0;
    m->s.p3_select = 0;
    m->s.p4_select = 0;
    m->s.p5_select = 0;
}

static void hover_select2(Global_t *m)
{
    if (sfFloatRect_contains(&m->s.gb_play, m->mouse.x, m->mouse.y))
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_pause(m->menu.music);
            sfMusic_play(m->hub.music);
            m->current = 14;
        }
    hover(m, m->s.back, &m->s.gb_back);
    if (sfFloatRect_contains(&m->s.gb_back, m->mouse.x, m->mouse.y))
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->current = 10;
            all_deselect(m);
        }
}

void check_hover_select(Global_t *m)
{
    hover(m, m->s.button1, &m->s.gb_b1);
    roy_select(m);
    hover(m, m->s.button2, &m->s.gb_b2);
    xmarano_select(m);
    hover(m, m->s.button3, &m->s.gb_b3);
    patecarbo_select(m);
    hover(m, m->s.button4, &m->s.gb_b4);
    infenium_select(m);
    hover(m, m->s.button5, &m->s.gb_b5);
    racaillou_select(m);
    hover(m, m->s.play, &m->s.gb_play);
    hover_select2(m);
}
