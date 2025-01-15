/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** menu.c
*/

#include "../rpg.h"

int is_weapon_advantage2(Weapons_t *weapon_atk, Weapons_t *weapon_def)
{
    if (strcmp(weapon_atk->weapon_type, "axe") == 0) {
        if (strcmp(weapon_def->weapon_type, "sword") == 0)
            return -1;
    }
    if (strcmp(weapon_atk->weapon_type, "sword") == 0) {
        if (strcmp(weapon_def->weapon_type, "spear") == 0)
            return -1;
    }
    if (strcmp(weapon_atk->weapon_type, "spear") == 0) {
        if (strcmp(weapon_def->weapon_type, "axe") == 0)
            return -1;
    }
    return 0;
}

int is_weapon_advantage(Weapons_t *weapon_atk, Weapons_t *weapon_def)
{
    if (strcmp(weapon_atk->weapon_type, "sword") == 0) {
        if (strcmp(weapon_def->weapon_type, "axe") == 0)
            return 1;
    }
    if (strcmp(weapon_atk->weapon_type, "axe") == 0) {
        if (strcmp(weapon_def->weapon_type, "spear") == 0)
            return 1;
    }
    if (strcmp(weapon_atk->weapon_type, "spear") == 0) {
        if (strcmp(weapon_def->weapon_type, "sword") == 0)
            return 1;
    }
    return is_weapon_advantage2(weapon_atk, weapon_def);
}

int is_hit(Perso_t *attack, Perso_t *defense, Weapons_t
    *weapon_atk, Weapons_t *weapon_def)
{
    int nb1 = rand() % 100;
    int nb2 = rand() % 100;
    int accuracy = weapon_atk->accuracy + attack->stat_p.skl * 2 +
    attack->stat_p.lck * 2 + is_weapon_advantage(weapon_atk, weapon_def) * 10;
    int avoid = defense->stat_p.spd * 2 + defense->stat_p.lck;

    accuracy = accuracy - avoid;
    if (accuracy <= 0) {
        return 0;
    }
    if ((nb1 + nb2) / 2 <= accuracy) {
        return 1;
    }
    return 0;
}

void level_up(stchar_t *stats)
{
    int rng = rand();

    if (stats->xp >= 100) {
        stats->level += 1;
        stats->xp -= 100;
        if (rng % 2 == 0)
            stats->skl += rand() % 2;
        if (rng % 3 == 0)
            stats->def += rand() % 2;
        if (rng % 4 == 0)
            stats->max_hp += rand() % 2;
        if (rng % 5 == 0)
            stats->lck += rand() % 2;
        if (rng % 6 == 0)
            stats->res += rand() % 2;
        if (rng % 7 == 0)
            stats->spd += rand() % 2;
    }
}

void get_fight_exp(Perso_t *atk, Perso_t *def)
{
    if (atk->is_hero == true) {
        atk->stat_p.xp += 60 + def->stat_p.level - atk->stat_p.level;
        level_up(&atk->stat_p);
    }
    if (def->is_hero == true) {
        def->stat_p.xp += 30 + atk->stat_p.level;
        level_up(&def->stat_p);
    }
}
