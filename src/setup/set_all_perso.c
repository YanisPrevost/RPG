/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_perso.c
*/

#include "../include/perso.h"
#include "../rpg.h"

static void set_empty(Perso_t *perso)
{
    perso->inv_weapon[SLOT1].is_empty = false;
    perso->inv_weapon[HEAL].is_empty = false;
    perso->inv_weapon[SLOT2].is_empty = true;
    perso->inv_weapon[SLOT3].is_empty = true;
    perso->inv_weapon[SLOT4].is_empty = true;
}

static void init_raca(Perso_t *perso, char *name, Weapons_t weapon[])
{
    char *link_text = "assets/weapons/Racaillou_axe.png";
    char *link_dia = "assets/perso/dialogue/hero/Racaillou_dialogue.png";
    char *link_bat = "assets/perso/battle/hero/Racaillou_armed.png";
    size_t size = sizeof(Weapons_t);

    perso->name_perso = name;
    perso->type = "Warrior";
    memcpy(perso->current_weapon, &weapon[RACAILLOU_AXE], size);
    strcpy(perso->current_weapon->link_texture, link_text);
    memcpy(&perso->inv_weapon[SLOT1], &weapon[RACAILLOU_AXE], size);
    memcpy(&perso->inv_weapon[HEAL], &weapon[POTION], size);
    strcpy(perso->texture_dialogue, link_dia);
    strcpy(perso->texture_battle, link_bat);
    raca_stats(perso);
    set_empty(perso);
}

static void initxmarano(Perso_t *perso, char *name, Weapons_t weapon[])
{
    char *link_text = "assets/weapons/Xmarano_spear.png";
    char *link_dia = "assets/perso/dialogue/hero/Xmarano_dialogue.png";
    char *link_bat = "assets/perso/battle/hero/Xmarano_armed.png";
    size_t size = sizeof(Weapons_t);

    perso->name_perso = name;
    perso->type = "Knight";
    memcpy(perso->current_weapon, &weapon[XMARANO_SPEAR], size);
    strcpy(perso->current_weapon->link_texture, link_text);
    memcpy(&perso->inv_weapon[SLOT1], &weapon[XMARANO_SPEAR], size);
    memcpy(&perso->inv_weapon[HEAL], &weapon[POTION], size);
    strcpy(perso->texture_dialogue, link_dia);
    strcpy(perso->texture_battle, link_bat);
    xmarano_stats(perso);
    set_empty(perso);
}

static void init_pate(Perso_t *perso, char *name, Weapons_t weapon[])
{
    char *link_text = "assets/weapons/Patecarbo_bow.png";
    char *link_dia = "assets/perso/dialogue/hero/Patecarbo_dialogue.png";
    char *link_bat = "assets/perso/battle/hero/Patecarbo_armed.png";
    size_t size = sizeof(Weapons_t);

    perso->name_perso = name;
    perso->type = "Archer";
    memcpy(perso->current_weapon, &weapon[PATECARBO_BOW], size);
    strcpy(perso->current_weapon->link_texture, link_text);
    memcpy(&perso->inv_weapon[SLOT1], &weapon[PATECARBO_BOW], size);
    memcpy(&perso->inv_weapon[HEAL], &weapon[POTION], size);
    strcpy(perso->texture_dialogue, link_dia);
    strcpy(perso->texture_battle, link_bat);
    pate_stats(perso);
    set_empty(perso);
}

static void initinfenium(Perso_t *perso, char *name, Weapons_t weapon[])
{
    char *link_text = "assets/weapons/Infenium_book.png";
    char *link_dia = "assets/perso/dialogue/hero/Infenium_dialogue.png";
    char *link_bat = "assets/perso/battle/hero/Infenium_armed.png";
    size_t size = sizeof(Weapons_t);

    perso->name_perso = name;
    perso->type = "Paladin";
    memcpy(perso->current_weapon, &weapon[INFENIUM_BOOK], size);
    strcpy(perso->current_weapon->link_texture, link_text);
    memcpy(&perso->inv_weapon[SLOT1], &weapon[INFENIUM_BOOK], size);
    memcpy(&perso->inv_weapon[HEAL], &weapon[HEAL_STICK], size);
    strcpy(perso->texture_dialogue, link_dia);
    strcpy(perso->texture_battle, link_bat);
    infe_stats(perso);
    set_empty(perso);
}

static void initroy(Perso_t *perso, char *name,
    Weapons_t weapon[], Global_t *m)
{
    char *link_text = "assets/weapons/Roy_sword.png";
    char *link_dia = "assets/perso/dialogue/hero/Roy_dialogue.png";
    char *link_bat = "assets/perso/battle/hero/Roy_armed.png";
    size_t size = sizeof(Weapons_t);

    perso->name_perso = name;
    perso->type = "Lord";
    perso->is_hero = true;
    memcpy(perso->current_weapon, &weapon[ROY_SWORD], size);
    strcpy(perso->current_weapon->link_texture, link_text);
    memcpy(&perso->inv_weapon[SLOT1], &weapon[ROY_SWORD], size);
    memcpy(&perso->inv_weapon[HEAL], &weapon[POTION], size);
    strcpy(perso->texture_dialogue, link_dia);
    strcpy(perso->texture_battle, link_bat);
    roy_stats(perso);
    set_empty(perso);
}

int setup_stat(Global_t *m)
{
    initroy(&m->perso[ROY], "ROY", m->weapons, m);
    initinfenium(&m->perso[INFENIUM], "Infenium", m->weapons);
    init_pate(&m->perso[PATECARBO], "PateCarbo", m->weapons);
    initxmarano(&m->perso[XMARANO], "Xmarano", m->weapons);
    init_raca(&m->perso[RACAILLOU], "Racaillou", m->weapons);
    set_boss(m);
    set_enemy(m);
    return 0;
}
