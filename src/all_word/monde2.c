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
    if (m->perso[BOSS2].stat_p.current_hp <= 0 &&
    !m->univ.interface.go_fight) {
        m->zone2.is_w2_clear = true;
        look_win(m, 2);
    }
    look_loose(m, &m->perso[BOSS2], h);
}

void draw_monde2(Global_t *m, fight_t *f, hub_t *h)
{
    if (m->current == 2) {
        sfRenderWindow_setView(m->window, m->zone2.view_w2);
        sfRenderWindow_drawSprite(m->window, m->zone2.w2_map, NULL);
        check_all_pose(m, m->current_map, 2);
        if (!m->univ.interface.go_fight)
            move_game_cursor(m);
        if (m->univ.interface.limite_tour > 0 && !m->univ.interface.go_fight)
            all_perso_movement(m, m->current_map);
        if (m->univ.interface.limite_tour == 0 && !m->univ.interface.go_fight)
            all_ennemy_movement(m, m->current_map);
        print_mini_barre(m, f, 2);
        if (m->perso[BOSS2].stat_p.current_hp > 0)
            print_boss_barre(m, BOSS2, m->univ.spr_Boss2);
        part2(m, h);
        return_and_old_current2(m, 2);
    }
}
