/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** init_all_pose.c
*/

#include "../rpg.h"
#include "../include/menu.h"

void check_all_pose3(Global_t *m, char **tab, int word)
{
    if (word >= 7 && word <= 8) {
        if (word == 7 && (m->perso[BOSS7].stat_p.current_hp > 0))
            check_position(tab, 'W', m->univ.spr_Boss7, m);
        if (word == 8 && (m->perso[BOSS8].stat_p.current_hp > 0))
            check_position(tab, 'Y', m->univ.spr_Boss8, m);
        if (m->perso[ENEMY3_SWORD].stat_p.current_hp > 0)
            check_position(tab, '/', m->univ.spr_emy3_sword, m);
        else
            delet_from_map(m, '/');
        if (m->perso[ENEMY_MAGE].stat_p.current_hp > 0)
            check_position(tab, '*', m->univ.spr_emy_mage, m);
        else
            delet_from_map(m, '*');
    }
}

void check_all_pose2(Global_t *m, char **tab, int word)
{
    if (word >= 4 && word <= 8) {
        if (word == 4 && (m->perso[BOSS4].stat_p.current_hp > 0))
            check_position(tab, 'S', m->univ.spr_Boss4, m);
        if (word == 5 && (m->perso[BOSS5].stat_p.current_hp > 0))
            check_position(tab, 'T', m->univ.spr_Boss5, m);
        if (word == 6 && (m->perso[BOSS6].stat_p.current_hp > 0))
            check_position(tab, 'U', m->univ.spr_Boss6, m);
    }
    check_all_pose3(m, tab, word);
}

static void encore(Global_t *m, char **tab, int word)
{
    if (word > 1 && m->perso[ENEMY2_SPEAR].stat_p.current_hp > 0)
        check_position(tab, 'J', m->univ.spr_emy2_spear, m);
    else
        delet_from_map(m, 'J');
    if (word > 3 && m->perso[ENEMY2_AXE].stat_p.current_hp > 0)
        check_position(tab, 'D', m->univ.spr_emy2_axe, m);
    else
        delet_from_map(m, 'D');
    if (word > 4 && m->perso[ENEMY3_AXE].stat_p.current_hp > 0)
        check_position(tab, 'E', m->univ.spr_emy3_axe, m);
    else
        delet_from_map(m, 'E');
    if (word > 5 && m->perso[ENEMY3_SPEAR].stat_p.current_hp > 0)
        check_position(tab, 'K', m->univ.spr_emy3_spear, m);
    else
        delet_from_map(m, 'K');
}

static void parti(Global_t *m, char **tab)
{
    if (m->perso[ENEMY1_SPEAR].stat_p.current_hp > 0)
        check_position(tab, 'G', m->univ.spr_emy1_spear, m);
    else
        delet_from_map(m, 'G');
    if (m->perso[ENEMY1_SWORD].stat_p.current_hp > 0)
        check_position(tab, 'L', m->univ.spr_emy1_sword, m);
    else
        delet_from_map(m, 'L');
    if (m->perso[ENEMY2_SWORD].stat_p.current_hp > 0)
        check_position(tab, 'M', m->univ.spr_emy2_sword, m);
    else
        delet_from_map(m, 'M');
}

static void check_all_pose2_1(Global_t *m, char **tab, int word)
{
    if (word >= 1 && word <= 8) {
        if (word == 1 && (m->perso[BOSS1].stat_p.current_hp > 0))
            check_position(tab, 'P', m->univ.spr_Boss1, m);
        if (word == 2 && (m->perso[BOSS2].stat_p.current_hp > 0))
            check_position(tab, 'Q', m->univ.spr_Boss2, m);
        if (word == 3 && (m->perso[BOSS3].stat_p.current_hp > 0))
            check_position(tab, 'R', m->univ.spr_Boss3, m);
        if (m->perso[ENEMY1_AXE].stat_p.current_hp > 0)
            check_position(tab, 'Z', m->univ.spr_emy1_axe, m);
        else
            delet_from_map(m, 'Z');
        parti(m, tab);
        encore(m, tab, word);
    }
}

static void check_perso_pose2(Global_t *m, char **tab)
{
    if (m->perso[XMARANO].stat_p.current_hp > 0)
        check_position(tab, '3', m->univ.spr_xmara, m);
    else
        delet_from_map(m, '3');
    if (m->perso[RACAILLOU].stat_p.current_hp > 0)
        check_position(tab, '4', m->univ.spr_raca, m);
    else
        delet_from_map(m, '4');
}

void check_all_pose(Global_t *m, char **tab, int word)
{
    if (m->perso[ROY].stat_p.current_hp > 0)
        check_position(tab, '0', m->univ.spr_roy, m);
    else
        delet_from_map(m, '0');
    if (m->perso[INFENIUM].stat_p.current_hp > 0)
        check_position(tab, '1', m->univ.spr_infe, m);
    else
        delet_from_map(m, '1');
    if (m->perso[PATECARBO].stat_p.current_hp > 0)
        check_position(tab, '2', m->univ.spr_pate, m);
    else
        delet_from_map(m, '2');
    check_perso_pose2(m, tab);
    check_all_pose2_1(m, tab, word);
    check_all_pose2(m, tab, word);
}
