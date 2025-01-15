/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** menu_option_combat.c
*/

#include "../rpg.h"
#include "../include/menu.h"

void return_and_old_current2(Global_t *m, int value)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        m->old_current = value;
        m->current = 21;
    }
}

static void check_globalbounds(Global_t *m)
{
    m->o2.gb_b1 = sfRectangleShape_getGlobalBounds(m->o2.button1);
    m->o2.gb_b2 = sfRectangleShape_getGlobalBounds(m->o2.button2);
    m->o2.gb_b3 = sfRectangleShape_getGlobalBounds(m->o2.button3);
    m->o2.gb_b4 = sfRectangleShape_getGlobalBounds(m->o2.button4);
}

void init_menu_option_combat(Global_t *m)
{
    m->o2.fond = init_sprite("assets/menu/option.png", (sfVector2f){0, 0});
    m->o2.button1 = init_button(m, (sfVector2f){325, 100}, 295);
    m->o2.button2 = init_button(m, (sfVector2f){325, 100}, 445);
    m->o2.button3 = init_button(m, (sfVector2f){325, 100}, 595);
    m->o2.button4 = init_button(m, (sfVector2f){490, 100}, 745);
    m->o2.text1 = init_text(m, "RESUME", 60, 300);
    m->o2.text2 = init_text(m, "HELP", 60, 450);
    m->o2.text3 = init_text(m, "SETTINGS", 60, 600);
    m->o2.text4 = init_text(m, "RETURN LOBBY", 60, 750);
    check_globalbounds(m);
}

static void check_hover2(Global_t *m)
{
    hover(m, m->o2.button3, &m->o2.gb_b3);
    if (sfFloatRect_contains(&m->o2.gb_b3, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->old_current = m->current;
            m->current = 13;
            init_setting(m);
        }
    }
    hover(m, m->o2.button4, &m->o2.gb_b4);
    if (sfFloatRect_contains(&m->o2.gb_b4, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            usleep(1000000);
            sfMusic_pause(m->setting.music);
            sfMusic_play(m->hub.music);
            reset_stats_end(m);
            m->current = 0;
        }
    }
}

static void check_hover(Global_t *m, hub_t *h)
{
    hover(m, m->o2.button1, &m->o2.gb_b1);
    click(m, &m->o2.gb_b1, m->current_combat);
    hover(m, m->o2.button2, &m->o2.gb_b2);
    click(m, &m->o2.gb_b2, 23);
    check_hover2(m);
}

void draw_menu_option_combat(Global_t *m, hub_t *h)
{
    if (m->current == 21) {
        check_hover(m, h);
        sfRenderWindow_setView(m->window, m->hub.normal_view);
        sfRenderWindow_drawSprite(m->window, m->o2.fond, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->o2.button1, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->o2.button2, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->o2.button3, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->o2.button4, NULL);
        sfRenderWindow_drawText(m->window, m->o2.text1, NULL);
        sfRenderWindow_drawText(m->window, m->o2.text2, NULL);
        sfRenderWindow_drawText(m->window, m->o2.text3, NULL);
        sfRenderWindow_drawText(m->window, m->o2.text4, NULL);
    }
}

void destroy_menu_option_combat(Global_t *m)
{
    sfSprite_destroy(m->o2.fond);
    sfRectangleShape_destroy(m->o2.button1);
    sfRectangleShape_destroy(m->o2.button2);
    sfRectangleShape_destroy(m->o2.button3);
    sfRectangleShape_destroy(m->o2.button4);
    sfText_destroy(m->o2.text1);
    sfText_destroy(m->o2.text2);
    sfText_destroy(m->o2.text3);
    sfText_destroy(m->o2.text4);
}
