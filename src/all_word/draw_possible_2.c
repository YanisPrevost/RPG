/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** draw_possible_2.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

static int fast_check_ok(Global_t *m, int i, int dy, int dx)
{
    int ny = m->codi.pos_spr.y + dy;

    if (m->codi.nx == m->codi.pos_curs.x && ny == m->codi.pos_curs.y &&
        abs(dx) + abs(dy) <= i) {
        if (ligne_sans_obstacle((sfVector2i){m->codi.pos_spr.x + 1,
            m->codi.pos_spr.y + 1}, (sfVector2i){m->codi.pos_curs.x + 1,
            m->codi.pos_curs.y + 1}, m->current_map, m))
            return 0;
    }
    return 1;
}

static int is_moove_ok(Global_t *m, int dx, int i)
{
    int ny;

    for (int dy = -i; dy <= i; dy++) {
        ny = m->codi.pos_spr.y + dy;
        if (fast_check_ok(m, i, dy, dx) == 0)
            return 1;
    }
    return 0;
}

bool is_movement_ok(sfSprite *spr, int i, char **map, Global_t *m)
{
    m->codi.pos_curs = sfSprite_getPosition(m->univ.map_cursor_sprite);
    m->codi.pos_spr = sfSprite_getPosition(spr);
    m->codi.pos_spr.x = m->codi.pos_spr.x / 40;
    m->codi.pos_spr.y = m->codi.pos_spr.y / 40;
    m->codi.pos_curs.x = m->codi.pos_curs.x / 40;
    m->codi.pos_curs.y = m->codi.pos_curs.y / 40;
    for (int dx = -i; dx <= i; dx++) {
        m->codi.nx = m->codi.pos_spr.x + dx;
        if (is_moove_ok(m, dx, i) == 1)
            return true;
    }
    return false;
}
