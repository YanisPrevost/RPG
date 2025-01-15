/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** monde_commun.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"
#include <ctype.h>

int check_cursor_on_sprite(Global_t *m, sfSprite *spr)
{
    sfVector2f pos_curs = sfSprite_getPosition(m->univ.map_cursor_sprite);
    sfVector2f pos_spr = sfSprite_getPosition(spr);

    if (pos_curs.x == pos_spr.x && pos_curs.y == pos_spr.y)
        return 1;
    return 0;
}

static void draw_visible2(Global_t *m, sfSprite *spr, Perso_t *perso)
{
    if (check_cursor_on_sprite(m, spr) == 1) {
        if (sfKeyboard_isKeyPressed(sfKeySpace) &&
        perso->case_visble == true) {
            perso->case_visble = false;
            sfClock_restart(m->univ.clock_select_perso);
            return;
        }
        if (sfKeyboard_isKeyPressed(sfKeySpace) &&
        perso->case_visble == false) {
            perso->case_visble = true;
            sfClock_restart(m->univ.clock_select_perso);
        }
    }
}

static void ridicule(Global_t *m, int i, int j, char c)
{
    if (m->current_map[i][j] == c)
        m->current_map[i][j] = ' ';
}

void delet_from_map(Global_t *m, char c)
{
    for (int i = 0; m->current_map[i] != NULL; i++) {
        for (int j = 0; m->current_map[i][j] != '\0'; j++) {
            ridicule(m, i, j, c);
        }
    }
}

static void draw_visible_cases(Global_t *m, sfSprite *spr, int who, char c)
{
    sfTime time = sfClock_getElapsedTime(m->univ.clock_select_perso);
    float seconds = sfTime_asMilliseconds(time) / 1000.0;

    if (m->perso[who].stat_p.current_hp > 0) {
        if (m->perso[who].case_visble == 1)
            draw_possible_movement(m->perso[who].stat_p.mov,
            m, m->current_map, spr);
        if (seconds > 0.3) {
            draw_visible2(m, spr, &m->perso[who]);
        }
    } else
        delet_from_map(m, c);
}

void all_perso_movement(Global_t *m, char **tab)
{
    if (!m->univ.interface.select_inteface) {
        draw_visible_cases(m, m->univ.spr_roy, ROY, '0');
        draw_visible_cases(m, m->univ.spr_xmara, XMARANO, '3');
        draw_visible_cases(m, m->univ.spr_raca, RACAILLOU, '4');
        draw_visible_cases(m, m->univ.spr_pate, PATECARBO, '2');
        draw_visible_cases(m, m->univ.spr_infe, INFENIUM, '1');
    }
    set_new_position(m, m->univ.spr_roy, &m->perso[ROY], tab);
    set_new_position(m, m->univ.spr_xmara, &m->perso[XMARANO], tab);
    set_new_position(m, m->univ.spr_raca, &m->perso[RACAILLOU], tab);
    set_new_position(m, m->univ.spr_pate, &m->perso[PATECARBO], tab);
    set_new_position(m, m->univ.spr_infe, &m->perso[INFENIUM], tab);
}

void all_ennemy_movement(Global_t *m, char **tab)
{
    TAR_EM(m->perso[BOSS1].stat_p.mov, m, m->univ.spr_Boss1, 'P');
    TAR_EM(m->perso[BOSS2].stat_p.mov, m, m->univ.spr_Boss2, 'Q');
    TAR_EM(m->perso[BOSS3].stat_p.mov, m, m->univ.spr_Boss3, 'R');
    TAR_EM(m->perso[BOSS4].stat_p.mov, m, m->univ.spr_Boss4, 'S');
    TAR_EM(m->perso[BOSS5].stat_p.mov, m, m->univ.spr_Boss5, 'T');
    TAR_EM(m->perso[BOSS6].stat_p.mov, m, m->univ.spr_Boss6, 'U');
    TAR_EM(m->perso[BOSS7].stat_p.mov, m, m->univ.spr_Boss7, 'W');
    TAR_EM(m->perso[BOSS8].stat_p.mov, m, m->univ.spr_Boss8, 'Y');
    TAR_EM(m->perso[ENEMY1_SWORD].stat_p.mov, m, m->univ.spr_emy1_sword, 'L');
    TAR_EM(m->perso[ENEMY1_AXE].stat_p.mov, m, m->univ.spr_emy1_axe, 'Z');
    TAR_EM(m->perso[ENEMY2_SWORD].stat_p.mov, m, m->univ.spr_emy2_sword, 'M');
    TAR_EM(m->perso[ENEMY3_SWORD].stat_p.mov, m, m->univ.spr_emy3_sword, '/');
    TAR_EM(m->perso[ENEMY1_SPEAR].stat_p.mov, m, m->univ.spr_emy1_spear, 'G');
    TAR_EM(m->perso[ENEMY2_SPEAR].stat_p.mov, m, m->univ.spr_emy2_spear, 'J');
    TAR_EM(m->perso[ENEMY3_SPEAR].stat_p.mov, m, m->univ.spr_emy3_spear, 'K');
    TAR_EM(m->perso[ENEMY2_AXE].stat_p.mov, m, m->univ.spr_emy2_axe, 'D');
    TAR_EM(m->perso[ENEMY3_AXE].stat_p.mov, m, m->univ.spr_emy3_axe, 'E');
    TAR_EM(m->perso[ENEMY_MAGE].stat_p.mov, m, m->univ.spr_emy_mage, '*');
    m->univ.interface.limite_tour = 5;
}
