/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <SFML/Graphics.h>

void big_size(sfVector2i mu, Global_t *m)
{
    sfVideoMode mode;

    mode.width = 1920;
    mode.height = 1080;
    mode.bitsPerPixel = 32;
    sfRenderWindow_close(m->window);
    m->window = sfRenderWindow_create(mode, "MY_RPG", sfResize |
    sfClose, NULL);
    sfMouse_setPositionRenderWindow((sfVector2i){mu.x, mu.y}, m->window);
}

void mid_size(sfVector2i mu, Global_t *m)
{
    sfVideoMode mode;

    mode.width = 1280;
    mode.height = 720;
    mode.bitsPerPixel = 32;
    sfRenderWindow_close(m->window);
    m->window = sfRenderWindow_create(mode, "MY_RPG", sfResize |
    sfClose, NULL);
    sfMouse_setPositionRenderWindow((sfVector2i){mu.x, mu.y}, m->window);
}

void diff_size(sfVector2i mu, Global_t *m)
{
    sfFloatRect bigzBounds = sfText_getGlobalBounds(m->setting.bigz);
    sfFloatRect mediumzBounds = sfText_getGlobalBounds(m->setting.mediumz);
    sfFloatRect littlezBounds = sfText_getGlobalBounds(m->setting.littlez);
    sfVideoMode mode;

    if (sfFloatRect_contains(&littlezBounds, mu.x, mu.y)) {
        mode = sfVideoMode_getDesktopMode();
        sfRenderWindow_close(m->window);
        m->window = sfRenderWindow_create(mode, "MY_RPG", sfFullscreen, NULL);
        sfMouse_setPositionRenderWindow((sfVector2i){mu.x, mu.y}, m->window);
    }
    if (sfFloatRect_contains(&mediumzBounds, mu.x, mu.y)) {
        mid_size(mu, m);
    }
    if (sfFloatRect_contains(&bigzBounds, mu.x, mu.y))
        big_size(mu, m);
}

void modify_size(sfVector2i mouse, Global_t *m)
{
    if (m->setting.displaySizeOptions) {
        diff_size(mouse, m);
    }
}

static void modify_song(sfVector2i mouse, Global_t *m)
{
    if (m->setting.displaySizeOptions) {
        verif_song(mouse, m);
    }
}

static void other_option(sfVector2i mouse, Global_t *m)
{
    sfFloatRect crb = sfRectangleShape_getGlobalBounds(m->setting.buttoncred);
    sfFloatRect rt = sfRectangleShape_getGlobalBounds(m->setting.buttonretour);
    sfFloatRect bsy = sfRectangleShape_getGlobalBounds(m->setting.buttonsynop);

    if (sfFloatRect_contains(&crb, mouse.x, mouse.y))
        m->setting.creditbool = !m->setting.creditbool;
    if (sfFloatRect_contains(&bsy, mouse.x, mouse.y))
        m->setting.synopbool = !m->setting.synopbool;
    if (sfFloatRect_contains(&rt, mouse.x, mouse.y)){
        m->current = m->old_current;
        destroy_all(m);
    }
}

void event_setting(sfEvent event, Global_t *m)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect sizb =
    sfRectangleShape_getGlobalBounds(m->setting.buttonwindow);
    sfFloatRect volboun =
    sfRectangleShape_getGlobalBounds(m->setting.buttonvolum);

    if (event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&sizb, mouse.x, mouse.y))
            m->setting.displaySizeOptions = !m->setting.displaySizeOptions;
        if (sfFloatRect_contains(&volboun, mouse.x, mouse.y))
            m->setting.volumeclicked = !m->setting.volumeclicked;
        other_option(mouse, m);
        modify_size(mouse, m);
        modify_song(mouse, m);
    }
}
