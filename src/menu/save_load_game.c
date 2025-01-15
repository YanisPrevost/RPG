/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** save_load_game.c
*/

#include "../rpg.h"
#include "../include/menu.h"

static int gestion_err_du_fichier(FILE *file, int c, Global_t *m)
{
    if (file == NULL) {
        printf("fichier de sauvegarde introuvable!\n");
        exit(1);
    }
    c = fgetc(file);
    if (c == EOF) {
        printf("Aucune données de sauvegarde trouvée!\n");
        fclose(file);
        return -1;
    }
    fseek(file, 0, SEEK_SET);
}

static void add_to_inv(Global_t *m, FILE *file, int i, int j)
{
    size_t size = sizeof(Weapons_t);
    int inv;

    fscanf(file, "%d,", &inv);
    memset(&m->perso[i].inv_weapon[j], 0, size);
    if (inv != 0) {
        if (inv == 30)
            inv = 0;
        m->perso[i].inv_weapon[j].is_empty = false;
        memcpy(&m->perso[i].inv_weapon[j], &m->weapons[inv], size);
    } else
        m->perso[i].inv_weapon[j].is_empty = true;
}

static void load_inventory(Global_t *m, FILE *file)
{
    size_t size = sizeof(Weapons_t);
    int weap;

    for (int i = 0; i < 5; i++) {
        fscanf(file, "%d,", &weap);
        memset(m->perso[i].current_weapon, 0, size);
        if (weap == -1)
            m->perso[i].current_weapon->idx_weap = -1;
        if (weap == 30)
            weap = 0;
        if (weap != -1)
            memcpy(&m->perso[i].current_weapon, &m->weapons[weap], size);
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            add_to_inv(m, file, i, j);
        }
    }
}

static void load_stats(Global_t *m, FILE *file, int i)
{
    fscanf(file, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
        &m->perso[i].stat_p.level, &m->perso[i].stat_p.xp,
        &m->perso[i].stat_p.current_hp, &m->perso[i].stat_p.max_hp,
        &m->perso[i].stat_p.lck, &m->perso[i].stat_p.mag,
        &m->perso[i].stat_p.skl, &m->perso[i].stat_p.def,
        &m->perso[i].stat_p.res,
        &m->perso[i].stat_p.str, &m->perso[i].stat_p.spd,
        &m->perso[i].stat_p.mov);
}

void load_game(Global_t *m, hub_t *hub)
{
    FILE *file = fopen("assets/save_party/save.txt", "r");
    int c;

    if (gestion_err_du_fichier(file, c, m) == -1) {
        m->current = 14;
        return;
    }
    fscanf(file, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", &m->gold,
    &m->hub.prologue_ok,
    &m->zone1.is_w1_clear, &m->zone2.is_w2_clear, &m->zone3.is_w3_clear,
    &m->zone4.is_w4_clear,
    &m->zone5.is_w5_clear, &m->zone6.is_w6_clear, &m->zone7.is_w7_clear,
    &m->zone8.is_w8_clear, &m->perso->current_perso,
    &m->perso->first_current_perso, &m->univ.interface.is_passif_apply);
    for (int i = 0; i < 5; i++) {
        load_stats(m, file, i);
    }
    load_inventory(m, file);
    m->current = 14;
    fclose(file);
}

static void print_virgule(FILE *file, int j)
{
    if (j != 4)
        fprintf(file, ",");
}

static void save_current_weapon(Global_t *m, FILE *file)
{
    for (int i = 0; i < 5; i++) {
        fprintf(file, "%d", m->perso[i].current_weapon->idx_weap);
        if (i != 4)
            fprintf(file, ",");
    }
    fprintf(file, "\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fprintf(file, "%d", m->perso[i].inv_weapon[j].idx_weap);
            print_virgule(file, j);
        }
        fprintf(file, "\n");
    }
    m->o.is_saved = 1;
    sfClock_restart(m->o.txt_clock);
}

void save_game(Global_t *m)
{
    FILE *file = fopen("assets/save_party/save.txt", "w");

    fprintf(file, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", m->gold,
    m->hub.prologue_ok, m->zone1.is_w1_clear,
    m->zone2.is_w2_clear, m->zone3.is_w3_clear, m->zone4.is_w4_clear,
    m->zone5.is_w5_clear, m->zone6.is_w6_clear, m->zone7.is_w7_clear,
    m->zone8.is_w8_clear, m->perso->current_perso,
    m->perso->first_current_perso, m->univ.interface.is_passif_apply);
    for (int i = 0; i < 5; i++) {
        fprintf(file, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
            m->perso[i].stat_p.level, m->perso[i].stat_p.xp,
            m->perso[i].stat_p.current_hp, m->perso[i].stat_p.max_hp,
            m->perso[i].stat_p.lck, m->perso[i].stat_p.mag,
            m->perso[i].stat_p.skl, m->perso[i].stat_p.def,
            m->perso[i].stat_p.res,
            m->perso[i].stat_p.str, m->perso[i].stat_p.spd,
            m->perso[i].stat_p.mov);
    }
    save_current_weapon(m, file);
    fflush(file);
}

void save_auto(Global_t *m)
{
    sfTime time = sfClock_getElapsedTime(m->menu.save_auto_clk);
    float seconds = sfTime_asSeconds(time);

    if (m->current == 0 || m->current == 9) {
        if (seconds >= 600.0f) {
            save_game(m);
            m->is_a_save = true;
            sfClock_restart(m->menu.save_auto_clk);
        }
    }
}
