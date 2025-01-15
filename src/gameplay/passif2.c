/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** passif2.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

void passif_pate(Global_t *m)
{
    if (m->perso->current_perso == PATECARBO) {
        for (int i = 0; i < 5; i++) {
            m->perso[i].stat_p.lck += 1;
            m->perso[i].stat_p.spd += 1;
        }
    }
    m->univ.interface.is_passif_apply = true;
}

void passif_xmara(Global_t *m)
{
    if (m->perso->current_perso == XMARANO) {
        for (int i = 0; i < 5; i++)
            m->perso[i].stat_p.mov += 1;
    }
    m->univ.interface.is_passif_apply = true;
}

void passif_roy(Global_t *m)
{
    if (m->perso->current_perso == ROY) {
        for (int i = 0; i < 5; i++)
            m->perso[i].stat_p.str += 3;
    }
    m->univ.interface.is_passif_apply = true;
}

void passif_raca(Global_t *m)
{
    if (m->perso->current_perso == RACAILLOU) {
        for (int i = 0; i < 5; i++) {
            m->perso[i].stat_p.def += 2;
            m->perso[i].stat_p.mag += 2;
        }
    }
    m->univ.interface.is_passif_apply = true;
}
