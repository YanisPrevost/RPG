/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** mini_verif.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"
#include <ctype.h>

int the_while2(Global_t *m, sfVector2i pos_0,
    sfVector2i pos_1, char **map)
{
    while (1) {
        if (map[pos_0.y][pos_0.x] == 'X')
            return 0;
        if (pos_0.x == pos_1.x && pos_0.y == pos_1.y)
            return 1;
        m->codi2.e2 = 2 * m->codi2.err;
        if (m->codi2.e2 >= m->codi2.dy) {
            m->codi2.err += m->codi2.dy;
            pos_0.x += m->codi2.sx;
        }
        if (m->codi2.e2 <= m->codi2.dx) {
            m->codi2.err += m->codi2.dx;
            pos_0.y += m->codi2.sy;
        }
    }
    return 1;
}

static int check2(char **map, int y, int x, Global_t *m)
{
    char *tab = "PQRSTUWYLM/GJKZDE*";

    for (int i = 0; i < strlen(tab); i++) {
        if (map[x][y] == tab[i])
            return -1;
    }
    return 0;
}

int the_while(Global_t *m, sfVector2i pos_0,
    sfVector2i pos_1, char **map)
{
    while (1) {
        if (check2(map, pos_0.x, pos_0.y, m) == -1)
            return 0;
        if (map[pos_0.y][pos_0.x] == 'X')
            return 0;
        if (pos_0.x == pos_1.x && pos_0.y == pos_1.y)
            return 1;
        m->codi2.e2 = 2 * m->codi2.err;
        if (m->codi2.e2 >= m->codi2.dy) {
            m->codi2.err += m->codi2.dy;
            pos_0.x += m->codi2.sx;
        }
        if (m->codi2.e2 <= m->codi2.dx) {
            m->codi2.err += m->codi2.dx;
            pos_0.y += m->codi2.sy;
        }
    }
    return 1;
}
