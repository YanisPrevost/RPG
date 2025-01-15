/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** weapons.h
*/

#ifndef WEAPONS_H
    #define WEAPONS_H
    #include "../rpg.h"
    #define MAX_WEAPONS 20
    #define MAX_NAME_LENGTH 50

typedef struct stats_weapon {
    int idx_weap;
    char name[MAX_NAME_LENGTH];
    char weapon_type[MAX_NAME_LENGTH];
    char link_texture[100];
    int attack;
    int accuracy;
    int rng;
    int crit;
    int cost;
    sfTexture *texture;
    sfSprite *sprite;
    bool is_empty;
} Weapons_t;

#endif
