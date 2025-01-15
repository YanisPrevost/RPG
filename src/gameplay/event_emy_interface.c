/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** event_emy_interface.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

static void import_emy_in_battle(Global_t *m, int k, fight_t *f)
{
    char *liste = ENNEMY_CODE;
    int i = 0;

    for (i; liste[i] != '\0'; i++) {
        if (liste[i] == m->univ.interface.current_emy) {
            break;
        }
    }
    i += 5;
    if (m->perso[i].stat_p.current_hp <= 0)
        return;
    init_fight_sprites(&m->perso[i], &m->perso[k], f, m);
    set_dmg(f, m, &m->perso[m->univ.interface.who], &m->perso[k]);
    m->univ.interface.attacker = i;
    m->univ.interface.defender = k;
    m->univ.interface.go_fight = true;
}

static void attack3(Global_t *m, int i, int j, fight_t *f)
{
    char *liste_emy = "01234";

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
        if (m->current_map[i][j] == m->univ.interface.current_emy) {
            attack3(m, i, j, f);
        }
    }
    return;
}

void attack_ally(Global_t *m, fight_t *f)
{
    if (m->univ.interface.attack_gpy2 == true) {
        for (int i = 0; m->current_map[i] != NULL; i++) {
            attack2(m, i, f);
        }
        m->univ.interface.attack_gpy2 = false;
    }
    return;
}
