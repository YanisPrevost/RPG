/*
** EPITECH PROJECT, 2023
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
    if (m->perso[BOSS5].stat_p.current_hp <= 0 &&
    !m->univ.interface.go_fight) {
        m->zone5.is_w5_clear = true;
        look_win(m, 5);
    }
    look_loose(m, &m->perso[BOSS5], h);
}

void draw_monde5(Global_t *m, fight_t *f, hub_t *h)
{
    if (m->current == 5) {
        sfRenderWindow_setView(m->window, m->zone5.view_w5);
        sfRenderWindow_drawSprite(m->window, m->zone5.w5_map, NULL);
        check_all_pose(m, m->current_map, 5);
        if (!m->univ.interface.go_fight)
            move_game_cursor(m);
        if (m->univ.interface.limite_tour > 0 && !m->univ.interface.go_fight)
            all_perso_movement(m, m->current_map);
        if (m->univ.interface.limite_tour == 0 && !m->univ.interface.go_fight)
            all_ennemy_movement(m, m->current_map);
        print_mini_barre(m, f, 5);
        if (m->perso[BOSS5].stat_p.current_hp > 0)
            print_boss_barre(m, BOSS5, m->univ.spr_Boss5);
        part2(m, h);
        return_and_old_current2(m, 5);
    }
}
