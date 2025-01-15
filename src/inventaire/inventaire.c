/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory.c
*/

#include "../my.h"
#include "../rpg.h"
#include "../include/perso.h"

static void inventaire2(Global_t *m)
{
    sfRenderWindow *w = m->window;
    sfRectangleShape *hoo = m->perso->inv.inv_sprite.hooved_weapon;
    sfRectangleShape *inv_rect = m->perso->inv.inv_sprite.rect_inv;

    sfRenderWindow_drawSprite(w, m->perso->inv.inv_sprite.inventory2, NULL);
    equiped_weapon(m, m->perso->current_perso);
    weapons_inv_stat(m);
    sfRenderWindow_drawSprite(w, m->perso->inv.inv_sprite.cursor, NULL);
    sfRenderWindow_drawRectangleShape(w, hoo, NULL);
    sfRenderWindow_drawRectangleShape(w, inv_rect, NULL);
}

static void inventaire1(Global_t *m)
{
    sfSprite *inv1 = m->perso->inv.inv_sprite.inventory;
    sfRectangleShape *rect_inv = m->perso->inv.inv_sprite.rect_inv;

    m->show_mouse = false;
    sfRenderWindow_drawSprite(m->window, m->perso->inv.inv_sprite.fond, NULL);
    sfRenderWindow_drawSprite(m->window, inv1, NULL);
    set_sprite_head_name(m, m->perso->current_perso);
    set_text_lvl_xd(m, m->perso->current_perso);
    set_sprite_mini(m, m->perso->current_perso);
    set_text_health(m, m->perso->current_perso);
    set_others_stats(m, m->perso->current_perso);
    sfRenderWindow_drawRectangleShape(m->window, rect_inv, NULL);
}

void draw_inventaire(Global_t *m, hub_t *hub)
{
    if (m->current >= 0 && m->current <= 8) {
        sfRenderWindow_setView(m->window, m->hub.normal_view);
        if (m->perso->is_visible) {
            swap_current(m);
            inventaire1(m);
        }
        if (m->perso->is_visible2) {
            swap_current(m);
            inventaire2(m);
        }
        if (!m->perso->is_visible && !m->perso->is_visible2) {
            m->show_mouse = true;
        }
    }
}

static void reset(Global_t *m)
{
    m->perso->is_visible = false;
    m->perso->is_visible2 = false;
    m->perso->what_weapons_stat = 0;
    m->perso->inv.inv_sprite.pos_cursor.x = 940;
    m->perso->inv.inv_sprite.pos_hooved.x = 980;
    m->perso->inv.inv_sprite.pos_cursor.y = 443;
    m->perso->inv.inv_sprite.pos_hooved.y = 443;
    m->perso->current_perso = m->perso->first_current_perso;
}

void what_inv2(Global_t *m, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && m->perso->is_visible2) {
        m->perso->is_visible = true;
        m->perso->is_visible2 = false;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && !m->perso->is_visible
    && m->perso->is_visible2) {
        m->perso->is_visible2 = false;
        m->perso->is_visible = true;
        return;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI)
        reset(m);
}

void what_inv(Global_t *m, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI &&
    !m->perso->is_visible && !m->perso->is_visible2) {
        m->perso->is_visible = true;
        m->perso->is_visible2 = false;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && m->perso->is_visible &&
    !m->perso->is_visible2) {
        m->perso->is_visible2 = true;
        return;
    }
    what_inv2(m, event);
}

static void moove_cursor_weapons(Global_t *m)
{
    sfRectangleShape *rect = m->perso->inv.inv_sprite.hooved_weapon;
    sfSprite *cursor = m->perso->inv.inv_sprite.cursor;

    if (m->perso->inv.inv_sprite.pos_hooved.y < 559) {
        m->perso->inv.inv_sprite.pos_cursor.y += 38;
        m->perso->inv.inv_sprite.pos_hooved.y += 38;
    } else {
        m->perso->inv.inv_sprite.pos_cursor.y = 443;
        m->perso->inv.inv_sprite.pos_hooved.y = 443;
    }
    sfSprite_setPosition(cursor, m->perso->inv.inv_sprite.pos_cursor);
    sfRectangleShape_setPosition(rect, m->perso->inv.inv_sprite.pos_hooved);
}

static void keydown(Global_t *m)
{
    m->perso->what_weapons_stat += 1;
    moove_cursor_weapons(m);
        if (m->perso->what_weapons_stat >= 5)
    m->perso->what_weapons_stat = 0;
}

static void print_sprite(Global_t *m)
{
    sfVector2f p_ho_w = {980, 443};
    sfVector2f s_ho_w = {330, 16 * 1.8};
    sfVector2f p_rct_inv = {600, 300};
    sfVector2f s_rct_inv = {755, 500};
    sfSprite *sprite = m->perso->inv.inv_sprite.fond;
    sfTexture *Fond = m->perso->inv.inv_sprite.Fond;

    sfSprite_setTexture(sprite, Fond, sfFalse);
    m->perso->inv.inv_sprite.inventory = set_inv_fond(m);
    m->perso->inv.inv_sprite.inventory2 = set_inv_fond2(m);
    m->perso->inv.inv_sprite.cursor = set_cursor(m);
    m->perso->inv.inv_sprite.hooved_weapon = hoov_w(m, p_ho_w, s_ho_w, 2);
    m->perso->inv.inv_sprite.rect_inv = hoov_inv(m, p_rct_inv, s_rct_inv, 7);
}

int inventory(Global_t *m, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyI) ||
    sfKeyboard_isKeyPressed(sfKeyLeft) ||
    sfKeyboard_isKeyPressed(sfKeyRight) ||
    sfKeyboard_isKeyPressed(sfKeyDown)) {
        print_sprite(m);
        what_inv(m, event);
        if (sfKeyboard_isKeyPressed(sfKeyDown))
            keydown(m);
    }
    return 0;
}
