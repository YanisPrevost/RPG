/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** print_txt.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

static void setup(Global_t *m, sfVector2f pose)
{
    sfText_setFont(m->dialogue.pro_dia, m->setting.fontdi);
    sfText_setColor(m->dialogue.pro_dia, sfBlack);
    sfText_setPosition(m->dialogue.pro_dia, pose);
    sfText_setScale(m->dialogue.pro_dia, (sfVector2f){0.4, 0.6});
}

void what_dialogue(Global_t *m, int word, hub_t *hub, sfVector2f pose)
{
    setup(m, pose);
    if (word == 0)
        displaydialogue(m, hub, word, m->dialogue.lines);
    if (word == 1)
        displaydialogue(m, hub, word, m->dialogue.lines_w1);
    if (word == 2)
        displaydialogue(m, hub, word, m->dialogue.lines_w2);
    if (word == 3)
        displaydialogue(m, hub, word, m->dialogue.lines_w3);
    if (word == 4)
        displaydialogue(m, hub, word, m->dialogue.lines_w4);
    if (word == 5)
        displaydialogue(m, hub, word, m->dialogue.lines_w5);
    if (word == 6)
        displaydialogue(m, hub, word, m->dialogue.lines_w6);
    if (word == 7)
        displaydialogue(m, hub, word, m->dialogue.lines_w7);
    if (word == 8)
        displaydialogue(m, hub, word, m->dialogue.lines_w8);
}
