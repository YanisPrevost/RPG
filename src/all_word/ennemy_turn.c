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

bool ennemy_on_case(Global_t *m, int y_target, int x_target)
{
    char *enemy_list = ENNEMY_CODE;

    for (int i = 0; enemy_list[i] != '\0'; i++) {
        if (m->current_map[y_target][x_target] == enemy_list[i])
            return true;
    }
    return false;
}

void set_previous_case_ennemy(Global_t *m, sfVector2f pos_spr, char **map)
{
    if (m->current_map[(int)pos_spr.y / 40 + 1]
    [(int)pos_spr.x / 40 + 1] != m->codi.patern)
        map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1] =
        m->old_map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1];
    else {
        map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1] = ' ';
    }
}

static void moove_emy2(Global_t *m, sfVector2i previous_pos,
    sfVector2i pos_target, char patern)
{
    if (m->current_map[pos_target.y + 1][pos_target.x] != 'X' &&
    !isdigit(m->current_map[pos_target.y + 1][pos_target.x]) &&
    !ennemy_on_case(m, pos_target.y + 1, pos_target.x)) {
        m->current_map[pos_target.y + 1][pos_target.x] = patern;
        if (m->current_map[previous_pos.y][previous_pos.x] == patern)
            m->current_map[previous_pos.y][previous_pos.x] = ' ';
        return;
    }
    if (m->current_map[pos_target.y - 1][pos_target.x] != 'X' &&
    !isdigit(m->current_map[pos_target.y - 1][pos_target.x + 1]) &&
    !ennemy_on_case(m, pos_target.y - 1, pos_target.x)) {
        m->current_map[pos_target.y - 1][pos_target.x] = patern;
        if (m->current_map[previous_pos.y][previous_pos.x] == patern)
            m->current_map[previous_pos.y][previous_pos.x] = ' ';
        return;
    }
}

static int check_emy_alive(Global_t *m, char patern)
{
    char *liste = ENNEMY_CODE;
    int i = 0;

    for (i; liste[i] != '\0'; i++) {
        if (liste[i] == patern)
            break;
    }
    i += 5;
    if (m->perso[i].stat_p.current_hp <= 0)
        return 1;
    return 0;
}

void move_ennemy(Global_t *m, sfVector2i previous_pos,
    sfVector2i pos_target, char patern)
{
    if (check_emy_alive(m, patern) == 1)
        return;
    if (m->current_map[pos_target.y][pos_target.x + 1] != 'X' &&
    !isdigit(m->current_map[pos_target.y][pos_target.x + 1]) &&
    !ennemy_on_case(m, pos_target.y, pos_target.x + 1)) {
        m->current_map[pos_target.y][pos_target.x + 1] = patern;
        if (m->current_map[previous_pos.y][previous_pos.x] == patern)
            m->current_map[previous_pos.y][previous_pos.x] = ' ';
        return;
    }
    if (m->current_map[pos_target.y][pos_target.x - 1] != 'X' &&
    !isdigit(m->current_map[pos_target.y][pos_target.x - 1]) &&
    !ennemy_on_case(m, pos_target.y, pos_target.x - 1)) {
        m->current_map[pos_target.y][pos_target.x - 1] = patern;
        if (m->current_map[previous_pos.y][previous_pos.x] == patern)
            m->current_map[previous_pos.y][previous_pos.x] = ' ';
        return;
    }
    moove_emy2(m, previous_pos, pos_target, patern);
}

static void taget_emy2(Global_t *m, int i, int dx, int dy)
{
    int nx;
    int ny;

    nx = m->codi.pos.x + dx;
    ny = m->codi.pos.y + dy;
    if (abs(dx) + abs(dy) <= i && est_dans_grille(nx, ny)) {
        if (ligne_sans_obstacle2((sfVector2i){m->codi.pos.x + 1,
        m->codi.pos.y + 1}, (sfVector2i){nx + 1, ny + 1}, m->current_map, m) &&
        isdigit(m->current_map[ny + 1][nx + 1])) {
            move_ennemy(m, (sfVector2i){(int)m->codi.pos.x + 1,
            (int)m->codi.pos.y + 1}, (sfVector2i){nx + 1, ny + 1},
            m->codi.patern);
            m->univ.interface.current_emy = m->codi.patern;
            m->univ.interface.attack_gpy2 = true;
            m->univ.interface.queue += 1;
            return;
        }
    }
}

void check_target_ennemy_turn(int i, Global_t *m, sfSprite *spr, char patern)
{
    m->codi.pos = sfSprite_getPosition(spr);
    m->codi.pos.x /= 40;
    m->codi.pos.y /= 40;
    m->codi.patern = patern;
    for (int dx = -i; dx <= i; dx++) {
        for (int dy = -i; dy <= i; dy++) {
            taget_emy2(m, i, dx, dy);
        }
    }
}
