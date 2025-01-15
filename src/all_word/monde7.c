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
    if (m->perso[ENEMY_MAGE].stat_p.current_hp > 0
    && m->univ.interface.limite_tour == 0) {
        passif_mage(m);
    }
    if (m->perso[BOSS7].stat_p.current_hp <= 0 &&
    !m->univ.interface.go_fight) {
        m->zone7.is_w7_clear = true;
        look_win(m, 7);
    }
    look_loose(m, &m->perso[BOSS7], h);
}

void draw_monde7(Global_t *m, fight_t *f, hub_t *h)
{
    if (m->current == 7) {
        sfRenderWindow_setView(m->window, m->zone7.view_w7);
        sfRenderWindow_drawSprite(m->window, m->zone7.w7_map, NULL);
        check_all_pose(m, m->current_map, 7);
        if (!m->univ.interface.go_fight)
            move_game_cursor(m);
        if (m->univ.interface.limite_tour > 0 && !m->univ.interface.go_fight)
            all_perso_movement(m, m->current_map);
        if (m->univ.interface.limite_tour == 0 && !m->univ.interface.go_fight)
            all_ennemy_movement(m, m->current_map);
        print_mini_barre(m, f, 7);
        if (m->perso[BOSS7].stat_p.current_hp > 0)
            print_boss_barre(m, BOSS7, m->univ.spr_Boss7);
        part2(m, h);
        return_and_old_current2(m, 7);
    }
}
