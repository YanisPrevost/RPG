/*
** EPITECH PROJECT, 2026
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** monde1.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

static void part2(Global_t *m, hub_t *h)
{
    if (m->perso[BOSS6].stat_p.current_hp <= 0 &&
    !m->univ.interface.go_fight) {
        m->zone6.is_w6_clear = true;
        look_win(m, 6);
    }
    look_loose(m, &m->perso[BOSS6], h);
}

void draw_monde6(Global_t *m, fight_t *f, hub_t *h)
{
    if (m->current == 6) {
        sfRenderWindow_setView(m->window, m->zone6.view_w6);
        sfRenderWindow_drawSprite(m->window, m->zone6.w6_map, NULL);
        check_all_pose(m, m->current_map, 6);
        if (!m->univ.interface.go_fight)
            move_game_cursor(m);
        if (m->univ.interface.limite_tour > 0 && !m->univ.interface.go_fight)
            all_perso_movement(m, m->current_map);
        if (m->univ.interface.limite_tour == 0 && !m->univ.interface.go_fight)
            all_ennemy_movement(m, m->current_map);
        print_mini_barre(m, f, 6);
        if (m->perso[BOSS6].stat_p.current_hp > 0)
            print_boss_barre(m, BOSS6, m->univ.spr_Boss6);
        part2(m, h);
        return_and_old_current2(m, 6);
    }
}
