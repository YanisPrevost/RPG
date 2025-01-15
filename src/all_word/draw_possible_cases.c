/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** game_cursor.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"
#include <ctype.h>

int ligne_sans_obstacle(sfVector2i pos_0, sfVector2i pos_1,
    char **map, Global_t *m)
{
    m->codi2.dx = abs(pos_1.x - pos_0.x);
    m->codi2.sx = pos_0.x < pos_1.x ? 1 : -1;
    m->codi2.dy = -abs(pos_1.y - pos_0.y);
    m->codi2.sy = pos_0.y < pos_1.y ? 1 : -1;
    m->codi2.err = m->codi2.dx + m->codi2.dy;
    if (the_while(m, pos_0, pos_1, map) == 1)
        return 1;
    return 0;
}

int ligne_sans_obstacle2(sfVector2i pos_0, sfVector2i pos_1,
    char **map, Global_t *m)
{
    m->codi2.dx = abs(pos_1.x - pos_0.x);
    m->codi2.sx = pos_0.x < pos_1.x ? 1 : -1;
    m->codi2.dy = -abs(pos_1.y - pos_0.y);
    m->codi2.sy = pos_0.y < pos_1.y ? 1 : -1;
    m->codi2.err = m->codi2.dx + m->codi2.dy;
    if (the_while2(m, pos_0, pos_1, map) == 1)
        return 1;
    return 0;
}

int est_dans_grille(int x, int y)
{
    return (x >= 0 && x < 30 && y >= 0 && y < 20);
}

static void draw_squares(Global_t *m, int nx, int ny)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, (sfVector2f){40, 40});
    sfRectangleShape_setPosition(rect, (sfVector2f){nx * 40, ny * 40});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(100, 206, 250, 150));
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRenderWindow_drawRectangleShape(m->window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

static void verif(Global_t *m, sfVector2f pos, int nx, int ny)
{
    if (ligne_sans_obstacle((sfVector2i){pos.x + 1, pos.y + 1},
    (sfVector2i){nx + 1, ny + 1}, m->current_map, m)) {
        draw_squares(m, nx, ny);
    }
}

static void draw_possible_movement2(Global_t *m, int dx, int i, sfVector2f pos)
{
    int nx;
    int ny;

    for (int dy = -i; dy <= i; dy++) {
        nx = pos.x + dx;
        ny = pos.y + dy;
        if (abs(dx) + abs(dy) <= i && est_dans_grille(nx, ny)) {
            verif(m, pos, nx, ny);
        }
    }
}

void draw_possible_movement(int i, Global_t *m, char **map, sfSprite *spr)
{
    sfVector2f pos = sfSprite_getPosition(spr);

    pos.x /= 40;
    pos.y /= 40;
    for (int dx = -i; dx <= i; dx++) {
        draw_possible_movement2(m, dx, i, pos);
    }
}
