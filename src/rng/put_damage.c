/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** put_damage.c
*/

#include "../rpg.h"

int double_attack(stchar_t *attack, stchar_t *defense)
{
    if (attack->spd - defense->spd >= 4)
        return 2;
    return 1;
}

int critical_hit(stchar_t *attack, stchar_t *defense, Weapons_t *weapon)
{
    int nb = rand() % 100;
    int critical_weapon = weapon->crit + attack->skl * 2 - defense->lck;

    if (nb <= critical_weapon) {
        return 3;
    }
    return 1;
}

int damage_physical(Perso_t *attacker, Perso_t *defender)
{
    int crit = critical_hit(&attacker->stat_p, &defender->stat_p,
    attacker->current_weapon);
    int atk = attacker->stat_p.str +
    is_weapon_advantage(attacker->current_weapon,
    defender->current_weapon) + attacker->current_weapon->attack;
    int def = defender->stat_p.def;

    if ((atk - def) * crit *
    double_attack(&attacker->stat_p, &defender->stat_p) <= 0)
        return 0;
    return (atk - def) * crit *
    double_attack(&attacker->stat_p, &defender->stat_p);
}

int damage_magical(Perso_t *attacker, Perso_t *defender)
{
    int crit = critical_hit(&attacker->stat_p,
    &defender->stat_p, attacker->current_weapon);
    int atk = attacker->stat_p.mag +
    is_weapon_advantage(attacker->current_weapon,
    defender->current_weapon) + attacker->current_weapon->attack;
    int def = defender->stat_p.res;

    if ((atk - def) * crit *
    double_attack(&attacker->stat_p, &defender->stat_p) <= 0)
        return 0;
    return (atk - def) * crit *
    double_attack(&attacker->stat_p, &defender->stat_p);
}
