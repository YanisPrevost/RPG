/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** give_stat_bass2.c
*/

#include "../my.h"
#include "../rpg.h"
#include "../include/perso.h"

void set_stats_b8(Perso_t *perso)
{
    perso->stat_p.level = 20;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 40;
    perso->stat_p.max_hp = 40;
    perso->stat_p.mag = 1;
    perso->stat_p.lck = 21;
    perso->stat_p.skl = 10;
    perso->stat_p.def = 20;
    perso->stat_p.res = 20;
    perso->stat_p.str = 10;
    perso->stat_p.spd = 20;
    perso->stat_p.mov = 0;
}

void set_stats_b7(Perso_t *perso)
{
    perso->stat_p.level = 18;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 36;
    perso->stat_p.max_hp = 36;
    perso->stat_p.mag = 1;
    perso->stat_p.lck = 19;
    perso->stat_p.skl = 9;
    perso->stat_p.def = 16;
    perso->stat_p.res = 16;
    perso->stat_p.str = 9;
    perso->stat_p.spd = 18;
    perso->stat_p.mov = 0;
}

void set_stats_b6(Perso_t *perso)
{
    perso->stat_p.level = 16;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 33;
    perso->stat_p.max_hp = 33;
    perso->stat_p.lck = 16;
    perso->stat_p.mag = 13;
    perso->stat_p.skl = 6;
    perso->stat_p.def = 16;
    perso->stat_p.res = 16;
    perso->stat_p.str = 0;
    perso->stat_p.spd = 11;
    perso->stat_p.mov = 0;
}

void set_stats_b5(Perso_t *perso)
{
    perso->stat_p.level = 13;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 30;
    perso->stat_p.max_hp = 30;
    perso->stat_p.lck = 12;
    perso->stat_p.mag = 1;
    perso->stat_p.skl = 6;
    perso->stat_p.def = 13;
    perso->stat_p.res = 13;
    perso->stat_p.str = 8;
    perso->stat_p.spd = 15;
    perso->stat_p.mov = 0;
}
