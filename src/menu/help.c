/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** help.c
*/

#include "../rpg.h"
#include "../include/menu.h"

void init_help(Global_t *m)
{
    time_t rawtime;
    struct tm *timeinfo;
    char *map = "assets/loading/back.png";

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    if (timeinfo->tm_hour >= 20 || timeinfo->tm_hour < 10)
        m->help.hub = init_sprite("maps/map_nblurr.png", (sfVector2f){0, 0});
    else
        m->help.hub = init_sprite(map, (sfVector2f){0, 0});
    m->help.combat = init_sprite("assets/menu/option.png", (sfVector2f){0, 0});
    m->help.key_h = init_sprite("assets/menu/key_h.png", (sfVector2f){0, 0});
    m->help.key_c = init_sprite("assets/menu/key_c.png", (sfVector2f){0, 0});
    m->help.exit = init_b_s(m, (sfVector2f){120, 60}, (sfVector2f){100, 70});
    m->help.text_exit = init_t_s(m, "back", 50, (sfVector2f){95, 40});
    m->help.gb_exit = sfRectangleShape_getGlobalBounds(m->help.exit);
}

void draw_help(Global_t *m)
{
    if (m->current == 22 || m->current == 23) {
        hover(m, m->help.exit, &m->help.gb_exit);
        if (m->current == 22)
            click(m, &m->help.gb_exit, 20);
        if (m->current == 23)
            click(m, &m->help.gb_exit, 21);
        if (m->current == 22) {
            sfRenderWindow_drawSprite(m->window, m->help.hub, NULL);
            sfRenderWindow_drawSprite(m->window, m->help.key_h, NULL);
        }
        if (m->current == 23) {
            sfRenderWindow_drawSprite(m->window, m->help.combat, NULL);
            sfRenderWindow_drawSprite(m->window, m->help.key_c, NULL);
        }
        sfRenderWindow_drawRectangleShape(m->window, m->help.exit, NULL);
        sfRenderWindow_drawText(m->window, m->help.text_exit, NULL);
    }
}

void destroy_help(Global_t *m)
{
    sfSprite_destroy(m->help.hub);
    sfSprite_destroy(m->help.combat);
    sfSprite_destroy(m->help.key_h);
    sfSprite_destroy(m->help.key_c);
    sfRectangleShape_destroy(m->help.exit);
    sfText_destroy(m->help.text_exit);
}
