/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** give_stats.c
*/

#include "../include/perso.h"
#include "../rpg.h"

void raca_stats(Perso_t *perso)
{
    perso->is_hero = true;
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 19;
    perso->stat_p.max_hp = 19;
    perso->stat_p.lck = 7;
    perso->stat_p.mag = 1;
    perso->stat_p.skl = 5;
    perso->stat_p.def = 2;
    perso->stat_p.res = 8;
    perso->stat_p.str = 7;
    perso->stat_p.spd = 7;
    perso->stat_p.mov = 5;
}

void xmarano_stats(Perso_t *perso)
{
    perso->is_hero = true;
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 20;
    perso->stat_p.max_hp = 20;
    perso->stat_p.lck = 2;
    perso->stat_p.mag = 1;
    perso->stat_p.skl = 4;
    perso->stat_p.def = 3;
    perso->stat_p.res = 0;
    perso->stat_p.str = 7;
    perso->stat_p.spd = 3;
    perso->stat_p.mov = 5;
}

void pate_stats(Perso_t *perso)
{
    perso->is_hero = true;
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 18;
    perso->stat_p.max_hp = 18;
    perso->stat_p.lck = 3;
    perso->stat_p.skl = 6;
    perso->stat_p.mag = 1;
    perso->stat_p.def = 4;
    perso->stat_p.res = 0;
    perso->stat_p.str = 8;
    perso->stat_p.spd = 4;
    perso->stat_p.mov = 6;
}

void infe_stats(Perso_t *perso)
{
    perso->is_hero = true;
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 20;
    perso->stat_p.max_hp = 20;
    perso->stat_p.lck = 7;
    perso->stat_p.skl = 4;
    perso->stat_p.mag = 3;
    perso->stat_p.def = 4;
    perso->stat_p.res = 1;
    perso->stat_p.str = 1;
    perso->stat_p.spd = 5;
    perso->stat_p.mov = 7;
}

void roy_stats(Perso_t *perso)
{
    perso->is_hero = true;
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 20;
    perso->stat_p.max_hp = 20;
    perso->stat_p.lck = 7;
    perso->stat_p.mag = 1;
    perso->stat_p.skl = 5;
    perso->stat_p.def = 5;
    perso->stat_p.res = 0;
    perso->stat_p.str = 5;
    perso->stat_p.spd = 7;
    perso->stat_p.mov = 5;
}
