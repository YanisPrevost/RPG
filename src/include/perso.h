/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory.h
*/
#include "../my.h"
#include "../rpg.h"
#include "weapons.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>

#ifndef INVENTORY_H
    #define INVENTORY_H

typedef struct inv2_sprite {
    sfSprite *inventory;
    sfTexture *Inventory;
    sfSprite *inventory2;
    sfTexture *Inventory2;
    sfSprite *cursor;
    sfTexture *Cursor;
    sfVector2f pos_cursor;
    sfVector2f pos_hooved;
    sfRectangleShape *rect_inv;
    sfRectangleShape *hooved_weapon;
    sfSprite *fond;
    sfTexture *Fond;
}inv2_sprite_t;

typedef struct inventaire {
    inv2_sprite_t inv_sprite;
} inv_t;

typedef struct stats_char {
    int level;
    int xp;
    int current_hp;
    int max_hp;
    int lck;
    int mag;
    int skl;
    int def;
    int res;
    int str;
    int spd;
    int mov;
} stchar_t;

typedef struct case_struct {
    char *name;
    int def_bonus;
    int esq_bonus;
    sfBool is_accessible;
    int move_penalty;
} case_t;

typedef struct Perso {
    sfClock *swap_clock;
    int what_weapons_stat;
    int current_perso; //perso designer
    int first_current_perso;
    char *name_perso; // nom du perso
    char *type; // type du perso
    Weapons_t current_weapon[20]; //arme actuelle
    Weapons_t inv_weapon[5]; // armes dans l'inventaire
    stchar_t stat_p; //stat du perso
    inv_t inv; //inventaire du perso
    bool is_visible;
    bool is_visible2;
    char texture_dialogue[100]; //texture dialogue
    char texture_battle[100]; // texture combat
    sfSprite *dialogue_sprite;
    sfTexture *dialogue_texture;
    bool is_hero;
    case_t *current_case;
    bool case_visble;
}Perso_t;

#endif
