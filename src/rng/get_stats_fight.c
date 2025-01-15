/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** put_damage.c
*/

#include "../rpg.h"

int get_crit_rate(Perso_t *atk, Perso_t *def)
{
    if (atk->current_weapon->crit
    + atk->stat_p.skl * 2 - def->stat_p.lck <= 0)
        return 0;
    return atk->current_weapon->crit
    + atk->stat_p.skl * 2 - def->stat_p.lck;
}

int get_hit_rate(Perso_t *atk, Perso_t *def)
{
    int accuracy = atk->current_weapon->accuracy + atk->stat_p.skl * 2 +
    atk->stat_p.lck * 2 +
    is_weapon_advantage(atk->current_weapon, def->current_weapon) * 10;
    int avoid = def->stat_p.spd * 2 + def->stat_p.lck;

    if (accuracy - avoid > 100)
        return 100;
    return accuracy - avoid;
}

int get_damage_physical(Perso_t *attacker, Perso_t *defender)
{
    int atk = attacker->stat_p.str +
    is_weapon_advantage(attacker->current_weapon,
    defender->current_weapon) + attacker->current_weapon->attack;
    int def = defender->stat_p.def;

    if ((atk - def) * double_attack(&attacker->stat_p, &defender->stat_p) <= 0)
        return 0;
    return (atk - def) * double_attack(&attacker->stat_p, &defender->stat_p);
}

int get_damage_magical(Perso_t *attacker, Perso_t *defender)
{
    int atk = attacker->stat_p.mag +
    is_weapon_advantage(attacker->current_weapon,
    defender->current_weapon) + attacker->current_weapon->attack;
    int def = defender->stat_p.res;

    if ((atk - def) * double_attack(&attacker->stat_p, &defender->stat_p) <= 0)
        return 0;
    return (atk - def) * double_attack(&attacker->stat_p, &defender->stat_p);
}
