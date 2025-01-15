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
    if (m->perso[BOSS3].stat_p.current_hp <= 0 &&
    !m->univ.interface.go_fight) {
        m->zone3.is_w3_clear = true;
        look_win(m, 3);
    }
    look_loose(m, &m->perso[BOSS3], h);
}

void draw_monde3(Global_t *m, fight_t *f, hub_t *h)
{
    if (m->current == 3) {
        sfRenderWindow_setView(m->window, m->zone3.view_w3);
        sfRenderWindow_drawSprite(m->window, m->zone3.w3_map, NULL);
        check_all_pose(m, m->current_map, 3);
        if (!m->univ.interface.go_fight)
            move_game_cursor(m);
        if (m->univ.interface.limite_tour > 0 && !m->univ.interface.go_fight)
            all_perso_movement(m, m->current_map);
        if (m->univ.interface.limite_tour == 0 && !m->univ.interface.go_fight)
            all_ennemy_movement(m, m->current_map);
        print_mini_barre(m, f, 3);
        if (m->perso[BOSS3].stat_p.current_hp > 0)
            print_boss_barre(m, BOSS3, m->univ.spr_Boss3);
        part2(m, h);
        return_and_old_current2(m, 3);
    }
}
