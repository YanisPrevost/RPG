/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** mode_commun2.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"
#include <ctype.h>

void set_previous_case(Global_t *m, sfVector2f pos_spr, char **map)
{
    if (isdigit(m->current_map[(int)pos_spr.y / 40 + 1]
    [(int)pos_spr.x / 40 + 1]) == 0)
        map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1] =
        m->current_map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1];
    else {
        map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1] = ' ';
    }
}

static void placement(Global_t *m, Perso_t *perso, char **map,
    sfVector2f pos_curs)
{
    if (strcmp(perso->name_perso, "ROY") == 0) {
        map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1] = '0';
        m->univ.interface.who = 0;
    }
    if (strcmp(perso->name_perso, "Infenium") == 0) {
        map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1] = '1';
        m->univ.interface.who = 1;
    }
    if (strcmp(perso->name_perso, "Racaillou") == 0) {
        map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1] = '4';
        m->univ.interface.who = 4;
    }
    if (strcmp(perso->name_perso, "PateCarbo") == 0) {
        map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1] = '2';
        m->univ.interface.who = 2;
    }
    if (strcmp(perso->name_perso, "Xmarano") == 0) {
        map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1] = '3';
        m->univ.interface.who = 3;
    }
}

void set_new_position(Global_t *m, sfSprite *spr, Perso_t *perso, char **map)
{
    sfVector2f pos_curs = sfSprite_getPosition(m->univ.map_cursor_sprite);
    sfVector2f pos_spr = sfSprite_getPosition(spr);

    if (perso->case_visble == 1 &&
    sfKeyboard_isKeyPressed(sfKeySpace) &&
    check_cursor_on_sprite(m, spr) == 0 &&
    is_movement_ok(spr, perso->stat_p.mov, map, m) == true) {
        set_previous_case(m, pos_spr, map);
        if (isdigit(map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1])
        == 0) {
            placement(m, perso, map, pos_curs);
        }
        m->univ.interface.select_inteface = true;
    }
}
