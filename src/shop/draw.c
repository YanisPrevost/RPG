/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** draw.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

void draw_plus(Global_t *m)
{
    sfRenderWindow *win = m->window;

    sfRenderWindow_drawSprite(win, m->weapons[LEGENDARY_SPEAR].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[LEGENDARY_AXE].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[THUNDER_BOOK].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[FIRE_BOOK].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[FREEZE_BOOK].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[POTION].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->shop.all_head, NULL);
    move_coin(m);
    sfRenderWindow_drawRectangleShape(m->window, m->shop.hooved, NULL);
    sfText_setString(m->shop.gold, my_inttostr(m->gold));
    sfRenderWindow_drawText(m->window, m->shop.gold, NULL);
    draw_stats_shop(m);
    sfRenderWindow_drawText(m->window, m->shop.text, NULL);
    sfRenderWindow_drawSprite(m->window, m->shop.cursor, NULL);
}

void draw_all_shop(Global_t *m)
{
    sfRenderWindow *win = m->window;

    sfRenderWindow_drawSprite(win, m->shop.fond, NULL);
    sfRenderWindow_drawSprite(win, m->shop.shop, NULL);
    sfRenderWindow_drawSprite(win, m->shop.contour, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[COMMON_SWORD].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[COMMON_BOW].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[COMMON_SPEAR].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[COMMON_AXE].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[RARE_SWORD].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[RARE_BOW].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[RARE_SPEAR].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[RARE_AXE].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[LEGENDARY_SWORD].sprite, NULL);
    sfRenderWindow_drawSprite(win, m->weapons[LEGENDARY_BOW].sprite, NULL);
}

static void moove(Global_t *m)
{
    if (m->shop.is_select == true) {
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
            move_hover_rect(m, sfKeyLeft);
        if (sfKeyboard_isKeyPressed(sfKeyRight))
            move_hover_rect(m, sfKeyRight);
        if (sfKeyboard_isKeyPressed(sfKeyUp))
            move_hover_rect(m, sfKeyUp);
        if (sfKeyboard_isKeyPressed(sfKeyDown))
            move_hover_rect(m, sfKeyDown);
    }
}

void draw_shop(Global_t *m)
{
    if (m->current == 9) {
        draw_all_shop(m);
        draw_plus(m);
        if (sfKeyboard_isKeyPressed(sfKeyR))
            m->shop.is_select = false;
        if (m->shop.is_select == false)
            select_perso(m);
        moove(m);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            m->shop.is_select = -1;
            m->shop.is_lock = false;
            m->current = 0;
            sfSleep(sfSeconds(0.2));
        }
    }
}
