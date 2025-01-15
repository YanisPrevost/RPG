/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** event_interface.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

static void add_hp(Global_t *m, int who)
{
    m->perso[who].stat_p.current_hp += 10;
    if (m->perso[who].stat_p.current_hp > m->perso[who].stat_p.max_hp)
        m->perso[who].stat_p.current_hp = m->perso[who].stat_p.max_hp;
}

void hp_up(Global_t *m)
{
    int who = m->univ.interface.who;

    if (who == 5)
        who = 0;
    for (int j = 0; j < 5; j++) {
        if (strcmp(m->perso[who].inv_weapon[j].name, "Potion") == 0) {
            add_hp(m, who);
            memset(&m->perso[who].inv_weapon[j], 0, sizeof(Weapons_t));
            m->perso[who].inv_weapon[j].is_empty = true;
        }
    }
}

void import_emy_in_battle(Global_t *m, int k, fight_t *f)
{
    k += 5;
    if (m->perso[k].stat_p.current_hp <= 0)
        return;
    init_fight_sprites(&m->perso[m->univ.interface.who], &m->perso[k], f, m);
    set_dmg(f, m, &m->perso[m->univ.interface.who], &m->perso[k]);
    m->univ.interface.attacker = m->univ.interface.who;
    m->univ.interface.defender = k;
    m->univ.interface.go_fight = true;
}

static void attack3(Global_t *m, int i, int j, fight_t *f)
{
    char *liste_emy = ENNEMY_CODE;

    for (int k = 0; liste_emy[k] != '\0'; k++) {
        if (m->current_map[i + 1][j] == liste_emy[k]) {
            import_emy_in_battle(m, k, f);
            return;
        }
        if (m->current_map[i - 1][j] == liste_emy[k]) {
            import_emy_in_battle(m, k, f);
            return;
        }
        if (m->current_map[i][j + 1] == liste_emy[k]) {
            import_emy_in_battle(m, k, f);
            return;
        }
        if (m->current_map[i][j - 1] == liste_emy[k]) {
            import_emy_in_battle(m, k, f);
            return;
        }
    }
}

static void attack2(Global_t *m, int i, fight_t *f)
{
    for (int j = 0; m->current_map[i][j] != '\0'; j++) {
        if (m->current_map[i][j] == (m->univ.interface.who + 48)) {
            attack3(m, i, j, f);
        }
    }
    return;
}

static void heal_all(Global_t *m)
{
    for (int i = 0; i < 5; i++) {
        if (m->perso[i].stat_p.current_hp > 0 &&
        m->univ.interface.heal_capa > 0)
            m->perso[i].stat_p.current_hp += 4;
        if (m->perso[i].stat_p.current_hp > m->perso[i].stat_p.max_hp)
            m->perso[i].stat_p.current_hp = m->perso[i].stat_p.max_hp;
    }
    if (m->univ.interface.heal_capa != 0)
        m->univ.interface.heal_capa -= 1;
    m->univ.interface.attack_gpy = false;
}

void attack(Global_t *m, fight_t *f)
{
    if (m->univ.interface.attack_gpy == true) {
        if (m->univ.interface.who == INFENIUM &&
        strcmp(m->perso[INFENIUM].current_weapon->name, "Heal") == 0) {
            return heal_all(m);
        }
        for (int i = 0; m->current_map[i] != NULL; i++) {
            attack2(m, i, f);
        }
        m->univ.interface.attack_gpy = false;
    }
    return;
}
