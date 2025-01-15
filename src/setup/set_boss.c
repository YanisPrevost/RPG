/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_boss.c
*/

#include "../include/perso.h"
#include "../rpg.h"

static void init_boss8(Perso_t *perso, char *name, Weapons_t weapon)
{
    char *link_wep = "assets/weapons/Boss8_sword.png";
    char *link_dia = "assets/perso/dialogue/boss/Boss8_dialogue.png";
    char *link_bat = "assets/perso/battle/boss/Boss8_armed.png";

    perso->name_perso = name;
    perso->type = "Boss";
    perso->is_hero = false;
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, link_wep);
    strcpy(perso->texture_dialogue, link_dia);
    strcpy(perso->texture_battle, link_bat);
    set_stats_b8(perso);
}

static void init_boss7(Perso_t *perso, char *name, Weapons_t weapon)
{
    char *link_wep = "assets/weapons/Boss7_axe.png";
    char *link_dia = "assets/perso/dialogue/boss/Boss7_dialogue.png";
    char *link_bat = "assets/perso/battle/boss/Boss7_armed.png";

    perso->name_perso = name;
    perso->type = "Boss";
    perso->is_hero = false;
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, link_wep);
    strcpy(perso->texture_dialogue, link_dia);
    strcpy(perso->texture_battle, link_bat);
    set_stats_b7(perso);
}

static void init_boss6(Perso_t *perso, char *name, Weapons_t weapon)
{
    char *link_wep = "assets/weapons/Boss6_book.png";
    char *link_dia = "assets/perso/dialogue/boss/Boss6_dialogue.png";
    char *link_bat = "assets/perso/battle/boss/Boss6_armed.png";

    perso->name_perso = name;
    perso->type = "Boss";
    perso->is_hero = false;
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, link_wep);
    strcpy(perso->texture_dialogue, link_dia);
    strcpy(perso->texture_battle, link_bat);
    set_stats_b6(perso);
}

static void init_boss5(Perso_t *perso, char *name, Weapons_t weapon)
{
    char *link_wep = "assets/weapons/Boss5_sword.png";
    char *link_dia = "assets/perso/dialogue/boss/Boss5_dialogue.png";
    char *link_bat = "assets/perso/battle/boss/Boss5_armed.png";

    perso->name_perso = name;
    perso->type = "Boss";
    perso->is_hero = false;
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, link_wep);
    strcpy(perso->texture_dialogue, link_dia);
    strcpy(perso->texture_battle, link_bat);
    set_stats_b5(perso);
}

static void init_boss4(Perso_t *perso, char *name, Weapons_t weapon)
{
    char *link_wep = "assets/weapons/Boss4_spear.png";
    char *link_dia = "assets/perso/dialogue/boss/Boss4_dialogue.png";
    char *link_bat = "assets/perso/battle/boss/Boss4_armed.png";

    perso->name_perso = name;
    perso->type = "Boss";
    perso->is_hero = false;
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, link_wep);
    strcpy(perso->texture_dialogue, link_dia);
    strcpy(perso->texture_battle, link_bat);
    set_stats_b4(perso);
}

static void init_boss3(Perso_t *perso, char *name, Weapons_t weapon)
{
    char *link_wep = "assets/weapons/Boss3_bow.png";
    char *link_dia = "assets/perso/dialogue/boss/Boss3_dialogue.png";
    char *link_bat = "assets/perso/battle/boss/Boss3_armed.png";

    perso->name_perso = name;
    perso->type = "Boss";
    perso->is_hero = false;
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, link_wep);
    strcpy(perso->texture_dialogue, link_dia);
    strcpy(perso->texture_battle, link_bat);
    set_stats_b3(perso);
}

static void init_boss2(Perso_t *perso, char *name, Weapons_t weapon)
{
    char *link_wep = "assets/weapons/Boss2_stick.png";
    char *link_dia = "assets/perso/dialogue/boss/Boss2_dialogue.png";
    char *link_bat = "assets/perso/battle/boss/Boss2_armed.png";

    perso->name_perso = name;
    perso->type = "Boss";
    perso->is_hero = false;
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, link_wep);
    strcpy(perso->texture_dialogue, link_dia);
    strcpy(perso->texture_battle, link_bat);
    set_stats_b2(perso);
}

static void init_boss1(Perso_t *perso, char *name, Weapons_t weapon)
{
    char *link_wep = "assets/weapons/Boss1_sword.png";
    char *link_dia = "assets/perso/dialogue/boss/Boss1_dialogue.png";
    char *link_bat = "assets/perso/battle/boss/Boss1_armed.png";

    perso->name_perso = name;
    perso->type = "Boss";
    perso->is_hero = false;
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, link_wep);
    strcpy(perso->texture_dialogue, link_dia);
    strcpy(perso->texture_battle, link_bat);
    set_stats_b1(perso);
}

int set_boss(Global_t *m)
{
    init_boss1(&m->perso[BOSS1], "Ethan", m->weapons[BOSS1_SWORD]);
    init_boss2(&m->perso[BOSS2], "Godrick", m->weapons[BOSS2_STICK]);
    init_boss3(&m->perso[BOSS3], "Melenia", m->weapons[BOSS3_BOW]);
    init_boss4(&m->perso[BOSS4], "Morgot", m->weapons[BOSS4_SPEAR]);
    init_boss5(&m->perso[BOSS5], "Rykard", m->weapons[BOSS5_SWORD]);
    init_boss6(&m->perso[BOSS6], "Godfrey", m->weapons[BOSS6_BOOK]);
    init_boss7(&m->perso[BOSS7], "Hoarah", m->weapons[BOSS7_AXE]);
    init_boss8(&m->perso[BOSS8], "Radagon", m->weapons[BOSS8_SWORD]);
    return 0;
}
