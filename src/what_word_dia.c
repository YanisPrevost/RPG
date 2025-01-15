/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** what_word_dia.c
*/

#include "rpg.h"
#include "include/perso.h"
#include "include/menu.h"
#include "my.h"

static void what_world_dia3(Global_t *m, RenderContext_t context)
{
    if (m->dialogue.start_dialogue == 7) {
        m->current_combat = 7;
        m->current_boss = 11;
        m->old_map = str_to_word_array(get_buff("maps/map7/map7.txt"));
        m->current_map = str_to_word_array(get_buff("maps/map7/map7.txt"));
        parse_file("dialogue/chap7.txt", &context, m, 7);
        return;
    }
    if (m->dialogue.start_dialogue == 8) {
        m->current_combat = 8;
        m->current_boss = 12;
        m->old_map = str_to_word_array(get_buff("maps/map8/map8.txt"));
        m->current_map = str_to_word_array(get_buff("maps/map8/map8.txt"));
        parse_file("dialogue/chap8.txt", &context, m, 8);
        return;
    }
}

static void what_world_dia2(Global_t *m, RenderContext_t context)
{
    if (m->dialogue.start_dialogue == 5) {
        m->current_combat = 5;
        m->current_boss = 9;
        m->old_map = str_to_word_array(get_buff("maps/map5/map5.txt"));
        m->current_map = str_to_word_array(get_buff("maps/map5/map5.txt"));
        parse_file("dialogue/chap5.txt", &context, m, 5);
        return;
    }
    if (m->dialogue.start_dialogue == 6) {
        m->current_combat = 6;
        m->current_boss = 10;
        m->old_map = str_to_word_array(get_buff("maps/map6/map6.txt"));
        m->current_map = str_to_word_array(get_buff("maps/map6/map6.txt"));
        parse_file("dialogue/chap6.txt", &context, m, 6);
        return;
    }
    what_world_dia3(m, context);
}

static void what_world_dia1(Global_t *m, RenderContext_t context)
{
    if (m->dialogue.start_dialogue == 3) {
        m->current_combat = 3;
        m->current_boss = 7;
        m->old_map = str_to_word_array(get_buff("maps/map3/map3.txt"));
        m->current_map = str_to_word_array(get_buff("maps/map3/map3.txt"));
        parse_file("dialogue/chap3.txt", &context, m, 3);
        return;
    }
    if (m->dialogue.start_dialogue == 4) {
        m->current_combat = 4;
        m->current_boss = 8;
        m->old_map = str_to_word_array(get_buff("maps/map4/map4.txt"));
        m->current_map = str_to_word_array(get_buff("maps/map4/map4.txt"));
        parse_file("dialogue/chap4.txt", &context, m, 4);
        return;
    }
    what_world_dia2(m, context);
}

void what_world_dia(Global_t *m)
{
    RenderContext_t context = {m->window, m->setting.fontdi};

    if (m->dialogue.start_dialogue == 1) {
        m->current_combat = 1;
        m->current_boss = 5;
        m->old_map = str_to_word_array(get_buff("maps/map1/map1.txt"));
        m->current_map = str_to_word_array(get_buff("maps/map1/map1.txt"));
        parse_file("dialogue/chap1.txt", &context, m, 1);
        return;
    }
    if (m->dialogue.start_dialogue == 2) {
        m->current_combat = 2;
        m->current_boss = 6;
        m->old_map = str_to_word_array(get_buff("maps/map2/map2.txt"));
        m->current_map = str_to_word_array(get_buff("maps/map2/map2.txt"));
        parse_file("dialogue/chap2.txt", &context, m, 2);
        return;
    }
    what_world_dia1(m, context);
}
