/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** passif.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

void passif_mage(Global_t *m)
{
    for (int i = 13; i < 23; i++) {
        if (m->perso[i].stat_p.current_hp > 0)
            m->perso[i].stat_p.current_hp += 10;
        if (m->perso[i].stat_p.current_hp > m->perso[i].stat_p.max_hp)
            m->perso[i].stat_p.current_hp = m->perso[i].stat_p.max_hp;
    }
}

static void heal_de_infe(Global_t *m)
{
    for (int i = 0; i < 5; i++) {
        if (m->perso[i].stat_p.current_hp > 0)
            m->perso[i].stat_p.current_hp += 5;
        if (m->perso[i].stat_p.current_hp > m->perso[i].stat_p.max_hp)
            m->perso[i].stat_p.current_hp = m->perso[i].stat_p.max_hp;
    }
}

void passif_infenium(Global_t *m)
{
    if (m->perso[INFENIUM].stat_p.current_hp > 0 &&
    m->perso->first_current_perso == INFENIUM &&
    m->univ.interface.limite_tour == 0) {
        heal_de_infe(m);
    }
}

void apply_passif(Global_t *m)
{
    if (m->univ.interface.is_passif_apply == false && m->current == 0) {
        passif_raca(m);
        passif_roy(m);
        passif_xmara(m);
        passif_pate(m);
    }
}
