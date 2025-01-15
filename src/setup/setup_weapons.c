/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** setup_weapons.c
*/

#include "../rpg.h"
#include "../include/npc.h"

void change_name(char *name)
{
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == '_')
            name[i] = ' ';
    }
}

int import_weapons_stats(Global_t *m)
{
    FILE *file = fopen("assets/weapons/weapons_stat.txt", "r");

    for (int i = 0; i < 30; i++) {
        if (fscanf(file, "%s %s %d %d %d %d %d %s %d", m->weapons[i].name,
        m->weapons[i].weapon_type, &m->weapons[i].attack,
        &m->weapons[i].accuracy,
        &m->weapons[i].rng, &m->weapons[i].crit, &m->weapons[i].cost,
        &m->weapons[i].link_texture, &m->weapons[i].idx_weap) != 9) {
            printf("Erreur de lecture pour l'arme %d\n", i);
            fclose(file);
            return 84;
        }
        change_name(m->weapons[i].name);
    }
    fclose(file);
    return 0;
}
