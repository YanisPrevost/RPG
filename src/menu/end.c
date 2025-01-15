/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** end.c
*/

#include "../rpg.h"
#include "../include/menu.h"

void init_end(Global_t *m)
{
    m->end.fond = init_sprite("assets/menu/end.png", (sfVector2f){0, 0});
    m->end.button1 = init_b_s(m, (sfVector2f){450, 75},
    (sfVector2f){-200, -100});
    m->end.button2 = init_b_s(m, (sfVector2f){450, 75},
    (sfVector2f){-200, 100});
    m->end.text1 = init_t_s(m, "RETRY", 60, (sfVector2f){-205, -133});
    m->end.text2 = init_t_s(m, "RETURN LOBBY", 60, (sfVector2f){-205, 67});
    m->end.gb_b1 = sfRectangleShape_getGlobalBounds(m->end.button1);
    m->end.gb_b2 = sfRectangleShape_getGlobalBounds(m->end.button2);
    m->end.win = init_text(m, "YOU WIN", 200, 50);
    m->end.loose = init_text(m, "YOU LOOSE", 200, 50);
}

static void check_hover(Global_t *m)
{
    hover(m, m->end.button2, &m->end.gb_b2);
    if (sfFloatRect_contains(&m->end.gb_b2, m->mouse.x, m->mouse.y))
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_pause(m->setting.music);
            sfMusic_play(m->hub.music);
            m->current = 0;
        }
    if (m->current == 25) {
        hover(m, m->end.button1, &m->end.gb_b1);
        click(m, &m->end.gb_b1, m->current_combat);
        reset_stats_end(m);
        m->current_map = m->old_map;
    }
}

void draw_end(Global_t *m, hub_t *h)
{
    if (m->current == 24 || m->current == 25) {
        check_hover(m);
        sfRenderWindow_setView(m->window, m->hub.normal_view);
        sfRenderWindow_drawSprite(m->window, m->end.fond, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->end.button2, NULL);
        sfRenderWindow_drawText(m->window, m->end.text2, NULL);
        if (m->current == 24)
            sfRenderWindow_drawText(m->window, m->end.win, NULL);
        if (m->current == 25) {
            sfRenderWindow_drawText(m->window, m->end.loose, NULL);
            sfRenderWindow_drawRectangleShape(m->window, m->end.button1, NULL);
            sfRenderWindow_drawText(m->window, m->end.text1, NULL);
        }
    }
}

void destroy_end(Global_t *m)
{
    sfSprite_destroy(m->end.fond);
    sfRectangleShape_destroy(m->end.button1);
    sfRectangleShape_destroy(m->end.button2);
    sfText_destroy(m->end.text1);
    sfText_destroy(m->end.text2);
    sfText_destroy(m->end.win);
    sfText_destroy(m->end.loose);
}
