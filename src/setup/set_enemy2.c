/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_enemy2.c
*/

#include "../rpg.h"
#include "../include/perso.h"

void init_enemy_mage(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    perso->is_hero = false;
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture,
    "assets/weapons/Heal_stick.png");
    strcpy(perso->texture_dialogue, "NULL");
    strcpy(perso->texture_battle, "assets/perso/battle/enemy/enemy_mage.png");
    perso->stat_p.level = 7;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 25;
    perso->stat_p.max_hp = 25;
    perso->stat_p.lck = 7;
    perso->stat_p.mag = 7;
    perso->stat_p.skl = 7;
    perso->stat_p.def = 4;
    perso->stat_p.res = 2;
    perso->stat_p.str = 2;
    perso->stat_p.spd = 8;
    perso->stat_p.mov = 0;
}

void init_enemy3_axe(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    perso->is_hero = false;
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/axe3.png");
    strcpy(perso->texture_dialogue, "NULL");
    strcpy(perso->texture_battle, "assets/perso/battle/enemy/enemy3_axe.png");
    perso->stat_p.level = 7;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 28;
    perso->stat_p.max_hp = 28;
    perso->stat_p.lck = 7;
    perso->stat_p.mag = 1;
    perso->stat_p.skl = 7;
    perso->stat_p.def = 4;
    perso->stat_p.res = 2;
    perso->stat_p.str = 13;
    perso->stat_p.spd = 8;
    perso->stat_p.mov = 5;
}

void init_enemy2_axe(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    perso->is_hero = false;
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/axe2.png");
    strcpy(perso->texture_dialogue, "NULL");
    strcpy(perso->texture_battle, "assets/perso/battle/enemy/enemy2_axe.png");
    perso->stat_p.level = 3;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 23;
    perso->stat_p.max_hp = 23;
    perso->stat_p.mag = 1;
    perso->stat_p.lck = 7;
    perso->stat_p.skl = 7;
    perso->stat_p.def = 4;
    perso->stat_p.res = 2;
    perso->stat_p.str = 6;
    perso->stat_p.spd = 5;
    perso->stat_p.mov = 5;
}

void init_enemy1_axe(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    perso->is_hero = false;
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/axe1.png");
    strcpy(perso->texture_dialogue, "NULL");
    strcpy(perso->texture_battle, "assets/perso/battle/enemy/enemy1_axe.png");
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 20;
    perso->stat_p.max_hp = 20;
    perso->stat_p.lck = 6;
    perso->stat_p.mag = 1;
    perso->stat_p.skl = 5;
    perso->stat_p.def = 2;
    perso->stat_p.res = 0;
    perso->stat_p.str = 6;
    perso->stat_p.spd = 6;
    perso->stat_p.mov = 5;
}
