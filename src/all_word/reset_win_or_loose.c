/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** reset_win_or_loose.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

static void win_gold(Global_t *m, int world)
{
    if (world == 1)
        m->gold += 5000;
    if (world == 2)
        m->gold += 6000;
    if (world == 3)
        m->gold += 7000;
    if (world == 4)
        m->gold += 8000;
    if (world == 5)
        m->gold += 9000;
    if (world == 6)
        m->gold += 15000;
    if (world == 7)
        m->gold += 20000;
}

void reset_stats_end(Global_t *m)
{
    for (int i = 0; i < 5; i++)
        m->perso[i].stat_p.current_hp = m->perso[i].stat_p.max_hp;
    for (int j = 13; j < 23; j++)
        m->perso[j].stat_p.current_hp = m->perso[j].stat_p.max_hp;
    m->univ.interface.attack_gpy2 = false;
    m->univ.interface.attack_gpy = false;
    m->univ.interface.go_fight = false;
    m->univ.interface.limite_tour = 5;
}

void look_win(Global_t *m, int world)
{
    win_gold(m, world);
    reset_stats_end(m);
    m->current = 24;
}

void look_loose(Global_t *m, Perso_t *boss, hub_t *h)
{
    int nbr = 0;

    for (int i = 0; i < 5; i++)
        if (m->perso[i].stat_p.current_hp <= 0)
            nbr++;
    if (nbr == 5) {
        boss->stat_p.current_hp = boss->stat_p.max_hp;
        reset_stats_end(m);
        load_game(m, h);
        m->univ.interface.fake_save = true;
        m->current = 25;
    }
}
