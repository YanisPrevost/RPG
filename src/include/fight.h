/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** fight.h
*/

#include "../my.h"
#include "../rpg.h"

#ifndef FIGHT_H
    #define FIGHT_H
    #define S_PARTICLES 10

typedef struct {
    sfVector2f position;
    float life_duration;
    sfSprite *spr;
    sfTexture *texture;
} slash_t;

typedef struct fight_struct {
    sfSprite *empty_bar_sprite;
    sfIntRect rect_empty_bar;
    sfSprite *hero_lifebar_sprite;
    sfIntRect rect_hero_bar;
    sfSprite *ennemy_bar_sprite;
    sfIntRect rect_ennemy_bar;
    sfSprite *empty_bar_sprite2;
    sfSprite *ennemy_bar_sprite2;
    sfIntRect rect_empty_bar2;
    sfIntRect rect_ennemy_bar2;
    sfSprite *hero_lifebar_sprite2;
    sfSprite *weapon_advantage;
    sfIntRect weapon_advantage_rect;
    sfTexture *globat_texture;
    sfSprite *combat_scene;
    sfText **text_tab;
    sfFont *font;
    int dmg_atk;
    int dmg_def;
    int dmg_atk_received;
    int dmg_def_received;
    sfSprite *sprite_atk;
    sfSprite *sprite_def;
    sfTexture *texture_atk;
    sfTexture *texture_def;
    sfBool is_fight;
    sfBool has_def_attacked;
    sfSprite *dead_head;
    sfTexture *Dead_head;
    sfSprite *dead_head2;
    sfClock *slash_clock;
    slash_t s_particles[S_PARTICLES];
    int is_white;
    sfClock *lifebar_clock;
    int pv_atk;
    int pv_def;
} fight_t;

void init_lifebars(fight_t *fight, Global_t *m);
void print_fight_scene(Global_t *m, fight_t *fight);
void destroy_fight_struct(fight_t *fight);
int is_weapon_advantage(Weapons_t *weapon_atk, Weapons_t *weapon_def);
int is_hit(Perso_t *attack, Perso_t *defense, Weapons_t
    *weapon_atk, Weapons_t *weapon_def);
int double_attack(stchar_t *attack, stchar_t *defense);
int critical_hit(stchar_t *attack, stchar_t *defense, Weapons_t *weapon);
void level_up(stchar_t *stats);
int damage_physical(Perso_t *attacker, Perso_t *defender);
int damage_magical(Perso_t *attacker, Perso_t *defender);
int get_crit_rate(Perso_t *atk, Perso_t *def);
int get_hit_rate(Perso_t *atk, Perso_t *def);
int set_dmg(fight_t *fight, Global_t *m, Perso_t *atk, Perso_t *def);
int get_damage_physical(Perso_t *attacker, Perso_t *defender);
int get_damage_magical(Perso_t *attacker, Perso_t *defender);
void print_sprites(Perso_t *atk, Perso_t *def, Global_t *m, fight_t *f);
void destroy_fight_sprites(fight_t *f);
void init_fight_sprites(Perso_t *atk, Perso_t *def, fight_t *f, Global_t *m);
void get_fight_exp(Perso_t *atk, Perso_t *def);

#endif
