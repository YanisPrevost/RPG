/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** save_txt.c
*/

#include "../rpg.h"
#include "../include/menu.h"

static void coco(Global_t *m)
{
    if (m->current == 0 || m->current == 9)
        sfText_setString(m->menu.save_txt, "Auto saving game...");
    else
        sfText_setString(m->menu.save_txt, "Saving game...");
    if (m->univ.interface.fake_save == false)
    sfRenderWindow_drawText(m->window, m->menu.save_txt, NULL);
}

void suite_ptr_saving(Global_t *m, sfTime elapsed, float seconds)
{
    elapsed = sfClock_getElapsedTime(m->o.txt_clock);
    seconds = sfTime_asSeconds(elapsed);
    if (seconds < 2.0f) {
        sfText_setFillColor(m->menu.save_txt, sfBlack);
        coco(m);
    } else {
        m->o.is_saved = 2;
        sfClock_restart(m->o.txt_clock);
    }
}

void suite_ptr(Global_t *m, sfTime elapsed, float seconds)
{
    elapsed = sfClock_getElapsedTime(m->o.txt_clock);
    seconds = sfTime_asSeconds(elapsed);
    if (seconds < 1.0f && m->univ.interface.fake_save == false) {
        sfText_setString(m->menu.save_txt, "\t\t\tGame saved !");
        sfRenderWindow_drawText(m->window, m->menu.save_txt, NULL);
    } else {
        m->o.is_saved = 0;
    }
}

void print_save_txt(Global_t *m)
{
    sfTime elapsed;
    float seconds;

    if (m->current == 9) {
        sfText_setPosition(m->menu.save_txt, (sfVector2f){675, 450});
        sfText_setScale(m->menu.save_txt, (sfVector2f){0.5, 0.5});
    } else {
        sfText_setPosition(m->menu.save_txt, (sfVector2f){1610, 1010});
        sfText_setScale(m->menu.save_txt, (sfVector2f){1, 1});
    }
    if (m->o.is_saved == 1) {
        suite_ptr_saving(m, elapsed, seconds);
    } else if (m->o.is_saved == 2) {
        suite_ptr(m, elapsed, seconds);
        m->univ.interface.fake_save = false;
    }
}
